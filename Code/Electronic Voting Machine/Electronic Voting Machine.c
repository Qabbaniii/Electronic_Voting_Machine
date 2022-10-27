/*
 * Electronic_Voting_Machine.c
 *
 * Created: 27/10/2022 12:55:07 ص
 *  Author: Qabbani
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>

#include "LCD/LCD_interface.h"
#include "BUTTON/BUTTON_interface.h"
u8 counter1 = 0;
u8 counter2 = 0;
u8 counter3 = 0;
u8 counter4 = 0;
 
int main(void)
{
	
	LCD_vInit();
	BUTTON_vInit(DIO_u8_PORTA,DIO_u8_PIN0);
	BUTTON_vInit(DIO_u8_PORTA,DIO_u8_PIN1);
	BUTTON_vInit(DIO_u8_PORTA,DIO_u8_PIN2);
	BUTTON_vInit(DIO_u8_PORTA,DIO_u8_PIN3);
	BUTTON_vInit(DIO_u8_PORTA,DIO_u8_PIN4);

	LCD_vSendString("A=0");
	LCD_vMoveCursor(1,12);
	LCD_vSendString("B=0");
	LCD_vMoveCursor(2,1);
	LCD_vSendString("C=0");
	LCD_vMoveCursor(2,12);
	LCD_vSendString("D=0");
    while(1)
    {
		
		if(BUTTON_u8Read(DIO_u8_PORTA,DIO_u8_PIN0)==1)
		{
			counter1++;
			if(counter1<10)
			{
			LCD_vMoveCursor(1,3);
			LCD_vSendChar(counter1+48);
			}else if(counter1<100)
			{
				LCD_vMoveCursor(1,3);
				LCD_vSendChar(counter1/10+48);
				LCD_vSendChar(counter1%10+48);
			}
		}
		else if(BUTTON_u8Read(DIO_u8_PORTA,DIO_u8_PIN1)==1)
		{
			counter2++;
			 if(counter2<10)
			 {
			LCD_vMoveCursor(1,14);
			LCD_vSendChar(counter2+48);
			}else if(counter2<100)
			{
				LCD_vMoveCursor(1,14);
				LCD_vSendChar(counter2/10+48);
				LCD_vSendChar(counter2%10+48);
			}				
		}
		else if(BUTTON_u8Read(DIO_u8_PORTA,DIO_u8_PIN2)==1)
		{
			counter3++;
			if(counter3<10)
			{
			LCD_vMoveCursor(2,3);
			LCD_vSendChar(counter3+48);
		}else if(counter3<100)
		{
			LCD_vMoveCursor(2,3);
			LCD_vSendChar(counter3/10+48);
			LCD_vSendChar(counter3%10+48);
		}
		}
		else if(BUTTON_u8Read(DIO_u8_PORTA,DIO_u8_PIN3)==1)
		{
			counter4++;
			if(counter4<10)
			{
			LCD_vMoveCursor(2,14);
			LCD_vSendChar(counter4+48);
		}else if(counter4<100)
		{
			LCD_vMoveCursor(2,14);
			LCD_vSendChar(counter4/10+48);
			LCD_vSendChar(counter4%10+48);
		}
		}
		else if(BUTTON_u8Read(DIO_u8_PORTA,DIO_u8_PIN4)==1)
		{
			counter1=counter2=counter3=counter4=0;
			LCD_vMoveCursor(1,1);
			LCD_vSendString("A=0");
			LCD_vMoveCursor(1,12);
			LCD_vSendString("B=0");
			LCD_vMoveCursor(2,1);
			LCD_vSendString("C=0");
			LCD_vMoveCursor(2,12);
			LCD_vSendString("D=0");
			LCD_vMoveCursor(1,1);
		}
		_delay_ms(200);
         
    }
}