#ifndef __SYS_INIT_H

#define __SYS_INIT_H
#include "stdint.h"
#define CODER_EN 0

typedef struct
{
	
	void (*Sys_running)(uint8_t*sta);
	void (*key_scan)(uint8_t*state); 
	void (*judge_switch)(uint8_t*state);
	void (*lcd_running)(uint8_t*sta); 
} Hardware_Init_t;

/* extern variables-----------------------------------------------------------*/
extern Hardware_Init_t  Hardware_Init;


#endif 

