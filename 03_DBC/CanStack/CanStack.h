/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef CANSTACK_H
#define CANSTACK_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include "msgOutPack.h"

/* Tx message Global variables -----------------------------------------------*/
extern CAN_TxHeaderTypeDef msg_MCU_200h_TxHeader;
extern CAN_TxHeaderTypeDef msg_MCU_201h_TxHeader;

/* CAN Stack initialization function ----------------------------------------*/
void CanStackInit(void);

/* Tx message initialization function ----------------------------------------*/
void msg_MCU_200h_TxHeaderInit(void);
void msg_MCU_201h_TxHeaderInit(void);

#endif