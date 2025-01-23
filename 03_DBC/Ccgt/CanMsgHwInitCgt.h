/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _CANMSGHWINIT_H
#define _CANMSGHWINIT_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Tx message initialization function ----------------------------*/
void msg_MCU_200h_TxHeaderInit(void);
void msg_MCU_201h_TxHeaderInit(void);

#endif