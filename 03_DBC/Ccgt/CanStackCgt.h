/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _CANSTACK_H
#define _CANSTACK_H

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