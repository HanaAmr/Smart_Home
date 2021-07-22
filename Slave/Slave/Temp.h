/*
 * Temp.h
 *
 * Created: 4/27/2021 12:48:29 AM
 *  Author: Ali
 */ 


#ifndef TEMP_H_
#define TEMP_H_

#include "ADC.h"

void TempSensor_Init(void);

uint16 TempSensor_Read(void);



#endif /* TEMP_H_ */