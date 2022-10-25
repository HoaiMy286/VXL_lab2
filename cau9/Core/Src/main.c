/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "cau9_header.h"

/* USER CODE END Includes */

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
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

const int MAX_LED = 4;
int index_led = 0;
int led_buffer [4] = {1 , 2 , 3 , 4};

int hour = 15 , minute = 8 , second = 50;

// LED MATRIX

const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
uint8_t matrix_buffer [8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

void display7SEG(int num)
{
	if (num == 0)
	{
		HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,0);
		HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,0);
		HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,0);
		HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,0);
		HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,0);
		HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,0);
		HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,1);
	}
	if (num == 1)
	{
		HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,1);
		HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,0);
		HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,0);
		HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,1);
		HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,1);
		HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,1);
		HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,1);
	}
	if (num == 2)
	{
		HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,0);
		HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,0);
		HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,1);
		HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,0);
		HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,0);
		HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,1);
		HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,0);
	}
	if (num == 3)
	{
		HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,0);
		HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,0);
		HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,0);
		HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,0);
		HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,1);
		HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,1);
		HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,0);
	}
	if (num == 4)
	{
		HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,1);
		HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,0);
		HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,0);
		HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,1);
		HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,1);
		HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,0);
		HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,0);
	}
	if (num == 5)
	{
		HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,0);
		HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,1);
		HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,0);
		HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,0);
		HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,1);
		HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,0);
		HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,0);
	}
	if (num == 6)
	{
		HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,0);
		HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,1);
		HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,0);
		HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,0);
		HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,0);
		HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,0);
		HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,0);
	}
	if (num == 7)
	{
		HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,0);
		HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,0);
		HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,0);
		HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,1);
		HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,1);
		HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,1);
		HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,1);
	}
	if (num == 8)
	{
		HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,0);
		HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,0);
		HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,0);
		HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,0);
		HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,0);
		HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,0);
		HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,0);
	}
	if (num == 9)
	{
		HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,0);
		HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,0);
		HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,0);
		HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,0);
		HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,1);
		HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,0);
		HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,0);
	}
}

void update7SEG (int index)
{
	switch(index)
	{
		case 0:		// Display the first 7 SEG with led_buffer [0]
			display7SEG(led_buffer [0]);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);	// seg 1 on
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);	// seg 2 off
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);	// seg 3 off
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);	// seg 4 off
			break;
		case 1:		// Display the second 7 SEG with led_buffer [1]
			display7SEG(led_buffer [1]);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);	// seg 1 off
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);	// seg 2 on
			break;
		case 2:		// Display the third 7 SEG with led_buffer [2]
			display7SEG(led_buffer [2]);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);	// seg 2 off
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);	// seg 3 on
			break;
		default:	// Display the forth 7 SEG with led_buffer [3]
			display7SEG(led_buffer [3]);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);	// seg 3 off
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);	// seg 4 on
		break;
	}
}

void updateClockBuffer()
{
	led_buffer [0] = hour/10;
	led_buffer [1] = hour%10;
	led_buffer [2] = minute/10;
	led_buffer [3] = minute%10;
}

