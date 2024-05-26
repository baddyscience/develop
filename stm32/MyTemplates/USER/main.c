#include "stm32f10x.h"
#include "usart_Init_Config.h"
#include "adc.h"
#include "systick.h"

extern  __IO uint16_t  ADC_Converted_Value;

float  ADC_ConvertedValueLocal; 
int main(void)
{
    ADC1_Init();
    printf("\n\r ADC ????????\r");
    while (1)
    {
        ADC_ConvertedValueLocal =(float) ADC_Converted_Value /4096*3.3;
        printf("\r\n ????????16?? = 0x%04X \r\n", ADC_Converted_Value); 
        printf("\r\n ???????? = %f V \r\n",ADC_ConvertedValueLocal); 
        Delay_ms(500);

		}
}