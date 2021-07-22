/*
 * Slave.c
 *
 * Created: 7/21/2021 3:46:55 AM
 * Author : PC
 */ 

#include "ADC.h"
#include "LCD.h"
#include "LED.h"
#include "SPI.h"
#define F_CPU  16000000
#include <util/delay.h>
#include "EXT_INT.h"
#include "avr/interrupt.h"


int main(void)
{
	// Make necessary initializations
	LED0_INIT();
	LED1_INIT();
	LCD_Init();
	ADC_Init();
	EXT_INT0_Init();
	
	SPI_Slave_Init();	
	_delay_ms(1000);

	uint8 tx_data = 1;
	uint8 rx_data = 0;
	uint16 temp = 0;
	
	
	while (1)
	{
		// Receive data from Master
		rx_data = SPI_TranSiver(tx_data);
		
		if(rx_data)  // Check type of instruction received
		{
			LCD_Clear();
			if(rx_data == '1')
			{
				LED0_ON();
			} else if(rx_data == '2')
			{
				LED0_OFF();
			} else if(rx_data == '3')
			{
				LED1_ON();
			} else if(rx_data == '4')
			{
				LED1_OFF();
			} else if(rx_data == '5')
			{
				temp = ADC_Read(1);
				temp = temp/4;
				LCD_WriteInteger(temp);	
			}
			
			rx_data = 0;
		}
		
	}
}


ISR(INT0_vect)
{
	LCD_Clear();
	LCD_WriteString((uint8*)"Resetting All");
	LED0_OFF();
	LED1_OFF();
}



