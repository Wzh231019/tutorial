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
  BEEP_Init(); //³õÊ¼»¯·äÃùÆ÷¶Ë¿Ú
	
while(1){
	
	GPIOB->ODR|=(1<<5);
	GPIOE->ODR|=(1<<5);
	BEEP=0; //¹Ø±Õ·äÃùÆ÷
	delay_ms(300);
	
	GPIOB->ODR=~(1<<5);
	GPIOE->ODR=~(1<<5);
	BEEP=1; //´ò¿ª·äÃùÆ÷
	delay_ms(300);
	
}	

}


