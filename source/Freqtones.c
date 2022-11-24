/*Author: Raghu Sai Phani Sriraj Vemparala
 *
 * Reference: Lecture given by Professor.Lalit Pandit
 *
 *
 * Description: Entry point to functions
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "DMAfunctions.h"
#include "autocorrelate.h"
#include "test_sine.h"
#include "systick.h"
#include "TPMfunctions.h"
#include "DAC_ADC.h"
#include "fsl_debug_console.h"

#define ADC_TIMER_FREQ 96000
#define samples_440 109
#define samples_587	82
#define samples_659 73
#define samples_880 55

#define count_440 981
#define count_587 984
#define count_659 1022
#define count_880 990

uint16_t buffer_440[1024];
uint16_t buffer_587[1024];
uint16_t buffer_659[1024];
uint16_t buffer_880[1024];

extern volatile ticktime_t count;
// Enable DAC, select VDDA as reference voltage DACO->CO DAC_CO_DACEN_MASK DAC_CO_DACRFS_MASK;

/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */
int main(void) {

	uint16_t* adc_buff_ptr;
	uint16_t adc_freq;
	//int size_flag = 0;
    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif
    init_systick();
    Init_DAC();
    ADC0_init();
    Init_DMA();
    TPM0_Init();
    TPM1_init();
    //test_sin();
    reset_timer();
    while(1)
    {
    	if(count == 100)
    	{
    		tone_to_sample(buffer_440,samples_440);
    		Start_DMA_transfer(buffer_440, count_440);
    		adc_buff_ptr = start_adc();//Move data and convert
     		printf("\r\n samples generated = %d at %d Hz, computed period = %d samples", count_440, 440, samples_440);
     		int period = autocorrelate_detect_period(&adc_buff_ptr[0], 1024, kAC_16bps_unsigned);
     		adc_freq = ADC_TIMER_FREQ/period;// Calculate ADC_signal Frequency
     		adc_param_calculation(adc_buff_ptr);
     		printf(", period = %d, samples frequency = %u", period, adc_freq);

    	}
    	else if((count == 200))
    	{
    	    tone_to_sample(buffer_587,samples_587);
    	    Start_DMA_transfer(buffer_587, count_587);
    	    adc_buff_ptr =  start_adc();
    	    printf("\r\n samples generated = %d at %d Hz, computed period = %d samples", count_587, 587, samples_587);
    	    int period = autocorrelate_detect_period(&adc_buff_ptr[0], 1024, kAC_16bps_unsigned);
    	    adc_freq = ADC_TIMER_FREQ/period;// Calculate ADC_signal Frequency
    	    adc_param_calculation(adc_buff_ptr);
    	    printf(", period = %d, samples frequency = %u", period, adc_freq);

    	}
    	else if(count  == 300)
    	{
    	    tone_to_sample(buffer_659,samples_659);
        	Start_DMA_transfer(buffer_659, count_659);
    	    adc_buff_ptr =  start_adc();
    	    printf("\r\n samples generated = %d at %d Hz, computed period = %d samples", count_659, 659, samples_659);
    	    int period = autocorrelate_detect_period(&adc_buff_ptr[0], 1024, kAC_16bps_unsigned);
    	    adc_freq = ADC_TIMER_FREQ/period;// Calculate ADC_signal Frequency
    	    adc_param_calculation(adc_buff_ptr);
    	    printf(", period = %d, samples frequency = %u", period, adc_freq);

    	}
    	else if(count == 400)
    	{
    	    tone_to_sample(buffer_880,samples_880);
        	Start_DMA_transfer(buffer_880, count_880);
    	    adc_buff_ptr =  start_adc();
        	printf("\r\n samples generated = %d at %d Hz, computed period = %d samples", count_880, 880, samples_880);
        	int period = autocorrelate_detect_period(&adc_buff_ptr[0], 1024, kAC_16bps_unsigned);
        	adc_freq = ADC_TIMER_FREQ/period;// Calculate ADC_signal Frequency
        	adc_param_calculation(adc_buff_ptr);
        	printf(", period = %d, samples frequency = %u", period, adc_freq);
        	reset_timer();
    	}

    }
    return 0 ;
}
