/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
#n
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */
#n
/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;
#n
/* USER CODE BEGIN PV */

/* USER CODE END PV */
#n
/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
#t/* USER CODE BEGIN 1 */

#t/* USER CODE END 1 */
#n
#t/* MCU Configuration--------------------------------------------------------*/
#n#t/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
#tHAL_Init();
#n
#n
#n
#n
#t/* USER CODE BEGIN Init */
#n#t/* USER CODE END Init */
#n
#n#t/* Configure the system clock */
#tSystemClock_Config();
#n
#n
#n
#t/* USER CODE BEGIN SysInit */
#n#t/* USER CODE END SysInit */
#n
#n#t/* Initialize all configured peripherals */
#tMX_GPIO_Init();
#tMX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */
#n
#t/* Infinite loop */
#t/* USER CODE BEGIN WHILE */
#twhile (1)
#t{
#t#t/* USER CODE END WHILE */
#n
#t#t/* USER CODE BEGIN 3 */
#t}
#t/* USER CODE END 3 */
}
#n/**
#t* @brief System Clock Configuration
#t* @retval None
#t*/
void SystemClock_Config(void)
{
#tRCC_OscInitTypeDef RCC_OscInitStruct = {0};
#tRCC_ClkInitTypeDef RCC_ClkInitStruct = {0};#n
#t/** Configure the main internal regulator output voltage #n#t*/
#t__HAL_RCC_PWR_CLK_ENABLE();
#t__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
#t/** Initializes the CPU, AHB and APB busses clocks #n#t*/
#tRCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
#tRCC_OscInitStruct.HSIState = RCC_HSI_ON;
#tRCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
#tRCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
#tRCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
#tRCC_OscInitStruct.PLL.PLLM = 16;
#tRCC_OscInitStruct.PLL.PLLN = 336;
#tRCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
#tRCC_OscInitStruct.PLL.PLLQ = 4;
#tif (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
#t{
#t#tError_Handler();
#t}
#t/** Initializes the CPU, AHB and APB busses clocks #n#t*/
#tRCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK#n#t#t#t#t#t#t#t#t#t#t#t#t#t#t#t|RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
#tRCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
#tRCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
#tRCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
#tRCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
#n
#tif (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
#t{
#t#tError_Handler();
#t}
}


#n
/**
#t* @brief USART2 Initialization Function
#t* @param None
#t* @retval None
#t*/
static void MX_USART2_UART_Init(void)
{
#n
#t/* USER CODE BEGIN USART2_Init 0 */
#n
#t/* USER CODE END USART2_Init 0 */
#n
#n
#n
#t/* USER CODE BEGIN USART2_Init 1 */
#n
#t/* USER CODE END USART2_Init 1 */
#thuart2.Instance = USART2;
#thuart2.Init.BaudRate = 115200;
#thuart2.Init.WordLength = UART_WORDLENGTH_8B;
#thuart2.Init.StopBits = UART_STOPBITS_1;
#thuart2.Init.Parity = UART_PARITY_NONE;
#thuart2.Init.Mode = UART_MODE_TX_RX;
#thuart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
#thuart2.Init.OverSampling = UART_OVERSAMPLING_16;
#tif (HAL_UART_Init(&huart2) != HAL_OK)
#t{
#t#tError_Handler();
#t}
#t/* USER CODE BEGIN USART2_Init 2 */
#n
#t/* USER CODE END USART2_Init 2 */
#n}#n


/**
#t* @brief GPIO Initialization Function
#t* @param None
#t* @retval None
#t*/
static void MX_GPIO_Init(void)
{
#tGPIO_InitTypeDef GPIO_InitStruct = {0};
#n#t/* GPIO Ports Clock Enable */
#t__HAL_RCC_GPIOC_CLK_ENABLE();
#t__HAL_RCC_GPIOH_CLK_ENABLE();
#t__HAL_RCC_GPIOA_CLK_ENABLE();
#t__HAL_RCC_GPIOB_CLK_ENABLE();
#n#t/*Configure GPIO pin Output Level */
#tHAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
#n#t/*Configure GPIO pin : B1_Pin */
#tGPIO_InitStruct.Pin = B1_Pin;
#tGPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
#tGPIO_InitStruct.Pull = GPIO_NOPULL;
#tHAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);
#n#t/*Configure GPIO pin : LD2_Pin */
#tGPIO_InitStruct.Pin = LD2_Pin;
#tGPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
#tGPIO_InitStruct.Pull = GPIO_NOPULL;
#tGPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
#tHAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);
#n
}
#n
 
#n

#n

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */
#n

 
 
/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */



/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
