# PES-Assignment-7

In this assignment, we implemented DAC and ADC.

Once the sine wave is generated we fill the buffer for desired frequency.

After initializing the DAC and DMA ,I use TPM0 for DAC and we use DMA to transfer this buffer to DAC.

Once DAC outputs, we configure ADC and we will use TPM1. I configure ADC such that output of DAC is input for ADC.

Instead of analog_in or analog_out I have used ADC.c/ADC.h and DAC.c/DAC.h



Frequency_440Hz:

![440_Hz](https://user-images.githubusercontent.com/91862302/203698152-f62954ea-ada3-4358-a60f-d826114c6199.png)

Frequency_585Hz:

![585_Hz](https://user-images.githubusercontent.com/91862302/203698184-476909be-5398-4cb7-9449-f610c5d6bf68.png)

Frequency_657Hz:

![657_Hz](https://user-images.githubusercontent.com/91862302/203698233-a1c97c79-2b7e-45d3-ba7e-8c8951e9a2f2.png)

Frequency_880Hz:

![880_Hz](https://user-images.githubusercontent.com/91862302/203698281-229a5c5f-380e-47e9-b463-9493430cab4b.png)

