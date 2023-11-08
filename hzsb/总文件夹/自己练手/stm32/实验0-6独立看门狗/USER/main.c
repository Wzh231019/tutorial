#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "beep.h"
#include "iwdg.h"

/************************************************
 ALIENTEK精英STM32开发板实验3
 按键输入实验     
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/

 int main(void)
 {
 
	delay_init();	    	 //延时函数初始化	  
	LED_Init();		  		//初始化与LED连接的硬件接口
	BEEP_Init();         	//初始化蜂鸣器端口
	KEY_Init();  	 //初始化与按键连接的硬件接口
	
	delay_ms(500);
	LED0=0;					//先点亮红灯
	
	IWDG_Init(4,625);
	 
	 while(1){
	 if(KEY_Scan(0)==WKUP_PRES){
	 
		 IWDG_ReloadCounter();
	 
	 }
	 }
	
}

