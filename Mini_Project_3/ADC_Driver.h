/*
 * ADC.h
 *
 *  Created on: Oct 2, 2021
 *      Author: DELL
 */

#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_
#include"std_types.h"
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56
typedef enum{
    NO_CLOCK,F_CPU_2,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_PreScalar;
typedef enum{
	AREF_INTERNAL,AVCC_EXTERNAL,RESERVED,INTERNAL_2_56
}Reference_Voltage;
typedef struct{
	Reference_Voltage REF_VOLT;
	ADC_PreScalar PRE_SCALAR;
}ADC_configType;
void ADC_Init(const ADC_configType * config_ptr);
uint16 ADC_readChannel(uint8 ch_num);


#endif /* ADC_DRIVER_H_ */
