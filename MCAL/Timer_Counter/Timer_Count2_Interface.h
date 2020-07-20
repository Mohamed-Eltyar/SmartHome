/*
 * Timer_Count2_Interface.h
 *
 *  Created on: Jul 19, 2020
 *      Author: PiLoT
 */

#ifndef SMARTHOME_MCAL_TIMER_COUNTER_TIMER_COUNT2_INTERFACE_H_
#define SMARTHOME_MCAL_TIMER_COUNTER_TIMER_COUNT2_INTERFACE_H_

//***************** Functions of Timer/Counter 2 *****************
void Tim_Count2_VidInit(void);
void Tim_Count2_VidCompareReg(u8 Loc_u8OCRvalue);

void Timer2_VidSetCallBack(void (*Fptr)(void));

//************** Configuration of Timer 2 Registers *****************

// Configuration of WaveForm Generation Mode on TCCR0 bit 6 and 3
#define Wavegen 	Fast_PWM
#define Normal 		0
#define PWM_Phase	1
#define CTC			2
#define Fast_PWM	3

// Configuration of Clock Set on TCCR2 bit 2, 1 and 0
#define ClockSet	256		// configuration numbers are 8, 32, 64, 128, 256, 1024 or below
#define NoClk	0
#define NoPreScale	1

#endif /* SMARTHOME_MCAL_TIMER_COUNTER_TIMER_COUNT2_INTERFACE_H_ */
