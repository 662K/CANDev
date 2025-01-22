/* Includes ------------------------------------------------------------------*/
#include "CanStack.h"

/* Tx message Global variables -----------------------------------------------*/
<TxMsgGlobalVariablesDefine>
/* CAN Stack initialization function ----------------------------------------*/
/**
  * @brief  The initialization function for the Can Stack
  * @retval None
  */
void CanStackInit(void){
<TxMsgInitCall>
  msgOutPack_initialize();
}

/* Tx message initialization function ----------------------------------------*/
<TxMsgInitDefine>
