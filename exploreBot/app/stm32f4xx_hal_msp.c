/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : stm32f4xx_hal_msp.c
  * Description        : This file provides code for the MSP Initialization 
  *                      and de-Initialization codes.
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */
#n


/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN Define */
 
/* USER CODE END Define */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN Macro */

/* USER CODE END Macro */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* External functions --------------------------------------------------------*/
/* USER CODE BEGIN ExternalFunctions */

/* USER CODE END ExternalFunctions */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */
/**
#t* Initializes the Global MSP.
#t*/
void HAL_MspInit(void)
{
#t/* USER CODE BEGIN MspInit 0 */

#n#t/* USER CODE END MspInit 0 */
#n
#n
#t__HAL_RCC_SYSCFG_CLK_ENABLE();
#t__HAL_RCC_PWR_CLK_ENABLE();
#n
#tHAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_0);#n
#t/* System interrupt init*/
#n
#n
#n
#n
#t/* USER CODE BEGIN MspInit 1 */#n
#t/* USER CODE END MspInit 1 */
}





/**
* @brief UART MSP Initialization
* This function configures the hardware resources used in this example
* @param huart: UART handle pointer
* @retval None
*/#nvoid HAL_UART_MspInit(UART_HandleTypeDef* huart)
{
#tGPIO_InitTypeDef GPIO_InitStruct = {0};
#tif(huart->Instance==USART2)
#t{
#t/* USER CODE BEGIN USART2_MspInit 0 */
#n#t/* USER CODE END USART2_MspInit 0 */
#t#t/* Peripheral clock enable */
#t#t__HAL_RCC_USART2_CLK_ENABLE();
#t
#t#t__HAL_RCC_GPIOA_CLK_ENABLE();
#t#t/**USART2 GPIO Configuration#t#t
#t#tPA2#t#t ------> USART2_TX
#t#tPA3#t#t ------> USART2_RX #n#t#t*/
#t#tGPIO_InitStruct.Pin = USART_TX_Pin|USART_RX_Pin;
#t#tGPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
#t#tGPIO_InitStruct.Pull = GPIO_NOPULL;
#t#tGPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
#t#tGPIO_InitStruct.Alternate = GPIO_AF7_USART2;
#t#tHAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
#n
#t/* USER CODE BEGIN USART2_MspInit 1 */
#n#t/* USER CODE END USART2_MspInit 1 */
#t}
#n}#n
/**
* @brief UART MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param huart: UART handle pointer
* @retval None
*/#nvoid HAL_UART_MspDeInit(UART_HandleTypeDef* huart)
{
#tif(huart->Instance==USART2)
#t{
#t/* USER CODE BEGIN USART2_MspDeInit 0 */
#n#t/* USER CODE END USART2_MspDeInit 0 */
#t#t/* Peripheral clock disable */
#t#t__HAL_RCC_USART2_CLK_DISABLE();
#t
#t#t/**USART2 GPIO Configuration#t#t
#t#tPA2#t#t ------> USART2_TX
#t#tPA3#t#t ------> USART2_RX #n#t#t*/
#t#tHAL_GPIO_DeInit(GPIOA, USART_TX_Pin|USART_RX_Pin);
#n
#t/* USER CODE BEGIN USART2_MspDeInit 1 */
#n#t/* USER CODE END USART2_MspDeInit 1 */
#t}
#n}#n#n



/* USER CODE BEGIN 1 */

/* USER CODE END 1 */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
