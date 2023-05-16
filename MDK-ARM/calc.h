#ifndef __CALC_H


#define __CALC_H
#include "stdint.h"

typedef struct
{
	
	uint16_t (*voltage_calc)(uint16_t data,uint8_t state);

} Calc_Init;

/* extern variables-----------------------------------------------------------*/
extern Calc_Init  Calc;

#endif
