/*
 * ADC.h
 *
 * Created: 10/17/2020 3:37:48 AM
 *  Author: Dell
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "LCD.h"

void ADC_Init();
unsigned short ADC_Read(uint8 channel); //which channel will receive the analogue value



#endif /* ADC_H_ */