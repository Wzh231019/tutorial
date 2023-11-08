#include"beep.h"
void BEEP_Init(void){
	RCC->APB2ENR|=1<<3;
	
	GPIOB->CRH&=0xFFFFFFF0;
	GPIOB->CRH|=0x00000003;
	BEEP = 0;


}
