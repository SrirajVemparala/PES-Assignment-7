/*
 *
 * Author: Vemparala Raghu Sai Phani Sriraj
 * File Name: ADCfunctions.h
 * Use: This file contains all the function declarations required for ADC to function properly.
 * Compiler: GCC
 * References:1. DEAN text book Chapter:6
 *
 */
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#ifndef ADCFUNCTIONS_H_
#define ADCFUNCTIONS_H_

/* Function: ADC0_init()
 *
 * Description: Initializes the ADC0 module for converting the data coming from DAC
 *
 * Param: void
 *
 * return: void
 *
 */

void ADC0_init();

/* Function: start_adc()
 *
 * Description: Start transferring
 *
 * Param: void
 *
 * return: uint16_t*
 *
 */
uint16_t* start_adc();

/* Function: adc_param_calculation()
 *
 * Description: Calculate the parameters
 *
 * Param: void
 *
 * return: uint16_t*
 *
 */
void adc_param_calculation(uint16_t*);

#endif /* ADCFUNCTIONS_H_ */
