
/* Includes ------------------------------------------------------------------*/
#include "main.h"


/* Private define-------------------------------------------------------------*/

/* Private variables----------------------------------------------------------*/

static uint16_t mid_filter(uint16_t* adc);  
/* Public variables-----------------------------------------------------------*/


Filter_FUNC Filter = 
{
	mid_filter
};

/* Private function prototypes------------------------------------------------*/      

/*
	* @name   Sys_init
	* @brief  系统初始化
	* @param  None
	* @retval None      
*/
static uint16_t mid_filter(uint16_t* adc)
{	
	uint16_t temp;
	uint8_t j,k;
	
	for(j = 0 ; j < FILTER_NUM-1; ++j)
    {
        for(k = 0; k < FILTER_NUM-j-1; ++k)
        {
            //从小到大排序，冒泡法排序
            if(adc[k] > adc[k+1])
            {
                temp = adc[k];
                adc[k] = adc[k+1];
                adc[k+1] = temp;
            }
        }
    }
		
    return adc[(FILTER_NUM-1)/2];


	
}
/********************************************************
  End Of File
********************************************************/

