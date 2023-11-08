#include"key.h"
#include"delay.h"

void KEY_Init(void)
{
		RCC->APB2ENR|=1<<2; //使能 PORTA 时钟
    RCC->APB2ENR|=1<<6; //使能 PORTE 时钟
	  
	  GPIOA->CRL&=0XFFFFFFF0; //PA0 设置成输入，默认下拉 
    GPIOA->CRL|=0X00000008; 
    GPIOE->CRL&=0XFFF00FFF; //PE3/4 设置成输入 
    GPIOE->CRL|=0X00088000;
	  GPIOE->ODR|=3<<3; //PE3/4 上拉
}
//按键处理函数
//返回按键值
//mode:0,不支持连续按;1,支持连续按;
//0，没有任何按键按下
//1，KEY0 按下
//2，KEY1 按下
//3，KEY_UP 按下 即 WK_UP
//注意此函数有响应优先级,KEY0>KEY1>KEY_UP!!

u8 KEY_Scan(u8 mode)
{
	static u8 key_up=1;
	if(mode)key_up=1;//支持连按
	if(key_up&&(KEY0==0||KEY1==0||WK_UP==1))
	{
		delay_ms(10);
		key_up=0;
    if(KEY0==0)return 1;
    else if(KEY1==0)return 2; 
    else if(WK_UP==1)return 3;
  }else if(KEY0==1&&KEY1==1&&WK_UP==0)key_up=1; 
  return 0;// 无按键按下
}

