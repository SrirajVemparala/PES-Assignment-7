# PES-Assignment-7

In this assignment, we implemented DAC and ADC.

Once the sine wave is generated we fill the buffer for desired frequency.

After initializing the DAC and DMA ,I use TPM0 for DAC and we use DMA to transfer this buffer to DAC.

Once DAC outputs, we configure ADC and we will use TPM1. I configure ADC such that output of DAC is input for ADC.

Instead of analog_in or analog_out I have used ADC.c/ADC.h and DAC.c/DAC.h
