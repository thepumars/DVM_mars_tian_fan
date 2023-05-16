/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usart_putc.h"
#include "sys_init.h"
#include "stdio.h"
#include "filter.h"
#include "stdint.h"
#include "Analog_sw.h"
#include "calc.h"
#include "lcd.h"
#include "LCDAPI.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define AmA0_Pin GPIO_PIN_3
#define AmA0_GPIO_Port GPIOA
#define AmA1_Pin GPIO_PIN_4
#define AmA1_GPIO_Port GPIOA
#define DcA0_Pin GPIO_PIN_5
#define DcA0_GPIO_Port GPIOA
#define DcA1_Pin GPIO_PIN_6
#define DcA1_GPIO_Port GPIOA
#define CODER_L_Pin GPIO_PIN_7
#define CODER_L_GPIO_Port GPIOA
#define CODER_R_Pin GPIO_PIN_0
#define CODER_R_GPIO_Port GPIOB
#define CODER_SET_Pin GPIO_PIN_1
#define CODER_SET_GPIO_Port GPIOB
#define AUTO_Pin GPIO_PIN_11
#define AUTO_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */
#define AmA0_SET HAL_GPIO_WritePin(AmA0_GPIO_Port,AmA0_Pin,GPIO_PIN_SET);
#define	AmA1_SET HAL_GPIO_WritePin(AmA1_GPIO_Port,AmA1_Pin,GPIO_PIN_SET);
#define	DcA0_SET HAL_GPIO_WritePin(DcA0_GPIO_Port,DcA0_Pin,GPIO_PIN_SET);
#define	DcA1_SET HAL_GPIO_WritePin(DcA1_GPIO_Port,DcA1_Pin,GPIO_PIN_SET);
#define AmA0_RESET HAL_GPIO_WritePin(AmA0_GPIO_Port,AmA0_Pin,GPIO_PIN_RESET);
#define	AmA1_RESET HAL_GPIO_WritePin(AmA1_GPIO_Port,AmA1_Pin,GPIO_PIN_RESET);
#define	DcA0_RESET HAL_GPIO_WritePin(DcA0_GPIO_Port,DcA0_Pin,GPIO_PIN_RESET);
#define	DcA1_RESET HAL_GPIO_WritePin(DcA1_GPIO_Port,DcA1_Pin,GPIO_PIN_RESET);
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
