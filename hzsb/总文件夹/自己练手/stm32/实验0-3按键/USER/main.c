#include"stm32f10x.h"
#include"delay.h"
#include"led.h"
#include"beep.h"
#include"sys.h"
#include"delay.h"
#include"key.h"
#include"usart.h"	

int main(void)
{
	u8 key; 
  delay_init(); //延时初始化
  LED_Init();
  BEEP_Init(); //初始化蜂鸣器端口
	KEY_Init(); //初始化与按键连接的硬件接口
  LED0=0; //先点亮红灯
while(1){
	
	{
  key=KEY_Scan(0);//得到键值
     if(key)
    {
	    switch(key)
      {
        case WKUP_PRES: //控制蜂鸣器
          BEEP=!BEEP;
          break; 
        case KEY1_PRES: //控制 LED1 翻转
          LED1=!LED1;
          break;
        case KEY0_PRES: //同时控制 LED0,LED1 翻转
          LED0=!LED0;
          LED1=!LED1;
          break;
       }
     }else delay_ms(10); 
    }
}
}

