
#include "bsp_led.h"   

 /**
  * @brief  led硬件配置
  * @param  无
  * @retval 无
  */
void LED_GPIO_Config(void)
{
	/* gpio类型结构体 */
	GPIO_InitTypeDef GPIO_InitStructure;

	/* gpio时钟 */
	RCC_AHB1PeriphClockCmd ( LED1_GPIO_CLK|
                           LED2_GPIO_CLK|
                           LED3_GPIO_CLK|
                           LED_GPIO_CLK, ENABLE); 

	/* gpio pin */
	GPIO_InitStructure.GPIO_Pin = LED1_PIN;	

	/* gpio mode */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;   
    
  /* gpio output type */
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  
  /*up*/
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

	/* gpio速率 */   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz; 

	/*gpio init*/
	GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStructure);	
    
  /* gpio init */  
	GPIO_InitStructure.GPIO_Pin = LED2_PIN;	
  GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStructure);	
  
  /*gpio init*/															   
	GPIO_InitStructure.GPIO_Pin = LED3_PIN;	
  GPIO_Init(LED3_GPIO_PORT, &GPIO_InitStructure);	

  //system led
  GPIO_InitStructure.GPIO_Pin = LED_PIN;	
  GPIO_Init(LED_GPIO_PORT, &GPIO_InitStructure);	
	
	/* 关闭RGB */
	LED_RGBOFF;		
}
/*********************************************END OF FILE**********************/
