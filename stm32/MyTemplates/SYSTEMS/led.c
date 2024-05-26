#include "led.h"

	
void LED_Init(void){
	
	GPIO_InitTypeDef gpio_09;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOD,ENABLE);

	gpio_09.GPIO_Pin = GPIO_Pin_8;

	gpio_09.GPIO_Mode = GPIO_Mode_Out_PP;
	
	gpio_09.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOA,&gpio_09);
	
	gpio_09.GPIO_Pin = GPIO_Pin_2;

	gpio_09.GPIO_Mode = GPIO_Mode_Out_PP;
	
	gpio_09.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOD,&gpio_09);

}
