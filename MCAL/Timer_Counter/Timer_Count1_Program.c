#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "Timer_Count1_Register.h"
#include "Timer_Count1_Interface.h"

static void (*Tim1CallBackPtrOVFL)(void)=NULL;
static void (*Tim1CallBackPtrCOMA)(void)=NULL;
//static void (*Tim1CallBackPtrCOMB)(void)=NULL;
static void (*Tim1CallBackPtrCapture)(void)=NULL;

void Tim1_VidInit(void)
{
	//Wave Generation Mode
	#if Wavegen==Normal
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	CLR_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);
	#elif Wavegen==Phase_PWM_8bit
	SET_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	CLR_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);
	#elif Wavegen==Phase_PWM_9bit
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	CLR_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);
	#elif Wavegen==Phase_PWM_10bit
	SET_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	CLR_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);
	#elif Wavegen==CTC_OCR
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);
	#elif Wavegen==Fast_PWM_8bit
	SET_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);
	#elif Wavegen==Fast_PWM_9bit
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);
	#elif Wavegen==Fast_PWM_10bit
	SET_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);
	#elif Wavegen==Phase_PWM_Frq_ICR
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	CLR_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);
	#elif Wavegen==Phase_PWM_Frq_OCR
	SET_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	CLR_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);
	#elif Wavegen==Phase_PWM_ICR
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	CLR_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);
	#elif Wavegen==Phase_PWM_OCR
	SET_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	CLR_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);
	#elif Wavegen==CTC_ICR
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);
	#elif Wavegen==Fast_PWM_ICR
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);
	#elif Wavegen==Fast_PWM_OCR
	SET_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);
	#else
		#error "Wrong Mode of Wave Generation"
	#endif
	
	//Prescaler
	#if Prescaler== No_Pres
	CLR_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
	#elif Prescaler==1
	SET_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
	#elif Prescaler==8
	CLR_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
	#elif Prescaler==64
	SET_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
	#elif Prescaler==256
	CLR_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,2);
	#elif Prescaler==1024
	SET_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,2);
	#elif Prescaler==EXT_Clk_Falling
	CLR_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,2);
	#elif Prescaler==EXT_Clk_Rising
	SET_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,2);
	#else
		#error	"Wronge Choose of Prescaler"
	#endif
	

	
	
}


void Tim1_VidOutCompare(void)
{
		#if OutFast==Normal
			CLR_BIT(TCCR1A,7);
			CLR_BIT(TCCR1A,5);
			CLR_BIT(TCCR1A,6);
			CLR_BIT(TCCR1A,4);
		#elif OutFast==Toggle_OC1A
			CLR_BIT(TCCR1A,7);
			CLR_BIT(TCCR1A,5);
			SET_BIT(TCCR1A,6);
			SET_BIT(TCCR1A,4);
		#elif OutFast==Clear
			SET_BIT(TCCR1A,7);
			SET_BIT(TCCR1A,5);
			CLR_BIT(TCCR1A,6);
			CLR_BIT(TCCR1A,4);
		#elif OutFast==Set
			SET_BIT(TCCR1A,7);
			SET_BIT(TCCR1A,5);
			SET_BIT(TCCR1A,6);
			SET_BIT(TCCR1A,4)
		#endif

}
void Tim1_VidEdgeSelect(u8 LOC_u16Edge)
{
	if (LOC_u16Edge==0)
	{
		CLR_BIT(TCCR1B,6);
	}
	else if (LOC_u16Edge==1)
	{
		SET_BIT(TCCR1B,6);
	}

}

void Tim1_VidOCRA(u16 LOC_u16OCRA)
{
	OCR1A=LOC_u16OCRA;
}

void Tim1_VidICR(u16 LOC_u16ICR)
{
	ICR1=LOC_u16ICR;
}

//***********************************************************************************************************

void Timer1_VidSetCallBack(void (*Fptr)(void))
{
	if (Fptr !=NULL)
	{
		Tim1CallBackPtrCOMA=Fptr;
	}

}

void __vector_7(void) //Compare match A Interrupt
{
	if (Tim1CallBackPtrCOMA !=NULL)
		{
		Tim1CallBackPtrCOMA();
		}
}

