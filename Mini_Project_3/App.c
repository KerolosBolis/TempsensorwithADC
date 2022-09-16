/*
 * App.c
 *
 *  Created on: Oct 9, 2021
 *      Author: DELL
 */
#include"ADC_Driver.h"
#include"LCD.h"
#include"pwm_Driver.h"
#include"lm35_sensor.h"
#include"dc_motor.h"
#include"GPIO.h"
int main(){
	ADC_configType adc_config={INTERNAL_2_56,F_CPU_8};
	DcMotor_State state=STOP;
	uint8 temperature;
	ADC_Init(&adc_config);
	LCD_init();
	DcMotor_Init();
	while(1){
		temperature=LM35_getTemperature();
		if(temperature<30){
			DcMotor_Rotate(state,0);
			LCD_moveCursor(0,5);
			LCD_displayString("FAN IS OFF");
			LCD_moveCursor(1,5);
			LCD_displayString("Temp =");
			if(temperature >= 100)
			{
				LCD_intgerToString(temperature);
			}
			else
			{
				LCD_intgerToString(temperature);
				LCD_displayCharacter(' ');
			}
		}
		else if((temperature>=30)&&(temperature<60)){
			state=CLOCKWISE;
			DcMotor_Rotate(state,25);
			LCD_moveCursor(0,5);
			LCD_displayString("FAN IS ON ");
			LCD_moveCursor(1,5);
			LCD_displayString("Temp =");
			if(temperature >= 100)
			{
				LCD_intgerToString(temperature);
			}
			else
			{
				LCD_intgerToString(temperature);
				LCD_displayCharacter(' ');
			}
		}
		else if((temperature>=60)&&(temperature<90)){
			state=CLOCKWISE;
			DcMotor_Rotate(state,50);
			LCD_moveCursor(0,5);
			LCD_displayString("FAN IS ON ");
			LCD_moveCursor(1,5);
			LCD_displayString("Temp =");
			if(temperature >= 100)
			{
				LCD_intgerToString(temperature);
			}
			else
			{
				LCD_intgerToString(temperature);
				LCD_displayCharacter(' ');
			}
		}
		else if((temperature>=90)&&(temperature<120)){
			state=CLOCKWISE;
			DcMotor_Rotate(state,75);
			LCD_moveCursor(0,5);
			LCD_displayString("FAN IS ON ");
			LCD_moveCursor(1,5);
			LCD_displayString("Temp =");
			if(temperature >= 100)
			{
				LCD_intgerToString(temperature);
			}
			else
			{
				LCD_intgerToString(temperature);
				LCD_displayCharacter(' ');
			}
		}
		else if(temperature>=120){
			state=CLOCKWISE;
			DcMotor_Rotate(state,100);
			LCD_moveCursor(0,5);
			LCD_displayString("FAN IS ON ");
			LCD_moveCursor(1,5);
			LCD_displayString("Temp =");
			if(temperature >= 100)
			{
				LCD_intgerToString(temperature);
			}
			else
			{
				LCD_intgerToString(temperature);
				LCD_displayCharacter(' ');
			}

		}
	}
}


