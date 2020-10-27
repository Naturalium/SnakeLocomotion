/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_hal.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* USER CODE BEGIN Includes */
uint8_t ch;
uint8_t gh[10];
int st = 0;

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
void tail(int val1) //////////////// 70 for straight
      {
        TIM2->CCR2 = val1;
        HAL_Delay(100);
        TIM2->CCR2 = 0;
      }
      void body3(int val2)
      {
        TIM3->CCR1 = val2;
        HAL_Delay(100);
        TIM3->CCR1 = 0;
      }
      void body2(int val3)
      {
        TIM3->CCR2 = val3;
        HAL_Delay(100);
        TIM3->CCR2 = 0;
      }
      void body1(int val4)
      {
        TIM4->CCR1 = val4;
        HAL_Delay(100);
        TIM4->CCR1 = 0;
      }
      void head(int val5)
      {
        TIM4->CCR2 = val5;
        HAL_Delay(100);
        TIM4->CCR2 = 0;
      }

void rightmotion()
        {
          body1(90);
          body3(90);
          tail(90);
          head(50);
          body2(50);
          body1(50);
          body3(50);
        }
void leftmotion()
{
  body1(50);
          body3(50);
          tail(50);
          head(90);
          body2(90);
          body1(90);
          body3(90);
}
void ongoing()
{
  body1(90);
  HAL_Delay(100);
  body3(90);
  HAL_Delay(100);
  body1(50);
  body2(90);
  HAL_Delay(100);
  body2(50);
  HAL_Delay(100);
  //tail(90);
  body3(50);
  head(90);
HAL_Delay(100);
head(50);
HAL_Delay(100);
  //tail(70);  
}
void nothing()
{
  body1(70);
          body3(70);
          tail(70);
          body2(70);
          head(70);
}

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  HAL_TIM_Base_Start(&htim2);
  HAL_TIM_Base_Start(&htim3);
  HAL_TIM_Base_Start(&htim4);
  HAL_TIM_OC_Start(&htim2, TIM_CHANNEL_2); 
  HAL_TIM_OC_Start(&htim3, TIM_CHANNEL_1);
  HAL_TIM_OC_Start(&htim3, TIM_CHANNEL_2);
  HAL_TIM_OC_Start(&htim4, TIM_CHANNEL_1);
  HAL_TIM_OC_Start(&htim4, TIM_CHANNEL_2); 
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
  MX_USART1_UART_Init();
  MX_USART3_UART_Init();
  HAL_UART_Transmit(&huart3, "AT", 10, 1);
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  
  while (0)
  {
    while(!(USART3->SR & UART_FLAG_TXE));
    while(!(USART3->SR & UART_FLAG_RXNE));
    HAL_UART_Receive(&huart3, gh, 9, 100);
    if(gh[0] == 'm' && gh[1] == '1')
    {
      //uint8_t gh[10] = 0;
      HAL_UART_Transmit(&huart3, "then?", 5, 100);
      while(!(USART3->SR & UART_FLAG_TXE));
      while(!(USART3->SR & UART_FLAG_RXNE));
      HAL_UART_Receive(&huart3, gh, 9, 100);
      if(gh[0] == '1')
      {
        st=0;
        TIM2->CCR2 = 20;
      }
      else if(gh[0] == '2')
      {
        st=1;
        TIM2->CCR2 = 30;
      }
      else if(gh[0] == '3')
      {
        st=2;
        TIM2->CCR2 = 40;
      }
      else if(gh[0] == '4')
      {
        st=3;
        TIM2->CCR2 = 50;
      }
      else if(gh[0] == '5')
      {
        st=4;
        TIM2->CCR2 = 60;
      }
      else if(gh[0] == '6')
      {
        st=5;
        TIM2->CCR2 = 70;
      }
      else if(gh[0] == '7')
      {
        st=6;
        TIM2->CCR2 = 80;
      }
      else if(gh[0] == '8')
      {
        st=7;
        TIM2->CCR2 = 90;
      }
    }
    else if(gh[0] == 'm' && gh[1] == '2')
    {
      //uint8_t gh[10] = 0;
      HAL_UART_Transmit(&huart3, "then?", 5, 100);
      while(!(USART3->SR & UART_FLAG_TXE));
      while(!(USART3->SR & UART_FLAG_RXNE));
      HAL_UART_Receive(&huart3, gh, 9, 100);
      if(gh[0] == '1')
      {
        st=8;
        TIM3->CCR1 = 20;
      }
      else if(gh[0] == '2')
      {
        st=9;
        TIM3->CCR1 = 30;
      }
      else if(gh[0] == '3')
      {st=10;
        TIM3->CCR1 = 40;
      }
      else if(gh[0] == '4')
      {
        st=11;
        TIM3->CCR1 = 50;
      }
      else if(gh[0] == '5')
      {
        st=12;
        TIM3->CCR1 = 60;
      }
      else if(gh[0] == '6')
      {st=13;
        TIM3->CCR1 = 70;
      }
      else if(gh[0] == '7')
      {
        st=14;
        TIM3->CCR1 = 80;
      }
      else if(gh[0] == '8')
      {st=15;
        TIM3->CCR1 = 90;
      }
    }
    else if(gh[0] == 'm' && gh[1] == '3')
    {
      //uint8_t gh[10] = 0;
      HAL_UART_Transmit(&huart3, "then?", 5, 100);
      while(!(USART3->SR & UART_FLAG_TXE));
      while(!(USART3->SR & UART_FLAG_RXNE));
      HAL_UART_Receive(&huart3, gh, 9, 100);
      if(gh[0] == '1')
      {st=16;
        TIM3->CCR2 = 20;
      }
      else if(gh[0] == '2')
      {
        st=17;
        TIM3->CCR2 = 30;
      }
      else if(gh[0] == '3')
      {st=18;
        TIM3->CCR2 = 40;
      }
      else if(gh[0] == '4')
      {st=19;
        TIM3->CCR2 = 50;
      }
      else if(gh[0] == '5')
      {st=20;
        TIM3->CCR2 = 60;
      }
      else if(gh[0] == '6')
      {st=21;
        TIM3->CCR2 = 70;
      }
      else if(gh[0] == '7')
      {st=22;
        TIM3->CCR2 = 80;
      }
      else if(gh[0] == '8')
      {st=23;
        TIM3->CCR2 = 90;
      }
    }
    else if(gh[0] == 'm' && gh[1] == '4')
    {
      //uint8_t gh[10] = 0;
      HAL_UART_Transmit(&huart3, "then?", 5, 100);
      while(!(USART3->SR & UART_FLAG_TXE));
      while(!(USART3->SR & UART_FLAG_RXNE));
      HAL_UART_Receive(&huart3, gh, 9, 100);
      if(gh[0] == '1')
      {st=24;
        TIM4->CCR1 = 20;
      }
      else if(gh[0] == '2')
      {st=25;
        TIM4->CCR1 = 30;
      }
      else if(gh[0] == '3')
      {st=26;
        TIM4->CCR1 = 40;
      }
      else if(gh[0] == '4')
      {st=27;
        TIM4->CCR1 = 50;
      }
      else if(gh[0] == '5')
      {st=28;
        TIM4->CCR1 = 60;
      }
      else if(gh[0] == '6')
      {st=29;
        TIM4->CCR1 = 70;
      }
      else if(gh[0] == '7')
      {st=30;
        TIM4->CCR1 = 80;
      }
      else if(gh[0] == '8')
      {st=31;
        TIM4->CCR1 = 90;
      }
    }
    else if(gh[0] == 'm' && gh[1] == '5')
    {
      //uint8_t gh[10] = 0;
      HAL_UART_Transmit(&huart3, "then?", 5, 100);
      while(!(USART3->SR & UART_FLAG_TXE));
      while(!(USART3->SR & UART_FLAG_RXNE));
      HAL_UART_Receive(&huart3, gh, 9, 100);
      if(gh[0] == '1')
      {st=32;
        TIM4->CCR2 = 20;
      }
      else if(gh[0] == '2')
      {st=33;
        TIM4->CCR2 = 30;
      }
      else if(gh[0] == '3')
      {st=34;
        TIM4->CCR2 = 40;
      }
      else if(gh[0] == '4')
      {st=35;
        TIM4->CCR2 = 50;
      }
      else if(gh[0] == '5')
      {st=36;
        TIM4->CCR2 = 60;
      }
      else if(gh[0] == '6')
      {st=37;
        TIM4->CCR2 = 70;
      }
      else if(gh[0] == '7')
      {st=38;
        TIM4->CCR2 = 80;
      }
      else if(gh[0] == '8')
      {st=39;
        TIM4->CCR2 = 90;
      }
    }
  
  /* USER CODE END WHILE */
    /*
    TIM2->CCR2 = 55;
    TIM3->CCR1 = 55;
    TIM3->CCR2 = 55;
    TIM4->CCR1 = 55;
    TIM4->CCR2 = 55;
    HAL_Delay(1000);
    */
  /* USER CODE BEGIN 3 */
 HAL_UART_Transmit(&huart3, "OK", 2, 100);
 uint8_t gh[10] = 0;
 
 while(1)
 {
 if(st / 8 == 0)
 {
   TIM2->CCR2 = (int)((st % 8) * 10 +20);
   HAL_Delay(1000);
 }
 else if(st / 8 == 1)
 {
   TIM3->CCR1 = (int)((st % 8) * 10+20);
   HAL_Delay(1000);
 } 
 else if(st / 8 == 2)
 {
   TIM3->CCR2 = (int)((st % 8) * 10+20);
   HAL_Delay(1000);
 }
 else if(st / 8 == 3)
 {
   TIM4->CCR1 = (int)((st % 8) * 10+20);
   HAL_Delay(1000);
 }
 else if(st / 8 == 4)
 {
   TIM4->CCR2 = (int)((st % 8) * 10+20);
   HAL_Delay(1000);
 }
 
      if(!(USART3->SR & UART_FLAG_RXNE));
 {
      HAL_UART_Transmit(&huart3, "RESTART", 2, 100);
      break;
 }
 }
 
  }
  /* USER CODE END 3 */
 ///////////////////////////////////////////////////
  TIM2->CCR2 = 70;
  HAL_Delay(500);
  TIM2->CCR2 = 0;
      TIM3->CCR1 = 70;
      HAL_Delay(500);
      TIM3->CCR1 = 0;
      TIM3->CCR2 = 70;
      HAL_Delay(500);
      TIM3->CCR2 = 0;
      TIM4->CCR1 = 70;
      HAL_Delay(500);
      TIM4->CCR1 = 0;
      TIM4->CCR2 = 70;
      HAL_Delay(500);
      TIM4->CCR2 = 0;
      
  while(1)
  {
    
    HAL_Delay(2000);
    
      while(1)
      {
        ongoing();
        /*
      TIM2->CCR2 = 90;
      HAL_Delay(400);
      TIM2->CCR2 = 0;
      TIM3->CCR1 = 50;
      HAL_Delay(400);
      
      TIM3->CCR1 = 0;
      TIM3->CCR2 = 90;
      HAL_Delay(400);
      TIM3->CCR2 = 0;
      TIM4->CCR1 = 50;
      HAL_Delay(400);
      TIM4->CCR1 = 0;
      
      TIM4->CCR2 = 90;
      HAL_Delay(400);
      TIM4->CCR2 = 0;
      
      TIM2->CCR2 = 50;
      HAL_Delay(400);
      TIM2->CCR2 = 0;
      TIM3->CCR1 = 90;
      HAL_Delay(400);
      TIM3->CCR1 = 0;
      
      TIM3->CCR2 = 50;
      HAL_Delay(400);
      
      TIM3->CCR2 = 0;
      TIM4->CCR1 = 90;
      HAL_Delay(400);
      TIM4->CCR1 = 0;
      TIM4->CCR2 = 50;
      HAL_Delay(400);
      TIM4->CCR2 = 0;
      HAL_Delay(400);
      */
    }
    
    if(gh[0] == 'd' && gh[1] == 'o' && gh[2] == 'w' && gh[3] == 'n')
    {
      TIM2->CCR2 = 50;
      TIM3->CCR1 = 90;
      TIM3->CCR2 = 50;
      TIM4->CCR1 = 90;
      TIM4->CCR2 = 50;
      HAL_Delay(800);
      TIM2->CCR2 = 90;
      TIM3->CCR1 = 50;
      TIM3->CCR2 = 90;
      TIM4->CCR1 = 50;
      TIM4->CCR2 = 90;
    }
    else if(gh[0] == 's' && gh[1] == 't' && gh[2] == 'o' && gh[3] == 'p')
    {
      TIM2->CCR2 = 0;
      TIM3->CCR1 = 0;
      TIM3->CCR2 = 0;
      TIM4->CCR1 = 0;
      TIM4->CCR2 = 0;
    }
    HAL_UART_Transmit(&huart1, gh, 9, 100);
    while(!(USART1->SR & UART_FLAG_TC));
  }
  
}


/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void _Error_Handler(char * file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler_Debug */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
