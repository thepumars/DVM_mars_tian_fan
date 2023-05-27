/* Includes ------------------------------------------------------------------*/
#include "main.h"


/* Private define-------------------------------------------------------------*/
#define CORRECT_ERR 1600 //即附带的漂移电压1.6V
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
		//pass
	if((state & 0x07) == 0x00){
		data = data * 33 * 10000/409600-1600;//用四位数字表示ADC默认电压 161,132.8125例如1.6V
	}
	else if((state & 0x07) == 0x01){
		data = data * 33 * 10000/409600-1600;//用四位数字表示ADC默认电压 161,132.8125例如1.6V
	}
	else if((state & 0x07) == 0x02){
		data = data * 33 * 10000/409600-1600;//用四位数字表示ADC默认电压 161,132.8125例如1.6V
	}
	else if((state & 0x07) == 0x03){
		data = data * 33 * 10000/409600-1600;//用四位数字表示ADC默认电压 161,132.8125例如1.6V
	}

	return data;
	
}

