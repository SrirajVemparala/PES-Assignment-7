/*
 *
 * Author: Vemparala Raghu Sai Phani Sriraj
 * File Name: DMAfunctions.h
 * Use: This file contains all the function declarations required for DAC and ADC to function properly.
 * Compiler: GCC
 * References: https://github.com/alexander-g-dean/ESF/blob/master/NXP/Code/Chapter_9/DMA_Examples/Source/DMA.c
 *
 */

#ifndef DMAFUNCTIONS_H_
#define DMAFUNCTIONS_H_

/* Function: Init_DMA()
 *
 * Description: Initialize the DMA.
 *
 * Param: N/A
 *
 * return: void
 *
 */
void Init_DMA();

/* Function: Start_DMA_transfer()
 *
 * Description: Initialize the DMA.
 *
 * Param: uint16_t* ,uint32_t
 *
 * return: void
 *
 */
void Start_DMA_transfer();

#endif /* DMAFUNCTIONS_H_ */
