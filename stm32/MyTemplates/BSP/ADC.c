#include "adc.h"
#define  ADC1_DR_Address    ((u32)0x40012400+0x4c)

__IO uint16_t ADC_Converted_Value; 

static void ADC1_GPIO_Config(void)
{   GPIO_InitTypeDef GPIO_InitStructure;
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE); 

   RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 |  RCC_APB2Periph_GPIOC, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
 }
    static void ADC1_Mode_Config(void)
{
    DMA_InitTypeDef DMA_InitStructure;
    ADC_InitTypeDef ADC_InitStructure;

    DMA_DeInit(DMA1_Channel1);
    DMA_InitStructure.DMA_PeripheralBaseAddr = ADC1_DR_Address; //ADC1??
    DMA_InitStructure.DMA_MemoryBaseAddr = (u32)& ADC_Converted_Value;//????
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
         //???????????
    DMA_InitStructure.DMA_BufferSize = 1;//DMA??1???
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;//??????
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable;  //??????
		DMA_InitStructure.DMA_PeripheralDataSize=DMA_PeripheralDataSize_HalfWord;
					 //???????
		DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
		DMA_InitStructure.DMA_Mode = DMA_Mode_Circular; //????DMA??
		DMA_InitStructure.DMA_Priority = DMA_Priority_High;
		DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
		DMA_Init(DMA1_Channel1, &DMA_InitStructure); //??DMA??1
		DMA_Cmd(DMA1_Channel1, ENABLE); //??DMA1??1
					/* ADC1???? */
		ADC_InitStructure.ADC_Mode = ADC_Mode_Independent; //??ADC??
		ADC_InitStructure.ADC_ScanConvMode = DISABLE ; //??????	
		ADC_InitStructure.ADC_ContinuousConvMode = ENABLE; //????????
		ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None; //??????
		ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//??????????
		ADC_InitStructure.ADC_NbrOfChannel = 1;	//????????
		ADC_Init(ADC1, &ADC_InitStructure);
		RCC_ADCCLKConfig(RCC_PCLK2_Div8); //??ADC??,?PCLK2?8??,?9MHz
						/*??ADC1???11?55.5?????,???1 */ 
		ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 1, ADC_SampleTime_55Cycles5);
		ADC_DMACmd(ADC1, ENABLE); //??ADC1 ?DMA
		ADC_Cmd(ADC1, ENABLE); //??ADC1
		ADC_ResetCalibration(ADC1); //????ADC1???
		while(ADC_GetResetCalibrationStatus(ADC1));  
     //???????????
		ADC_StartCalibration(ADC1); 
				//??ADC1??
		while(ADC_GetCalibrationStatus(ADC1));  
				 //??????
		ADC_SoftwareStartConvCmd(ADC1, ENABLE);     
      //????ADC??
}
void ADC1_Init(void)
{
		ADC1_GPIO_Config();
		ADC1_Mode_Config();
}
