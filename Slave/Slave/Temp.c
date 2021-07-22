/*
 * Temp.c
 *
 * Created: 4/27/2021 12:48:17 AM
 *  Author: Ali
 */ 

#include "Temp.h"

void TempSensor_Init(void)
{
	ADC_Init();
}

uint16 TempSensor_Read(void)
{
	uint16 digital_value  = 0;
	uint32 analog_value  = 0;
	
	//digital_value = ADC_Read();
	
	analog_value = ((digital_value * 500) /1024 );
	
	return (analog_value);
}