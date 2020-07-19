#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_Interface.h"
#include "../DIO/DIO_Register.h"
#include "ADC_Interface.h"
#include "ADC_Register.h"
static void ((*GPFunction)(void))= NULL;
void ADC_SetCallBackF(void (*LocCALLFUNC)(void))
{
	if (LocCALLFUNC!=NULL)
	{
		GPFunction=LocCALLFUNC;
	}
}

void ADC_VidInit(void)
{
	//Set Interrupt Enable
#if ADC_INT_En==1
	SET_BIT(ADCSRA,3);
#elif ADC_INT_En==0
	CLR_BIT(ADCSRA,3);
#endif

		//Set Voltage Referance
#if InternVCC==0
		CLR_BIT(ADMUX,7);
		CLR_BIT(ADMUX,6);
#elif InternVCC==1
		CLR_BIT(ADMUX,7);
		SET_BIT(ADMUX,6);
#elif InternVCC==3
		SET_BIT(ADMUX,7);
		SET_BIT(ADMUX,6);
#else
		#error "Wrong Choose Voltage Referance ! "
#endif
	
	// Set Left adjustment 
	#if ADC_LeftAdj==0
		CLR_BIT(ADMUX,5);
	#else
		SET_BIT(ADMUX,5);
	#endif
	//Set prescaler
	#if Prescaler==2
		CLR_BIT(ADCSRA,2);
		CLR_BIT(ADCSRA,1);
		SET_BIT(ADCSRA,0);
	#elif Prescaler==4
		CLR_BIT(ADCSRA,2);
		SET_BIT(ADCSRA,1);
		CLR_BIT(ADCSRA,0);
	#elif Prescaler==8
		CLR_BIT(ADCSRA,2);
		SET_BIT(ADCSRA,1);
		SET_BIT(ADCSRA,0);
	#elif Prescaler==16
		SET_BIT(ADCSRA,2);
		CLR_BIT(ADCSRA,1);
		CLR_BIT(ADCSRA,0);
	#elif Prescaler==32
		SET_BIT(ADCSRA,2);
		CLR_BIT(ADCSRA,1);
		SET_BIT(ADCSRA,0);
	#elif Prescaler==64
		SET_BIT(ADCSRA,2);
		SET_BIT(ADCSRA,1);
		CLR_BIT(ADCSRA,0);
	#elif Prescaler==128
		SET_BIT(ADCSRA,2);
		SET_BIT(ADCSRA,1);
		SET_BIT(ADCSRA,0);
	#else
		#error "Wrong Choose Prescaler!"
	#endif
}


void ADC_VidEnable(void)
{
	SET_BIT(ADCSRA,7);
}
	
	
void ADC_VidSingleEnded(u8 LOC_Channel)
{
	ADMUX&=0b11100000;               //singel ended
	ADMUX |=LOC_Channel;              //number of channel by user

	SET_BIT(ADCSRA,PIN6);             //Start Conversion
}
/*
u16  ADC_u16GetDataSingleEnded(void)
{
	SET_BIT(ADCSRA,PIN6);
	while(0==GET_BIT(ADCSRA, PIN4));
	return ((ADC*5000UL)/1023);
}
*/
void ADC_VidAutoTriggerSource(void)
{
#if AutoTrigEn==1 && Trigger_Mode==FreeRunning
	SET_BIT(ADCSRA,5);
	CLR_BIT(SFIOR,7);
	CLR_BIT(SFIOR,6);
	CLR_BIT(SFIOR,5);
#elif AutoTrigEn==1 && Trigger_Mode==AnalogComp
	SET_BIT(ADCSRA,5);
	CLR_BIT(SFIOR,7);
	CLR_BIT(SFIOR,6);
	SET_BIT(SFIOR,5);
#elif AutoTrigEn==1 && Trigger_Mode==EXT_I0Req
	SET_BIT(ADCSRA,5);
	CLR_BIT(SFIOR,7);
	SET_BIT(SFIOR,6);
	CLR_BIT(SFIOR,5);
#elif AutoTrigEn==1 && Trigger_Mode==Timer0CompMatch
	SET_BIT(ADCSRA,5);
	CLR_BIT(SFIOR,7);
	SET_BIT(SFIOR,6);
	SET_BIT(SFIOR,5);
#elif AutoTrigEn==1 && Trigger_Mode==Timer0OvFlow
	SET_BIT(ADCSRA,5);
	SET_BIT(SFIOR,7);
	CLR_BIT(SFIOR,6);
	CLR_BIT(SFIOR,5);
#elif AutoTrigEn==1 && Trigger_Mode==Timer1ComMatch
	SET_BIT(ADCSRA,5);
	SET_BIT(SFIOR,7);
	CLR_BIT(SFIOR,6);
	SET_BIT(SFIOR,5);
#elif AutoTrigEn==1 && Trigger_Mode==Timer1OvFlow
	SET_BIT(ADCSRA,5);
	SET_BIT(SFIOR,7);
	SET_BIT(SFIOR,6);
	CLR_BIT(SFIOR,5);
#elif AutoTrigEn==1 && Trigger_Mode==Timer1CapEvent
	SET_BIT(ADCSRA,5);
	SET_BIT(SFIOR,7);
	SET_BIT(SFIOR,6);
	SET_BIT(SFIOR,5);
#endif
}

ISR(ADC_VECT)
{
	if (GPFunction!=NULL)
	{
		GPFunction();
	}
}
