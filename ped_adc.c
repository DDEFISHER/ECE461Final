/*
 * ped_adc.c - used to init the adc and timers that the entire project uses
 *
 *  Created on: Apr 4, 2016
 *      Author: daniel
 */

/* TI-RTOS Header files */
#include "driverlib.h"
#include "msp.h"

//init adc
void init_adc()
{
    /* Configures Pin 4.0, 4.2, and 6.1 as ADC input */
    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P4, GPIO_PIN0 | GPIO_PIN2, GPIO_TERTIARY_MODULE_FUNCTION);
    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P6, GPIO_PIN1, GPIO_TERTIARY_MODULE_FUNCTION);

    /* Initializing ADC (ADCOSC/64/8) */
    MAP_ADC14_enableModule();
    MAP_ADC14_initModule(((uint32_t)0x00200000), ((uint32_t)0xC0000000) , ((uint32_t)0x01C00000),
            0);

    /* Configuring ADC Memory (ADC_MEM0 - ADC_MEM2 (A11, A13, A14)  with no repeat)
         * with internal 2.5v reference */
    MAP_ADC14_configureMultiSequenceMode(ADC_MEM0, ADC_MEM2, true);
    MAP_ADC14_configureConversionMemory(ADC_MEM0,
    		((uint32_t)0x00000000),
			((uint32_t)0x0000000E), ADC_NONDIFFERENTIAL_INPUTS);

    MAP_ADC14_configureConversionMemory(ADC_MEM1,
    		((uint32_t)0x00000000),
			((uint32_t)0x0000000D), ADC_NONDIFFERENTIAL_INPUTS);

    MAP_ADC14_configureConversionMemory(ADC_MEM2,
    		((uint32_t)0x00000000),
			((uint32_t)0x0000000B), ADC_NONDIFFERENTIAL_INPUTS);

    /* Enabling the interrupt when a conversion on channel 2 (end of sequence)
     *  is complete and enabling conversions */
    MAP_ADC14_enableInterrupt(((uint32_t)0x00000004) );

    /* Enabling Interrupts */
    MAP_Interrupt_enableInterrupt(INT_ADC14);
    MAP_Interrupt_enableMaster();

    /* Setting up the sample timer to automatically step through the sequence
     * convert.
     */
    MAP_ADC14_enableSampleTimer(((uint32_t)0x00000080));

    /* Triggering the start of the sample */
    MAP_ADC14_enableConversion();
    MAP_ADC14_toggleConversionTrigger();
}
//init clocks
void init_clocks()
{
	/* Initializes Clock System */
	MAP_CS_setDCOCenteredFrequency((0x00050000)); //DCO = 48 MHZ
	MAP_CS_initClockSignal((0x00000002), (0x00000003), (0x00000000)); // MCLK = DCO /1
	MAP_CS_initClockSignal((0x00000004), (0x00000003), (0x00000000)); // HSMCLK = DCO/1
	MAP_CS_initClockSignal((0x00000008), (0x00000003), (0x00000000)); // SMCLK = DCO /1
}


