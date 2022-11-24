/*
 *
 * Author: Vemparala Raghu Sai Phani Sriraj
 * File Name: DACfunctions.c
 * Use: This file contains all the function definitions required for DAC to function properly.
 * Compiler: GCC
 * References:1. DEAN text book Chapter:6
 *
 */

#include <DACfunctions.h>
#include "fp_trig.h"

#define DAC_POS	(30)
#define BUFFER_SIZE 1024


/* Function: Init_DAC()
 *
 * Description: Initializes DAC module
 *
 * Param: void
 *
 * return: void
 *
 */

void Init_DAC (void)
{

// Enable clock to DAC and Port E

SIM->SCGC6 |= SIM_SCGC6_DAC0_MASK;

SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;

// Select analog for pin

PORTE->PCR [DAC_POS] &=PORT_PCR_MUX_MASK;
PORTE->PCR [DAC_POS] = PORT_PCR_MUX(0);

// Disable buffer mode

DAC0->C1 = 0;

DAC0->C2 = 0;

DAC0->C0 = DAC_C0_DACEN_MASK | DAC_C0_DACRFS_MASK;// Enable DAC, DACREF_2 is set.
}

/* Function: tone_to_sample()
 *
 * Description: Generated the tone sample variables.
 *
 * Param: uint16_t* buffer,int samples
 *
 * return: void
 *
 */
void tone_to_sample(uint16_t* buffer,int samples)
{
	int total_rounds =  (BUFFER_SIZE/samples);// This provides the count of number of times the sample should be repeating.
	int total_samples = total_rounds*samples;// Provides total number of samples.
		for(int j =0;j<total_samples;j++)
		{
			buffer[j] = fp_sin(TWO_PI*j/samples)+TRIG_SCALE_FACTOR;
		}
}

