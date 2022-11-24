/*
 *
 * Author: Vemparala Raghu Sai Phani Sriraj
 * File Name: systick.h
 * Use: This file contains all the function declarations required for Systick to function properly.
 * Compiler: GCC
 * References:1. DEAN text book Chapter:7
 *
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_
/* Function Name: init_systick
 * Use: Systick initialization
 * Return Type: void
 */
void init_systick();
/* Function Name: reset_time
 * Use:Resets time to zero
 * Return Type: void
 */
void reset_timer();

typedef uint32_t ticktime_t;
/* Function Name: get_timer
 * Use:returns count
 * Return Type: ticktime_t
 */
ticktime_t get_timer();
/* Function Name: now
 * Use: Provides time since start of program
 * Return Type: ticktime_t
 */
ticktime_t now();


#endif /* SYSTICK_H_ */
