#include "main.h"
#include "stm32f7xx_hal.h"
#include "main_FSM.h"

void ALL_LED_OFF(void);

void LED1_ON(void)
{
  ALL_LED_OFF();
  HAL_GPIO_TogglePin(GPIOI,ARDUINO_D7_Pin);
  //HAL_Delay(180);
}
void LED2_ON(void)
{
  ALL_LED_OFF();
  HAL_GPIO_TogglePin(GPIOI,ARDUINO_D8_Pin);
 // HAL_Delay(180);
}
void ALL_LED_OFF(void)
{
  HAL_GPIO_WritePin(GPIOI,ARDUINO_D7_Pin,GPIO_PIN_RESET);  
  HAL_GPIO_WritePin(GPIOI,ARDUINO_D8_Pin,GPIO_PIN_RESET);
}
