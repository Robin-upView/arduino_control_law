/*
 * File: gru_quadcl.c
 *
 * Code generated for Simulink model 'gru_quadcl'.
 *
 * Model version                  : 1.1164
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Sun May 03 18:28:43 2015
 *
 * Target selection: ert_shrlib.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "gru_quadcl.h"
#include "gru_quadcl_private.h"

/* Block signals (auto storage) */
B_gru_quadcl_T gru_quadcl_B;

/* Block states (auto storage) */
DW_gru_quadcl_T gru_quadcl_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_gru_quadcl_T gru_quadcl_PrevZCX;

/* External inputs (root inport signals with auto storage) */
ExtU_gru_quadcl_T gru_quadcl_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_gru_quadcl_T gru_quadcl_Y;

/* Real-time model */
RT_MODEL_gru_quadcl_T gru_quadcl_M_;
RT_MODEL_gru_quadcl_T *const gru_quadcl_M = &gru_quadcl_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (gru_quadcl_M->Timing.TaskCounters.TID[1])++;
  if ((gru_quadcl_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.1s, 0.0s] */
    gru_quadcl_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function */
void gru_quadcl_step(void)
{
  /* local block i/o variables */
  real_T rtb_snapact;
  real_T rtb_DataTypeConversion3;
  real_T rtb_Switch_g;
  real_T rtb_Switch1_k;
  real_T rtb_WeightedMovingAverage;
  real_T rtb_Add_o;
  real_T rtb_Gain[8];
  boolean_T rtb_LogicalOperator_dp;
  real_T rtb_Add4;
  real_T rtb_TSamp;
  real_T rtb_pdemscale;
  real_T rtb_Switch_l;
  real_T rtb_Add_b;
  real_T rtb_TSamp_e;
  real_T rtb_pdemscale1;
  real_T rtb_Switch1;
  real_T rtb_Add_pu;
  real_T rtb_TSamp_j;
  real_T rtb_Add1;
  real_T rtb_Add1_cb;
  real_T rtb_Add1_pm;
  real_T rtb_Add1_op;
  real_T rtb_Add1_m;
  boolean_T rtb_LogicalOperator_p;
  real_T rtb_DiscreteTransferFcn;
  real_T rtb_DiscreteTransferFcn1;
  real_T DiscreteTransferFcn1_tmp;
  int32_T i;
  real_T u0;

  /* Sum: '<Root>/Add' incorporates:
   *  Inport: '<Root>/crackle_cmds'
   *  Inport: '<Root>/extparams'
   */
  u0 = gru_quadcl_U.extparams[20] + gru_quadcl_U.crackle_cmds[1];

  /* Saturate: '<Root>/Saturation' */
  if (u0 > 5.0) {
    u0 = 5.0;
  } else {
    if (u0 < 0.0) {
      u0 = 0.0;
    }
  }

  /* Sum: '<S3>/Add' incorporates:
   *  Inport: '<Root>/extparams'
   *  Saturate: '<Root>/Saturation'
   */
  rtb_Add_o = u0 - gru_quadcl_U.extparams[31];

  /* Gain: '<S24>/Gain' incorporates:
   *  Constant: '<S24>/Constant'
   *  Inport: '<Root>/rx'
   *  Sum: '<S24>/Add'
   */
  for (i = 0; i < 8; i++) {
    rtb_Gain[i] = (gru_quadcl_U.rx[i] - 15000.0) * 0.0002;
  }

  /* End of Gain: '<S24>/Gain' */

  /* DataTypeConversion: '<S15>/Data Type Conversion2' incorporates:
   *  Constant: '<S22>/Constant'
   *  RelationalOperator: '<S22>/Compare'
   */
  rtb_snapact = (rtb_Gain[5] >= 0.0);

  /* DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */
  if ((rtb_snapact > 0.0) && (gru_quadcl_DW.DiscreteTimeIntegrator_PrevRese <= 0))
  {
    gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
  }

  /* RateTransition: '<S3>/Rate Transition' incorporates:
   *  Inport: '<Root>/extparams'
   */
  if (gru_quadcl_M->Timing.TaskCounters.TID[1] == 0) {
    gru_quadcl_B.RateTransition = gru_quadcl_U.extparams[31];

    /* SampleTimeMath: '<S25>/TSamp' incorporates:
     *  Inport: '<Root>/extparams'
     *
     * About '<S25>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_TSamp = gru_quadcl_B.RateTransition * 10.0;

    /* Sum: '<S25>/Diff' incorporates:
     *  UnitDelay: '<S25>/UD'
     */
    gru_quadcl_B.Diff = rtb_TSamp - gru_quadcl_DW.UD_DSTATE;

    /* Weighted Moving Average Block: '<S3>/Weighted Moving Average'
     *
     *  Finite Impulse Response Filter
     *
     * Input0  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     *
     * Parameter: Gain
     *   Data Type:  Floating Point real_T
     *
     */
    {
      real_T yTemp1;
      rtb_WeightedMovingAverage = gru_quadcl_B.Diff * 0.1;

      {
        int_T i1;
        real_T *dw_TapDelayU = &gru_quadcl_DW.WeightedMovingAverage_TapDelayU[1];
        for (i1=0; i1 < 9; i1++) {
          yTemp1 = dw_TapDelayU[((i1)-1)] *
            gru_quadcl_ConstP.WeightedMovingAverag[i1+1];
          rtb_WeightedMovingAverage = rtb_WeightedMovingAverage + yTemp1;
        }
      }
    }

    /* UnaryMinus: '<S3>/Unary Minus' */
    gru_quadcl_B.UnaryMinus = -rtb_WeightedMovingAverage;
  }

  /* End of RateTransition: '<S3>/Rate Transition' */

  /* Sum: '<S3>/Add1' incorporates:
   *  DiscreteIntegrator: '<S27>/Discrete-Time Integrator'
   *  Inport: '<Root>/extparams'
   *  Product: '<S3>/Product'
   *  Product: '<S3>/Product1'
   *  Product: '<S3>/Product2'
   */
  rtb_Add1 = (rtb_Add_o * gru_quadcl_U.extparams[7] + gru_quadcl_U.extparams[8] *
              gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE) +
    gru_quadcl_B.UnaryMinus * gru_quadcl_U.extparams[9];

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant'
   */
  if (rtb_snapact >= 0.5) {
    /* Saturate: '<S28>/Saturation' */
    if (rtb_Add1 > 0.4) {
      rtb_Add4 = 0.4;
    } else if (rtb_Add1 < -0.25) {
      rtb_Add4 = -0.25;
    } else {
      rtb_Add4 = rtb_Add1;
    }

    /* End of Saturate: '<S28>/Saturation' */
  } else {
    rtb_Add4 = 0.0;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Sum: '<S6>/Add4' */
  rtb_Add4 += rtb_Gain[0];

  /* Gain: '<S7>/p dem scale' incorporates:
   *  Inport: '<Root>/extparams'
   *  Product: '<S7>/Product1'
   */
  rtb_pdemscale = rtb_Gain[2] * gru_quadcl_U.extparams[6] * 0.017453292519943295;

  /* Switch: '<S1>/Switch4' incorporates:
   *  DiscreteTransferFcn: '<S10>/Discrete Transfer Fcn'
   *  Sum: '<S1>/Add'
   */
  if (rtb_snapact >= 0.5) {
    rtb_pdemscale += 0.00245 * gru_quadcl_DW.DiscreteTransferFcn_states[0] +
      0.002401 * gru_quadcl_DW.DiscreteTransferFcn_states[1];
  }

  /* End of Switch: '<S1>/Switch4' */

  /* Sum: '<S30>/Add' incorporates:
   *  Inport: '<Root>/ahrs'
   */
  rtb_pdemscale -= gru_quadcl_U.ahrs[0];

  /* DataTypeConversion: '<S15>/Data Type Conversion3' incorporates:
   *  Constant: '<S21>/Constant'
   *  Logic: '<S15>/Logical Operator'
   *  RelationalOperator: '<S21>/Compare'
   */
  rtb_DataTypeConversion3 = !(rtb_Gain[0] >= 0.0);

  /* DiscreteIntegrator: '<S35>/Discrete-Time Integrator' */
  if ((rtb_DataTypeConversion3 != 0.0) ||
      (gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_i != 0)) {
    gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_i = 0.0;
  }

  /* Sum: '<S30>/Add1' incorporates:
   *  DiscreteIntegrator: '<S35>/Discrete-Time Integrator'
   *  Inport: '<Root>/extparams'
   *  Product: '<S30>/Product'
   *  Product: '<S30>/Product1'
   */
  rtb_Add1_op = rtb_pdemscale * gru_quadcl_U.extparams[4] +
    gru_quadcl_U.extparams[5] * gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_i;

  /* Switch: '<Root>/Switch' incorporates:
   *  Gain: '<S8>/p dem scale'
   *  Inport: '<Root>/extparams'
   *  Product: '<S8>/Product1'
   */
  if (gru_quadcl_U.extparams[14] >= 0.5) {
    /* Saturate: '<S36>/Saturation' */
    if (rtb_Add1_op > 3.1415926535897931) {
      rtb_Switch_l = 3.1415926535897931;
    } else if (rtb_Add1_op < -3.1415926535897931) {
      rtb_Switch_l = -3.1415926535897931;
    } else {
      rtb_Switch_l = rtb_Add1_op;
    }

    /* End of Saturate: '<S36>/Saturation' */
  } else {
    rtb_Switch_l = rtb_Gain[2] * gru_quadcl_U.extparams[2] *
      0.017453292519943295;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Sum: '<S39>/Add' incorporates:
   *  Inport: '<Root>/rates'
   */
  rtb_Add_b = rtb_Switch_l - gru_quadcl_U.rates[0];

  /* DiscreteIntegrator: '<S47>/Discrete-Time Integrator' */
  if ((rtb_DataTypeConversion3 != 0.0) ||
      (gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_p != 0)) {
    gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_l = 0.0;
  }

  rtb_Switch_g = gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_l;

  /* End of DiscreteIntegrator: '<S47>/Discrete-Time Integrator' */

  /* Product: '<S39>/Product1' incorporates:
   *  Inport: '<Root>/extparams'
   */
  rtb_DiscreteTransferFcn = gru_quadcl_U.extparams[10] * rtb_Switch_g;

  /* UnaryMinus: '<S39>/Unary Minus' incorporates:
   *  Inport: '<Root>/rates'
   */
  rtb_Switch_g = -gru_quadcl_U.rates[0];

  /* SampleTimeMath: '<S45>/TSamp'
   *
   * About '<S45>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_e = rtb_Switch_g * 100.0;

  /* Product: '<S39>/Product2' incorporates:
   *  Inport: '<Root>/extparams'
   *  Sum: '<S45>/Diff'
   *  UnitDelay: '<S45>/UD'
   */
  gru_quadcl_B.Product2 = (rtb_TSamp_e - gru_quadcl_DW.UD_DSTATE_n) *
    gru_quadcl_U.extparams[11];

  /* Weighted Moving Average Block: '<S39>/Weighted Moving Average'
   *
   *  Finite Impulse Response Filter
   *
   * Input0  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   *
   * Parameter: Gain
   *   Data Type:  Floating Point real_T
   *
   */
  {
    real_T yTemp1;
    rtb_Switch_g = gru_quadcl_B.Product2 * 0.5;
    yTemp1 = gru_quadcl_DW.WeightedMovingAverage_TapDela_f * 0.5;
    rtb_Switch_g = rtb_Switch_g + yTemp1;
  }

  /* Sum: '<S39>/Add1' incorporates:
   *  Inport: '<Root>/extparams'
   *  Product: '<S39>/Product'
   */
  rtb_Add1_m = (rtb_Add_b * gru_quadcl_U.extparams[0] + rtb_DiscreteTransferFcn)
    + rtb_Switch_g;

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant'
   */
  if (rtb_Gain[0] >= -0.8) {
    /* Saturate: '<S48>/Saturation' */
    if (rtb_Add1_m > 0.2) {
      rtb_Switch_g = 0.2;
    } else if (rtb_Add1_m < -0.2) {
      rtb_Switch_g = -0.2;
    } else {
      rtb_Switch_g = rtb_Add1_m;
    }

    /* End of Saturate: '<S48>/Saturation' */
  } else {
    rtb_Switch_g = 0.0;
  }

  /* End of Switch: '<S6>/Switch' */

  /* DiscreteTransferFcn: '<S10>/Discrete Transfer Fcn1' incorporates:
   *  Inport: '<Root>/crackle_cmds'
   *  Inport: '<Root>/extparams'
   *  Product: '<S10>/Product1'
   */
  DiscreteTransferFcn1_tmp = (gru_quadcl_U.extparams[21] *
    gru_quadcl_U.crackle_cmds[5] - 0.9418 *
    gru_quadcl_DW.DiscreteTransferFcn1_states) / -0.937;

  /* Gain: '<S7>/p dem scale1' incorporates:
   *  Gain: '<S15>/Gain'
   *  Inport: '<Root>/extparams'
   *  Product: '<S7>/Product2'
   */
  rtb_pdemscale1 = -rtb_Gain[3] * gru_quadcl_U.extparams[6] *
    0.017453292519943295;

  /* Switch: '<S1>/Switch3' incorporates:
   *  DiscreteTransferFcn: '<S10>/Discrete Transfer Fcn1'
   *  Sum: '<S1>/Add1'
   */
  if (rtb_snapact >= 0.5) {
    rtb_pdemscale1 += 0.00245 * DiscreteTransferFcn1_tmp + 0.002401 *
      gru_quadcl_DW.DiscreteTransferFcn1_states;
  }

  /* End of Switch: '<S1>/Switch3' */

  /* Sum: '<S29>/Add' incorporates:
   *  Inport: '<Root>/ahrs'
   */
  rtb_pdemscale1 -= gru_quadcl_U.ahrs[1];

  /* DiscreteIntegrator: '<S32>/Discrete-Time Integrator' */
  if ((rtb_DataTypeConversion3 != 0.0) ||
      (gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_c != 0)) {
    gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_k = 0.0;
  }

  /* Sum: '<S29>/Add1' incorporates:
   *  DiscreteIntegrator: '<S32>/Discrete-Time Integrator'
   *  Inport: '<Root>/extparams'
   *  Product: '<S29>/Product'
   *  Product: '<S29>/Product1'
   */
  rtb_Add1_cb = rtb_pdemscale1 * gru_quadcl_U.extparams[4] +
    gru_quadcl_U.extparams[5] * gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_k;

  /* Switch: '<Root>/Switch1' incorporates:
   *  Gain: '<S15>/Gain'
   *  Gain: '<S8>/p dem scale1'
   *  Inport: '<Root>/extparams'
   *  Product: '<S8>/Product2'
   */
  if (gru_quadcl_U.extparams[14] >= 0.5) {
    /* Saturate: '<S33>/Saturation' */
    if (rtb_Add1_cb > 3.1415926535897931) {
      rtb_Switch1 = 3.1415926535897931;
    } else if (rtb_Add1_cb < -3.1415926535897931) {
      rtb_Switch1 = -3.1415926535897931;
    } else {
      rtb_Switch1 = rtb_Add1_cb;
    }

    /* End of Saturate: '<S33>/Saturation' */
  } else {
    rtb_Switch1 = -rtb_Gain[3] * gru_quadcl_U.extparams[2] *
      0.017453292519943295;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Sum: '<S38>/Add' incorporates:
   *  Inport: '<Root>/rates'
   */
  rtb_Add_pu = rtb_Switch1 - gru_quadcl_U.rates[1];

  /* DiscreteIntegrator: '<S43>/Discrete-Time Integrator' */
  if ((rtb_DataTypeConversion3 != 0.0) ||
      (gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_d != 0)) {
    gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_n = 0.0;
  }

  rtb_Switch1_k = gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_n;

  /* End of DiscreteIntegrator: '<S43>/Discrete-Time Integrator' */

  /* Product: '<S38>/Product1' incorporates:
   *  Inport: '<Root>/extparams'
   */
  rtb_DiscreteTransferFcn = gru_quadcl_U.extparams[16] * rtb_Switch1_k;

  /* UnaryMinus: '<S38>/Unary Minus' incorporates:
   *  Inport: '<Root>/rates'
   */
  rtb_Switch1_k = -gru_quadcl_U.rates[1];

  /* SampleTimeMath: '<S41>/TSamp'
   *
   * About '<S41>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_j = rtb_Switch1_k * 100.0;

  /* Product: '<S38>/Product2' incorporates:
   *  Inport: '<Root>/extparams'
   *  Sum: '<S41>/Diff'
   *  UnitDelay: '<S41>/UD'
   */
  gru_quadcl_B.Product2_f = (rtb_TSamp_j - gru_quadcl_DW.UD_DSTATE_h) *
    gru_quadcl_U.extparams[17];

  /* Weighted Moving Average Block: '<S38>/Weighted Moving Average'
   *
   *  Finite Impulse Response Filter
   *
   * Input0  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   *
   * Parameter: Gain
   *   Data Type:  Floating Point real_T
   *
   */
  {
    real_T yTemp1;
    rtb_Switch1_k = gru_quadcl_B.Product2_f * 0.5;
    yTemp1 = gru_quadcl_DW.WeightedMovingAverage_TapDel_fo * 0.5;
    rtb_Switch1_k = rtb_Switch1_k + yTemp1;
  }

  /* Sum: '<S38>/Add1' incorporates:
   *  Inport: '<Root>/extparams'
   *  Product: '<S38>/Product'
   */
  rtb_Add1_pm = (rtb_Add_pu * gru_quadcl_U.extparams[15] +
                 rtb_DiscreteTransferFcn) + rtb_Switch1_k;

  /* Switch: '<S6>/Switch1' incorporates:
   *  Constant: '<S6>/Constant'
   */
  if (rtb_Gain[0] >= -0.8) {
    /* Saturate: '<S44>/Saturation' */
    if (rtb_Add1_pm > 0.2) {
      rtb_Switch1_k = 0.2;
    } else if (rtb_Add1_pm < -0.2) {
      rtb_Switch1_k = -0.2;
    } else {
      rtb_Switch1_k = rtb_Add1_pm;
    }

    /* End of Saturate: '<S44>/Saturation' */
  } else {
    rtb_Switch1_k = 0.0;
  }

  /* End of Switch: '<S6>/Switch1' */

  /* Gain: '<S7>/p dem scale2' incorporates:
   *  Inport: '<Root>/extparams'
   *  Product: '<S7>/Product3'
   */
  rtb_DiscreteTransferFcn = rtb_Gain[4] * gru_quadcl_U.extparams[3] *
    0.017453292519943295;

  /* Switch: '<S1>/Switch2' incorporates:
   *  Saturate: '<S10>/Saturation1'
   *  Sum: '<S1>/Add2'
   */
  if (rtb_snapact >= 0.5) {
    /* Product: '<S10>/Product2' incorporates:
     *  Inport: '<Root>/crackle_cmds'
     *  Inport: '<Root>/extparams'
     */
    u0 = gru_quadcl_U.crackle_cmds[4] * gru_quadcl_U.extparams[22];

    /* Saturate: '<S10>/Saturation1' */
    if (u0 > 0.5) {
      u0 = 0.5;
    } else {
      if (u0 < -0.5) {
        u0 = -0.5;
      }
    }

    rtb_DiscreteTransferFcn += u0;
  }

  /* End of Switch: '<S1>/Switch2' */

  /* Switch: '<S6>/Switch2' incorporates:
   *  Constant: '<S6>/Constant'
   */
  if (rtb_Gain[0] >= -0.8) {
    /* Product: '<S40>/Product' incorporates:
     *  Inport: '<Root>/extparams'
     *  Inport: '<Root>/rates'
     *  Sum: '<S40>/Add'
     */
    rtb_DiscreteTransferFcn1 = (rtb_DiscreteTransferFcn - gru_quadcl_U.rates[2])
      * gru_quadcl_U.extparams[1];

    /* Saturate: '<S40>/Saturation' */
    if (rtb_DiscreteTransferFcn1 > 0.2) {
      rtb_DiscreteTransferFcn1 = 0.2;
    } else {
      if (rtb_DiscreteTransferFcn1 < -0.2) {
        rtb_DiscreteTransferFcn1 = -0.2;
      }
    }

    /* End of Saturate: '<S40>/Saturation' */
  } else {
    rtb_DiscreteTransferFcn1 = 0.0;
  }

  /* End of Switch: '<S6>/Switch2' */

  /* Sum: '<S37>/Add1' incorporates:
   *  Constant: '<S37>/Constant'
   *  Constant: '<S37>/Constant1'
   *  Gain: '<S37>/Gain'
   *  Sum: '<S37>/Add'
   *  Sum: '<S6>/Add3'
   */
  u0 = ((((rtb_Add4 - rtb_Switch_g) + rtb_Switch1_k) + rtb_DiscreteTransferFcn1)
        + 1.0) * 5000.0 + 10000.0;

  /* Saturate: '<S6>/Saturation1' */
  if (u0 > 20000.0) {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[0] = 20000.0;
  } else if (u0 < 9000.0) {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[0] = 9000.0;
  } else {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[0] = u0;
  }

  /* Sum: '<S37>/Add1' incorporates:
   *  Constant: '<S37>/Constant'
   *  Constant: '<S37>/Constant1'
   *  Gain: '<S37>/Gain'
   *  Sum: '<S37>/Add'
   *  Sum: '<S6>/Add2'
   */
  u0 = ((((rtb_Add4 + rtb_Switch_g) + rtb_Switch1_k) - rtb_DiscreteTransferFcn1)
        + 1.0) * 5000.0 + 10000.0;

  /* Saturate: '<S6>/Saturation1' */
  if (u0 > 20000.0) {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[1] = 20000.0;
  } else if (u0 < 9000.0) {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[1] = 9000.0;
  } else {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[1] = u0;
  }

  /* Sum: '<S37>/Add1' incorporates:
   *  Constant: '<S37>/Constant'
   *  Constant: '<S37>/Constant1'
   *  Gain: '<S37>/Gain'
   *  Sum: '<S37>/Add'
   *  Sum: '<S6>/Add1'
   */
  u0 = ((((rtb_Add4 + rtb_Switch_g) - rtb_Switch1_k) + rtb_DiscreteTransferFcn1)
        + 1.0) * 5000.0 + 10000.0;

  /* Saturate: '<S6>/Saturation1' */
  if (u0 > 20000.0) {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[2] = 20000.0;
  } else if (u0 < 9000.0) {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[2] = 9000.0;
  } else {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[2] = u0;
  }

  /* Sum: '<S37>/Add1' incorporates:
   *  Constant: '<S37>/Constant'
   *  Constant: '<S37>/Constant1'
   *  Gain: '<S37>/Gain'
   *  Sum: '<S37>/Add'
   *  Sum: '<S6>/Add'
   */
  u0 = ((((rtb_Add4 - rtb_Switch_g) - rtb_Switch1_k) - rtb_DiscreteTransferFcn1)
        + 1.0) * 5000.0 + 10000.0;

  /* Saturate: '<S6>/Saturation1' */
  if (u0 > 20000.0) {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[3] = 20000.0;
  } else if (u0 < 9000.0) {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[3] = 9000.0;
  } else {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[3] = u0;
  }

  /* Outport: '<Root>/servos' incorporates:
   *  Constant: '<S37>/Constant1'
   *  Gain: '<S37>/Gain'
   *  Saturate: '<S6>/Saturation1'
   *  Sum: '<S37>/Add1'
   */
  gru_quadcl_Y.servos[4] = 15000.0;
  gru_quadcl_Y.servos[5] = 15000.0;
  gru_quadcl_Y.servos[6] = 15000.0;
  gru_quadcl_Y.servos[7] = 15000.0;

  /* Outport: '<Root>/addlog' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Gain: '<S15>/Gain'
   *  Inport: '<Root>/extparams'
   *  Inport: '<Root>/rates'
   */
  gru_quadcl_Y.addlog[0] = gru_quadcl_U.extparams[0];
  gru_quadcl_Y.addlog[1] = gru_quadcl_U.extparams[10];
  gru_quadcl_Y.addlog[2] = gru_quadcl_U.extparams[11];
  gru_quadcl_Y.addlog[3] = gru_quadcl_U.extparams[15];
  gru_quadcl_Y.addlog[4] = gru_quadcl_U.extparams[16];
  gru_quadcl_Y.addlog[5] = gru_quadcl_U.extparams[17];
  gru_quadcl_Y.addlog[6] = gru_quadcl_U.extparams[1];
  gru_quadcl_Y.addlog[7] = rtb_Gain[0];
  gru_quadcl_Y.addlog[8] = rtb_Gain[2];
  gru_quadcl_Y.addlog[9] = -rtb_Gain[3];
  gru_quadcl_Y.addlog[10] = rtb_Gain[4];
  gru_quadcl_Y.addlog[11] = rtb_DataTypeConversion3;
  gru_quadcl_Y.addlog[12] = gru_quadcl_U.extparams[2];
  gru_quadcl_Y.addlog[13] = gru_quadcl_U.extparams[2];
  gru_quadcl_Y.addlog[14] = gru_quadcl_U.extparams[3];
  gru_quadcl_Y.addlog[15] = gru_quadcl_U.extparams[14];
  gru_quadcl_Y.addlog[16] = gru_quadcl_U.rates[0];
  gru_quadcl_Y.addlog[17] = gru_quadcl_U.rates[1];
  gru_quadcl_Y.addlog[18] = gru_quadcl_U.rates[2];
  gru_quadcl_Y.addlog[19] = rtb_Switch_l;
  gru_quadcl_Y.addlog[20] = rtb_Switch1;
  gru_quadcl_Y.addlog[21] = rtb_DiscreteTransferFcn;
  gru_quadcl_Y.addlog[22] = rtb_Add4;
  gru_quadcl_Y.addlog[23] = rtb_Switch_g;
  gru_quadcl_Y.addlog[24] = rtb_Switch1_k;
  gru_quadcl_Y.addlog[25] = rtb_DiscreteTransferFcn1;
  gru_quadcl_Y.addlog[26] = 0.0;
  gru_quadcl_Y.addlog[27] = 0.0;
  gru_quadcl_Y.addlog[28] = 0.0;
  gru_quadcl_Y.addlog[29] = 0.0;
  gru_quadcl_Y.addlog[30] = 0.0;
  gru_quadcl_Y.addlog[31] = 0.0;

  /* Outputs for Triggered SubSystem: '<S14>/grab alt' incorporates:
   *  TriggerPort: '<S20>/Trigger'
   */
  rt_ZCFcn(FALLING_ZERO_CROSSING,&gru_quadcl_PrevZCX.grabalt_Trig_ZCE,
           (rtb_DataTypeConversion3));

  /* End of Outputs for SubSystem: '<S14>/grab alt' */

  /* Logic: '<S44>/Logical Operator' incorporates:
   *  Constant: '<S44>/lower limit'
   *  Constant: '<S44>/upper limit'
   *  RelationalOperator: '<S44>/Relational Operator'
   *  RelationalOperator: '<S44>/Relational Operator1'
   */
  rtb_LogicalOperator_dp = ((rtb_Add1_pm >= 0.2) || (rtb_Add1_pm <= -0.2));

  /* Logic: '<S48>/Logical Operator' incorporates:
   *  Constant: '<S48>/lower limit'
   *  Constant: '<S48>/upper limit'
   *  RelationalOperator: '<S48>/Relational Operator'
   *  RelationalOperator: '<S48>/Relational Operator1'
   */
  rtb_LogicalOperator_p = ((rtb_Add1_m >= 0.2) || (rtb_Add1_m <= -0.2));

  /* Signum: '<S26>/Sign' */
  if (rtb_Add_o < 0.0) {
    u0 = -1.0;
  } else if (rtb_Add_o > 0.0) {
    u0 = 1.0;
  } else if (rtb_Add_o == 0.0) {
    u0 = 0.0;
  } else {
    u0 = rtb_Add_o;
  }

  /* Signum: '<S26>/Sign1' */
  if (rtb_Add1 < 0.0) {
    rtb_Add4 = -1.0;
  } else if (rtb_Add1 > 0.0) {
    rtb_Add4 = 1.0;
  } else if (rtb_Add1 == 0.0) {
    rtb_Add4 = 0.0;
  } else {
    rtb_Add4 = rtb_Add1;
  }

  /* Switch: '<S27>/Switch' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S28>/lower limit'
   *  Constant: '<S28>/upper limit'
   *  Logic: '<S26>/Logical Operator'
   *  Logic: '<S28>/Logical Operator'
   *  RelationalOperator: '<S26>/Relational Operator'
   *  RelationalOperator: '<S28>/Relational Operator'
   *  RelationalOperator: '<S28>/Relational Operator1'
   *  Signum: '<S26>/Sign'
   *  Signum: '<S26>/Sign1'
   */
  if (((rtb_Add1 >= 0.4) || (rtb_Add1 <= -0.25)) && (u0 == rtb_Add4)) {
    rtb_Add_o = 0.0;
  }

  /* End of Switch: '<S27>/Switch' */

  /* Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */
  gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE += 0.01 * rtb_Add_o;
  if (rtb_snapact > 0.0) {
    gru_quadcl_DW.DiscreteTimeIntegrator_PrevRese = 1;
  } else if (rtb_snapact < 0.0) {
    gru_quadcl_DW.DiscreteTimeIntegrator_PrevRese = -1;
  } else if (rtb_snapact == 0.0) {
    gru_quadcl_DW.DiscreteTimeIntegrator_PrevRese = 0;
  } else {
    gru_quadcl_DW.DiscreteTimeIntegrator_PrevRese = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */
  if (gru_quadcl_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for UnitDelay: '<S25>/UD' */
    gru_quadcl_DW.UD_DSTATE = rtb_TSamp;

    /* Weighted Moving Average Block: '<S3>/Weighted Moving Average'
     */
    {
      int32_T iObj;

      /*
       * shift all the discrete states on time delay
       *  being careful not to overwrite a value before it
       *  has been moved.
       */
      for (iObj = (8); iObj > 0; iObj-- ) {
        gru_quadcl_DW.WeightedMovingAverage_TapDelayU[iObj] =
          gru_quadcl_DW.WeightedMovingAverage_TapDelayU[iObj-1];
      }

      /*
       * the top state is the current input
       */
      gru_quadcl_DW.WeightedMovingAverage_TapDelayU[0] = gru_quadcl_B.Diff;
    }
  }

  /* Update for DiscreteTransferFcn: '<S10>/Discrete Transfer Fcn' incorporates:
   *  Inport: '<Root>/crackle_cmds'
   *  Inport: '<Root>/extparams'
   *  Product: '<S10>/Product'
   */
  rtb_DiscreteTransferFcn = (gru_quadcl_U.crackle_cmds[3] *
    gru_quadcl_U.extparams[21] - -1.937 *
    gru_quadcl_DW.DiscreteTransferFcn_states[0]) - 0.9418 *
    gru_quadcl_DW.DiscreteTransferFcn_states[1];
  gru_quadcl_DW.DiscreteTransferFcn_states[1] =
    gru_quadcl_DW.DiscreteTransferFcn_states[0];
  gru_quadcl_DW.DiscreteTransferFcn_states[0] = rtb_DiscreteTransferFcn;

  /* Update for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' */
  if (rtb_DataTypeConversion3 == 0.0) {
    /* Signum: '<S34>/Sign' */
    if (rtb_pdemscale < 0.0) {
      u0 = -1.0;
    } else if (rtb_pdemscale > 0.0) {
      u0 = 1.0;
    } else if (rtb_pdemscale == 0.0) {
      u0 = 0.0;
    } else {
      u0 = rtb_pdemscale;
    }

    /* Signum: '<S34>/Sign1' */
    if (rtb_Add1_op < 0.0) {
      rtb_Add4 = -1.0;
    } else if (rtb_Add1_op > 0.0) {
      rtb_Add4 = 1.0;
    } else if (rtb_Add1_op == 0.0) {
      rtb_Add4 = 0.0;
    } else {
      rtb_Add4 = rtb_Add1_op;
    }

    /* Switch: '<S35>/Switch' incorporates:
     *  Constant: '<S35>/Constant'
     *  Constant: '<S36>/lower limit'
     *  Constant: '<S36>/upper limit'
     *  Logic: '<S30>/Logical Operator'
     *  Logic: '<S34>/Logical Operator'
     *  Logic: '<S36>/Logical Operator'
     *  RelationalOperator: '<S34>/Relational Operator'
     *  RelationalOperator: '<S36>/Relational Operator'
     *  RelationalOperator: '<S36>/Relational Operator1'
     *  Signum: '<S34>/Sign'
     *  Signum: '<S34>/Sign1'
     */
    if (((rtb_Add1_op >= 3.1415926535897931) || (rtb_Add1_op <=
          -3.1415926535897931) || rtb_LogicalOperator_p) && (u0 == rtb_Add4)) {
      rtb_pdemscale = 0.0;
    }

    /* End of Switch: '<S35>/Switch' */
    gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_i += 0.01 * rtb_pdemscale;
  }

  if (rtb_DataTypeConversion3 > 0.0) {
    gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_i = 1;
  } else if (rtb_DataTypeConversion3 < 0.0) {
    gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_i = -1;
  } else if (rtb_DataTypeConversion3 == 0.0) {
    gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_i = 0;
  } else {
    gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_i = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' */
  if (rtb_DataTypeConversion3 == 0.0) {
    /* Signum: '<S46>/Sign' */
    if (rtb_Add_b < 0.0) {
      rtb_Add4 = -1.0;
    } else if (rtb_Add_b > 0.0) {
      rtb_Add4 = 1.0;
    } else if (rtb_Add_b == 0.0) {
      rtb_Add4 = 0.0;
    } else {
      rtb_Add4 = rtb_Add_b;
    }

    /* Signum: '<S46>/Sign1' */
    if (rtb_Add1_m < 0.0) {
      rtb_Add1_m = -1.0;
    } else if (rtb_Add1_m > 0.0) {
      rtb_Add1_m = 1.0;
    } else {
      if (rtb_Add1_m == 0.0) {
        rtb_Add1_m = 0.0;
      }
    }

    /* Switch: '<S47>/Switch' incorporates:
     *  Constant: '<S47>/Constant'
     *  Logic: '<S46>/Logical Operator'
     *  RelationalOperator: '<S46>/Relational Operator'
     *  Signum: '<S46>/Sign'
     *  Signum: '<S46>/Sign1'
     */
    if (rtb_LogicalOperator_p && (rtb_Add4 == rtb_Add1_m)) {
      rtb_Add_b = 0.0;
    }

    /* End of Switch: '<S47>/Switch' */
    gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_l += 0.01 * rtb_Add_b;
  }

  if (rtb_DataTypeConversion3 > 0.0) {
    gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_p = 1;
  } else if (rtb_DataTypeConversion3 < 0.0) {
    gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_p = -1;
  } else if (rtb_DataTypeConversion3 == 0.0) {
    gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_p = 0;
  } else {
    gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_p = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S45>/UD' */
  gru_quadcl_DW.UD_DSTATE_n = rtb_TSamp_e;

  /* Weighted Moving Average Block: '<S39>/Weighted Moving Average'
   */
  {
    /*
     * the top state is the current input
     */
    gru_quadcl_DW.WeightedMovingAverage_TapDela_f = gru_quadcl_B.Product2;
  }

  /* Update for DiscreteTransferFcn: '<S10>/Discrete Transfer Fcn1' */
  gru_quadcl_DW.DiscreteTransferFcn1_states = DiscreteTransferFcn1_tmp;

  /* Update for DiscreteIntegrator: '<S32>/Discrete-Time Integrator' */
  if (rtb_DataTypeConversion3 == 0.0) {
    /* Signum: '<S31>/Sign' */
    if (rtb_pdemscale1 < 0.0) {
      rtb_Add4 = -1.0;
    } else if (rtb_pdemscale1 > 0.0) {
      rtb_Add4 = 1.0;
    } else if (rtb_pdemscale1 == 0.0) {
      rtb_Add4 = 0.0;
    } else {
      rtb_Add4 = rtb_pdemscale1;
    }

    /* Signum: '<S31>/Sign1' */
    if (rtb_Add1_cb < 0.0) {
      u0 = -1.0;
    } else if (rtb_Add1_cb > 0.0) {
      u0 = 1.0;
    } else if (rtb_Add1_cb == 0.0) {
      u0 = 0.0;
    } else {
      u0 = rtb_Add1_cb;
    }

    /* Switch: '<S32>/Switch' incorporates:
     *  Constant: '<S32>/Constant'
     *  Constant: '<S33>/lower limit'
     *  Constant: '<S33>/upper limit'
     *  Logic: '<S29>/Logical Operator'
     *  Logic: '<S31>/Logical Operator'
     *  Logic: '<S33>/Logical Operator'
     *  RelationalOperator: '<S31>/Relational Operator'
     *  RelationalOperator: '<S33>/Relational Operator'
     *  RelationalOperator: '<S33>/Relational Operator1'
     *  Signum: '<S31>/Sign'
     *  Signum: '<S31>/Sign1'
     */
    if (((rtb_Add1_cb >= 3.1415926535897931) || (rtb_Add1_cb <=
          -3.1415926535897931) || rtb_LogicalOperator_dp) && (rtb_Add4 == u0)) {
      rtb_pdemscale1 = 0.0;
    }

    /* End of Switch: '<S32>/Switch' */
    gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_k += 0.01 * rtb_pdemscale1;
  }

  if (rtb_DataTypeConversion3 > 0.0) {
    gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_c = 1;
  } else if (rtb_DataTypeConversion3 < 0.0) {
    gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_c = -1;
  } else if (rtb_DataTypeConversion3 == 0.0) {
    gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_c = 0;
  } else {
    gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_c = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S32>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator' */
  if (rtb_DataTypeConversion3 == 0.0) {
    /* Signum: '<S42>/Sign' */
    if (rtb_Add_pu < 0.0) {
      rtb_Add4 = -1.0;
    } else if (rtb_Add_pu > 0.0) {
      rtb_Add4 = 1.0;
    } else if (rtb_Add_pu == 0.0) {
      rtb_Add4 = 0.0;
    } else {
      rtb_Add4 = rtb_Add_pu;
    }

    /* Signum: '<S42>/Sign1' */
    if (rtb_Add1_pm < 0.0) {
      rtb_Add1_pm = -1.0;
    } else if (rtb_Add1_pm > 0.0) {
      rtb_Add1_pm = 1.0;
    } else {
      if (rtb_Add1_pm == 0.0) {
        rtb_Add1_pm = 0.0;
      }
    }

    /* Switch: '<S43>/Switch' incorporates:
     *  Constant: '<S43>/Constant'
     *  Logic: '<S42>/Logical Operator'
     *  RelationalOperator: '<S42>/Relational Operator'
     *  Signum: '<S42>/Sign'
     *  Signum: '<S42>/Sign1'
     */
    if (rtb_LogicalOperator_dp && (rtb_Add4 == rtb_Add1_pm)) {
      rtb_Add_pu = 0.0;
    }

    /* End of Switch: '<S43>/Switch' */
    gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_n += 0.01 * rtb_Add_pu;
  }

  if (rtb_DataTypeConversion3 > 0.0) {
    gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_d = 1;
  } else if (rtb_DataTypeConversion3 < 0.0) {
    gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_d = -1;
  } else if (rtb_DataTypeConversion3 == 0.0) {
    gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_d = 0;
  } else {
    gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_d = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S41>/UD' */
  gru_quadcl_DW.UD_DSTATE_h = rtb_TSamp_j;

  /* Weighted Moving Average Block: '<S38>/Weighted Moving Average'
   */
  {
    /*
     * the top state is the current input
     */
    gru_quadcl_DW.WeightedMovingAverage_TapDel_fo = gru_quadcl_B.Product2_f;
  }

  rate_scheduler();
}

/* Model initialize function */
void gru_quadcl_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)gru_quadcl_M, 0,
                sizeof(RT_MODEL_gru_quadcl_T));

  /* block I/O */
  {
    gru_quadcl_B.RateTransition = 0.0;
    gru_quadcl_B.Diff = 0.0;
    gru_quadcl_B.UnaryMinus = 0.0;
    gru_quadcl_B.Product2 = 0.0;
    gru_quadcl_B.Product2_f = 0.0;
  }

  /* states (dwork) */
  (void) memset((void *)&gru_quadcl_DW, 0,
                sizeof(DW_gru_quadcl_T));
  gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
  gru_quadcl_DW.UD_DSTATE = 0.0;

  {
    int_T i;
    for (i = 0; i < 9; i++) {
      gru_quadcl_DW.WeightedMovingAverage_TapDelayU[i] = 0.0;
    }
  }

  gru_quadcl_DW.DiscreteTransferFcn_states[0] = 0.0;
  gru_quadcl_DW.DiscreteTransferFcn_states[1] = 0.0;
  gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_i = 0.0;
  gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_l = 0.0;
  gru_quadcl_DW.UD_DSTATE_n = 0.0;
  gru_quadcl_DW.WeightedMovingAverage_TapDela_f = 0.0;
  gru_quadcl_DW.DiscreteTransferFcn1_states = 0.0;
  gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_k = 0.0;
  gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_n = 0.0;
  gru_quadcl_DW.UD_DSTATE_h = 0.0;
  gru_quadcl_DW.WeightedMovingAverage_TapDel_fo = 0.0;

  /* external inputs */
  gru_quadcl_U.rates[0] = 0.0;
  gru_quadcl_U.rates[1] = 0.0;
  gru_quadcl_U.rates[2] = 0.0;
  gru_quadcl_U.accels[0] = 0.0;
  gru_quadcl_U.accels[1] = 0.0;
  gru_quadcl_U.accels[2] = 0.0;
  gru_quadcl_U.magneto[0] = 0.0;
  gru_quadcl_U.magneto[1] = 0.0;
  gru_quadcl_U.magneto[2] = 0.0;
  gru_quadcl_U.airdata[0] = 0.0;
  gru_quadcl_U.airdata[1] = 0.0;
  gru_quadcl_U.airdata[2] = 0.0;

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      gru_quadcl_U.rx[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 9; i++) {
      gru_quadcl_U.gps[i] = 0.0;
    }
  }

  gru_quadcl_U.ahrs[0] = 0.0;
  gru_quadcl_U.ahrs[1] = 0.0;
  gru_quadcl_U.ahrs[2] = 0.0;
  gru_quadcl_U.ahrs[3] = 0.0;
  gru_quadcl_U.power[0] = 0.0;
  gru_quadcl_U.power[1] = 0.0;
  gru_quadcl_U.power[2] = 0.0;

  {
    int_T i;
    for (i = 0; i < 64; i++) {
      gru_quadcl_U.extparams[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      gru_quadcl_U.analogues[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 32; i++) {
      gru_quadcl_U.crackle_cmds[i] = 0.0;
    }
  }

  /* external outputs */
  {
    int_T i;
    for (i = 0; i < 8; i++) {
      gru_quadcl_Y.servos[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 32; i++) {
      gru_quadcl_Y.addlog[i] = 0.0;
    }
  }

  gru_quadcl_PrevZCX.grabalt_Trig_ZCE = UNINITIALIZED_ZCSIG;
  gru_quadcl_PrevZCX.grablatlongscaling_Trig_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */
  gru_quadcl_DW.DiscreteTimeIntegrator_PrevRese = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' */
  gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_i = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' */
  gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S32>/Discrete-Time Integrator' */
  gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_c = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S43>/Discrete-Time Integrator' */
  gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_d = 0;
}

/* Model terminate function */
void gru_quadcl_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
