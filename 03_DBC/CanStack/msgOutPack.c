/*
 * File: msgOutPack.c
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

#include "msgOutPack.h"
#include "rtwtypes.h"

/* Block states (default storage) */
DW_msgOutPack_T msgOutPack_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_msgOutPack_T msgOutPack_Y;

/* Real-time model */
static RT_MODEL_msgOutPack_T msgOutPack_M_;
RT_MODEL_msgOutPack_T *const msgOutPack_M = &msgOutPack_M_;

/* Model step function */
void msgOutPack_step(void)
{
  /* S-Function (scanpack): '<Root>/Mcu0x200Pack' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   *  Constant: '<Root>/Constant6'
   *  Outport: '<Root>/msgMcu0x200'
   */
  /* S-Function (scanpack): '<Root>/Mcu0x200Pack' */
  msgOutPack_Y.msgMcu0x200.ID = 512U;
  msgOutPack_Y.msgMcu0x200.Length = 8U;
  msgOutPack_Y.msgMcu0x200.Extended = 0U;
  msgOutPack_Y.msgMcu0x200.Remote = 0;
  msgOutPack_Y.msgMcu0x200.Data[0] = 0;
  msgOutPack_Y.msgMcu0x200.Data[1] = 0;
  msgOutPack_Y.msgMcu0x200.Data[2] = 0;
  msgOutPack_Y.msgMcu0x200.Data[3] = 0;
  msgOutPack_Y.msgMcu0x200.Data[4] = 0;
  msgOutPack_Y.msgMcu0x200.Data[5] = 0;
  msgOutPack_Y.msgMcu0x200.Data[6] = 0;
  msgOutPack_Y.msgMcu0x200.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 56
     *  length                  = 4
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (((uint8_T)1U));

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(15)) {
          packedValue = (uint8_T) 15;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            msgOutPack_Y.msgMcu0x200.Data[7] = msgOutPack_Y.msgMcu0x200.Data[7] |
              (uint8_T)((uint8_T)(packedValue & (uint8_T)0xFU));
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 14
     *  length                  = 10
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = SIGNED
     *  factor                  = 0.01
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = 0.76F;

        /* no offset to apply */
        result = result * (1 / 0.01F);

        /* round to closest integer value for integer CAN signal */
        outValue = (result);
      }

      {
        int16_T packedValue;
        int32_T scaledValue;

        if (scaledValue > (int32_T) (511)) {
          packedValue = 511;
        } else if (scaledValue < (int32_T)((-(511)-1))) {
          packedValue = (-(511)-1);
        } else {
          packedValue = (int16_T) (scaledValue);
        }

        {
          uint16_T* tempValuePtr = (uint16_T*)&packedValue;
          uint16_T tempValue = *tempValuePtr;

          {
            msgOutPack_Y.msgMcu0x200.Data[1] = msgOutPack_Y.msgMcu0x200.Data[1] |
              (uint8_T)((uint16_T)((uint16_T)(tempValue & (uint16_T)0x3U) << 6));
            msgOutPack_Y.msgMcu0x200.Data[0] = msgOutPack_Y.msgMcu0x200.Data[0] |
              (uint8_T)((uint16_T)((uint16_T)(tempValue & (uint16_T)0x3FCU) >> 2));
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 20
     *  length                  = 10
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = SIGNED
     *  factor                  = 0.01
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = 1.35F;

        /* no offset to apply */
        result = result * (1 / 0.01F);

        /* round to closest integer value for integer CAN signal */
        outValue = result;
      }

      {
        int16_T packedValue;
        int32_T scaledValue;

        if (scaledValue > (int32_T) (511)) {
          packedValue = 511;
        } else if (scaledValue < (int32_T)((-(511)-1))) {
          packedValue = (-(511)-1);
        } else {
          packedValue = (int16_T) (scaledValue);
        }

        {
          uint16_T* tempValuePtr = (uint16_T*)&packedValue;
          uint16_T tempValue = *tempValuePtr;

          {
            msgOutPack_Y.msgMcu0x200.Data[2] = msgOutPack_Y.msgMcu0x200.Data[2] |
              (uint8_T)((uint16_T)((uint16_T)(tempValue & (uint16_T)0xFU) << 4));
            msgOutPack_Y.msgMcu0x200.Data[1] = msgOutPack_Y.msgMcu0x200.Data[1] |
              (uint8_T)((uint16_T)((uint16_T)(tempValue & (uint16_T)0x3F0U) >> 4));
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 26
     *  length                  = 10
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = SIGNED
     *  factor                  = 0.01
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = 2.53F;

        /* no offset to apply */
        result = result * (1 / 0.01F);

        /* round to closest integer value for integer CAN signal */
        outValue = (result);
      }

      {
        int16_T packedValue;
        int32_T scaledValue;

        if (scaledValue > (int32_T) (511)) {
          packedValue = 511;
        } else if (scaledValue < (int32_T)((-(511)-1))) {
          packedValue = (-(511)-1);
        } else {
          packedValue = (int16_T) (scaledValue);
        }

        {
          uint16_T* tempValuePtr = (uint16_T*)&packedValue;
          uint16_T tempValue = *tempValuePtr;

          {
            msgOutPack_Y.msgMcu0x200.Data[3] = msgOutPack_Y.msgMcu0x200.Data[3] |
              (uint8_T)((uint16_T)((uint16_T)(tempValue & (uint16_T)0x3FU) << 2));
            msgOutPack_Y.msgMcu0x200.Data[2] = msgOutPack_Y.msgMcu0x200.Data[2] |
              (uint8_T)((uint16_T)((uint16_T)(tempValue & (uint16_T)0x3C0U) >> 6));
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 32
     *  length                  = 10
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = SIGNED
     *  factor                  = 0.01
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = -2.24F;

        /* no offset to apply */
        result = result * (1 / 0.01F);

        /* round to closest integer value for integer CAN signal */
        outValue = (result);
      }

      {
        int16_T packedValue;
        int32_T scaledValue;

        if (scaledValue > (int32_T) (511)) {
          packedValue = 511;
        } else if (scaledValue < (int32_T)((-(511)-1))) {
          packedValue = (-(511)-1);
        } else {
          packedValue = (int16_T) (scaledValue);
        }

        {
          uint16_T* tempValuePtr = (uint16_T*)&packedValue;
          uint16_T tempValue = *tempValuePtr;

          {
            msgOutPack_Y.msgMcu0x200.Data[4] = msgOutPack_Y.msgMcu0x200.Data[4] |
              (uint8_T)((uint16_T)(tempValue & (uint16_T)0xFFU));
            msgOutPack_Y.msgMcu0x200.Data[3] = msgOutPack_Y.msgMcu0x200.Data[3] |
              (uint8_T)((uint16_T)((uint16_T)(tempValue & (uint16_T)0x300U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 5 ------------------
     *  startBit                = 54
     *  length                  = 10
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = SIGNED
     *  factor                  = 0.01
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = -1.67F;

        /* no offset to apply */
        result = result * (1 / 0.01F);

        /* round to closest integer value for integer CAN signal */
        outValue = (result);
      }

      {
        int16_T packedValue;
        int32_T scaledValue;

        if (scaledValue > (int32_T) (511)) {
          packedValue = 511;
        } else if (scaledValue < (int32_T)((-(511)-1))) {
          packedValue = (-(511)-1);
        } else {
          packedValue = (int16_T) (scaledValue);
        }

        {
          uint16_T* tempValuePtr = (uint16_T*)&packedValue;
          uint16_T tempValue = *tempValuePtr;

          {
            msgOutPack_Y.msgMcu0x200.Data[6] = msgOutPack_Y.msgMcu0x200.Data[6] |
              (uint8_T)((uint16_T)((uint16_T)(tempValue & (uint16_T)0x3U) << 6));
            msgOutPack_Y.msgMcu0x200.Data[5] = msgOutPack_Y.msgMcu0x200.Data[5] |
              (uint8_T)((uint16_T)((uint16_T)(tempValue & (uint16_T)0x3FCU) >> 2));
          }
        }
      }
    }

    /* --------------- START Packing signal 6 ------------------
     *  startBit                = 60
     *  length                  = 10
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.1
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = 46.8F;

        /* no offset to apply */
        result = result * (1 / 0.1F);

        /* round to closest integer value for integer CAN signal */
        outValue = (result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real32_T)(1023)) {
          packedValue = (uint16_T) 1023;
        } else if (outValue < (real32_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            msgOutPack_Y.msgMcu0x200.Data[7] = msgOutPack_Y.msgMcu0x200.Data[7] |
              (uint8_T)((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFU) << 4));
            msgOutPack_Y.msgMcu0x200.Data[6] = msgOutPack_Y.msgMcu0x200.Data[6] |
              (uint8_T)((uint16_T)((uint16_T)(packedValue & (uint16_T)0x3F0U) >>
              4));
          }
        }
      }
    }
  }
}

/* Model initialize function */
void msgOutPack_initialize(void)
{
  /* Registration code */

  /* external outputs */
  msgOutPack_Y.msgMcu0x200 = CAN_DATATYPE_GROUND;
}

/* Model terminate function */
void msgOutPack_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
