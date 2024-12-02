#include "Timer.h"

void Bsw_Task_1ms(void){
  static uint16_t Bsw_TIM_uCnt1s = 0U;

  if(Bsw_TIM_uCnt1s < 999U){
    Bsw_TIM_uCnt1s++;
  }
  else{
    Bsw_TIM_uCnt1s = 0U;
  }

  if(Bsw_TIM_uCnt1s % 10U == 0U){
    Bsw_Task_10ms();
  }

  if(Bsw_TIM_uCnt1s % 100U == 0U){
    Bsw_Task_100ms();
  }

  if(Bsw_TIM_uCnt1s == 0U){
    Bsw_Task_1s();
  }  
}

void Bsw_Task_10ms(void){
  static uint8_t LED_State = 0U;
  if (LED_State){
    LED_State = 0U;
    LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_10);
  }
  else{
    LED_State = 1U;
    LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_10);
  }
}

void Bsw_Task_100ms(void){

}

void Bsw_Task_1s(void){
  static uint8_t LED_State = 0U;
  if (LED_State){
    LED_State = 0U;
    LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_11);
  }
  else{
    LED_State = 1U;
    LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_11);
  }
}