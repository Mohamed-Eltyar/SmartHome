#ifndef SMARTHOME_LIB_BIT_MATH_H_
#define SMARTHOME_LIB_BIT_MATH_H_


#define SET_BIT(VAR,BITNO) (VAR) |=  (1 << (BITNO))
#define CLR_BIT(VAR,BITNO) (VAR) &= ~(1 << (BITNO))
#define TOG_BIT(VAR,BITNO) (VAR) ^=  (1 << (BITNO))
#define GET_BIT(VAR,BITNO) (((VAR) >> (BITNO)) & 0x01)

#define INT1_VECT     __vector_2
#define INT2_VECT     __vector_3
#define ADC_VECT     __vector_16
#define TIMER0_OV     __vector_11
#define TIMER0_CTC_VECT     __vector_10


#define ISR(vector,...) \
	void vector(void)   __attribute__((signal)) __VA_ARGS__; \
	void vector(void)




#define HIGH 1
#define LOW 0

#include <avr/delay.h>


#endif /*SMARTHOME_LIB_BIT_MATH_H_*/
