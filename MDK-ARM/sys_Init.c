/* Includes ------------------------------------------------------------------*/
#include "main.h"


/* Private define-------------------------------------------------------------*/

/* Private variables----------------------------------------------------------*/

static void Sys_running(uint8_t*sta);
static void key_scan(uint8_t*state); 
static void judge_switch(uint8_t*state);  
static void lcd_running(uint8_t*sta);

/* Public variables-----------------------------------------------------------*/
extern uint16_t adc_calc_res;


Hardware_Init_t Hardware_Init = 
{
	Sys_running,
	key_scan,
	judge_switch,
	lcd_running
};

/* Private function prototypes------------------------------------------------*/      

/*
	* @name   Sys_init
	* @brief  系统初始化
	* @param  None
	* @retval None      
*/
static void Sys_running(uint8_t* sta)
{	
	Hardware_Init.key_scan(sta);
	Hardware_Init.judge_switch(sta);
	Hardware_Init.lcd_running(sta);
	Analog_sw_Init.Analog_sw(*sta);
	
	
}
static void key_scan(uint8_t*state){
	#if CODER_EN
	//旋转编码器
	
	#else
	uint8_t tmp = (*state)&0x07;
	if(((*state)&0x80)== 0x00){
	if(HAL_GPIO_ReadPin(CODER_L_GPIO_Port,CODER_L_Pin)== GPIO_PIN_RESET){//暂时写的高电平上拉按键
		HAL_Delay(20);
		if(HAL_GPIO_ReadPin(CODER_L_GPIO_Port,CODER_L_Pin)==GPIO_PIN_RESET){
			
			
			if(tmp>0)
				tmp--;
			(*state) = ((*state) & 0xF8) | tmp;
			
			while(HAL_GPIO_ReadPin(CODER_L_GPIO_Port,CODER_L_Pin)==GPIO_PIN_RESET);
			
		}
	}
	if(HAL_GPIO_ReadPin(CODER_R_GPIO_Port,CODER_R_Pin)==GPIO_PIN_RESET){
		HAL_Delay(20);
		if(HAL_GPIO_ReadPin(CODER_R_GPIO_Port,CODER_R_Pin)==GPIO_PIN_RESET){
			
			tmp++;
			if(tmp>4)
				tmp = 4;
			 (*state) = ((*state) & 0xF8) | tmp;
			
			while(HAL_GPIO_ReadPin(CODER_R_GPIO_Port,CODER_R_Pin)==GPIO_PIN_RESET);
			
		}
	}
//	if(HAL_GPIO_ReadPin(CODER_SET_GPIO_Port,CODER_SET_Pin)==GPIO_PIN_RESET){
//		HAL_Delay(20);
//		if(HAL_GPIO_ReadPin(CODER_SET_GPIO_Port,CODER_SET_Pin)==GPIO_PIN_RESET){
//			
//			 
//			
//			while(HAL_GPIO_ReadPin(CODER_SET_GPIO_Port,CODER_SET_Pin)==GPIO_PIN_RESET);
//			
//		}
//	}

	
	}
	
//		if(HAL_GPIO_ReadPin(AUTO_GPIO_Port,AUTO_Pin)==GPIO_PIN_RESET){
//		HAL_Delay(20);
//		if(HAL_GPIO_ReadPin(AUTO_GPIO_Port,AUTO_Pin)==GPIO_PIN_RESET){
//			if(((*state) & 0x80) == 0x80)
//			 (*state) = 0x00; 
//			else
//			 (*state) = 0x80;
//			while(HAL_GPIO_ReadPin(AUTO_GPIO_Port,AUTO_Pin)==GPIO_PIN_RESET);
//			
//			}
//		}
	
	

	#endif
	

}
static void judge_switch(uint8_t*state){
	uint8_t tmp = 0;
	if(((*state) & 0x80)== 0x80){
		while((adc_calc_res<200)&&(tmp!=4)){
				if(tmp>4)
					tmp = 4;
				tmp++;
			
			Analog_sw_Init.Analog_sw(tmp);
			HAL_Delay(200);
			}
		(*state) = ((*state) & 0xF8) | tmp;
	}
	return;
}

static void lcd_running(uint8_t*state){
	static uint8_t sta_last;
	
	if(((sta_last&0x07) ^ ((*state)&0x07)) != 0)
		Lcd_Clear(WHITE);
	Gui_DrawFont_GBK16(50,0,GREEN,RED,"电压测量");
	Gui_DrawFont_GBK16(30,180,GREEN,RED,"电压");
	LCD_ShowNum(80,180,adc_calc_res,4);
	
	if(((*state) & 0x07) == 0x00)
		Gui_DrawFont_GBK16(30,90,GREEN,RED,"量程20V");
		Gui_DrawFont_GBK16(120,180,GREEN,RED,"V");
	if(((*state) & 0x07) == 0x01)
		Gui_DrawFont_GBK16(30,90,GREEN,RED,"量程2V");
		Gui_DrawFont_GBK16(120,180,GREEN,RED,"V");
	if(((*state) & 0x07) == 0x02)
		Gui_DrawFont_GBK16(30,90,GREEN,RED,"量程200mV");
		Gui_DrawFont_GBK16(120,180,GREEN,RED,"mV");
	if(((*state) & 0x07) == 0x03)
		Gui_DrawFont_GBK16(30,90,GREEN,RED,"量程20mV");
		Gui_DrawFont_GBK16(120,180,GREEN,RED,"mV");
	if(((*state) & 0x07) == 0x04)
		Gui_DrawFont_GBK16(30,90,GREEN,RED,"量程2mV");
		Gui_DrawFont_GBK16(120,180,GREEN,RED,"mV");
	sta_last = (*state) & 0x07;

}
/********************************************************
  End Of File
********************************************************/
