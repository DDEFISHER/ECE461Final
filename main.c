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

/* Button debounce state variables */
volatile unsigned int S1buttonDebounce = 0;
volatile unsigned int S2buttonDebounce = 0;
volatile int publishID = 1;

_u32  g_Status = 0;

/* Port mapper configuration register */
const uint8_t port_mapping[] =
{
    //Port P2:
    PM_TA0CCR1A, PM_TA0CCR2A, PM_TA0CCR3A, PM_NONE, PM_TA1CCR1A, PM_NONE, PM_NONE, PM_NONE
};

void menu();

//stuff for mqtt
#define MQTT_BROKER_SERVER  "192.168.1.88"
#define SUBSCRIBE_TOPIC "goal"
#define PUBLISH_TOPIC "step"

// MQTT message buffer size
#define BUFF_SIZE 32


#define APPLICATION_VERSION "1.0.0"
char uniqueID[9] = "cowcowcow";

void messageArrived(MessageData* data);

Network n;
Client hMQTTClient;     // MQTT Client

int goal_steps = 0;
int steps_taken = 0;

int menu_state = 0;
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
    cdata.clientID.cstring = "daniel";
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
        MQTTYield(&hMQTTClient, 10);

        if( (P3IN & BIT5) == 0) {
            MQTTMessage msg;
            msg.dup = 0;
            msg.id = 0;
            msg.payload = "daniel";
            msg.payloadlen = 8;
            msg.qos = QOS0;
            msg.retained = 0;
            MQTTPublish(&hMQTTClient, PUBLISH_TOPIC, &msg);

            Delay(20);
        } else if ( (P1IN & BIT4) == 0) {
          menu();
        }
    }
}

void PORT1_IRQHandler(void)
{
    uint32_t status = GPIO_getEnabledInterruptStatus(GPIO_PORT_P1);
    GPIO_clearInterruptFlag(GPIO_PORT_P1, status);
}

void TA1_0_IRQHandler(void)
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);


    MAP_Timer_A_clearCaptureCompareInterrupt(TIMER_A1_BASE,
                TIMER_A_CAPTURECOMPARE_REGISTER_0);
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
    show_steps();
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

    status = MAP_ADC14_getEnabledInterruptStatus();
    MAP_ADC14_clearInterruptFlag(status);

    /* ADC_MEM2 conversion completed */
    if(status & ((uint32_t)0x00000004))
    {
        step_track_and_alert(ADC14_getResult(ADC_MEM0),
                             ADC14_getResult(ADC_MEM1),
                             ADC14_getResult(ADC_MEM2));
    }
}

void menu() {

  if(menu_state == 0) {
    menu1();
    menu_state++;
  } else if (menu_state == 1) {
    menu2();
    menu_state++;
  } else if (menu_state == 2) {
    menu3();
    menu_state++;
  } else if (menu_state == 3) {
    menu4();
    menu_state = 0;
  } else if (menu_state == 3) {

  } else if (menu_state == 2) {

  } else if (menu_state == 2) {

  } else if (menu_state == 2) {

  } else if (menu_state == 2) {

  }

}
