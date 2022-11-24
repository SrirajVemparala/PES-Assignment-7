/*
 *
 * Author: Vemparala Raghu Sai Phani Sriraj
 * File Name: DAC_ADC.c
 * Use: This file contains all the function definitions required for DAC and ADC to function properly.
 * Compiler: GCC
 * References:1. DEAN text book Chapter:6
 *
 */

#include "DAC_ADC.h"
#include "fp_trig.h"

#define DAC_POS	(30)
#define BUFFER_SIZE 1024
#define ADC_SIZE	(65535)
#define ADC_POS 	23

uint16_t adc_buffer[BUFFER_SIZE];

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
	int total_rounds =  (1024/samples);// This provides the count of number of times the sample should be repeating.
	int total_samples = total_rounds*samples;// Provides total number of samples.
		for(int j =0;j<total_samples;j++)
		{
			buffer[j] = fp_sin(TWO_PI*j/samples)+TRIG_SCALE_FACTOR;
		}
}

/* Function: ADC0_init()
 *
 * Description: Initializes the ADC0 module for converting the data coming from DAC
 *
 * Param: void
 *
 * return: void
 *
 */

void ADC0_init()
{
	//Enable clock for ADC
	SIM->SCGC6 |= SIM_SCGC6_ADC0_MASK;
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
	//select pin as ADC pin.
	PORTE->PCR[ADC_POS] &= ~PORT_PCR_MUX_MASK;
	PORTE->PCR[ADC_POS] |= PORT_PCR_MUX(0);
	//Setting it to Normal power mode
	ADC0->CFG1 &= ~ADC_CFG1_ADLPC_MASK;
	//inputclock/2, single ended 16 bit conversion, ADCLK as Busclock/2.
	ADC0->CFG1 |= ADC_CFG1_ADIV(1) | ADC_CFG1_MODE(3) |
			ADC_CFG1_ADICLK(1);
	//select default reference voltage,Hardware trigger selected
	ADC0->SC2 = ADC_SC2_REFSEL(0) | ADC_SC2_ADTRG_MASK;
	SIM->SOPT7 &= ~SIM_SOPT7_ADC0PRETRGSEL_MASK;
	//configure for hardware trigger with TPM1
	SIM->SOPT7 |= SIM_SOPT7_ADC0ALTTRGEN_MASK | SIM_SOPT7_ADC0TRGSEL(9);
}

/* Function: start_adc()
 *
 * Description: Start transferring
 *
 * Param: void
 *
 * return: uint16_t*
 *
 */
uint16_t* start_adc()
{
	int i;
	TPM1->SC |= TPM_SC_CMOD(1);
	for(i =0;i<BUFFER_SIZE;i++)
	{
		//Select ADC channel
	ADC0->SC1[0] = ADC_SC1_ADCH(23);
	//Check if the data conversion is complete
	while(!(ADC0->SC1[0] & ADC_SC1_COCO_MASK));
	//Store data into buffer
	adc_buffer[i] = ADC0->R[0];
	}
	//Stop TPM
	TPM1->SC &= ~TPM_SC_CMOD_MASK;
	return &(adc_buffer[0]);
}

/* Function: adc_param_calculation()
 *
 * Description: Calculate the parameters
 *
 * Param: void
 *
 * return: uint16_t*
 *
 */
void adc_param_calculation(uint16_t *buff)
{
	uint16_t min_value_index=0;
	uint16_t max_value_index=0;
	uint16_t avg_val=0;
	uint32_t total_count=0;
	for (uint16_t i=0; i<BUFFER_SIZE; i++)
	{
		//Finding out the least value of the sample
			if(buff[i]<buff[min_value_index])
			{
				min_value_index = i;
			}
		//Finding out the maximum value of the sample
			if(buff[i]>buff[max_value_index])
			{
				max_value_index = i;
			}
			total_count += buff[i];
	}
		avg_val = total_count/BUFFER_SIZE;
		printf("\r\nMIN = %u, MAX = %u, AVG = %u", buff[min_value_index], buff[max_value_index], avg_val);
}
