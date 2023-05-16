#ifndef __ANALOG_SW_H

#define __ANALOG_SW_H

#include "stdint.h"
typedef struct
{
  void (*Analog_sw)(uint8_t sta);	
	
} Analog_sw_Init_t;

/* extern variables-----------------------------------------------------------*/
extern Analog_sw_Init_t  Analog_sw_Init;


#endif 

