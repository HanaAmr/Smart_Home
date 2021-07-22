/*
 * LED.c
 *
 * Created: 4/12/2021 8:36:18 PM
 *  Author: Ahmed
 */ 

#include "LED.h"

void LED0_INIT(void) // LED 0
{
	DIO_SetPinDir(DIO_PORTC , DIO_PIN2 , DIO_PIN_OUTPUT);
}
void LED0_ON(void)
{
	DIO_SetPinValue(DIO_PORTC , DIO_PIN2 , DIO_PIN_HIGH);
}
void LED0_OFF(void)
{
	DIO_SetPinValue(DIO_PORTC , DIO_PIN2 , DIO_PIN_LOW);
}
void LED0_TOGGLE(void)
{
	DIO_TogglePin(DIO_PORTC , DIO_PIN2);
}
//**********************************************************************
void LED1_INIT(void) //LED 1
{
	DIO_SetPinDir(DIO_PORTC , DIO_PIN7 , DIO_PIN_OUTPUT);
}
void LED1_ON(void)
{
	DIO_SetPinValue(DIO_PORTC , DIO_PIN7 , DIO_PIN_HIGH);
}
void LED1_OFF(void)
{
	DIO_SetPinValue(DIO_PORTC , DIO_PIN7 , DIO_PIN_LOW);
}
void LED1_TOGGLE(void)
{
	DIO_TogglePin(DIO_PORTC , DIO_PIN7);
}
//**********************************************************************
void LED2_INIT(void) // LED 2
{
	DIO_SetPinDir(DIO_PORTD , DIO_PIN3 , DIO_PIN_OUTPUT);
}
void LED2_ON(void)
{
	DIO_SetPinValue(DIO_PORTD , DIO_PIN3 , DIO_PIN_HIGH);
}
void LED2_OFF(void)
{
	DIO_SetPinValue(DIO_PORTD , DIO_PIN3 , DIO_PIN_LOW);
}
void LED2_TOGGLE(void)
{
	DIO_TogglePin(DIO_PORTD , DIO_PIN3);
}