#ifndef __LED_H
#define __LED_H
#include"sys.h"
void LED_Init(void);

#define LED0 PBout(5)// DS0
#define LED1 PEout(5)// DS1

#endif