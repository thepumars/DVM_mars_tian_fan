/* Includes ------------------------------------------------------------------*/
#include "main.h"


/* Private define-------------------------------------------------------------*/

/* Private variables----------------------------------------------------------*/

static uint16_t voltage_calc(uint16_t data,uint8_t state);
/* Public variables-----------------------------------------------------------*/


Calc_Init Calc = 
{
	voltage_calc
};

/* Private function prototypes------------------------------------------------*/      

/*
	* @name   Sys_init
	* @brief  系统初始化
	* @param  None
	* @retval None      
*/
static uint16_t voltage_calc(uint16_t data,uint8_t state){
//	
//	uint8_t b_dot,a_dot;
	
	data = data * 33 * 10000/ 409600;//用四位数字表示ADC默认电压 161,132.8125例如1.6V
	
	
	if(state)
		;
		//pass
//	if((state & 0x07) == 0x00){
//		b_dot = data/100;
//		a_dot = data%100;
//		
//	}
//	if((state & 0x07) == 0x01){
//		b_dot = data/1000;
//		a_dot = data%1000;
//	}
//	if((state & 0x07) == 0x02){
//		b_dot = data/10;
//		a_dot = data%10;
//		
//	}
//	if((state & 0x07) == 0x03){
//		b_dot = data/100;
//		a_dot = data%100;
//		
//	}
//	if((state & 0x07) == 0x04){
//		
//		b_dot = data/1000;
//		a_dot = data%1000;
//	}
	return data;
	
}

