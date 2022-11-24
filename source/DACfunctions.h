/*
 *
 * Author: Vemparala Raghu Sai Phani Sriraj
 * File Name: DACfunctions.h
 * Use: This file contains all the function declarations required for DAC to function properly.
 * Compiler: GCC
 * References:1. DEAN text book Chapter:6
 *
 */
#include "MKL25Z4.h"
#include "fsl_debug_console.h"

#ifndef DACFUNCTIONS_H_
#define DACFUNCTIONS_H_


/* Function: Init_DAC()
 *
 * Description: Initializes DAC module
 *
 * Param: void
 *
 * return: void
 *
 */
void Init_DAC();
/* Function: tone_to_sample()
 *
 * Description: Generated the tone sample variables.
 *
 * Param: uint16_t* buffer,int samples
 *
 * return: void
 *
 */
void tone_to_sample();


#endif /* DACFUNCTIONS_H_ */
