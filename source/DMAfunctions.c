/*
 *
 * Author: Vemparala Raghu Sai Phani Sriraj
 * File Name: DMAfunctions.c
 * Use: This file contains all the function definitions required for DAC and ADC to function properly.
 * Compiler: GCC
 * References: https://github.com/alexander-g-dean/ESF/blob/master/NXP/Code/Chapter_9/DMA_Examples/Source/DMA.c
 *
 */

#include <stdint.h>
#include <MKL25Z4.h>
#include <stdio.h>
#include <string.h>

uint16_t *Reload_DMA_Source; //buffer to load dma
uint32_t Reload_DMA_Byte_Count=0; //buffer for dma count
uint32_t DMA_Playback_Count=0;

/* Function: Init_DMA()
 *
 * Description: Initialize the DMA.
 *
 * Param: N/A
 *
 * return: void
 *
 */
void Init_DMA()
{
	// Gate clocks to DMA and DMAMUX
	SIM->SCGC7 |= SIM_SCGC7_DMA_MASK;
	SIM->SCGC6 |= SIM_SCGC6_DMAMUX_MASK;

	// Disable DMA channel to allow configuration
	DMAMUX0->CHCFG[0] = 0;

	// Generate DMA interrupt when done
	// Increment source, transfer words (16 bits)
	// Enable peripheral request
	DMA0->DMA[0].DCR = DMA_DCR_EINT_MASK | DMA_DCR_SINC_MASK|
			DMA_DCR_SSIZE(2) | DMA_DCR_DSIZE(2) |
			DMA_DCR_ERQ_MASK | DMA_DCR_CS_MASK;

	// Configure NVIC for DMA ISR
	NVIC_SetPriority(DMA0_IRQn, 1);
	NVIC_ClearPendingIRQ(DMA0_IRQn);
	NVIC_EnableIRQ(DMA0_IRQn);

	// Enable DMA MUX channel with TPM0 overflow as trigger
	DMAMUX0->CHCFG[0] = DMAMUX_CHCFG_SOURCE(54);

}

/* Function: Start_DMA_transfer()
 *
 * Description: Initialize the DMA.
 *
 * Param: uint16_t* ,uint32_t
 *
 * return: void
 *
 */
void Start_DMA_transfer(uint16_t *source,uint32_t count)
{
	// initialize source and destination pointers
	Reload_DMA_Source = source;
	Reload_DMA_Byte_Count = count;
	//Source address of the buffer
	DMA0->DMA[0].SAR = DMA_SAR_SAR((uint32_t) source);
	//DAC destination address
	DMA0->DMA[0].DAR = DMA_DAR_DAR((uint32_t)&(DAC0->DAT[0]));
	// byte count
	DMA0->DMA[0].DSR_BCR = DMA_DSR_BCR_BCR(count*2);
	// clear done flag
	DMA0->DMA[0].DSR_BCR &= ~DMA_DSR_BCR_DONE_MASK;
	// set enable flag
	DMAMUX0->CHCFG[0] |= DMAMUX_CHCFG_ENBL_MASK;
}

/* Function: DMA0_IRQHandler()
 *
 * Description: Generates Interrupt when TPM0 timer is overflowed.
 *
 * Param: void
 *
 * return: void
 *
 */
void DMA0_IRQHandler(void)
{
	// start
	DMA0->DMA[0].DSR_BCR |= DMA_DSR_BCR_DONE_MASK;
	//start dma transfer
	Start_DMA_transfer(Reload_DMA_Source, Reload_DMA_Byte_Count);
}

