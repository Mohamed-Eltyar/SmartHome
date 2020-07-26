#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LCD_4BIT/LCD_4BIT_Interface.h"
#include "../HAL/KeyPad/KeyPad_Interface.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/Timer_Counter/Timer_Count1_Interface.h"
extern volatile u8 flag_ADC_CHANNEL;	   // channel adc
u8 Display_Cursor[8]={0x10,0x18,0x1E,0x1F,0x1F,0x1E,0x18,0x10};

void Display(void)
{
	u8 GetValue=0;				//return keypad
	u16 GetADC_Value=0;			//get ADC value
	LCD_Vid4Initialization();	//Initialization of LCD
	//*****************************************************
	// Temp =1		LDR=2		LOCk Door=3  Back=4
	while (1)
	{
	GetValue=GetPressedKey(PRTC);
		LCD_Write4String("1-Temp",0,1);
		LCD_Write4String("2-Light",1,1);
		LCD_Write4String("3-Door",0,9);
		LCD_Write4String("4-Back",1,10);

		if (GetValue==1)
		{
			flag_ADC_CHANNEL=1;
			ADC_VidSingleEnded(flag_ADC_CHANNEL);
			while (1)
			{
				GetValue=GetPressedKey(PRTC);
				GetADC_Value=ADC_u16GetCrruntValu();
				GetADC_Value=(GetADC_Value*5000UL)/1024;
				LCD_Write4String("Temp=",0,0);
				LCD_GoToPosition(0,7);
				LCD_VidDisp4Number(GetADC_Value);
				LCD_Write4String("C",0,10);
			if (GetADC_Value>40)
			{
				LCD_Write4String("Fan ON",1,4);
			}

			else if (GetADC_Value<=35)
			{
				LCD_Write4String("Fan OFF",1,4);
			}
			if (GetValue==4)
			{
				break;
			}
			}
		}

		if (GetValue==2)
		{
			flag_ADC_CHANNEL=0;
			ADC_VidSingleEnded(flag_ADC_CHANNEL);
			while(1)
			{
				GetValue=GetPressedKey(PRTC);
				GetADC_Value=ADC_u16GetCrruntValu();
				GetADC_Value=(GetADC_Value*5000UL)/1024;
				GetADC_Value=(GetADC_Value/5000)*100;	//percentage
				LCD_Write4String("Light=",0,0);
				LCD_GoToPosition(0,8);
				LCD_VidDisp4Number(GetADC_Value);
				LCD_Write4String("%",0,11);
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
				if (GetValue==4)
				{
					break;
				}
			}
		}

		if (GetValue==3)
		{
			while (1)
			{
				GetValue=GetPressedKey(PRTC);
				if (GetValue==5)	//Open door
				{
					Tim1_VidOCRA(62);
				}
				else if (GetValue==6)	//closed door
				{
					Tim1_VidOCRA(31);
				}
				if (GetValue==4)
				{
					break;
				}
			}
		}

		if (GetValue==4)
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
