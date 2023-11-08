#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"	 
#include "rs485.h"

 int main(void)
 {	 

	 
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
	uart_init(115200);	 	//串口初始化为115200
	LED_Init();		  		//初始化与LED连接的硬件接口	 	 
	
	RS485_Init(9600);	//初始化RS485
									  
	while(1)
	{
		Send_Data();//发送5个字节
		Receive_Data();
		   
	}
}

void Receive_Data(){
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) 
                       //接收中断(接收到的数据必须是 0x0d 0x0a 结尾)
	{
             Res =USART_ReceiveData(USART1);//(USART1->DR); //读取接收到的数据
              if((USART_RX_STA&0x8000)==0)//接收未完成
				  {
                   if(USART_RX_STA&0x4000)//接收到了 0x0d
					   {
                                  if(Res!=0x0a)USART_RX_STA=0;//接收错误,重新开始
                           else USART_RX_STA|=0x8000; //接收完成了
						    }
                  else //还没收到 0X0D

				  {
                         if(Res==0x0d)USART_RX_STA|=0x4000;
                                   else
									   {
USART_RX_BUF[USART_RX_STA&0X3FFF]=Res ;
USART_RX_STA++;
if(USART_RX_STA>(USART_REC_LEN-1))USART_RX_STA=0;
//接收数据错误,重新开始接收 
}
}
} 
 }
	
	


}