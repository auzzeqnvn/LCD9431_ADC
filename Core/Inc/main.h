/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f2xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
#define HC595_OE_Pin GPIO_PIN_2
#define HC595_OE_GPIO_Port GPIOE
#define HC595_RCLK_Pin GPIO_PIN_3
#define HC595_RCLK_GPIO_Port GPIOE
#define HC595_SCLK_Pin GPIO_PIN_4
#define HC595_SCLK_GPIO_Port GPIOE
#define HC595_DATA_Pin GPIO_PIN_5
#define HC595_DATA_GPIO_Port GPIOE
#define BUTTON1_Pin GPIO_PIN_0
#define BUTTON1_GPIO_Port GPIOC
#define BUTTON2_Pin GPIO_PIN_1
#define BUTTON2_GPIO_Port GPIOC
#define BUTTON3_Pin GPIO_PIN_2
#define BUTTON3_GPIO_Port GPIOC
#define BUTTON4_Pin GPIO_PIN_3
#define BUTTON4_GPIO_Port GPIOC
#define BUTTON5_Pin GPIO_PIN_0
#define BUTTON5_GPIO_Port GPIOA
#define BUTTON6_Pin GPIO_PIN_1
#define BUTTON6_GPIO_Port GPIOA
#define BUTTON7_Pin GPIO_PIN_2
#define BUTTON7_GPIO_Port GPIOA
#define BUTTON8_Pin GPIO_PIN_3
#define BUTTON8_GPIO_Port GPIOA
#define LED_Pin GPIO_PIN_0
#define LED_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
