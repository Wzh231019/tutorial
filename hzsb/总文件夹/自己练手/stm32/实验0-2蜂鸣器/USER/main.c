#include"stm32f10x.h"
#include"delay.h"
#include"led.h"
#include"beep.h"
#include"sys.h"
#include"delay.h"
int main(void)
{
	delay_init(); 
  LED_Init();
  BEEP_Init(); //��ʼ���������˿�
	
while(1){
	
	GPIOB->ODR|=(1<<5);
	GPIOE->ODR|=(1<<5);
	BEEP=0; //�رշ�����
	delay_ms(300);
	
	GPIOB->ODR=~(1<<5);
	GPIOE->ODR=~(1<<5);
	BEEP=1; //�򿪷�����
	delay_ms(300);
	
}	

}


