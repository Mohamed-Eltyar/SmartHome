/*
 * Sensors.h
 *
 *  Created on: Jul 19, 2020
 *      Author: shafek
 */

#ifndef SMARTHOME_HAL_SENSORS_SENSORS_H_
#define SMARTHOME_HAL_SENSORS_SENSORS_H_

void func_ADC_Call_Back(void);
void func_TIMER0_CTC_Call_Back(void);
void Sensors(void);

#define Motor_ON 255
#define Motor_OFF 0
#define high_temprature  40
#define low_temprature    35
#define temprature_factor  ((500UL)<<10)

#endif /* SMARTHOME_HAL_SENSORS_SENSORS_H_ */

/* PRT>> for DIO
 * PORT >> for mask
 */
