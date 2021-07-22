/*
 * ADC.c
 *
 * Created: 10/17/2020 3:38:02 AM
 *  Author: Dell
 */ 
#include "ADC.h"
#include <avr/io.h>

void ADC_Init(){
	ADMUX |= (1<<REFS0)|(1<<REFS1);						   // Internal V ref
	ADCSRA |= (1<<ADEN)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2); // enable and 128 timer prescale
														  //PortA1 should be input 
}

unsigned short ADC_Read(uint8 channel){
	unsigned short data = 0;
	ADMUX = (ADMUX & 0xE0) | (channel & 0x1F);		// put zeros for the last 5 bits of the ADMUX and Or it with the last 5 bits of the channel
	ADCSRA |=(1<<ADSC);								// start conversion
	while(!(ADCSRA & (1<<ADIF)));					//stay until the interrupt produces 1 (conversion complete)
	ADCSRA |=(1<<ADIF);								// give the flag one again to clear it
	
	data = ADCL;								   //get the coming data 
	data |= ADCH<<8 ;
	
	return data;
}
