#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/GIE/GIE_Interface.h"
#include "../../MCAL/ADC/ADC_Interface.h"
#include "../../MCAL/Timer_Counter/Timer_Count2_Interface.h"
#include "Sensors.h"
volatile u8  flag_ADC_CHANNEL=0;	//To Change between Channels at ADC
void Sensors(void)
{
	//Directions
	DIO_VidSetPinDirection(PRTD,PIN7,OUTPUT);	//For Fan
	DIO_VidSetPortDirection(PRTA,0b00000011);	//ADC1 For Temperature, ADC0 FOR LDR and others for LEDs

	//******************************************************

	SREG_VidEnable();					 //General Interrupt Enable

	LCD_Vid4Initialization();			 //LCD Configuration

	Tim_Count2_VidInit();				 //timer2 Initialization

	ADC_VidInit();						 //ADC Initialization

	ADC_VidEnable();					 //ADC ENABLE

	ADC_VidAutoTriggerSource(); 		 //ADC AUTO TRIGGER(free running)

	ADC_SetCallBackF(func_ADC_Call_Back);//ADC CALL BACK


}
void func_ADC_Call_Back(void)
{

	u16  anlog_value=0;

	if(flag_ADC_CHANNEL==1)             //TEMPRUTER  SHAFEK
	{

		anlog_value = ADC_u16GetCrruntValu();
		anlog_value= anlog_value*temprature_factor;

		if(anlog_value>=high_temprature)
		{
			Tim_Count2_VidCompareReg(Motor_ON);		//Fan On
		}
		if(anlog_value<=low_temprature)
		{
			Tim_Count2_VidCompareReg(Motor_OFF);	//Fan OFF
		}
	}
	else if(flag_ADC_CHANNEL==0)     //LDR ELTYER
	{

		anlog_value = ADC_u16GetCrruntValu();		//Store Date from ADC Register
		anlog_value	=(anlog_value*5000UL)/1024;	    //Convert to Voltage

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

