/* Includes ------------------------------------------------------------------*/
#include "CanStack.h"

/* Tx message Global variables -----------------------------------------------*/
CAN_TxHeaderTypeDef msg_MCU_200h_TxHeader;

/* CAN Stack initialization function ----------------------------------------*/
void CanStackInit(void){
  msg_MCU_200h_TxHeaderInit();

}

/* Tx message initialization function ----------------------------------------*/
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
