#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "Timer_Count2_Register.h"
#include "Timer_Count2_Interface.h"

void Tim_Count2_VidInit(void)
{
	//Wave Generation Mode
	#if WaveGen==Normal
		CLR_BIT(TCCR2,WGM21);
		CLR_BIT(TCCR2,WGM20);
	#elif WaveGen==PWM_Phase
		CLR_BIT(TCCR2,WGM21);
		SET_BIT(TCCR2,WGM20);
	#elif WaveGen==CTC
		SET_BIT(TCCR2,WGM21);
		CLR_BIT(TCCR2,WGM20);
	#elif WaveGen==Fast_PWM
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
}

void Tim_Count2_VidCompOutMode(void)
{
	//for Fast PWM Mode
		#if FastOut==Normal
		CLR_BIT(TCCR2,COM21);
		CLR_BIT(TCCR2,COM20);
		#elif FastOut==Clear
		SET_BIT(TCCR2,COM21);
		CLR_BIT(TCCR2,COM20);
		#elif FastOut==Set
		SET_BIT(TCCR2,COM21);
		SET_BIT(TCCR2,COM20);
		#endif

}

void Tim_Count2_VidCompareReg(u8 Loc_u8OCRvalue)
{
	OCR2=Loc_u8OCRvalue;
}

void Tim_Count2_VidCounterReg(u8 Loc_u8TCNTvalue)
{
	TCNT2=Loc_u8TCNTvalue;
}
