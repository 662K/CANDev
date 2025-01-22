typedef struct {
  uint8 MCU_CtrlMode
  float MCU_CurPhsARms
  float MCU_CurPhsBRms
  float MCU_CurPhsCRms
  float MCU_CurPhsD
  float MCU_CurPhsQ
  float MCU_Vdc
} msg_MCU_200h_TypeDef;

typedef struct {
  uint16 MCU_CpuLoad
  float MCU_Task10msLoad
} msg_MCU_201h_TypeDef;

