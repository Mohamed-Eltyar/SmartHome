#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LCD_4BIT/LCD_4BIT_Interface.h"
#include "../HAL/KeyPad/KeyPad_Interface.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/ADC/ADC_Register.h"
#include "../MCAL/Timer_Counter/Timer_Count2_Interface.h"
#include "../MCAL/Timer_Counter/Timer_Count1_Interface.h"
extern volatile u8 flag_ADC_CHANNEL;	   // channel adc
u8 Display_Cursor[8]={0x10,0x18,0x1E,0x1F,0x1F,0x1E,0x18,0x10};
extern u8 Flag_ReturnHome;
extern u8 System;
u8 Flag_UART =0;
void Display(void)
{
	u8 GetValue=0;				//return keypad
	u8 GetUARTValue=0;			// Return UART
	u16 GetADC_Value=0;			//get ADC value
	LCD_Vid4Initialization();	//Initialization of LCD
	//*****************************************************
	// Temp =1		LDR=2		LOCk Door=3  Back=4
	while (1)
	{
		while (1)
		{
			if(GetValue==0 || GetUARTValue==0)
			{
			SET_BIT(ADCSRA,7);
			if (System==2)
			{
			Flag_UART=1;
			}
		LCD_Write4String("1-Temp",0,1);
		LCD_Write4String("2-Light",1,1);
		LCD_Write4String("3-Door",0,9);
		LCD_Write4String("4-Back",1,10);
		GetValue=GetPressedKey(PRTC);
		GetUARTValue=UART_u8ReadData();
		_delay_ms(100);
			}
		if (GetValue==1 || GetUARTValue==1)
		{
			flag_ADC_CHANNEL=1;
			if (System==2)
			{
				Flag_UART=1;
			}

			ADC_VidSingleEnded(flag_ADC_CHANNEL);
			LCD_VidWrite4Cmd(Clear_Display);

			while (1)
			{
				Flag_UART=1;
				GetValue=GetPressedKey(PRTC);
				GetUARTValue=UART_u8ReadData();
				GetADC_Value=ADC_u16GetCrruntValu();
				GetADC_Value=(GetADC_Value*5000UL)/102400;	//percentage

				LCD_Write4String("Temp=",0,0);
				LCD_GoToPosition(0,7);
				LCD_VidDisp4Number(GetADC_Value);
				LCD_Write4String("C",0,10);
				//_delay_ms(100);
			if (GetADC_Value>350)
			{
				LCD_Write4String("Fan ON",1,4);
			}

			else if (GetADC_Value<=250)
			{
				LCD_Write4String("Fan OFF",1,4);
			}
			if (GetValue==4 || GetUARTValue==4)
			{
				GetValue=0;
				GetUARTValue=0;
				Tim_Count2_VidCompareReg(0);
				CLR_BIT(ADCSRA,7);
				LCD_VidWrite4Cmd(Clear_Display);
				Flag_UART=0;
				break;
			}
			}
		}

		if (GetValue==7 || GetUARTValue==7)
		{
			flag_ADC_CHANNEL=0;
			if (System==2)
			{
				Flag_UART=1;
			}

			ADC_VidSingleEnded(flag_ADC_CHANNEL);
			LCD_VidWrite4Cmd(Clear_Display);

			while(1)
			{
				Flag_UART=1;
				GetValue=GetPressedKey(PRTC);
				GetUARTValue=UART_u8ReadData();
				GetADC_Value=ADC_u16GetCrruntValu();
				//GetADC_Value=(10000*5000UL)
				//GetADC_Value=(GetADC_Value/5000)*100;	percentage
				LCD_Write4String("Light=",0,0);
				LCD_GoToPosition(0,8);
				LCD_VidDisp4Number(GetADC_Value);
				LCD_Write4String("%",0,11);
				_delay_ms(100);
				if (GetADC_Value>75)
				{
					LCD_Write4String("NO Light",1,3);
				}
				else if (GetADC_Value<75 && GetADC_Value>50)
				{
					LCD_Write4String(" Some light",1,0);
				}
				else if (GetADC_Value<50 && GetADC_Value>25)
				{
					LCD_Write4String(" Light",1,3);
				}
				else if (GetADC_Value<25 && GetADC_Value>0)
				{
					LCD_Write4String(" Full Light",1,0);
				}
				if (GetValue==4 || GetUARTValue==4)
				{
					GetValue=0;
					GetUARTValue=0;
					CLR_BIT(ADCSRA,7);
					DIO_VidSetPortValue(PRTA,0x00);
					LCD_VidWrite4Cmd(Clear_Display);
					Flag_UART=0;
					break;
				}
			}
		}

		if (GetValue==3 || GetUARTValue==3)
		{
			while (1)
			{

				LCD_Write4String("Door Lock:",0,0);
				_delay_ms(250);
				GetValue=GetPressedKey(PRTC);
				GetUARTValue=UART_u8ReadData();
				if (GetValue==5 || GetUARTValue==5)	//Open door
				{
					LCD_VidWrite4Cmd(Clear_Display);
					LCD_Write4String("Door Lock:",0,0);
					LCD_Write4String(" ON",0,11);
					Tim1_VidOCRA(62);
					_delay_ms(500);

				}
				else if (GetValue==6 || GetUARTValue==6)	//closed door
				{
					LCD_VidWrite4Cmd(Clear_Display);
					LCD_Write4String("Door Lock:",0,0);
					LCD_Write4String(" OFF",0,11);
					Tim1_VidOCRA(31);
					_delay_ms(500);

				}
				if (GetValue==4 || GetUARTValue==4)
				{
					GetValue=0;
					GetUARTValue=0;
					LCD_VidWrite4Cmd(Clear_Display);

					break;
				}
			}
		}
		if (GetValue==4 || GetUARTValue==4)
		{
			GetValue=0;
			GetUARTValue=0;
			Flag_ReturnHome=1;
			break;
		}
	}
	if (Flag_ReturnHome==1)
	{
		break;
	}
	}
}

void Position_Cursor(u8 LOC_u8ROW,u8 LOC_u8COL)
{
	LCD_StoreCustomChr(Display_Cursor,0);
	LCD_GoToPosition(LOC_u8ROW,LOC_u8COL);
	LCD_VidWrite4Data(0);
}
