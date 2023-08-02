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
#include "stm32l1xx_hal.h"

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
#define BT1_Pin GPIO_PIN_0
#define BT1_GPIO_Port GPIOC
#define BT2_Pin GPIO_PIN_1
#define BT2_GPIO_Port GPIOC
#define BT2_EXTI_IRQn EXTI1_IRQn
#define BT3_Pin GPIO_PIN_2
#define BT3_GPIO_Port GPIOC
#define BT3_EXTI_IRQn EXTI2_IRQn
#define BT4_Pin GPIO_PIN_3
#define BT4_GPIO_Port GPIOC
#define BT4_EXTI_IRQn EXTI3_IRQn
#define DTR_Pin GPIO_PIN_1
#define DTR_GPIO_Port GPIOA
#define RI_Pin GPIO_PIN_2
#define RI_GPIO_Port GPIOA
#define BT5_Pin GPIO_PIN_4
#define BT5_GPIO_Port GPIOC
#define BT5_EXTI_IRQn EXTI4_IRQn
#define BT6_Pin GPIO_PIN_5
#define BT6_GPIO_Port GPIOC
#define BT6_EXTI_IRQn EXTI9_5_IRQn
#define PWR_Pin GPIO_PIN_12
#define PWR_GPIO_Port GPIOB
#define RST_SIM_Pin GPIO_PIN_13
#define RST_SIM_GPIO_Port GPIOB
#define FLIGHT_Pin GPIO_PIN_14
#define FLIGHT_GPIO_Port GPIOB
#define PWRKEY_Pin GPIO_PIN_15
#define PWRKEY_GPIO_Port GPIOB
#define BT7_Pin GPIO_PIN_6
#define BT7_GPIO_Port GPIOC
#define BT7_EXTI_IRQn EXTI9_5_IRQn
#define TX_Pin GPIO_PIN_9
#define TX_GPIO_Port GPIOA
#define RX_Pin GPIO_PIN_10
#define RX_GPIO_Port GPIOA
#define DETEC_Pin GPIO_PIN_15
#define DETEC_GPIO_Port GPIOA
#define SDCS_Pin GPIO_PIN_2
#define SDCS_GPIO_Port GPIOD
#define DC_Pin GPIO_PIN_3
#define DC_GPIO_Port GPIOB
#define RST_Pin GPIO_PIN_4
#define RST_GPIO_Port GPIOB
#define BUSY_Pin GPIO_PIN_5
#define BUSY_GPIO_Port GPIOB
#define CS_Pin GPIO_PIN_7
#define CS_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
