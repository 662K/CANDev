/* Includes ------------------------------------------------------------------*/
#include "CanStack.h"

/* Global variables -----------------------------------------------*/
CAN_TxHeaderTypeDef msg_MCU_200h_TxHeader;
CAN_TxHeaderTypeDef msg_MCU_201h_TxHeader;
CAN_TxHeaderTypeDef msg_PC_TxHeader;

/* function ------------------------------------------------------------------*/
/**
  * @brief  The initialization function for the Can Stack
  * @retval None
  */
void CanStackInit(void){
  msg_MCU_200h_TxHeaderInit();
  msg_MCU_201h_TxHeaderInit();
  msg_PC_TxHeaderInit();

  msgOutPack_initialize();
}

/**
  * @brief  The initialization function for the MCU_200h Tx message
  * @retval None
  */
void msg_MCU_200h_TxHeaderInit(void){
  msg_MCU_200h_TxHeader.StdId = 0x200;
  msg_MCU_200h_TxHeader.ExtId = 0x0;
  msg_MCU_200h_TxHeader.RTR = CAN_RTR_DATA;
  msg_MCU_200h_TxHeader.IDE = CAN_ID_STD;
  msg_MCU_200h_TxHeader.DLC = 8;
  msg_MCU_200h_TxHeader.TransmitGlobalTime = DISABLE;
}

/**
  * @brief  The initialization function for the MCU_201h Tx message
  * @retval None
  */
void msg_MCU_201h_TxHeaderInit(void){
  msg_MCU_201h_TxHeader.StdId = 0x201;
  msg_MCU_201h_TxHeader.ExtId = 0x0;
  msg_MCU_201h_TxHeader.RTR = CAN_RTR_DATA;
  msg_MCU_201h_TxHeader.IDE = CAN_ID_STD;
  msg_MCU_201h_TxHeader.DLC = 4;
  msg_MCU_201h_TxHeader.TransmitGlobalTime = DISABLE;
}

/**
  * @brief  The initialization function for the PC Tx message
  * @retval None
  */
void msg_PC_TxHeaderInit(void){
  msg_PC_TxHeader.StdId = 0x100;
  msg_PC_TxHeader.ExtId = 0x0;
  msg_PC_TxHeader.RTR = CAN_RTR_DATA;
  msg_PC_TxHeader.IDE = CAN_ID_STD;
  msg_PC_TxHeader.DLC = 8;
  msg_PC_TxHeader.TransmitGlobalTime = DISABLE;
}


