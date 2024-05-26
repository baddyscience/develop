#include "systick.h"
__IO uint32_t TimingDelay;  

void SysTick_Init(void)
{    SysTick_Config(9000); 

SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
}
void Delay_ms(uint16_t nCount)
{	TimingDelay = nCount;
	while(TimingDelay != 0);
}
