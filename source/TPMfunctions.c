/*
 *
 * Author: Vemparala Raghu Sai Phani Sriraj
 * File Name: TPMfunctions.c
 * Use: This file contains all the function definitions required for TPM0 and TPM1 to function properly.
 * Compiler: GCC
 * References:1. https://github.com/alexander-g-dean/ESF/blob/master/NXP/Code/Chapter_9/DMA_Examples/Source/timers.c
 *
 */

#include<stdint.h>
#include<MKL25Z4.h>
#define Sys_Clock 48000000
#define Period 48000
#define ADC_SAMPLING_FREQ 96000

/* Function: TPM0_Init()
 *
 * Description: Initialize TPM0
 *
 * Param: void
 *
 * return: void
 *
 */
void TPM0_Init()
{
	//turn on clock to TPM
	SIM->SCGC6 |= SIM_SCGC6_TPM0_MASK;
	//set clock source for tpm
	SIM->SOPT2 |= (SIM_SOPT2_TPMSRC(1) | SIM_SOPT2_PLLFLLSEL_MASK);
	// disable tpm
	TPM0->SC = 0;
	// Load the mod and counter
	TPM0->MOD = TPM_MOD_MOD((Sys_Clock/Period)-1); // set sampling frequency
	TPM0->CNT = 0;
	// No prescaler, no PWM, include CMOD, include DMA
	TPM0->SC = TPM_SC_PS(0) | TPM_SC_CPWMS(0) | TPM_SC_CMOD(1) | TPM_SC_DMA_MASK;

}

/* Function: TPM1_init()
 *
 * Description: Initialize TPM1
 *
 * Param: void
 *
 * return: void
 *
 */
void TPM1_init()
{
	//Providing clocks to ports and TMP0
	SIM->SCGC6 |= SIM_SCGC6_TPM1_MASK;
	//enable clock
	SIM->SOPT2 |= (SIM_SOPT2_TPMSRC(1) | SIM_SOPT2_PLLFLLSEL_MASK);
	//set MOD and prescalar according to 96KHz sampling frequency
	TPM1->SC = 0;
	TPM1->MOD = TPM_MOD_MOD((Sys_Clock / ADC_SAMPLING_FREQ)-1);
	TPM1->SC |= TPM_SC_PS(0);
	//set debug mode
	TPM1->CONF |= TPM_CONF_DBGMODE(3);
}
