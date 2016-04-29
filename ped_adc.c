/*
 * ped_adc.c - used to init the adc and timers that the entire project uses
 *
 *  Created on: Apr 4, 2016
 *      Author: daniel
 */

/* TI-RTOS Header files */
#include "driverlib.h"
#include "ped_adc.h"
#include "msp.h"
#include <stdio.h>

#define START  0x0003F000
#define START2 0x0003F004
extern int steps_taken;
extern int goal_steps;
int old_diffs_x[400];
int old_diffs_y[400];
int old_diffs_z[400];

int old_x = 0;
int old_y = 0;
int old_z = 0;

int new_x = 0;
int new_y = 0;
int new_z = 0;

int average_x = 0;
int average_y = 0;
int average_z = 0;
int counter = 0;
int loop_index = 0;
//init adc
void init_adc()
{
    /* Configures Pin 4.0, 4.2, and 6.1 as ADC input */
    MAP_CS_initClockSignal(CS_ACLK, CS_REFOCLK_SELECT, CS_CLOCK_DIVIDER_1);
    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P4, GPIO_PIN0 | GPIO_PIN2, GPIO_TERTIARY_MODULE_FUNCTION);
    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P6, GPIO_PIN1, GPIO_TERTIARY_MODULE_FUNCTION);

    /* Initializing ADC (ADCOSC/64/8) */
    MAP_ADC14_enableModule();
    MAP_ADC14_initModule(ADC_CLOCKSOURCE_ADCOSC, ADC_PREDIVIDER_64, ADC_DIVIDER_8,
            0);

    /* Configuring ADC Memory (ADC_MEM0 - ADC_MEM2 (A11, A13, A14)  with no repeat)
         * with internal 2.5v reference */
    MAP_ADC14_configureMultiSequenceMode(ADC_MEM0, ADC_MEM2, true);
    MAP_ADC14_configureConversionMemory(ADC_MEM0,
            ADC_VREFPOS_AVCC_VREFNEG_VSS,
            ADC_INPUT_A14, ADC_NONDIFFERENTIAL_INPUTS);

    MAP_ADC14_configureConversionMemory(ADC_MEM1,
            ADC_VREFPOS_AVCC_VREFNEG_VSS,
            ADC_INPUT_A13, ADC_NONDIFFERENTIAL_INPUTS);

    MAP_ADC14_configureConversionMemory(ADC_MEM2,
            ADC_VREFPOS_AVCC_VREFNEG_VSS,
            ADC_INPUT_A11, ADC_NONDIFFERENTIAL_INPUTS);

    /* Enabling the interrupt when a conversion on channel 2 (end of sequence)
     *  is complete and enabling conversions */
    MAP_ADC14_enableInterrupt(ADC_INT2);

    /* Enabling Interrupts */
    MAP_Interrupt_enableInterrupt(INT_ADC14);

    /* Setting up the sample timer to automatically step through the sequence
     * convert.
     */
    MAP_ADC14_enableSampleTimer(ADC_AUTOMATIC_ITERATION);

    /* Triggering the start of the sample */
    MAP_ADC14_enableConversion();
    MAP_ADC14_toggleConversionTrigger();
}

void step_track_and_alert(int x, int y, int z) {

      if((old_x - x) > 0 ) {

        old_diffs_x[counter] = old_x - x;
      } else {
        old_diffs_x[counter] = x - old_x;
      }
      if((old_y - y) > 0 ) {

        old_diffs_y[counter] = old_y - y;
      } else {
        old_diffs_x[counter] = y - old_y;
      }
      if((old_z - z) > 0 ) {

        old_diffs_z[counter] = old_z - z;
      } else {
        old_diffs_z[counter] = z - old_z;
      }

      old_x = x;
      old_y = y;
      old_z = z;


      counter++;

      if(counter > 399) {

          int sum_x = 0;
          int sum_y = 0;
          int sum_z = 0;

          for(loop_index = 0; loop_index < counter; loop_index++) {

            sum_x = sum_x + old_diffs_x[loop_index];

          }
          average_x = sum_x/(counter+1);

          for(loop_index = 0; loop_index < counter; loop_index++) {

            sum_y = sum_y + old_diffs_y[loop_index];

          }

          average_y = sum_y/(counter+1);

          for(loop_index = 0; loop_index < counter; loop_index++) {

            sum_z = sum_z + old_diffs_z[loop_index];

          }

          average_z = sum_z/(counter+1);

          //convert ints to string to display
          if(average_z > 20) {

            steps_taken++;
            write(steps_taken);
          }
          //combine_ints_to_string(average_x, 0, 0, 15,step_string);
          counter = 0;
      }
}
void init_clocks()
{
	/* Initializes Clock System */
	MAP_CS_setDCOCenteredFrequency((0x00050000)); //DCO = 48 MHZ
	MAP_CS_initClockSignal((0x00000002), (0x00000003), (0x00000000)); // MCLK = DCO /1
	MAP_CS_initClockSignal((0x00000004), (0x00000003), (0x00000000)); // HSMCLK = DCO/1
	MAP_CS_initClockSignal((0x00000008), (0x00000003), (0x00000000)); // SMCLK = DCO /1
}
void write(int steps) {

    uint8_t write_data[4] = "pppp";
    sprintf(write_data, "%d", steps);
    uint8_t write_data2[4] = "pppp";
    sprintf(write_data2, "%d", goal_steps);
    MAP_FlashCtl_unprotectSector(FLASH_MAIN_MEMORY_SPACE_BANK1,FLASH_SECTOR31);

    /* Trying to erase the sector. Within this function, the API will
        automatically try to erase the maximum number of tries. If it fails,
         trap in an infinite loop */
    if(!MAP_FlashCtl_eraseSector(START))
        while(1);

    /* Trying to program the memory. Within this function, the API will 
        automatically try to program the maximum number of tries. If it fails,
        trap inside an infinite loop */
    if(!MAP_FlashCtl_programMemory(write_data,
            (void*) START, 4))
                while(1);
    if(!MAP_FlashCtl_programMemory(write_data2,
            (void*) START2, 4))
                while(1);

    /* Setting the sector back to protected  */
    MAP_FlashCtl_protectSector(FLASH_MAIN_MEMORY_SPACE_BANK1,FLASH_SECTOR31);


}
