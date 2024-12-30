#include "Timer.h"
#include "can.h"
#include "CanStack.h"

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
  uint8_t        TxData[4];
  uint32_t       TxMailbox;
  uint16_t       TaskStratTm;
  uint16_t       TaskEndTm;
  uint32_t       CpuLoad;
  static uint16_t TaskUseTm;

  TaskStratTm = TIM1->CNT;

  msgOutPack_step();

  HAL_CAN_AddTxMessage(&hcan, &msg_MCU_200h_TxHeader, msgOutPack_Y.msgMcu0x200.Data, &TxMailbox);

  CpuLoad = 1000 * TaskUseTm / (TIM1->ARR + 1);

  TaskEndTm = CpuLoad;

  TxData[3] = TaskEndTm & 0xFF;
  TxData[2] = TaskEndTm >> 8;
  TxData[1] = TaskUseTm & 0xFF;
  TxData[0] = TaskUseTm >> 8;

  HAL_CAN_AddTxMessage(&hcan, &msg_MCU_201h_TxHeader, TxData, &TxMailbox);

  TaskEndTm = TIM1->CNT;
  TaskUseTm = TaskEndTm - TaskStratTm;
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