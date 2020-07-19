#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/GIE/GIE_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/ADC/ADC_Interface.h"
#include "Sensors.h"
volatile u8  flag_ADC_CHANNEL=0;
void Sensors(void)
{
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
	while(1)
	{

	}
}
void func_ADC_Call_Back(void)
{
	if(flag_ADC_CHANNEL==1)             //TEMPRUTER  SHAFEK
	{

	}
	else if(flag_ADC_CHANNEL==0)     //LDR ELTYER
	{

	}
}
void func_TIMER0_CTC_Call_Back(void)
{
	ADC_VidSingleEnded(flag_ADC_CHANNEL);
	flag_ADC_CHANNEL ^= 1;
}
