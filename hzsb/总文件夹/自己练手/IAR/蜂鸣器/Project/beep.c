#include"beep.h"

void BEEP_Init(void){
  
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE); //使能 PB,PE 端口时钟
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8; //蜂鸣器-->PB.58推挽输出
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
 
  GPIO_ResetBits(GPIOB,GPIO_Pin_8); //PE.8 输出高
}

