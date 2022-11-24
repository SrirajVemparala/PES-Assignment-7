/*
 *
 * Author: Vemparala Raghu Sai Phani Sriraj
 * File Name: systick.c
 * Use: This file contains all the function definitions required for Systick to function properly.
 * Compiler: GCC
 * References:1. DEAN text book Chapter:7
 *
 */

#include "MKL25Z4.h"
#include "systick.h"
static volatile ticktime_t timerafterstart=0;
volatile ticktime_t count=0;
int delay_time;
int i;
int flag = 0;
/* Function Name: init_systick
 * Use: Systick initialization
 * Return Type: void
 */
void init_systick()
{
	SysTick->LOAD=479999;
	NVIC_SetPriority(SysTick_IRQn,3);
	SysTick->VAL=0;
	SysTick->CTRL=SysTick_CTRL_TICKINT_Msk|SysTick_CTRL_ENABLE_Msk|SysTick_CTRL_CLKSOURCE_Msk;
}
/* Function Name: now
 * Use: Provides time since start of program
 * Return Type: ticktime_t
 */
ticktime_t now()
{
return timerafterstart;
}
/* Function Name: reset_time
 * Use:Resets time to zero
 * Return Type: void
 */
void reset_timer()
{
count=0;
}
/* Function Name: get_timer
 * Use:returns count
 * Return Type: ticktime_t
 */
ticktime_t get_timer()
{
return count;
}
/* Function Name: SysTick_Handler
 * Use:Increments count and timerafterstart
 * Return Type: void
 */
void SysTick_Handler()
{
count++;
timerafterstart++;
flag = 1;
}
