/*
 * EXT_INT.c
 *
 * Created: 4/21/2021 11:40:32 PM
 *  Author: Ali
 */ 

#include "EXT_INT.h"



void  SET_Global_INT(void)
{
	#if     GLOBAL_INTERRUPT ==  GLOBAL_INTERRUPT_ENABLE
	
	    SET_BIT(SREG , 7);
	
	#elif   GLOBAL_INTERRUPT == GLOBAL_INTERRUPT_DISABLE
	 
	   CLR_BIT(SREG , 7);
	#endif
}

void  EXT_INT0_Init(void)
{
	/*enable global INT*/
	SET_Global_INT();
	
	/*enable EXT INT0*/
	SET_BIT(GICR , 6);
	
	
	/*Select Trigger*/
	#if     EXT_INT0_TRIGGER  ==  TRIGGER_RISING
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
	//MCUCR = 1<<ISC01;
	
	#elif   EXT_INT0_TRIGGER  ==  TRIGGER_FALLING
	CLR_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
	
	#elif   EXT_INT0_TRIGGER  ==  TRIGGER_ANY_LOGICAL_CHANGE
	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
	
	#elif   EXT_INT0_TRIGGER  ==  TRIGGER_LOW_LEVEL
	CLR_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
	
	#endif
	
}

/*Your Assignment*/
void  EXT_INT1_Init(void)
{
	
}

/*Your Assignment*/
void EXT_INT2_Init(void)
{
	
}