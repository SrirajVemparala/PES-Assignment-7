# PES-Assignment-7: RAGHU SAI PHANI SRIRAJ VEMPARALA

## Introduction
The purpose of this assignment is to mathematically generate four tones in the form of analog signals. We will play the tones out using the DAC, and then link the DAC and ADC together and obtain the DAC output from ADC. The following are the musical notes: 440 Hz (an A4); 587 Hz (a D5); 659 Hz (an E5); and 880 Hz (an A5). Each note should be played for one second. When playback reaches the end of this list, it should restart at the beginning. 

We will use the following parameters:
                                           
 Sampling rate: Output (DAC)-  48 kHz	                Input (ADC)-96 kHz         
 Resolution:    Output (DAC)- 12 bits per sample	    Input (ADC)-16 bits per sample
 
The main() function is present in the file frequencytonesmain(). The ADCfunctions.c has the functions related to ADC init and frequency generation and DACfunctions.c has the DAC init and conversion functions.

## oscilloscope output

In Digital to analog conversion the output from the DAC is verified by connecting the oscilloscope to pin PTE30. The following are the results obtained.


Frequency_440Hz:

![440_Hz](https://user-images.githubusercontent.com/91862302/203698152-f62954ea-ada3-4358-a60f-d826114c6199.png)

Frequency_585Hz:

![585_Hz](https://user-images.githubusercontent.com/91862302/203698184-476909be-5398-4cb7-9449-f610c5d6bf68.png)

Frequency_657Hz:

![657_Hz](https://user-images.githubusercontent.com/91862302/203698233-a1c97c79-2b7e-45d3-ba7e-8c8951e9a2f2.png)

Frequency_880Hz:

![880_Hz](https://user-images.githubusercontent.com/91862302/203698281-229a5c5f-380e-47e9-b463-9493430cab4b.png)

