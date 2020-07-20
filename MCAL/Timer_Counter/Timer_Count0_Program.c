#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "Timer_Count0_Register.h"
#include "Timer_Count0_Interface.h"


static void (*Tim0CallBackPtrCOMA)(void)=NULL;

void Tim_Count0_VidInit(void)
{
	#if WaveGen==Normal
	CLR_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);
	#elif WaveGen==PWM_Phase
	SET_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);
	#elif WaveGen==CTC
	SET_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	#elif WaveGen==Fast_PWM
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	#else
		#error "Wrong Choose of Wave Generation"
	#endif
	
	#if ClockSet==NoClk
	CLR_BIT(TCCR0,2);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,0);
	#elif ClockSet==NoPrescale
	CLR_BIT(TCCR0,2);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,0);
	#elif ClockSet==8
	CLR_BIT(TCCR0,2);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,0);
	#elif ClockSet==64
	CLR_BIT(TCCR0,2);
	SET_BIT(TCCR0,1);
	SET_BIT(TCCR0,0);
	#elif ClockSet==256
	SET_BIT(TCCR0,2);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,0);
	#elif ClockSet==1024
	SET_BIT(TCCR0,2);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,0);
	#elif ClockSet==EXT_ClkFalling
	SET_BIT(TCCR0,2);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,0);
	#elif ClockSet==EXT_ClkRising
	SET_BIT(TCCR0,2);
	SET_BIT(TCCR0,1);
	SET_BIT(TCCR0,0);
	#else
		#error "Wrong Choose of Set Clock"
	#endif
//***********************************************************
	//OCR Register Value
	OCR0=125;
}

void Tim_Count0_VidCompOutMode(void)
{
		//for OC0 Disconnected at CTC mode
		CLR_BIT(TCCR0,5);
		CLR_BIT(TCCR0,4);
}


void Tim_Count0_VidInterruptEn(void)
{
	#if INT_EN==OverFlow
	SET_BIT(TIMSK,0);
	CLR_BIT(TIMSK,1);
	#elif INT_EN==CompMatch
	SET_BIT(TIMSK,1);
	CLR_BIT(TIMSK,0);
	#else
	CLR_BIT(TIMSK,1);
	CLR_BIT(TIMSK,0);
	#endif
}

void Timer0_VidSetCallBack(void (*Fptr)(void))	//Function Call back For ISR
{
	if (Fptr !=NULL)
	{
		Tim0CallBackPtrCOMA=Fptr;
	}
}
ISR(TIMER0_CTC_VECT) //Compare match Interrupt
{
	if (Tim0CallBackPtrCOMA !=NULL)
		{
		Tim0CallBackPtrCOMA();
		}
}
