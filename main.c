#include "defines.h"
#include "events.h"
#include "myinit.h"
#include "MQTTClient.h"


/*
 * Values for below macros shall be modified per the access-point's (AP) properties
 * SimpleLink device will connect to following AP when the application is executed
 */

/* Application specific status/error codes */
typedef enum{
    DEVICE_NOT_IN_STATION_MODE = -0x7D0,        /* Choosing this number to avoid overlap with host-driver's error codes */
    HTTP_SEND_ERROR = DEVICE_NOT_IN_STATION_MODE - 1,
    HTTP_RECV_ERROR = HTTP_SEND_ERROR - 1,
    HTTP_INVALID_RESPONSE = HTTP_RECV_ERROR -1,
    STATUS_CODE_MAX = -0xBB8,
    TCP_SEND_ERROR = DEVICE_NOT_IN_STATION_MODE - 1,
    TCP_RECV_ERROR = TCP_SEND_ERROR -1,
    BSD_UDP_CLIENT_FAILED = DEVICE_NOT_IN_STATION_MODE - 1,
}e_AppStatusCodes;

union
{
    _u8 BsdBuf[BUF_SIZE];
    _u32 demobuf[BUF_SIZE/4];
} uBuf;

/*
 * GLOBAL VARIABLES -- Start
 */
/* Button debounce state variables */
volatile unsigned int S1buttonDebounce = 0;
volatile unsigned int S2buttonDebounce = 0;
volatile int publishID = 1;

unsigned char macAddressVal[SL_MAC_ADDR_LEN];
unsigned char macAddressLen = SL_MAC_ADDR_LEN;

_u32  g_Status = 0;

/* Port mapper configuration register */
const uint8_t port_mapping[] =
{
    //Port P2:
    PM_TA0CCR1A, PM_TA0CCR2A, PM_TA0CCR3A, PM_NONE, PM_TA1CCR1A, PM_NONE, PM_NONE, PM_NONE
};
//stuff for mqtt
#define MQTT_BROKER_SERVER  "192.168.1.88"
#define SUBSCRIBE_TOPIC "goal"
#define PUBLISH_TOPIC "step"

// MQTT message buffer size
#define BUFF_SIZE 32


#define APPLICATION_VERSION "1.0.0"
char uniqueID[9] = "cowcowcow";

void mqtt_subscribe();
void messageArrived(MessageData* data);
void send_steps();

Network n;
Client hMQTTClient;     // MQTT Client




/*
 * ASYNCHRONOUS EVENT HANDLERS -- End
 */


/*
 * Application's entry point
 */
int main(int argc, char** argv)
{

    /* Stop WDT and initialize lcd, clcks, main interfaces */
    stopWDT();
    init_clocks(); //init clock for LCD
    init_lcd();
    initClk(); //init clock for wifi
    Delay(10);
    init_main();
    Delay(10);

    int rc = 0;
    unsigned char buf[100];
    unsigned char readbuf[100];

    NewNetwork(&n);
    rc = ConnectNetwork(&n, MQTT_BROKER_SERVER, 1883);

    if (rc != 0) {
        CLI_Write(" Failed to connect to MQTT broker \n\r");
    }

    MQTTClient(&hMQTTClient, &n, 1000, buf, 100, readbuf, 100);
    MQTTPacket_connectData cdata = MQTTPacket_connectData_initializer;
    cdata.MQTTVersion = 3;
    cdata.clientID.cstring = uniqueID;
    rc = MQTTConnect(&hMQTTClient, &cdata);

    if (rc != 0) {
        CLI_Write(" Failed to start MQTT client \n\r");
        //LOOP_FOREVER();
    }

    rc = MQTTSubscribe(&hMQTTClient, "test", QOS0, messageArrived);

    if (rc != 0) {
        CLI_Write(" Failed to subscribe to /msp/cc3100/demo topic \n\r");
        //LOOP_FOREVER();
    }

    while(1) {
        //TODO add real expression here
        if(1) {
            rc = MQTTYield(&hMQTTClient, 10);
            if (rc != 0) {
                CLI_Write(" MQTT failed to yield \n\r");
                //LOOP_FOREVER();
            }

            if (publishID) {
                int rc = 0;
                MQTTMessage msg;
                msg.dup = 0;
                msg.id = 0;
                msg.payload = uniqueID;
                msg.payloadlen = 8;
                msg.qos = QOS0;
                msg.retained = 0;
                rc = MQTTPublish(&hMQTTClient, PUBLISH_TOPIC, &msg);

                if (rc != 0) {
                    CLI_Write(" Failed to publish unique ID to MQTT broker \n\r");
                    //LOOP_FOREVER();
                }
                CLI_Write(" Published unique ID successfully \n\r");

                publishID = 1;
            }
            Delay(10);
        }
   }
}

