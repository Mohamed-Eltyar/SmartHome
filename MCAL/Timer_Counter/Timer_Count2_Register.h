
#ifndef SMARTHOME_MCAL_TIMER_COUNTER_TIMER_COUNT2_REGISTER_H_

#define SMARTHOME_MCAL_TIMER_COUNTER_TIMER_COUNT2_REGISTER_H_


#define TCCR2	*((volatile u8*)0x45)
#define TCNT2	*((volatile u8*)0x44)
#define OCR2	*((volatile u8*)0x43)
#define ASSR	*((volatile u8*)0x42)
#define TIMSK	*((volatile u8*)0x59)
#define	TIFR	*((volatile u8*)0x58)

// Pins of Timer/Counter Control Register – TCCR2
#define FOC2	7
#define WGM20	6
#define COM21	5
#define COM20	4
#define WGM21	3
#define CS22	2
#define CS21	1
#define CS20	0

// Pins of Asynchronous Status Register – ASSR

#define AS2			3
#define TCN2UB		2
#define OCR2UB		1
#define TCR2UB		0

// Pins of Timer/Counter Interrupt Mask Register – TIMSK

#define OCIE2	7
#define TOIE2	6










#endif  /* SMARTHOME_MCAL_TIMER_COUNTER_TIMER_COUNT2_REGISTER_H_ */
