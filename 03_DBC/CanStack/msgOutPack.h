/*
 * File: msgOutPack.h
 *
 * Code generated for Simulink model 'msgOutPack'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Sun Dec 29 23:17:06 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef msgOutPack_h_
#define msgOutPack_h_
#ifndef msgOutPack_COMMON_INCLUDES_
#define msgOutPack_COMMON_INCLUDES_
#include <math.h>
#include "rtwtypes.h"
#endif                                 /* msgOutPack_COMMON_INCLUDES_ */

#include "msgOutPack_types.h"
#include "can_message.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int_T Mcu0x200Pack_ModeSignalID;     /* '<Root>/Mcu0x200Pack' */
} DW_msgOutPack_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: Constant_Value
   * Referenced by: '<Root>/Constant'
   */
  uint8_T Constant_Value;
} ConstP_msgOutPack_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  CAN_DATATYPE msgMcu0x200;            /* '<Root>/msgMcu0x200' */
} ExtY_msgOutPack_T;

/* Real-time Model Data Structure */
struct tag_RTM_msgOutPack_T {
  const char_T * volatile errorStatus;
};

extern CAN_DATATYPE CAN_DATATYPE_GROUND;

/* Block states (default storage) */
extern DW_msgOutPack_T msgOutPack_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_msgOutPack_T msgOutPack_Y;

/* Constant parameters (default storage) */
extern const ConstP_msgOutPack_T msgOutPack_ConstP;

/* Model entry point functions */
extern void msgOutPack_initialize(void);
extern void msgOutPack_step(void);
extern void msgOutPack_terminate(void);

/* Real-time Model object */
extern RT_MODEL_msgOutPack_T *const msgOutPack_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'msgOutPack'
 */
#endif                                 /* msgOutPack_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