void PORT1_IRQHandler(void)
{
    uint32_t status = GPIO_getEnabledInterruptStatus(GPIO_PORT_P1);
    GPIO_clearInterruptFlag(GPIO_PORT_P1, status);

    if (status & GPIO_PIN1)
    {
        if (S1buttonDebounce == 0)
        {
            S1buttonDebounce = 1;

            GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);

            // Publish the unique ID
            publishID = 1;

            MAP_Timer_A_startCounter(TIMER_A1_BASE, TIMER_A_UP_MODE);
        }
    }
    if (status & GPIO_PIN4)
    {
        if (S2buttonDebounce == 0)
        {
            S2buttonDebounce = 1;


            MAP_Timer_A_startCounter(TIMER_A1_BASE, TIMER_A_UP_MODE);
        }
    }
}

void TA1_0_IRQHandler(void)
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
    if (P1IN & GPIO_PIN1)
    {
        S1buttonDebounce = 0;
    }
    if (P1IN & GPIO_PIN4)
    {
        S2buttonDebounce = 0;
    }

    if ((P1IN & GPIO_PIN1) && (P1IN & GPIO_PIN4))
    {
        Timer_A_stopTimer(TIMER_A1_BASE);
    }
    MAP_Timer_A_clearCaptureCompareInterrupt(TIMER_A1_BASE,
                TIMER_A_CAPTURECOMPARE_REGISTER_0);
}

void mqtt_subscribe() {


}
void send_steps() {
    //while(1){
        int rc = MQTTYield(&hMQTTClient, 10);
        if (rc != 0) {
            CLI_Write(" MQTT failed to yield \n\r");
            //LOOP_FOREVER();
        }

        publishID = 1;
        if (publishID) {
            int rc = 0;
            MQTTMessage msg;
            msg.dup = 0;
            msg.id = 0;
            msg.payload = "step123";
            msg.payloadlen = 8;
            msg.qos = QOS0;
            msg.retained = 0;
            rc = MQTTPublish(&hMQTTClient, PUBLISH_TOPIC, &msg);

            if (rc != 0) {
                CLI_Write(" Failed to publish unique ID to MQTT broker \n\r");
                //LOOP_FOREVER();
            }
            CLI_Write(" Published unique ID successfully \n\r");

            publishID = 0;
        }

        Delay(10);
   // }
}
//****************************************************************************
//
//!    \brief MQTT message received callback - Called when a subscribed topic
//!                                            receives a message.
//! \param[in]                  data is the data passed to the callback
//!
//! \return                        None
//
//****************************************************************************
void messageArrived(MessageData* data) {
    char buf[BUFF_SIZE];

    char *tok;
    long color;

    backlight_on();
    Delay(200);
    backlight_off();
    // Check for buffer overflow
    if (data->topicName->lenstring.len >= BUFF_SIZE) {
//      UART_PRINT("Topic name too long!\n\r");
        return;
    }
    if (data->message->payloadlen >= BUFF_SIZE) {
//      UART_PRINT("Payload too long!\n\r");
        return;
    }

    strncpy(buf, data->topicName->lenstring.data,
        min(BUFF_SIZE, data->topicName->lenstring.len));
    buf[data->topicName->lenstring.len] = 0;



    strncpy(buf, data->message->payload,
        min(BUFF_SIZE, data->message->payloadlen));
    buf[data->message->payloadlen] = 0;

    tok = strtok(buf, " ");
    color = strtol(tok, NULL, 10);
    TA0CCR1 = PWM_PERIOD * (color/255.0);                 // CCR1 PWM duty cycle
    tok = strtok(NULL, " ");
    color = strtol(tok, NULL, 10);
    TA0CCR2 = PWM_PERIOD * (color/255.0);                // CCR2 PWM duty cycle
    tok = strtok(NULL, " ");
    color = strtol(tok, NULL, 10);
    TA0CCR3 = PWM_PERIOD * (color/255.0);                  // CCR3 PWM duty cycle

    return;
}

void ADC14_IRQHandler(void)
{
  uint64_t status;

    //AdcObj adc_message;
    //adc_message.x = 0;
    //adc_message.y = 0;
    //adc_message.z = 0;

    MAP_Interrupt_disableInterrupt(INT_ADC14);
    status = MAP_ADC14_getEnabledInterruptStatus();
    MAP_ADC14_clearInterruptFlag(status);

    /* ADC_MEM2 conversion completed */
    if(status & ((uint32_t)0x00000004))
    {
        /* Store ADC14 conversion results */
        //adc_message.x = ADC14_getResult(ADC_MEM0);
        //adc_message.y = ADC14_getResult(ADC_MEM1);
        //adc_message.z = ADC14_getResult(ADC_MEM2);

        //Mailbox_post(ADC_Mbx, &adc_message, BIOS_WAIT_FOREVER);
        P1OUT ^= BIT1;

    }
}
