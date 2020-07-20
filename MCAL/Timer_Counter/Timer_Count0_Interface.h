#ifndef SMARTHOME_MCAL_TIMER_COUNTER_TIMER0_COUNT_INTERFACE_H_
#define SMARTHOME_MCAL_TIMER_COUNTER_TIMER0_COUNT_INTERFACE_H_


//***************** Functions of Timer/Counter 0 *****************
void Tim_Count0_VidInit(void);
void Tim_Count0_VidCompOutMode(void);
void Tim_Count0_VidInterruptEn(void);

void Timer0_VidSetCallBack(void (*Fptr)(void));


//*********************** Configuration of Timer Registers **************************

// Configuration of WaveForm Generation Mode on TCCR0 bit 6 and 3
#define WaveGen 	CTC
#define Normal 		0
#define PWM_Phase	1
#define CTC			2
#define Fast_PWM	3

//Configuration of Interrupt Enable
#define INT_EN		0	//To choose which mode you worked on to get the Enable on this Mode
#define	OverFlow		1
#define	CompMatch		2








#endif   /* SMARTHOME_MCAL_TIMER_COUNTER_TIMER0_COUNT_INTERFACE_H_ */
