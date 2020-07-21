#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/GIE/GIE_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/ADC/ADC_Interface.h"
#include "../../MCAL/Timer_Counter/Timer_Count0_Interface.h"
#include "../../MCAL/Timer_Counter/Timer_Count2_Interface.h"
#include "../LCD_4BIT/LCD_4BIT_Interface.h"
#include "../../MCAL/GIE/GIE_Interface.h"
#include "../../HAL/KeyPad/KeyPad_Interface.h"
#include "Sensors.h"
volatile u8  flag_ADC_CHANNEL=0;
extern volatile u8 arr[16];
void Sensors(void)
{
	SREG_VidEnable();	//General Interrupt Enable
	DIO_VidSetPinDirection(PRTD,PIN7,OUTPUT);
	DIO_VidSetPinDirection(PRTD,PIN0,OUTPUT);


	DIO_VidSetPortDirection(PRTA,0b00000011);	//ADC0 For Temp, ADC1 FOR LDR and others for LEDs
	//***************
	//LCD Configuration
	LCD_Vid4Initialization();

	//timer0 intial
	Tim_Count0_VidInit();
	//timer0 interrupt enable
	Tim_Count0_VidInterruptEn();
	//timer2 intial
	Tim_Count2_VidInit();
	//timer2 mode
	//ADC INITIAL
	ADC_VidInit();
	//ADC ENABLE
	ADC_VidEnable();
	//ADC AUTO TRIGGER
	ADC_VidAutoTriggerSource();
	//ADC CALL BACK
	ADC_SetCallBackF(func_ADC_Call_Back);
	//TIMER CALL BACK
	Timer0_VidSetCallBack(func_TIMER0_CTC_Call_Back);

}
void func_ADC_Call_Back(void)
{
	arr[GetPressedKey(PRTC)]=GetPressedKey(PRTC);
	u16  anlog_value=0;

	if(flag_ADC_CHANNEL==1)             //TEMPRUTER  SHAFEK
	{
		anlog_value = ADC_u16GetCrruntValu();
		LCD_Write4String("Ch1 = ",0,0);
		ADC_VidSingleEnded(flag_ADC_CHANNEL);
		anlog_value= anlog_value*temprature_factor;
		LCD_VidDisp4Number(anlog_value);

		if(anlog_value>=high_temprature)
		{
			Tim_Count2_VidCompareReg(Motor_ON);
		}
		if(anlog_value<=low_temprature)
		{
			Tim_Count2_VidCompareReg(Motor_OFF);
		}
	}
	else if(flag_ADC_CHANNEL==0)     //LDR ELTYER
	{
		anlog_value = ADC_u16GetCrruntValu();
		LCD_Write4String("Ch2 = ",1,0);
		//anlog_value	=(anlog_value*5000UL)/1024;
		LCD_VidDisp4Number(anlog_value);

		if(anlog_value>950)
		{
			DIO_VidOutLED(NO_LED);
		}
		else if (anlog_value>713 && anlog_value<950)
		{
			DIO_VidOutLED(Three_Quarters_LED);
		}
		else if (anlog_value>476 && anlog_value<713)
		{
			DIO_VidOutLED(Half_LED);
		}
		else if (anlog_value>0 && anlog_value<476)
		{
			DIO_VidOutLED(FUll_LED);
		}
	}
}
void func_TIMER0_CTC_Call_Back(void)
{
	flag_ADC_CHANNEL ^= 1;
	ADC_VidSingleEnded(flag_ADC_CHANNEL);
}
