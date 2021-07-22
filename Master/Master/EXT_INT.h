/*
 * EXT_INT.h
 *
 * Created: 4/21/2021 11:40:45 PM
 *  Author: Ali
 */ 


#ifndef EXT_INT_H_
#define EXT_INT_H_

#include "EXT_INT_CFG.h"
#include "MCU.h"
#include "BIT_Math.h"
#include "STD.h"


#define   GLOBAL_INTERRUPT_ENABLE      0
#define   GLOBAL_INTERRUPT_DISABLE     1

#define   TRIGGER_RISING               0
#define   TRIGGER_FALLING              1
#define   TRIGGER_ANY_LOGICAL_CHANGE   2
#define   TRIGGER_LOW_LEVEL            3
	


void  SET_Global_INT(void);

void  EXT_INT0_Init(void);




#endif /* EXT_INT_H_ */