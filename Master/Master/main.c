/*
 * Master.c
 *
 * Created: 7/21/2021 2:16:53 AM
 * Author : PC
 */ 

#include "UART.h"
#include "LCD.h"
#include "SPI.h"
#define F_CPU  16000000
#include <util/delay.h>


int main(void)
{
	/// Make necessary initializations
	 UART_Init();
	 LCD_Init();
	
	 SPI_Master_Init();
	 SPI_Master_InitTrans();
	 _delay_ms(1000);
	 
	 uint8 bluetoothData = 0;
	 uint8 rx_data = 0;
	 
	
    while (1) 
    {
		// Receive data from bluetooth device using UART
		bluetoothData = UART_Rx();
		
		if(bluetoothData)
		{
			// Send data to slave using SPI
			rx_data = SPI_TranSiver(bluetoothData);
			LCD_Clear();
			
			if(bluetoothData == '1')  // Check type of instruction to send to slave
			{
				LCD_WriteString((uint8*)"LED 1 ON");
			} else if(bluetoothData == '2')
			{
				LCD_WriteString((uint8*)"LED 1 OFF");
			}else if(bluetoothData == '3')
			{
				LCD_WriteString((uint8*)"LED 2 ON");
			}else if(bluetoothData == '4')
			{
				LCD_WriteString((uint8*)"LED 2 OFF");
			}else if(bluetoothData == '5')
			{
				LCD_WriteString((uint8*)"Checking Temp");
			}
			
			bluetoothData = 0;
		}
		
		
    }
}
