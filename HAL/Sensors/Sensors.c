#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/GIE/GIE_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/ADC/ADC_Interface.h"
#include "../../MCAL/Timer_Counter/Timer_Count0_Interface.h"
#include "../../MCAL/Timer_Counter/Timer_Count2_Interface.h"
#include "Sensors.h"
volatile u8  flag_ADC_CHANNEL=0;
void Sensors(void)
{
	DIO_VidSetPinDirection(PRTD,PIN7,OUTPUT);
	//timer0 intial
	Tim_Count0_VidInit();
	//timer0 interrupt enable
	Tim_Count0_VidInterruptEn();
	//timer2 intial
	Tim_Count2_VidInit();
	//timer2 mode
	Tim_Count2_VidCompOutMode();
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
	u16  anlog_value=0;
	if(flag_ADC_CHANNEL==1)             //TEMPRUTER  SHAFEK
	{
		anlog_value = ADC_u16GetCrruntValu();
		anlog_value= anlog_value*temprature_factor;
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
	}
}
void func_TIMER0_CTC_Call_Back(void)
{
	ADC_VidSingleEnded(flag_ADC_CHANNEL);
	flag_ADC_CHANNEL ^= 1;
}
