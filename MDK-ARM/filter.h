#ifndef __FILTER_H


#define __FILTER_H

#include "stdint.h"

#define FILTER_NUM 7

typedef struct
{
  uint16_t (*Mid_filter)(uint16_t* adc);	
	
} Filter_FUNC;

/* extern variables-----------------------------------------------------------*/
extern Filter_FUNC  Filter;






#endif 
