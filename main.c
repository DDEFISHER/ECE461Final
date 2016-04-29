#include "defines.h"
#include "events.h"
#include "myinit.h"
#include "MQTTClient.h"
#include <stdio.h>


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
void menu_select();
void load_data();

//stuff for mqtt
#define MQTT_BROKER_SERVER  "iot.eclipse.org"
#define SUBSCRIBE_TOPIC "defi"
#define PUBLISH_TOPIC "dedefishstep"
#define START 0x0003F000
#define START2 0x0003F004

// MQTT message buffer size
#define BUFF_SIZE 32


#define APPLICATION_VERSION "1.0.0"
char uniqueID[9] = "cowcowcow";

void messageArrived(MessageData* data);

Network n;
Client hMQTTClient;     // MQTT Client

int goal_steps = 10;
int steps_taken = 0;
int send_goal_bool = 0;
int send_on_bool = 0;
int active_bool = 1;

int debounce = 0;

int menu_state = 0;
int state2 = 0;
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
    Delay(5);
    init_main();
    Delay(5);

    load_data();

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

    rc = MQTTSubscribe(&hMQTTClient, SUBSCRIBE_TOPIC, QOS0, messageArrived);

    if (rc != 0) {
        CLI_Write(" Failed to subscribe to /msp/cc3100/demo topic \n\r");
        //LOOP_FOREVER();
    }

    MQTTYield(&hMQTTClient, 10);
    int8_t buffer[2] = "on";
    MQTTMessage msg;
    msg.dup = 0;
    msg.id = 0;
    msg.payload = buffer;
    msg.payloadlen = 8;
    msg.qos = QOS0;
    msg.retained = 0;
    MQTTPublish(&hMQTTClient, PUBLISH_TOPIC, &msg);
    Delay(20);

    backlight_off();
    while(1) {
        MQTTYield(&hMQTTClient, 10);
        debounce++;

        if(send_goal_bool) {
            int8_t buffer2[15] = "               ";
            sprintf(buffer2, "%d", goal_steps);
            msg;
            msg.dup = 0;
            msg.id = 0;
            msg.payload = buffer2;
            msg.payloadlen = 15;
            msg.qos = QOS0;
            msg.retained = 0;
            MQTTPublish(&hMQTTClient, PUBLISH_TOPIC, &msg);
            Delay(20);
            send_goal_bool = 0;
        }else if(send_on_bool) {
            int8_t buffer2[2] = "on";
            msg;
            msg.dup = 0;
            msg.id = 0;
            msg.payload = buffer2;
            msg.payloadlen = 2;
            msg.qos = QOS0;
            msg.retained = 0;
            MQTTPublish(&hMQTTClient, PUBLISH_TOPIC, &msg);
            Delay(20);
            send_on_bool = 0;
        } else if( (P3IN & BIT5) == 0 && debounce > 20) {
          debounce = 0;
          menu_select();
        } else if ( (P1IN & BIT4) == 0 && debounce > 10) {
          debounce = 0;
          menu();
        } else if ( steps_taken >= goal_steps && active_bool == 1 ) {
          P1OUT &= ~BIT0;
          int8_t buffer2[1] = "g";
          msg;
          msg.dup = 0;
          msg.id = 0;
          msg.payload = buffer2;
          msg.payloadlen = 1;
          msg.qos = QOS0;
          msg.retained = 0;
          MQTTPublish(&hMQTTClient, "on", &msg);
          Delay(20);
          MAP_Interrupt_disableInterrupt(INT_ADC14);
          active_bool = 0;
          view_goal_menu();
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


    char num_string[4] = "    ";
    num_string[0] = data->topicName->lenstring.data[4];
    num_string[1] = data->topicName->lenstring.data[5];
    num_string[2] = data->topicName->lenstring.data[6];
    num_string[3] = data->topicName->lenstring.data[7];
    int new_goal = 0;

    sscanf(num_string, "%d", &new_goal);

    if(new_goal > 0) {
    goal_steps = new_goal;
    }

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
    state2 = 0;
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
    state2 = 4;
  } else if (menu_state == 4) {

  } else if (menu_state == 5) {
    goal_steps+= 10;
    set_goal_menu1();

  } else if (menu_state == 6) {

    //on activity menu
    menu_state = 0;
    backlight_off();

  } else if (menu_state == 7) {

  } else if (menu_state == 4) {

  }

}
void menu_select() {

  if(menu_state == 1) {
        P1OUT &= ~BIT0;
        send_on_bool = 1;
        MAP_Interrupt_disableInterrupt(INT_ADC14);
        active_bool = 0;
        view_activity_menu();
        state2 = 0;
        menu_state = 6;
  } else if (menu_state == 2) {
        P1OUT |= BIT0;
        send_on_bool = 1;
        steps_taken = 0;
        active_bool = 1;
        MAP_Interrupt_enableInterrupt(INT_ADC14);
        menu_state = 0;
        backlight_off();
  } else if (menu_state == 3) {
        goal_steps = 10;
        set_goal_menu1();
        menu_state = 5;
  } else if (state2) {
        view_activity_menu();
        state2 = 0;
        menu_state = 6;
  } else if (menu_state == 5) {
        send_goal_bool = 1;
        menu_state = 0;
        backlight_off();
  } else if (menu_state == 6) {
        menu_state = 0;
        backlight_off();
  }
}
void load_data() {
    
    int i = 0;
    uint8_t data[4];
    for(i = 0; i < 4; i++) {
        data[i] = *(uint8_t*)(i+START);
    }
    sscanf(data, "%d", &steps_taken);
    for(i = 0; i < 4; i++) {
        data[i] = *(uint8_t*)(i+START2);
    }
    sscanf(data, "%d", &goal_steps);
}
