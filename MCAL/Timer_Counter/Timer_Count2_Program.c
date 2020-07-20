#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "Timer_Count2_Register.h"
#include "Timer_Count2_Interface.h"

void Tim_Count2_VidInit(void)
{
	//Wave Generation Mode
	#if Wavegen==Normal
		CLR_BIT(TCCR2,WGM21);
		CLR_BIT(TCCR2,WGM20);
	#elif Wavegen==PWM_Phase
		CLR_BIT(TCCR2,WGM21);
		SET_BIT(TCCR2,WGM20);
	#elif Wavegen==CTC
		SET_BIT(TCCR2,WGM21);
		CLR_BIT(TCCR2,WGM20);
	#elif Wavegen==Fast_PWM
		SET_BIT(TCCR2,WGM21);
		SET_BIT(TCCR2,WGM20);
	#endif

	//Prescaler

	#if	ClockSet==0
		CLR_BIT(TCCR2,CS22);
		CLR_BIT(TCCR2,CS21);
		CLR_BIT(TCCR2,CS20);
	#elif ClockSet==1
		CLR_BIT(TCCR2,CS22);
		CLR_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS20);
	#elif ClockSet==8
		CLR_BIT(TCCR2,CS22);
		SET_BIT(TCCR2,CS21);
		CLR_BIT(TCCR2,CS20);
	#elif ClockSet==32
		CLR_BIT(TCCR2,CS22);
		SET_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS20);
	#elif ClockSet==64
		SET_BIT(TCCR2,CS22);
		CLR_BIT(TCCR2,CS21);
		CLR_BIT(TCCR2,CS20);
	#elif ClockSet==128
		SET_BIT(TCCR2,CS22);
		CLR_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS20);
	#elif ClockSet==256
		SET_BIT(TCCR2,CS22);
		SET_BIT(TCCR2,CS21);
		CLR_BIT(TCCR2,CS20);
	#elif ClockSet==1024
		SET_BIT(TCCR2,CS22);
		SET_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS20);
	#endif

//for Fast PWM Mode Non-Inverted
		SET_BIT(TCCR2,COM21);
		CLR_BIT(TCCR2,COM20);
}



void Tim_Count2_VidCompareReg(u8 Loc_u8OCRvalue)
{
	OCR2=Loc_u8OCRvalue;
}


