/* Includes ------------------------------------------------------------------*/
#include "main.h"


/* Private define-------------------------------------------------------------*/

/* Private variables----------------------------------------------------------*/

static void Analog_sw(uint8_t sta);	
/* Public variables-----------------------------------------------------------*/


Analog_sw_Init_t  Analog_sw_Init = 
{
	Analog_sw
};

/* Private function prototypes------------------------------------------------*/      

/*
	* @name   Sys_init
	* @brief  系统初始化
	* @param  None
	* @retval None      
*/
static void Analog_sw(uint8_t sta)
{	
	if((sta & 0x07) == 0x00){// 2- 20
		AmA0_SET;
		AmA1_RESET;
		DcA0_RESET;
		DcA1_RESET;
	}
	else if((sta & 0x07) == 0x01){
		AmA0_RESET;
		AmA1_RESET;
		DcA0_RESET;
		DcA1_RESET;
	}
	else if((sta & 0x07) == 0x02){
		AmA0_RESET;
		AmA1_RESET;
		DcA0_SET;
		DcA1_RESET;
	}
	else if((sta & 0x07) == 0x03){
		AmA0_RESET;
		AmA1_RESET;
		DcA0_RESET;
		DcA1_SET;
	}
	else if((sta & 0x07) == 0x04){
		AmA0_RESET;
		AmA1_RESET;
		DcA0_SET;
		DcA1_SET;
	}
}
/********************************************************
  End Of File
********************************************************/
