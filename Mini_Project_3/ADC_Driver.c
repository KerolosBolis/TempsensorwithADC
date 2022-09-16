/*
 * ADC_Driver.c
 *
 *  Created on: Oct 2, 2021
 *      Author: DELL
 */
#include "ADC_Driver.h"
#include "commonmacros.h" /* To use the macros like SET_BIT */
#include "avr/io.h" /* To use the IO Ports Registers */
void ADC_Init(const ADC_configType * config_ptr){
	ADMUX=(ADMUX&0x1F)|((config_ptr->REF_VOLT)<<6);
	ADCSRA=(ADCSRA&0xF8)|(config_ptr->PRE_SCALAR);
	SET_BIT(ADCSRA,ADEN);
	CLEAR_BIT(ADCSRA,ADIE);
}
uint16 ADC_readChannel(uint8 ch_num){
	ADMUX=(ADMUX&0xE0)|(ch_num);
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
    return ADC;
}
