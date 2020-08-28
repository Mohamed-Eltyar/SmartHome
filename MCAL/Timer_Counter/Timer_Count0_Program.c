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
	

	//Prescaler equal 1024
	SET_BIT(TCCR0,2);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,0);


//***********************************************************
	//OCR Register Value to get 25 ms
	OCR0=195;
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


void _delayT_ms(u16 copy_u16timevalue)
{
	copy_u16timevalue *=4;
	//Normal mode
	CLR_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);

	//Prescaler equal 1024
	CLR_BIT(TCCR0,2);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,0);
	u16 couner=0;
	while(1)
	{
		TCNT0=24;
		while(!GET_BIT(TIFR,0));
		SET_BIT(TIFR,0);
		couner++;
		if(copy_u16timevalue==couner)
		{
			break;
		}
	}
}

