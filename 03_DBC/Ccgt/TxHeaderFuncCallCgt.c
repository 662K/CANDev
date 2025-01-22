/**
  * @brief  The initialization function for the <TxMsgName> Tx message
  * @retval None
  */
void msg_<TxMsgName>_TxHeaderInit(void){
  msg_<TxMsgName>_TxHeader.StdId = <TxMsgStdID>;
  msg_<TxMsgName>_TxHeader.ExtId = <TxMsgExtID>;
  msg_<TxMsgName>_TxHeader.RTR = CAN_RTR_DATA;
  msg_<TxMsgName>_TxHeader.IDE = CAN_ID_STD;
  msg_<TxMsgName>_TxHeader.DLC = <TxMsgDLC>;
  msg_<TxMsgName>_TxHeader.TransmitGlobalTime = DISABLE;
}