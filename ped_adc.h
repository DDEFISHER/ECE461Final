/*
 * ped_adc.h
 *
 *  Created on: Apr 4, 2016
 *      Author: daniel
 */

#ifndef PED_ADC_H_
#define PED_ADC_H_

void init_adc();
void init_clocks();
void show_adc14_info();
void ADC14_IRQHandler();
void step_track_and_alert(int, int, int);

#endif /* PED_ADC_H_ */
