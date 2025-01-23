/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _CANMSGVAR_H
#define _CANMSGVAR_H
/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
/* Struct Define -------------------------------------------------------------*/
typedef struct {
  uint8_t  MCU_CtrlMode;
  float    MCU_CurPhsARms;
  float    MCU_CurPhsBRms;
  float    MCU_CurPhsCRms;
  float    MCU_CurPhsD;
  float    MCU_CurPhsQ;
  float    MCU_Vdc;
} msg_MCU_200h_TypeDef;

typedef struct {
  uint16_t MCU_CpuLoad;
  float    MCU_Task10msLoad;
} msg_MCU_201h_TypeDef;

/* Global variables ----------------------------------------------------------*/
extern msg_MCU_200h_TypeDef msg_MCU_200h;
extern msg_MCU_201h_TypeDef msg_MCU_201h;

#endif