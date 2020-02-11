
/*8-bit olarak 0 - 255 arasinda girdigimiz dijital veriyi 0 - 3.3v arasýnda gerilim olarak aliyoruz.
 * bu sayede led yavas yavas yanip sönmektedir*/

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

int i = 0;

void delay(uint32_t time)
{
	while(time--);
}

GPIO_InitTypeDef GPIO_InitStruct;
DAC_InitTypeDef DAC_InitStruct;

/*GPIO ve DAC KONFIGURASYONLARI*/

void DAC2_Config()
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC,ENABLE);

	DAC_InitStruct.DAC_OutputBuffer = DAC_OutputBuffer_Enable;
	DAC_InitStruct.DAC_Trigger = DAC_Trigger_None; 	// tetikleyici olarak calistirmiyoruz
	DAC_InitStruct.DAC_WaveGeneration = DAC_WaveGeneration_None; //dalga uretmek istemiyoruz

	DAC_Init(DAC_Channel_2 ,&DAC_InitStruct);

	DAC_Cmd(DAC_Channel_2 ,ENABLE);		//cevresel birimlerle calistigimiz zaman cmd ile aktif etmeliyiz
}

GPIO_Config()
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);

	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;

	GPIO_Init(GPIOA,&GPIO_InitStruct);
}

int main(void)
{

	DAC2_Config();
	GPIO_Config();

  while (1)
  {
	  for(; i<255; i++) //DAC_Align_8b_R 8 bit sectigimiz icin 255 yazdýk.12 bit secseydik 4095 yazacaktik
	  {
		  DAC_SetChannel2Data(DAC_Align_8b_R,i);
		  delay(100000);
	  }
	  i=0;
  }
}



void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
