/*
#ifndef SMARTHOME_MCAL_TIMER_COUNTER_TIMER_COUNT2_REGISTER_H_
#define SMARTHOME_MCAL_TIMER_COUNTER_TIMER_COUNT2_REGISTER_H_


//***************** Functions of Timer/Counter 0 *****************
void Tim_Count0_VidWaveGeneration(void);
void Tim_Count0_VidCompOutMode(void);
void Tim_Count0_VidClockSelect(void);
void Tim_Count0_VidInterruptEn(void);
void Tim_Count0_VidCounterReg(u8 Loc_u8TCNTvalue);
void Tim_Count0_VidCompareReg(u8 Loc_u8OCRvalue);

void Timer_VidSetCallBack(void (*Fptr)(void));


//*********************** Configuration of Timer Register **************************

// Configuration of WaveForm Generation Mode on TCCR0 bit 6 and 3
#define WaveGen Normal
#define Normal 		0
#define PWM_Phase	1
#define CTC			2
#define Fast_PWM	3

// Configuration of Compare Match Output Mode, non-PWM Mode on TCCR0 bit 5 and 4
#define CompOut		Normal
#define Normal			0		// OC0 disconnected.
#define	Toggle			1		//Toggle OC0 on compare match
#define Clear			2		//Clear OC0 on compare match
#define Set				3		//Set OC0 on compare match

// Configuration of Compare Match Output Mode, Fast PWM Mode on TCCR0 bit 5 and 4
#define FastOut		Normal
#define Normal			0		// OC0 disconnected.
#define Clear			2		//Clear OC0 on compare match, set OC0 at TOP
#define Set				3		//Set OC0 on compare match, clear OC0 at TOP

// Configuration of Compare Match Output Mode,  Phase Correct PWM Mode on TCCR0 bit 5 and 4
#define PhaseOut		Normal
#define Normal			0		// OC0 disconnected.
#define Clear			2		//Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting
#define Set				3		//Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting

// Configuration of Clock Set on TCCR0 bit 2, 1 and 0
#define ClockSet	1024	// configuration numbers are 8, 64, 256, 1024 or below
#define NoClk	0
#define NoPreScale	1
#define	EXT_ClkFalling	6	//External clock source on T0 pin. Clock on falling edge.
#define EXT_ClkRising	7	//External clock source on T0 pin. Clock on rising edge.

//Configuration of Interrupt Enable
#define INT_EN		OverFlow	//To choose which mode you worked on to get the Enable o this Mode
#define	OverFlow		0
#define	CompMatch		1



void __vector_10(void) __attribute__((signal));
void __vector_11(void) __attribute__((signal));



#endif /*SMARTHOME_MCAL_TIMER_COUNTER_TIMER_COUNT2_REGISTER_H_*/
