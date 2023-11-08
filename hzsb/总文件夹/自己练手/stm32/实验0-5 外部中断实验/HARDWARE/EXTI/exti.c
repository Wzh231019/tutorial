#include "exti.h"
#include "led.h"
#include "key.h"
#include "delay.h"
#include "usart.h"
#include "beep.h"

//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK精英STM32开发板
//外部中断 驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/9/3
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////   
//外部中断0服务程序
void EXTIX_Init(void)
{
	
	EXTI_InitTypeDef EXTI_InitStrue;
	NVIC_InitTypeDef NVIC_InitStrue;
	
	KEY_Init();
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource4);
	
	EXTI_InitStrue.EXTI_Line=EXTI_Line4;
	EXTI_InitStrue.EXTI_LineCmd=ENABLE;
	EXTI_InitStrue.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStrue.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitStrue);
	
	NVIC_InitStrue.NVIC_IRQChannel=EXTI4_IRQn;
	NVIC_InitStrue.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStrue.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_InitStrue.NVIC_IRQChannelSubPriority=2;
	NVIC_Init(&NVIC_InitStrue);
	
}

void EXTI4_IRQHandler(void)
{
	delay_ms(10);
	if(KEY0==0){
		LED0=!LED0;
		LED1=!LED1;
	}
	EXTI_ClearITPendingBit(EXTI_Line4);
}
 
