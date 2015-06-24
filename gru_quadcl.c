/*
 * File: gru_quadcl.c
 *
 * Code generated for Simulink model 'gru_quadcl'.
 *
 * Model version                  : 1.1178
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Wed Jun 24 20:50:10 2015
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

/* Model step function */
void gru_quadcl_step(void)
{
  /* local block i/o variables */
  real_T rtb_snapact;
  real_T rtb_DataTypeConversion3;
  real_T rtb_Switch_h;
  real_T rtb_Switch_g;
  real_T rtb_Switch1_k;
  real_T rtb_Gain_l[8];
  ZCEventType zcEvent;
  real_T rtb_Add_o;
  real_T rtb_Product1;
  real_T rtb_TSamp;
  real_T rtb_pdemscale;
  real_T rtb_Add1_k4;
  real_T rtb_Add_b;
  real_T rtb_TSamp_e;
  real_T rtb_pdemscale1;
  real_T rtb_Add1_fo;
  real_T rtb_Add_pu;
  real_T rtb_TSamp_j;
  boolean_T rtb_RelationalOperator;
  real_T rtb_Add1;
  real_T rtb_Add1_k;
  real_T rtb_Add1_nm;
  boolean_T rtb_LogicalOperator_dn;
  real_T rtb_u_c;
  real_T rtb_DiscreteTransferFcn;
  real_T rtb_DiscreteTransferFcn1;
  real_T rtb_Sum9;
  real_T DiscreteTransferFcn1_tmp;
  int32_T i;

  /* Gain: '<S24>/Gain' incorporates:
   *  Constant: '<S24>/Constant'
   *  Inport: '<Root>/rx'
   *  Sum: '<S24>/Add'
   */
  for (i = 0; i < 8; i++) {
    rtb_Gain_l[i] = (gru_quadcl_U.rx[i] - 15000.0) * 0.0002;
  }

  /* End of Gain: '<S24>/Gain' */

  /* DataTypeConversion: '<S15>/Data Type Conversion2' incorporates:
   *  Constant: '<S22>/Constant'
   *  RelationalOperator: '<S22>/Compare'
   */
  rtb_snapact = (rtb_Gain_l[5] >= 0.0);

  /* Outputs for Triggered SubSystem: '<S3>/grab altitude' incorporates:
   *  TriggerPort: '<S28>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &gru_quadcl_PrevZCX.grabaltitude_Trig_ZCE,
                     (rtb_snapact));
  if (zcEvent != NO_ZCEVENT) {
    /* Inport: '<S28>/in' incorporates:
     *  Inport: '<Root>/extparams'
     */
    gru_quadcl_B.in_k = gru_quadcl_U.extparams[31];
  }

  /* End of Outputs for SubSystem: '<S3>/grab altitude' */

  /* Sum: '<S3>/Add' incorporates:
   *  Inport: '<Root>/extparams'
   */
  rtb_Add_o = gru_quadcl_B.in_k - gru_quadcl_U.extparams[31];

  /* DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */
  if ((rtb_snapact > 0.0) && (gru_quadcl_DW.DiscreteTimeIntegrator_PrevRese <= 0))
  {
    gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
  }

  rtb_Switch_h = gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE;

  /* End of DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */

  /* Product: '<S3>/Product1' incorporates:
   *  Inport: '<Root>/extparams'
   */
  rtb_Product1 = gru_quadcl_U.extparams[8] * rtb_Switch_h;

  /* SampleTimeMath: '<S25>/TSamp' incorporates:
   *  Inport: '<Root>/extparams'
   *
   * About '<S25>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = gru_quadcl_U.extparams[31] * 100.0;

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
    rtb_Switch_h = gru_quadcl_B.Diff * 0.1;

    {
      int_T i1;
      real_T *dw_TapDelayU = &gru_quadcl_DW.WeightedMovingAverage_TapDelayU[1];
      for (i1=0; i1 < 9; i1++) {
        yTemp1 = dw_TapDelayU[((i1)-1)] *
          gru_quadcl_ConstP.WeightedMovingAverag[i1+1];
        rtb_Switch_h = rtb_Switch_h + yTemp1;
      }
    }
  }

  /* Sum: '<S3>/Add1' incorporates:
   *  Inport: '<Root>/extparams'
   *  Product: '<S3>/Product'
   *  Product: '<S3>/Product2'
   *  UnaryMinus: '<S3>/Unary Minus'
   */
  rtb_Add1 = (rtb_Add_o * gru_quadcl_U.extparams[7] + rtb_Product1) +
    -rtb_Switch_h * gru_quadcl_U.extparams[9];

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant'
   */
  if (rtb_snapact >= 0.5) {
    /* Saturate: '<S29>/Saturation' */
    if (rtb_Add1 > 0.4) {
      rtb_Switch_h = 0.4;
    } else if (rtb_Add1 < -0.25) {
      rtb_Switch_h = -0.25;
    } else {
      rtb_Switch_h = rtb_Add1;
    }

    /* End of Saturate: '<S29>/Saturation' */
  } else {
    rtb_Switch_h = 0.0;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Sum: '<S7>/Add4' */
  rtb_u_c = rtb_Switch_h + rtb_Gain_l[0];

  /* Gain: '<S8>/p dem scale' incorporates:
   *  Inport: '<Root>/extparams'
   *  Product: '<S8>/Product1'
   */
  rtb_pdemscale = rtb_Gain_l[2] * gru_quadcl_U.extparams[6] *
    0.017453292519943295;

  /* Switch: '<S1>/Switch4' incorporates:
   *  DiscreteTransferFcn: '<S10>/Discrete Transfer Fcn'
   *  Sum: '<S1>/Add'
   */
  if (rtb_snapact >= 0.5) {
    rtb_pdemscale += 0.00245 * gru_quadcl_DW.DiscreteTransferFcn_states[0] +
      0.002401 * gru_quadcl_DW.DiscreteTransferFcn_states[1];
  }

  /* End of Switch: '<S1>/Switch4' */

  /* Sum: '<S31>/Add' incorporates:
   *  Inport: '<Root>/ahrs'
   */
  rtb_pdemscale -= gru_quadcl_U.ahrs[0];

  /* DataTypeConversion: '<S15>/Data Type Conversion3' incorporates:
   *  Constant: '<S21>/Constant'
   *  Logic: '<S15>/Logical Operator'
   *  RelationalOperator: '<S21>/Compare'
   */
  rtb_DataTypeConversion3 = !(rtb_Gain_l[0] >= -0.6);

  /* DiscreteIntegrator: '<S36>/Discrete-Time Integrator' */
  if ((rtb_DataTypeConversion3 != 0.0) ||
      (gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_i != 0)) {
    gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_i = 0.0;
  }

  /* Sum: '<S31>/Add1' incorporates:
   *  DiscreteIntegrator: '<S36>/Discrete-Time Integrator'
   *  Inport: '<Root>/extparams'
   *  Product: '<S31>/Product'
   *  Product: '<S31>/Product1'
   */
  rtb_Add1_k4 = rtb_pdemscale * gru_quadcl_U.extparams[4] +
    gru_quadcl_U.extparams[5] * gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_i;

  /* Saturate: '<S37>/Saturation' */
  if (rtb_Add1_k4 > 3.1415926535897931) {
    rtb_Product1 = 3.1415926535897931;
  } else if (rtb_Add1_k4 < -3.1415926535897931) {
    rtb_Product1 = -3.1415926535897931;
  } else {
    rtb_Product1 = rtb_Add1_k4;
  }

  /* Sum: '<S44>/Add' incorporates:
   *  Inport: '<Root>/rates'
   *  Saturate: '<S37>/Saturation'
   */
  rtb_Add_b = rtb_Product1 - gru_quadcl_U.rates[0];

  /* DiscreteIntegrator: '<S52>/Discrete-Time Integrator' */
  if ((rtb_DataTypeConversion3 != 0.0) ||
      (gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_p != 0)) {
    gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_l = 0.0;
  }

  rtb_Switch_g = gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_l;

  /* End of DiscreteIntegrator: '<S52>/Discrete-Time Integrator' */

  /* Product: '<S44>/Product1' incorporates:
   *  Inport: '<Root>/extparams'
   */
  rtb_Product1 = gru_quadcl_U.extparams[10] * rtb_Switch_g;

  /* UnaryMinus: '<S44>/Unary Minus' incorporates:
   *  Inport: '<Root>/rates'
   */
  rtb_Switch_g = -gru_quadcl_U.rates[0];

  /* SampleTimeMath: '<S50>/TSamp'
   *
   * About '<S50>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_e = rtb_Switch_g * 100.0;

  /* Product: '<S44>/Product2' incorporates:
   *  Inport: '<Root>/extparams'
   *  Sum: '<S50>/Diff'
   *  UnitDelay: '<S50>/UD'
   */
  gru_quadcl_B.Product2 = (rtb_TSamp_e - gru_quadcl_DW.UD_DSTATE_n) *
    gru_quadcl_U.extparams[11];

  /* Weighted Moving Average Block: '<S44>/Weighted Moving Average'
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

  /* Sum: '<S44>/Add1' incorporates:
   *  Inport: '<Root>/extparams'
   *  Product: '<S44>/Product'
   */
  rtb_Add1_nm = (rtb_Add_b * gru_quadcl_U.extparams[0] + rtb_Product1) +
    rtb_Switch_g;

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<S7>/Constant'
   */
  if (rtb_Gain_l[0] >= -0.8) {
    /* Saturate: '<S53>/Saturation' */
    if (rtb_Add1_nm > 0.2) {
      rtb_Switch_g = 0.2;
    } else if (rtb_Add1_nm < -0.2) {
      rtb_Switch_g = -0.2;
    } else {
      rtb_Switch_g = rtb_Add1_nm;
    }

    /* End of Saturate: '<S53>/Saturation' */
  } else {
    rtb_Switch_g = 0.0;
  }

  /* End of Switch: '<S7>/Switch' */

  /* DiscreteTransferFcn: '<S10>/Discrete Transfer Fcn1' incorporates:
   *  Inport: '<Root>/crackle_cmds'
   *  Inport: '<Root>/extparams'
   *  Product: '<S10>/Product1'
   */
  DiscreteTransferFcn1_tmp = (gru_quadcl_U.extparams[21] *
    gru_quadcl_U.crackle_cmds[5] - 0.9418 *
    gru_quadcl_DW.DiscreteTransferFcn1_states) / -0.937;

  /* Gain: '<S8>/p dem scale1' incorporates:
   *  Gain: '<S15>/Gain'
   *  Inport: '<Root>/extparams'
   *  Product: '<S8>/Product2'
   */
  rtb_pdemscale1 = -rtb_Gain_l[3] * gru_quadcl_U.extparams[6] *
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

  /* Sum: '<S30>/Add' incorporates:
   *  Inport: '<Root>/ahrs'
   */
  rtb_pdemscale1 -= gru_quadcl_U.ahrs[1];

  /* DiscreteIntegrator: '<S33>/Discrete-Time Integrator' */
  if ((rtb_DataTypeConversion3 != 0.0) ||
      (gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_c != 0)) {
    gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_k = 0.0;
  }

  /* Sum: '<S30>/Add1' incorporates:
   *  DiscreteIntegrator: '<S33>/Discrete-Time Integrator'
   *  Inport: '<Root>/extparams'
   *  Product: '<S30>/Product'
   *  Product: '<S30>/Product1'
   */
  rtb_Add1_fo = rtb_pdemscale1 * gru_quadcl_U.extparams[4] +
    gru_quadcl_U.extparams[5] * gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_k;

  /* Saturate: '<S34>/Saturation' */
  if (rtb_Add1_fo > 3.1415926535897931) {
    rtb_Product1 = 3.1415926535897931;
  } else if (rtb_Add1_fo < -3.1415926535897931) {
    rtb_Product1 = -3.1415926535897931;
  } else {
    rtb_Product1 = rtb_Add1_fo;
  }

  /* Sum: '<S43>/Add' incorporates:
   *  Inport: '<Root>/rates'
   *  Saturate: '<S34>/Saturation'
   */
  rtb_Add_pu = rtb_Product1 - gru_quadcl_U.rates[1];

  /* DiscreteIntegrator: '<S48>/Discrete-Time Integrator' */
  if ((rtb_DataTypeConversion3 != 0.0) ||
      (gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_d != 0)) {
    gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_n = 0.0;
  }

  rtb_Switch1_k = gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_n;

  /* End of DiscreteIntegrator: '<S48>/Discrete-Time Integrator' */

  /* Product: '<S43>/Product1' incorporates:
   *  Inport: '<Root>/extparams'
   */
  rtb_Product1 = gru_quadcl_U.extparams[16] * rtb_Switch1_k;

  /* UnaryMinus: '<S43>/Unary Minus' incorporates:
   *  Inport: '<Root>/rates'
   */
  rtb_Switch1_k = -gru_quadcl_U.rates[1];

  /* SampleTimeMath: '<S46>/TSamp'
   *
   * About '<S46>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_j = rtb_Switch1_k * 100.0;

  /* Product: '<S43>/Product2' incorporates:
   *  Inport: '<Root>/extparams'
   *  Sum: '<S46>/Diff'
   *  UnitDelay: '<S46>/UD'
   */
  gru_quadcl_B.Product2_f = (rtb_TSamp_j - gru_quadcl_DW.UD_DSTATE_h) *
    gru_quadcl_U.extparams[17];

  /* Weighted Moving Average Block: '<S43>/Weighted Moving Average'
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

  /* Sum: '<S43>/Add1' incorporates:
   *  Inport: '<Root>/extparams'
   *  Product: '<S43>/Product'
   */
  rtb_Add1_k = (rtb_Add_pu * gru_quadcl_U.extparams[15] + rtb_Product1) +
    rtb_Switch1_k;

  /* Switch: '<S7>/Switch1' incorporates:
   *  Constant: '<S7>/Constant'
   */
  if (rtb_Gain_l[0] >= -0.8) {
    /* Saturate: '<S49>/Saturation' */
    if (rtb_Add1_k > 0.4) {
      rtb_Switch1_k = 0.4;
    } else if (rtb_Add1_k < -0.4) {
      rtb_Switch1_k = -0.4;
    } else {
      rtb_Switch1_k = rtb_Add1_k;
    }

    /* End of Saturate: '<S49>/Saturation' */
  } else {
    rtb_Switch1_k = 0.0;
  }

  /* End of Switch: '<S7>/Switch1' */

  /* Gain: '<S8>/p dem scale2' incorporates:
   *  Inport: '<Root>/extparams'
   *  Product: '<S8>/Product3'
   */
  rtb_DiscreteTransferFcn = rtb_Gain_l[4] * gru_quadcl_U.extparams[3] *
    0.017453292519943295;

  /* RelationalOperator: '<S6>/Relational Operator' incorporates:
   *  Abs: '<S6>/Abs'
   *  Inport: '<Root>/extparams'
   */
  rtb_RelationalOperator = (fabs(rtb_DiscreteTransferFcn) <
    gru_quadcl_U.extparams[13]);

  /* Outputs for Triggered SubSystem: '<S6>/grab heading' incorporates:
   *  TriggerPort: '<S39>/Trigger'
   */
  if (rtb_RelationalOperator && (gru_quadcl_PrevZCX.grabheading_Trig_ZCE !=
       POS_ZCSIG)) {
    /* Inport: '<S39>/in' incorporates:
     *  Inport: '<Root>/ahrs'
     */
    gru_quadcl_B.in = gru_quadcl_U.ahrs[2];
  }

  gru_quadcl_PrevZCX.grabheading_Trig_ZCE = (uint8_T)(rtb_RelationalOperator ?
    (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);

  /* End of Outputs for SubSystem: '<S6>/grab heading' */

  /* Switch: '<S40>/Switch5' incorporates:
   *  Constant: '<S40>/360 deg'
   *  Inport: '<Root>/ahrs'
   *  Sum: '<S40>/Sum8'
   */
  if (gru_quadcl_B.in >= 0.0) {
    rtb_Product1 = gru_quadcl_B.in;
  } else {
    rtb_Product1 = gru_quadcl_B.in + 6.2831853071795862;
  }

  if (gru_quadcl_U.ahrs[2] >= 0.0) {
    rtb_Sum9 = gru_quadcl_U.ahrs[2];
  } else {
    rtb_Sum9 = gru_quadcl_U.ahrs[2] + 6.2831853071795862;
  }

  /* End of Switch: '<S40>/Switch5' */

  /* Sum: '<S40>/Sum9' */
  rtb_Sum9 = rtb_Product1 - rtb_Sum9;

  /* Switch: '<S40>/Switch6' incorporates:
   *  Constant: '<S40>/360 deg'
   *  Sum: '<S40>/Sum10'
   */
  if (rtb_Sum9 >= 3.1415926535897931) {
    rtb_Sum9 -= 6.2831853071795862;
  }

  /* End of Switch: '<S40>/Switch6' */

  /* Switch: '<S40>/Switch7' incorporates:
   *  Constant: '<S40>/360 deg'
   *  Sum: '<S40>/Sum11'
   */
  if (!(rtb_Sum9 >= -3.1415926535897931)) {
    rtb_Sum9 += 6.2831853071795862;
  }

  /* End of Switch: '<S40>/Switch7' */

  /* Switch: '<S7>/Switch2' incorporates:
   *  Constant: '<S7>/Constant'
   */
  if (rtb_Gain_l[0] >= -0.8) {
    /* Switch: '<S6>/Switch' incorporates:
     *  Inport: '<Root>/extparams'
     *  RelationalOperator: '<S38>/u_GTE_up'
     *  RelationalOperator: '<S38>/u_GT_lo'
     *  Sum: '<S38>/Diff'
     *  Switch: '<S38>/Switch'
     *  Switch: '<S38>/Switch1'
     *  UnaryMinus: '<S6>/Unary Minus'
     */
    if (rtb_RelationalOperator) {
      /* Product: '<S6>/Product' incorporates:
       *  Inport: '<Root>/extparams'
       */
      rtb_Product1 = rtb_Sum9 * gru_quadcl_U.extparams[12];

      /* Saturate: '<S41>/Saturation' */
      if (rtb_Product1 > 0.52359877559829882) {
        rtb_Product1 = 0.52359877559829882;
      } else {
        if (rtb_Product1 < -0.52359877559829882) {
          rtb_Product1 = -0.52359877559829882;
        }
      }

      /* End of Saturate: '<S41>/Saturation' */
    } else {
      if (rtb_DiscreteTransferFcn >= gru_quadcl_U.extparams[13]) {
        /* Switch: '<S38>/Switch' incorporates:
         *  Inport: '<Root>/extparams'
         */
        rtb_Sum9 = gru_quadcl_U.extparams[13];
      } else if (rtb_DiscreteTransferFcn > -gru_quadcl_U.extparams[13]) {
        /* Switch: '<S38>/Switch1' incorporates:
         *  Switch: '<S38>/Switch'
         */
        rtb_Sum9 = rtb_DiscreteTransferFcn;
      } else {
        /* Switch: '<S38>/Switch' incorporates:
         *  Inport: '<Root>/extparams'
         *  UnaryMinus: '<S6>/Unary Minus'
         */
        rtb_Sum9 = -gru_quadcl_U.extparams[13];
      }

      rtb_Product1 = rtb_DiscreteTransferFcn - rtb_Sum9;
    }

    /* End of Switch: '<S6>/Switch' */

    /* Product: '<S45>/Product' incorporates:
     *  Inport: '<Root>/extparams'
     *  Inport: '<Root>/rates'
     *  Sum: '<S45>/Add'
     */
    rtb_Product1 = (rtb_Product1 - gru_quadcl_U.rates[2]) *
      gru_quadcl_U.extparams[1];

    /* Saturate: '<S45>/Saturation' */
    if (rtb_Product1 > 0.2) {
      rtb_Sum9 = 0.2;
    } else if (rtb_Product1 < -0.2) {
      rtb_Sum9 = -0.2;
    } else {
      rtb_Sum9 = rtb_Product1;
    }

    /* End of Saturate: '<S45>/Saturation' */
  } else {
    rtb_Sum9 = 0.0;
  }

  /* End of Switch: '<S7>/Switch2' */

  /* Sum: '<S7>/Add3' */
  rtb_Product1 = ((rtb_u_c - rtb_Switch_g) + rtb_Switch1_k) + rtb_Sum9;

  /* Sum: '<S7>/Add2' */
  rtb_DiscreteTransferFcn = ((rtb_u_c + rtb_Switch_g) + rtb_Switch1_k) -
    rtb_Sum9;

  /* Sum: '<S7>/Add1' */
  rtb_DiscreteTransferFcn1 = ((rtb_u_c + rtb_Switch_g) - rtb_Switch1_k) +
    rtb_Sum9;

  /* Sum: '<S7>/Add' */
  rtb_u_c = ((rtb_u_c - rtb_Switch_g) - rtb_Switch1_k) - rtb_Sum9;

  /* Sum: '<S42>/Add1' incorporates:
   *  Constant: '<S42>/Constant'
   *  Constant: '<S42>/Constant1'
   *  Gain: '<S42>/Gain'
   *  Sum: '<S42>/Add'
   */
  rtb_Product1 = (rtb_Product1 + 1.0) * 5000.0 + 10000.0;

  /* Saturate: '<S7>/Saturation1' */
  if (rtb_Product1 > 20000.0) {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[0] = 20000.0;
  } else if (rtb_Product1 < 9000.0) {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[0] = 9000.0;
  } else {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[0] = rtb_Product1;
  }

  /* Sum: '<S42>/Add1' incorporates:
   *  Constant: '<S42>/Constant'
   *  Constant: '<S42>/Constant1'
   *  Gain: '<S42>/Gain'
   *  Sum: '<S42>/Add'
   */
  rtb_Product1 = (rtb_DiscreteTransferFcn + 1.0) * 5000.0 + 10000.0;

  /* Saturate: '<S7>/Saturation1' */
  if (rtb_Product1 > 20000.0) {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[1] = 20000.0;
  } else if (rtb_Product1 < 9000.0) {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[1] = 9000.0;
  } else {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[1] = rtb_Product1;
  }

  /* Sum: '<S42>/Add1' incorporates:
   *  Constant: '<S42>/Constant'
   *  Constant: '<S42>/Constant1'
   *  Gain: '<S42>/Gain'
   *  Sum: '<S42>/Add'
   */
  rtb_Product1 = (rtb_DiscreteTransferFcn1 + 1.0) * 5000.0 + 10000.0;

  /* Saturate: '<S7>/Saturation1' */
  if (rtb_Product1 > 20000.0) {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[2] = 20000.0;
  } else if (rtb_Product1 < 9000.0) {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[2] = 9000.0;
  } else {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[2] = rtb_Product1;
  }

  /* Sum: '<S42>/Add1' incorporates:
   *  Constant: '<S42>/Constant'
   *  Constant: '<S42>/Constant1'
   *  Gain: '<S42>/Gain'
   *  Sum: '<S42>/Add'
   */
  rtb_Product1 = (rtb_u_c + 1.0) * 5000.0 + 10000.0;

  /* Saturate: '<S7>/Saturation1' */
  if (rtb_Product1 > 20000.0) {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[3] = 20000.0;
  } else if (rtb_Product1 < 9000.0) {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[3] = 9000.0;
  } else {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[3] = rtb_Product1;
  }

  /* Outport: '<Root>/servos' incorporates:
   *  Constant: '<S42>/Constant1'
   *  Gain: '<S42>/Gain'
   *  Saturate: '<S7>/Saturation1'
   *  Sum: '<S42>/Add1'
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
  gru_quadcl_Y.addlog[0] = rtb_snapact;
  gru_quadcl_Y.addlog[1] = gru_quadcl_U.extparams[10];
  gru_quadcl_Y.addlog[2] = gru_quadcl_U.extparams[11];
  gru_quadcl_Y.addlog[3] = gru_quadcl_U.extparams[15];
  gru_quadcl_Y.addlog[4] = gru_quadcl_U.extparams[16];
  gru_quadcl_Y.addlog[5] = gru_quadcl_U.extparams[17];
  gru_quadcl_Y.addlog[6] = gru_quadcl_U.extparams[1];
  gru_quadcl_Y.addlog[7] = rtb_Gain_l[0];
  gru_quadcl_Y.addlog[8] = rtb_Gain_l[2];
  gru_quadcl_Y.addlog[9] = -rtb_Gain_l[3];
  gru_quadcl_Y.addlog[10] = rtb_Gain_l[4];
  gru_quadcl_Y.addlog[11] = rtb_DataTypeConversion3;
  gru_quadcl_Y.addlog[12] = gru_quadcl_U.extparams[2];
  gru_quadcl_Y.addlog[13] = gru_quadcl_U.extparams[2];
  gru_quadcl_Y.addlog[14] = gru_quadcl_U.extparams[3];
  gru_quadcl_Y.addlog[15] = gru_quadcl_U.extparams[14];
  gru_quadcl_Y.addlog[16] = gru_quadcl_U.rates[0];
  gru_quadcl_Y.addlog[17] = gru_quadcl_U.rates[1];
  gru_quadcl_Y.addlog[18] = gru_quadcl_U.rates[2];
  gru_quadcl_Y.addlog[19] = rtb_Switch_h;
  gru_quadcl_Y.addlog[20] = gru_quadcl_B.in_k;
  gru_quadcl_Y.addlog[21] = gru_quadcl_U.extparams[31];
  gru_quadcl_Y.addlog[22] = 0.0;
  gru_quadcl_Y.addlog[23] = 0.0;
  gru_quadcl_Y.addlog[24] = 0.0;
  gru_quadcl_Y.addlog[25] = 0.0;
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

  /* Logic: '<S49>/Logical Operator' incorporates:
   *  Constant: '<S49>/lower limit'
   *  Constant: '<S49>/upper limit'
   *  RelationalOperator: '<S49>/Relational Operator'
   *  RelationalOperator: '<S49>/Relational Operator1'
   */
  rtb_RelationalOperator = ((rtb_Add1_k >= 0.4) || (rtb_Add1_k <= -0.4));

  /* Logic: '<S53>/Logical Operator' incorporates:
   *  Constant: '<S53>/lower limit'
   *  Constant: '<S53>/upper limit'
   *  RelationalOperator: '<S53>/Relational Operator'
   *  RelationalOperator: '<S53>/Relational Operator1'
   */
  rtb_LogicalOperator_dn = ((rtb_Add1_nm >= 0.2) || (rtb_Add1_nm <= -0.2));

  /* Signum: '<S26>/Sign' */
  if (rtb_Add_o < 0.0) {
    rtb_Sum9 = -1.0;
  } else if (rtb_Add_o > 0.0) {
    rtb_Sum9 = 1.0;
  } else if (rtb_Add_o == 0.0) {
    rtb_Sum9 = 0.0;
  } else {
    rtb_Sum9 = rtb_Add_o;
  }

  /* Signum: '<S26>/Sign1' */
  if (rtb_Add1 < 0.0) {
    rtb_Product1 = -1.0;
  } else if (rtb_Add1 > 0.0) {
    rtb_Product1 = 1.0;
  } else if (rtb_Add1 == 0.0) {
    rtb_Product1 = 0.0;
  } else {
    rtb_Product1 = rtb_Add1;
  }

  /* Switch: '<S27>/Switch' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S29>/lower limit'
   *  Constant: '<S29>/upper limit'
   *  Logic: '<S26>/Logical Operator'
   *  Logic: '<S29>/Logical Operator'
   *  RelationalOperator: '<S26>/Relational Operator'
   *  RelationalOperator: '<S29>/Relational Operator'
   *  RelationalOperator: '<S29>/Relational Operator1'
   *  Signum: '<S26>/Sign'
   *  Signum: '<S26>/Sign1'
   */
  if (((rtb_Add1 >= 0.4) || (rtb_Add1 <= -0.25)) && (rtb_Sum9 == rtb_Product1))
  {
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

  /* Update for DiscreteTransferFcn: '<S10>/Discrete Transfer Fcn' incorporates:
   *  Inport: '<Root>/crackle_cmds'
   *  Inport: '<Root>/extparams'
   *  Product: '<S10>/Product'
   */
  rtb_Product1 = (gru_quadcl_U.crackle_cmds[3] * gru_quadcl_U.extparams[21] -
                  -1.937 * gru_quadcl_DW.DiscreteTransferFcn_states[0]) - 0.9418
    * gru_quadcl_DW.DiscreteTransferFcn_states[1];
  gru_quadcl_DW.DiscreteTransferFcn_states[1] =
    gru_quadcl_DW.DiscreteTransferFcn_states[0];
  gru_quadcl_DW.DiscreteTransferFcn_states[0] = rtb_Product1;

  /* Update for DiscreteIntegrator: '<S36>/Discrete-Time Integrator' */
  if (rtb_DataTypeConversion3 == 0.0) {
    /* Signum: '<S35>/Sign' */
    if (rtb_pdemscale < 0.0) {
      rtb_Sum9 = -1.0;
    } else if (rtb_pdemscale > 0.0) {
      rtb_Sum9 = 1.0;
    } else if (rtb_pdemscale == 0.0) {
      rtb_Sum9 = 0.0;
    } else {
      rtb_Sum9 = rtb_pdemscale;
    }

    /* Signum: '<S35>/Sign1' */
    if (rtb_Add1_k4 < 0.0) {
      rtb_Product1 = -1.0;
    } else if (rtb_Add1_k4 > 0.0) {
      rtb_Product1 = 1.0;
    } else if (rtb_Add1_k4 == 0.0) {
      rtb_Product1 = 0.0;
    } else {
      rtb_Product1 = rtb_Add1_k4;
    }

    /* Switch: '<S36>/Switch' incorporates:
     *  Constant: '<S36>/Constant'
     *  Constant: '<S37>/lower limit'
     *  Constant: '<S37>/upper limit'
     *  Logic: '<S31>/Logical Operator'
     *  Logic: '<S35>/Logical Operator'
     *  Logic: '<S37>/Logical Operator'
     *  RelationalOperator: '<S35>/Relational Operator'
     *  RelationalOperator: '<S37>/Relational Operator'
     *  RelationalOperator: '<S37>/Relational Operator1'
     *  Signum: '<S35>/Sign'
     *  Signum: '<S35>/Sign1'
     */
    if (((rtb_Add1_k4 >= 3.1415926535897931) || (rtb_Add1_k4 <=
          -3.1415926535897931) || rtb_LogicalOperator_dn) && (rtb_Sum9 ==
         rtb_Product1)) {
      rtb_pdemscale = 0.0;
    }

    /* End of Switch: '<S36>/Switch' */
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

  /* End of Update for DiscreteIntegrator: '<S36>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S52>/Discrete-Time Integrator' */
  if (rtb_DataTypeConversion3 == 0.0) {
    /* Signum: '<S51>/Sign' */
    if (rtb_Add_b < 0.0) {
      rtb_Sum9 = -1.0;
    } else if (rtb_Add_b > 0.0) {
      rtb_Sum9 = 1.0;
    } else if (rtb_Add_b == 0.0) {
      rtb_Sum9 = 0.0;
    } else {
      rtb_Sum9 = rtb_Add_b;
    }

    /* Signum: '<S51>/Sign1' */
    if (rtb_Add1_nm < 0.0) {
      rtb_Add1_nm = -1.0;
    } else if (rtb_Add1_nm > 0.0) {
      rtb_Add1_nm = 1.0;
    } else {
      if (rtb_Add1_nm == 0.0) {
        rtb_Add1_nm = 0.0;
      }
    }

    /* Switch: '<S52>/Switch' incorporates:
     *  Constant: '<S52>/Constant'
     *  Logic: '<S51>/Logical Operator'
     *  RelationalOperator: '<S51>/Relational Operator'
     *  Signum: '<S51>/Sign'
     *  Signum: '<S51>/Sign1'
     */
    if (rtb_LogicalOperator_dn && (rtb_Sum9 == rtb_Add1_nm)) {
      rtb_Add_b = 0.0;
    }

    /* End of Switch: '<S52>/Switch' */
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

  /* End of Update for DiscreteIntegrator: '<S52>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S50>/UD' */
  gru_quadcl_DW.UD_DSTATE_n = rtb_TSamp_e;

  /* Weighted Moving Average Block: '<S44>/Weighted Moving Average'
   */
  {
    /*
     * the top state is the current input
     */
    gru_quadcl_DW.WeightedMovingAverage_TapDela_f = gru_quadcl_B.Product2;
  }

  /* Update for DiscreteTransferFcn: '<S10>/Discrete Transfer Fcn1' */
  gru_quadcl_DW.DiscreteTransferFcn1_states = DiscreteTransferFcn1_tmp;

  /* Update for DiscreteIntegrator: '<S33>/Discrete-Time Integrator' */
  if (rtb_DataTypeConversion3 == 0.0) {
    /* Signum: '<S32>/Sign' */
    if (rtb_pdemscale1 < 0.0) {
      rtb_Sum9 = -1.0;
    } else if (rtb_pdemscale1 > 0.0) {
      rtb_Sum9 = 1.0;
    } else if (rtb_pdemscale1 == 0.0) {
      rtb_Sum9 = 0.0;
    } else {
      rtb_Sum9 = rtb_pdemscale1;
    }

    /* Signum: '<S32>/Sign1' */
    if (rtb_Add1_fo < 0.0) {
      rtb_Product1 = -1.0;
    } else if (rtb_Add1_fo > 0.0) {
      rtb_Product1 = 1.0;
    } else if (rtb_Add1_fo == 0.0) {
      rtb_Product1 = 0.0;
    } else {
      rtb_Product1 = rtb_Add1_fo;
    }

    /* Switch: '<S33>/Switch' incorporates:
     *  Constant: '<S33>/Constant'
     *  Constant: '<S34>/lower limit'
     *  Constant: '<S34>/upper limit'
     *  Logic: '<S30>/Logical Operator'
     *  Logic: '<S32>/Logical Operator'
     *  Logic: '<S34>/Logical Operator'
     *  RelationalOperator: '<S32>/Relational Operator'
     *  RelationalOperator: '<S34>/Relational Operator'
     *  RelationalOperator: '<S34>/Relational Operator1'
     *  Signum: '<S32>/Sign'
     *  Signum: '<S32>/Sign1'
     */
    if (((rtb_Add1_fo >= 3.1415926535897931) || (rtb_Add1_fo <=
          -3.1415926535897931) || rtb_RelationalOperator) && (rtb_Sum9 ==
         rtb_Product1)) {
      rtb_pdemscale1 = 0.0;
    }

    /* End of Switch: '<S33>/Switch' */
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

  /* End of Update for DiscreteIntegrator: '<S33>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S48>/Discrete-Time Integrator' */
  if (rtb_DataTypeConversion3 == 0.0) {
    /* Signum: '<S47>/Sign' */
    if (rtb_Add_pu < 0.0) {
      rtb_Sum9 = -1.0;
    } else if (rtb_Add_pu > 0.0) {
      rtb_Sum9 = 1.0;
    } else if (rtb_Add_pu == 0.0) {
      rtb_Sum9 = 0.0;
    } else {
      rtb_Sum9 = rtb_Add_pu;
    }

    /* Signum: '<S47>/Sign1' */
    if (rtb_Add1_k < 0.0) {
      rtb_Add1_k = -1.0;
    } else if (rtb_Add1_k > 0.0) {
      rtb_Add1_k = 1.0;
    } else {
      if (rtb_Add1_k == 0.0) {
        rtb_Add1_k = 0.0;
      }
    }

    /* Switch: '<S48>/Switch' incorporates:
     *  Constant: '<S48>/Constant'
     *  Logic: '<S47>/Logical Operator'
     *  RelationalOperator: '<S47>/Relational Operator'
     *  Signum: '<S47>/Sign'
     *  Signum: '<S47>/Sign1'
     */
    if (rtb_RelationalOperator && (rtb_Sum9 == rtb_Add1_k)) {
      rtb_Add_pu = 0.0;
    }

    /* End of Switch: '<S48>/Switch' */
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

  /* End of Update for DiscreteIntegrator: '<S48>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S46>/UD' */
  gru_quadcl_DW.UD_DSTATE_h = rtb_TSamp_j;

  /* Weighted Moving Average Block: '<S43>/Weighted Moving Average'
   */
  {
    /*
     * the top state is the current input
     */
    gru_quadcl_DW.WeightedMovingAverage_TapDel_fo = gru_quadcl_B.Product2_f;
  }
}

/* Model initialize function */
void gru_quadcl_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(gru_quadcl_M, (NULL));

  /* block I/O */
  {
    gru_quadcl_B.Diff = 0.0;
    gru_quadcl_B.Product2 = 0.0;
    gru_quadcl_B.Product2_f = 0.0;
    gru_quadcl_B.in = 0.0;
    gru_quadcl_B.in_k = 0.0;
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

  gru_quadcl_PrevZCX.grabheading_Trig_ZCE = POS_ZCSIG;
  gru_quadcl_PrevZCX.grabaltitude_Trig_ZCE = UNINITIALIZED_ZCSIG;
  gru_quadcl_PrevZCX.grabalt_Trig_ZCE = UNINITIALIZED_ZCSIG;
  gru_quadcl_PrevZCX.grablatlongscaling_Trig_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */
  gru_quadcl_DW.DiscreteTimeIntegrator_PrevRese = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S36>/Discrete-Time Integrator' */
  gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_i = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S52>/Discrete-Time Integrator' */
  gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S33>/Discrete-Time Integrator' */
  gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_c = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S48>/Discrete-Time Integrator' */
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