void updateLEDMatrix (int index )
{
	switch (index)
	{
		case 0:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, 0);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, 1);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, 1);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, 1);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, 1);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, 1);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, 1);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, 1);

			HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, ((matrix_buffer[0] >> 0)&1));
			HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, ((matrix_buffer[0] >> 1)&1));
			HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, ((matrix_buffer[0] >> 2)&1));
			HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, ((matrix_buffer[0] >> 3)&1));
			HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, ((matrix_buffer[0] >> 4)&1));
			HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, ((matrix_buffer[0] >> 5)&1));
			HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, ((matrix_buffer[0] >> 6)&1));
			HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, ((matrix_buffer[0] >> 7)&1));
			break;
		case 1:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, 1);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, 0);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, 1);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, 1);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, 1);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, 1);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, 1);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, 1);

			HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, ((matrix_buffer[1] >> 0)&1));
			HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, ((matrix_buffer[1] >> 1)&1));
			HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, ((matrix_buffer[1] >> 2)&1));
			HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, ((matrix_buffer[1] >> 3)&1));
			HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, ((matrix_buffer[1] >> 4)&1));
			HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, ((matrix_buffer[1] >> 5)&1));
			HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, ((matrix_buffer[1] >> 6)&1));
			HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, ((matrix_buffer[1] >> 7)&1));
			break;
		case 2:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, 1);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, 1);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, 0);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, 1);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, 1);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, 1);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, 1);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, 1);

			HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, ((matrix_buffer[2] >> 0)&1));
			HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, ((matrix_buffer[2] >> 1)&1));
			HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, ((matrix_buffer[2] >> 2)&1));
			HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, ((matrix_buffer[2] >> 3)&1));
			HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, ((matrix_buffer[2] >> 4)&1));
			HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, ((matrix_buffer[2] >> 5)&1));
			HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, ((matrix_buffer[2] >> 6)&1));
			HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, ((matrix_buffer[2] >> 7)&1));
			break;
		case 3:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, 1);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, 1);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, 1);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, 0);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, 1);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, 1);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, 1);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, 1);

			HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, ((matrix_buffer[3] >> 0)&1));
			HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, ((matrix_buffer[3] >> 1)&1));
			HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, ((matrix_buffer[3] >> 2)&1));
			HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, ((matrix_buffer[3] >> 3)&1));
			HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, ((matrix_buffer[3] >> 4)&1));
			HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, ((matrix_buffer[3] >> 5)&1));
			HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, ((matrix_buffer[3] >> 6)&1));
			HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, ((matrix_buffer[3] >> 7)&1));
			break;
		case 4:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, 1);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, 1);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, 1);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, 1);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, 0);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, 1);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, 1);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, 1);

			HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, ((matrix_buffer[4] >> 0)&1));
			HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, ((matrix_buffer[4] >> 1)&1));
			HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, ((matrix_buffer[4] >> 2)&1));
			HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, ((matrix_buffer[4] >> 3)&1));
			HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, ((matrix_buffer[4] >> 4)&1));
			HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, ((matrix_buffer[4] >> 5)&1));
			HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, ((matrix_buffer[4] >> 6)&1));
			HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, ((matrix_buffer[4] >> 7)&1));
			break;
		case 5:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, 1);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, 1);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, 1);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, 1);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, 1);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, 0);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, 1);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, 1);

			HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, ((matrix_buffer[5] >> 0)&1));
			HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, ((matrix_buffer[5] >> 1)&1));
			HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, ((matrix_buffer[5] >> 2)&1));
			HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, ((matrix_buffer[5] >> 3)&1));
			HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, ((matrix_buffer[5] >> 4)&1));
			HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, ((matrix_buffer[5] >> 5)&1));
			HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, ((matrix_buffer[5] >> 6)&1));
			HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, ((matrix_buffer[5] >> 7)&1));
			break;
		case 6:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, 1);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, 1);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, 1);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, 1);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, 1);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, 1);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, 0);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, 1);

			HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, ((matrix_buffer[6] >> 0)&1));
			HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, ((matrix_buffer[6] >> 1)&1));
			HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, ((matrix_buffer[6] >> 2)&1));
			HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, ((matrix_buffer[6] >> 3)&1));
			HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, ((matrix_buffer[6] >> 4)&1));
			HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, ((matrix_buffer[6] >> 5)&1));
			HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, ((matrix_buffer[6] >> 6)&1));
			HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, ((matrix_buffer[6] >> 7)&1));
			break;
		case 7:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, 1);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, 1);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, 1);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, 1);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, 1);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, 1);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, 1);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, 0);

			HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, ((matrix_buffer[7] >> 0)&1));
			HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, ((matrix_buffer[7] >> 1)&1));
			HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, ((matrix_buffer[7] >> 2)&1));
			HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, ((matrix_buffer[7] >> 3)&1));
			HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, ((matrix_buffer[7] >> 4)&1));
			HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, ((matrix_buffer[7] >> 5)&1));
			HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, ((matrix_buffer[7] >> 6)&1));
			HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, ((matrix_buffer[7] >> 7)&1));
			break;
		default:
			break;
	}
}

void updateLEDMatrixBuffer(char index)
{
	switch(index)
	{
	case 'A':
		matrix_buffer [0] = 0xFF;
		matrix_buffer [1] = 0x01;
		matrix_buffer [2] = 0x00;
		matrix_buffer [3] = 0xCC;
		matrix_buffer [4] = 0xCC;
		matrix_buffer [5] = 0x00;
		matrix_buffer [6] = 0x01;
		matrix_buffer [7] = 0xFF;
		break;

	default:
		break;
	}
}

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
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

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
  /* USER CODE BEGIN 2 */

  HAL_TIM_Base_Start_IT(&htim2);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  timer0_flag = 1;
  timer1_flag = 1;
  timer2_flag = 1;

  while (1)
  {
	  if(timer2_flag == 1)
	  {
		  setTimer2(10);
		  updateLEDMatrixBuffer('A');
		  updateLEDMatrix(index_led_matrix ++);
	  }

	  if(timer1_flag == 1)
	  {
		  setTimer1(1000);
		  second++;

		  if(second >= 60)
		  {
			  second = 0;
			  minute++;
		  }
		  if(minute >= 60)
		  {
			  minute = 0;
			  hour++;
		  }
		  if(hour >= 24)
			  hour = 0;
	  }

	  if(timer0_flag == 1)
	  {
		  setTimer0(500);
		  HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		  HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);

		  updateClockBuffer ();
		  update7SEG(index_led++);
	  }

	  if(index_led == 4)
		  index_led = 0;

	  if(index_led_matrix == 8)
		  index_led_matrix = 0;

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 10;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin|DOT_Pin|LED_RED_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, A_Pin|B_Pin|C_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|D_Pin|E_Pin|F_Pin
                          |G_Pin|ROW0_Pin|ROW1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : ENM0_Pin ENM1_Pin DOT_Pin LED_RED_Pin
                           EN0_Pin EN1_Pin EN2_Pin EN3_Pin
                           ENM2_Pin ENM3_Pin ENM4_Pin ENM5_Pin
                           ENM6_Pin ENM7_Pin */
  GPIO_InitStruct.Pin = ENM0_Pin|ENM1_Pin|DOT_Pin|LED_RED_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : A_Pin B_Pin C_Pin ROW2_Pin
                           ROW3_Pin ROW4_Pin ROW5_Pin ROW6_Pin
                           ROW7_Pin D_Pin E_Pin F_Pin
                           G_Pin ROW0_Pin ROW1_Pin */
  GPIO_InitStruct.Pin = A_Pin|B_Pin|C_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|D_Pin|E_Pin|F_Pin
                          |G_Pin|ROW0_Pin|ROW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

void HAL_TIM_PeriodElapsedCallback (TIM_HandleTypeDef *htim )
{
	timer_run ();
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
