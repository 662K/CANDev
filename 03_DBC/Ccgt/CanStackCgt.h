/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef CANSTACK_H
#define CANSTACK_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include "msgOutPack.h"

/* Tx message Global variables -----------------------------------------------*/
<TxMsgGlobalVariablesDefine>
/* CAN Stack initialization function -----------------------------*/
void CanStackInit(void);

/* Tx message initialization function ----------------------------*/
<TxMsgInitDefine>
#endif