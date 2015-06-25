/*
 * File: gru_quadcl.c
 *
 * Code generated for Simulink model 'gru_quadcl'.
 *
 * Model version                  : 1.1180
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Thu Jun 25 17:50:52 2015
 *
 * Target selection: ert_shrlib.tlc
 * Embedded hardware selection: Atmel->AVR
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
  real_T rtb_pdemscale2;
  boolean_T rtb_RelationalOperator;
  real_T rtb_Add1;
  real_T rtb_Add1_k;
  real_T rtb_Add1_nm;
  boolean_T rtb_LogicalOperator_dn;
  real_T rtb_u_c;
  real_T rtb_Sum9;
  real_T rtb_u_j;
  int16_T i;

  /* Gain: '<S23>/Gain' incorporates:
   *  Constant: '<S23>/Constant'
   *  Inport: '<Root>/rx'
   *  Sum: '<S23>/Add'
   */
  for (i = 0; i < 8; i++) {
    rtb_Gain_l[i] = (gru_quadcl_U.rx[i] - 15000.0) * 0.0002;
  }

  /* End of Gain: '<S23>/Gain' */

  /* DataTypeConversion: '<S14>/Data Type Conversion2' incorporates:
   *  Constant: '<S21>/Constant'
   *  RelationalOperator: '<S21>/Compare'
   */
  rtb_snapact = (rtb_Gain_l[5] >= 0.0);

  /* Outputs for Triggered SubSystem: '<S3>/grab altitude' incorporates:
   *  TriggerPort: '<S27>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &gru_quadcl_PrevZCX.grabaltitude_Trig_ZCE,
                     (rtb_snapact));
  if (zcEvent != NO_ZCEVENT) {
    /* Inport: '<S27>/in' incorporates:
     *  Inport: '<Root>/extparams'
     */
    gru_quadcl_B.in_k = gru_quadcl_U.extparams[31];
  }

  /* End of Outputs for SubSystem: '<S3>/grab altitude' */

  /* Sum: '<S3>/Add' incorporates:
   *  Inport: '<Root>/extparams'
   */
  rtb_Add_o = gru_quadcl_B.in_k - gru_quadcl_U.extparams[31];

  /* DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */
  if ((rtb_snapact > 0.0) && (gru_quadcl_DW.DiscreteTimeIntegrator_PrevRese <= 0))
  {
    gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
  }

  rtb_Switch_h = gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE;

  /* End of DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */

  /* Product: '<S3>/Product1' incorporates:
   *  Inport: '<Root>/extparams'
   */
  rtb_Product1 = gru_quadcl_U.extparams[8] * rtb_Switch_h;

  /* SampleTimeMath: '<S24>/TSamp' incorporates:
   *  Inport: '<Root>/extparams'
   *
   * About '<S24>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = gru_quadcl_U.extparams[31] * 100.0;

  /* Sum: '<S24>/Diff' incorporates:
   *  UnitDelay: '<S24>/UD'
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
    /* Saturate: '<S28>/Saturation' */
    if (rtb_Add1 > 0.4) {
      rtb_Switch_h = 0.4;
    } else if (rtb_Add1 < -0.25) {
      rtb_Switch_h = -0.25;
    } else {
      rtb_Switch_h = rtb_Add1;
    }

    /* End of Saturate: '<S28>/Saturation' */
  } else {
    rtb_Switch_h = 0.0;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Sum: '<S7>/Add4' */
  rtb_u_c = rtb_Switch_h + rtb_Gain_l[0];

  /* Sum: '<S30>/Add' incorporates:
   *  Gain: '<S8>/p dem scale'
   *  Inport: '<Root>/ahrs'
   *  Inport: '<Root>/extparams'
   *  Product: '<S8>/Product1'
   */
  rtb_pdemscale = rtb_Gain_l[2] * gru_quadcl_U.extparams[6] *
    0.017453292519943295 - gru_quadcl_U.ahrs[0];

  /* DataTypeConversion: '<S14>/Data Type Conversion3' incorporates:
   *  Constant: '<S20>/Constant'
   *  Logic: '<S14>/Logical Operator'
   *  RelationalOperator: '<S20>/Compare'
   */
  rtb_DataTypeConversion3 = !(rtb_Gain_l[0] >= -0.6);

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
  rtb_Add1_k4 = rtb_pdemscale * gru_quadcl_U.extparams[4] +
    gru_quadcl_U.extparams[5] * gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_i;

  /* Saturate: '<S36>/Saturation' */
  if (rtb_Add1_k4 > 3.1415926535897931) {
    rtb_Product1 = 3.1415926535897931;
  } else if (rtb_Add1_k4 < -3.1415926535897931) {
    rtb_Product1 = -3.1415926535897931;
  } else {
    rtb_Product1 = rtb_Add1_k4;
  }

  /* Sum: '<S43>/Add' incorporates:
   *  Inport: '<Root>/rates'
   *  Saturate: '<S36>/Saturation'
   */
  rtb_Add_b = rtb_Product1 - gru_quadcl_U.rates[0];

  /* DiscreteIntegrator: '<S51>/Discrete-Time Integrator' */
  if ((rtb_DataTypeConversion3 != 0.0) ||
      (gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_p != 0)) {
    gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_l = 0.0;
  }

  rtb_Switch_g = gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_l;

  /* End of DiscreteIntegrator: '<S51>/Discrete-Time Integrator' */

  /* Product: '<S43>/Product1' incorporates:
   *  Inport: '<Root>/extparams'
   */
  rtb_Product1 = gru_quadcl_U.extparams[10] * rtb_Switch_g;

  /* UnaryMinus: '<S43>/Unary Minus' incorporates:
   *  Inport: '<Root>/rates'
   */
  rtb_Switch_g = -gru_quadcl_U.rates[0];

  /* SampleTimeMath: '<S49>/TSamp'
   *
   * About '<S49>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_e = rtb_Switch_g * 100.0;

  /* Product: '<S43>/Product2' incorporates:
   *  Inport: '<Root>/extparams'
   *  Sum: '<S49>/Diff'
   *  UnitDelay: '<S49>/UD'
   */
  gru_quadcl_B.Product2 = (rtb_TSamp_e - gru_quadcl_DW.UD_DSTATE_n) *
    gru_quadcl_U.extparams[11];

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
    rtb_Switch_g = gru_quadcl_B.Product2 * 0.5;
    yTemp1 = gru_quadcl_DW.WeightedMovingAverage_TapDela_f * 0.5;
    rtb_Switch_g = rtb_Switch_g + yTemp1;
  }

  /* Sum: '<S43>/Add1' incorporates:
   *  Inport: '<Root>/extparams'
   *  Product: '<S43>/Product'
   */
  rtb_Add1_nm = (rtb_Add_b * gru_quadcl_U.extparams[0] + rtb_Product1) +
    rtb_Switch_g;

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<S7>/Constant'
   */
  if (rtb_Gain_l[0] >= -0.8) {
    /* Saturate: '<S52>/Saturation' */
    if (rtb_Add1_nm > 0.2) {
      rtb_Switch_g = 0.2;
    } else if (rtb_Add1_nm < -0.2) {
      rtb_Switch_g = -0.2;
    } else {
      rtb_Switch_g = rtb_Add1_nm;
    }

    /* End of Saturate: '<S52>/Saturation' */
  } else {
    rtb_Switch_g = 0.0;
  }

  /* End of Switch: '<S7>/Switch' */

  /* Sum: '<S29>/Add' incorporates:
   *  Gain: '<S14>/Gain'
   *  Gain: '<S8>/p dem scale1'
   *  Inport: '<Root>/ahrs'
   *  Inport: '<Root>/extparams'
   *  Product: '<S8>/Product2'
   */
  rtb_pdemscale1 = -rtb_Gain_l[3] * gru_quadcl_U.extparams[6] *
    0.017453292519943295 - gru_quadcl_U.ahrs[1];

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
  rtb_Add1_fo = rtb_pdemscale1 * gru_quadcl_U.extparams[4] +
    gru_quadcl_U.extparams[5] * gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_k;

  /* Saturate: '<S33>/Saturation' */
  if (rtb_Add1_fo > 3.1415926535897931) {
    rtb_Product1 = 3.1415926535897931;
  } else if (rtb_Add1_fo < -3.1415926535897931) {
    rtb_Product1 = -3.1415926535897931;
  } else {
    rtb_Product1 = rtb_Add1_fo;
  }

  /* Sum: '<S42>/Add' incorporates:
   *  Inport: '<Root>/rates'
   *  Saturate: '<S33>/Saturation'
   */
  rtb_Add_pu = rtb_Product1 - gru_quadcl_U.rates[1];

  /* DiscreteIntegrator: '<S47>/Discrete-Time Integrator' */
  if ((rtb_DataTypeConversion3 != 0.0) ||
      (gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_d != 0)) {
    gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_n = 0.0;
  }

  rtb_Switch1_k = gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_n;

  /* End of DiscreteIntegrator: '<S47>/Discrete-Time Integrator' */

  /* Product: '<S42>/Product1' incorporates:
   *  Inport: '<Root>/extparams'
   */
  rtb_Product1 = gru_quadcl_U.extparams[16] * rtb_Switch1_k;

  /* UnaryMinus: '<S42>/Unary Minus' incorporates:
   *  Inport: '<Root>/rates'
   */
  rtb_Switch1_k = -gru_quadcl_U.rates[1];

  /* SampleTimeMath: '<S45>/TSamp'
   *
   * About '<S45>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_j = rtb_Switch1_k * 100.0;

  /* Product: '<S42>/Product2' incorporates:
   *  Inport: '<Root>/extparams'
   *  Sum: '<S45>/Diff'
   *  UnitDelay: '<S45>/UD'
   */
  gru_quadcl_B.Product2_f = (rtb_TSamp_j - gru_quadcl_DW.UD_DSTATE_h) *
    gru_quadcl_U.extparams[17];

  /* Weighted Moving Average Block: '<S42>/Weighted Moving Average'
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

  /* Sum: '<S42>/Add1' incorporates:
   *  Inport: '<Root>/extparams'
   *  Product: '<S42>/Product'
   */
  rtb_Add1_k = (rtb_Add_pu * gru_quadcl_U.extparams[15] + rtb_Product1) +
    rtb_Switch1_k;

  /* Switch: '<S7>/Switch1' incorporates:
   *  Constant: '<S7>/Constant'
   */
  if (rtb_Gain_l[0] >= -0.8) {
    /* Saturate: '<S48>/Saturation' */
    if (rtb_Add1_k > 0.4) {
      rtb_Switch1_k = 0.4;
    } else if (rtb_Add1_k < -0.4) {
      rtb_Switch1_k = -0.4;
    } else {
      rtb_Switch1_k = rtb_Add1_k;
    }

    /* End of Saturate: '<S48>/Saturation' */
  } else {
    rtb_Switch1_k = 0.0;
  }

  /* End of Switch: '<S7>/Switch1' */

  /* Gain: '<S8>/p dem scale2' incorporates:
   *  Inport: '<Root>/extparams'
   *  Product: '<S8>/Product3'
   */
  rtb_pdemscale2 = rtb_Gain_l[4] * gru_quadcl_U.extparams[3] *
    0.017453292519943295;

  /* RelationalOperator: '<S6>/Relational Operator' incorporates:
   *  Abs: '<S6>/Abs'
   *  Inport: '<Root>/extparams'
   */
  rtb_RelationalOperator = (fabs(rtb_pdemscale2) < gru_quadcl_U.extparams[13]);

  /* Outputs for Triggered SubSystem: '<S6>/grab heading' incorporates:
   *  TriggerPort: '<S38>/Trigger'
   */
  if (rtb_RelationalOperator && (gru_quadcl_PrevZCX.grabheading_Trig_ZCE !=
       POS_ZCSIG)) {
    /* Inport: '<S38>/in' incorporates:
     *  Inport: '<Root>/ahrs'
     */
    gru_quadcl_B.in = gru_quadcl_U.ahrs[2];
  }

  gru_quadcl_PrevZCX.grabheading_Trig_ZCE = (uint8_T)(rtb_RelationalOperator ?
    (int16_T)POS_ZCSIG : (int16_T)ZERO_ZCSIG);

  /* End of Outputs for SubSystem: '<S6>/grab heading' */

  /* Switch: '<S39>/Switch5' incorporates:
   *  Constant: '<S39>/360 deg'
   *  Inport: '<Root>/ahrs'
   *  Sum: '<S39>/Sum8'
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

  /* End of Switch: '<S39>/Switch5' */

  /* Sum: '<S39>/Sum9' */
  rtb_Sum9 = rtb_Product1 - rtb_Sum9;

  /* Switch: '<S39>/Switch6' incorporates:
   *  Constant: '<S39>/360 deg'
   *  Sum: '<S39>/Sum10'
   */
  if (rtb_Sum9 >= 3.1415926535897931) {
    rtb_Sum9 -= 6.2831853071795862;
  }

  /* End of Switch: '<S39>/Switch6' */

  /* Switch: '<S39>/Switch7' incorporates:
   *  Constant: '<S39>/360 deg'
   *  Sum: '<S39>/Sum11'
   */
  if (!(rtb_Sum9 >= -3.1415926535897931)) {
    rtb_Sum9 += 6.2831853071795862;
  }

  /* End of Switch: '<S39>/Switch7' */

  /* Switch: '<S7>/Switch2' incorporates:
   *  Constant: '<S7>/Constant'
   */
  if (rtb_Gain_l[0] >= -0.8) {
    /* Switch: '<S6>/Switch' incorporates:
     *  Inport: '<Root>/extparams'
     *  RelationalOperator: '<S37>/u_GTE_up'
     *  RelationalOperator: '<S37>/u_GT_lo'
     *  Sum: '<S37>/Diff'
     *  Switch: '<S37>/Switch'
     *  Switch: '<S37>/Switch1'
     *  UnaryMinus: '<S6>/Unary Minus'
     */
    if (rtb_RelationalOperator) {
      /* Product: '<S6>/Product' incorporates:
       *  Inport: '<Root>/extparams'
       */
      rtb_Product1 = rtb_Sum9 * gru_quadcl_U.extparams[12];

      /* Saturate: '<S40>/Saturation' */
      if (rtb_Product1 > 0.52359877559829882) {
        rtb_Product1 = 0.52359877559829882;
      } else {
        if (rtb_Product1 < -0.52359877559829882) {
          rtb_Product1 = -0.52359877559829882;
        }
      }

      /* End of Saturate: '<S40>/Saturation' */
    } else {
      if (rtb_pdemscale2 >= gru_quadcl_U.extparams[13]) {
        /* Switch: '<S37>/Switch' incorporates:
         *  Inport: '<Root>/extparams'
         */
        rtb_Sum9 = gru_quadcl_U.extparams[13];
      } else if (rtb_pdemscale2 > -gru_quadcl_U.extparams[13]) {
        /* Switch: '<S37>/Switch1' incorporates:
         *  Switch: '<S37>/Switch'
         */
        rtb_Sum9 = rtb_pdemscale2;
      } else {
        /* Switch: '<S37>/Switch' incorporates:
         *  Inport: '<Root>/extparams'
         *  UnaryMinus: '<S6>/Unary Minus'
         */
        rtb_Sum9 = -gru_quadcl_U.extparams[13];
      }

      rtb_Product1 = rtb_pdemscale2 - rtb_Sum9;
    }

    /* End of Switch: '<S6>/Switch' */

    /* Product: '<S44>/Product' incorporates:
     *  Inport: '<Root>/extparams'
     *  Inport: '<Root>/rates'
     *  Sum: '<S44>/Add'
     */
    rtb_Product1 = (rtb_Product1 - gru_quadcl_U.rates[2]) *
      gru_quadcl_U.extparams[1];

    /* Saturate: '<S44>/Saturation' */
    if (rtb_Product1 > 0.2) {
      rtb_Sum9 = 0.2;
    } else if (rtb_Product1 < -0.2) {
      rtb_Sum9 = -0.2;
    } else {
      rtb_Sum9 = rtb_Product1;
    }

    /* End of Saturate: '<S44>/Saturation' */
  } else {
    rtb_Sum9 = 0.0;
  }

  /* End of Switch: '<S7>/Switch2' */

  /* Sum: '<S7>/Add3' */
  rtb_Product1 = ((rtb_u_c - rtb_Switch_g) + rtb_Switch1_k) + rtb_Sum9;

  /* Sum: '<S7>/Add2' */
  rtb_pdemscale2 = ((rtb_u_c + rtb_Switch_g) + rtb_Switch1_k) - rtb_Sum9;

  /* Sum: '<S7>/Add1' */
  rtb_u_j = ((rtb_u_c + rtb_Switch_g) - rtb_Switch1_k) + rtb_Sum9;

  /* Sum: '<S7>/Add' */
  rtb_u_c = ((rtb_u_c - rtb_Switch_g) - rtb_Switch1_k) - rtb_Sum9;

  /* Sum: '<S41>/Add1' incorporates:
   *  Constant: '<S41>/Constant'
   *  Constant: '<S41>/Constant1'
   *  Gain: '<S41>/Gain'
   *  Sum: '<S41>/Add'
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

  /* Sum: '<S41>/Add1' incorporates:
   *  Constant: '<S41>/Constant'
   *  Constant: '<S41>/Constant1'
   *  Gain: '<S41>/Gain'
   *  Sum: '<S41>/Add'
   */
  rtb_Product1 = (rtb_pdemscale2 + 1.0) * 5000.0 + 10000.0;

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

  /* Sum: '<S41>/Add1' incorporates:
   *  Constant: '<S41>/Constant'
   *  Constant: '<S41>/Constant1'
   *  Gain: '<S41>/Gain'
   *  Sum: '<S41>/Add'
   */
  rtb_Product1 = (rtb_u_j + 1.0) * 5000.0 + 10000.0;

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

  /* Sum: '<S41>/Add1' incorporates:
   *  Constant: '<S41>/Constant'
   *  Constant: '<S41>/Constant1'
   *  Gain: '<S41>/Gain'
   *  Sum: '<S41>/Add'
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
   *  Constant: '<S41>/Constant1'
   *  Gain: '<S41>/Gain'
   *  Saturate: '<S7>/Saturation1'
   *  Sum: '<S41>/Add1'
   */
  gru_quadcl_Y.servos[4] = 15000.0;
  gru_quadcl_Y.servos[5] = 15000.0;
  gru_quadcl_Y.servos[6] = 15000.0;
  gru_quadcl_Y.servos[7] = 15000.0;

  /* Outport: '<Root>/addlog' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Gain: '<S14>/Gain'
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

  /* Outputs for Triggered SubSystem: '<S13>/grab alt' incorporates:
   *  TriggerPort: '<S19>/Trigger'
   */
  rt_ZCFcn(FALLING_ZERO_CROSSING,&gru_quadcl_PrevZCX.grabalt_Trig_ZCE,
           (rtb_DataTypeConversion3));

  /* End of Outputs for SubSystem: '<S13>/grab alt' */

  /* Logic: '<S48>/Logical Operator' incorporates:
   *  Constant: '<S48>/lower limit'
   *  Constant: '<S48>/upper limit'
   *  RelationalOperator: '<S48>/Relational Operator'
   *  RelationalOperator: '<S48>/Relational Operator1'
   */
  rtb_RelationalOperator = ((rtb_Add1_k >= 0.4) || (rtb_Add1_k <= -0.4));

  /* Logic: '<S52>/Logical Operator' incorporates:
   *  Constant: '<S52>/lower limit'
   *  Constant: '<S52>/upper limit'
   *  RelationalOperator: '<S52>/Relational Operator'
   *  RelationalOperator: '<S52>/Relational Operator1'
   */
  rtb_LogicalOperator_dn = ((rtb_Add1_nm >= 0.2) || (rtb_Add1_nm <= -0.2));

  /* Signum: '<S25>/Sign' */
  if (rtb_Add_o < 0.0) {
    rtb_Sum9 = -1.0;
  } else if (rtb_Add_o > 0.0) {
    rtb_Sum9 = 1.0;
  } else if (rtb_Add_o == 0.0) {
    rtb_Sum9 = 0.0;
  } else {
    rtb_Sum9 = rtb_Add_o;
  }

  /* Signum: '<S25>/Sign1' */
  if (rtb_Add1 < 0.0) {
    rtb_Product1 = -1.0;
  } else if (rtb_Add1 > 0.0) {
    rtb_Product1 = 1.0;
  } else if (rtb_Add1 == 0.0) {
    rtb_Product1 = 0.0;
  } else {
    rtb_Product1 = rtb_Add1;
  }

  /* Switch: '<S26>/Switch' incorporates:
   *  Constant: '<S26>/Constant'
   *  Constant: '<S28>/lower limit'
   *  Constant: '<S28>/upper limit'
   *  Logic: '<S25>/Logical Operator'
   *  Logic: '<S28>/Logical Operator'
   *  RelationalOperator: '<S25>/Relational Operator'
   *  RelationalOperator: '<S28>/Relational Operator'
   *  RelationalOperator: '<S28>/Relational Operator1'
   *  Signum: '<S25>/Sign'
   *  Signum: '<S25>/Sign1'
   */
  if (((rtb_Add1 >= 0.4) || (rtb_Add1 <= -0.25)) && (rtb_Sum9 == rtb_Product1))
  {
    rtb_Add_o = 0.0;
  }

  /* End of Switch: '<S26>/Switch' */

  /* Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */
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

  /* End of Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S24>/UD' */
  gru_quadcl_DW.UD_DSTATE = rtb_TSamp;

  /* Weighted Moving Average Block: '<S3>/Weighted Moving Average'
   */
  {
    int16_T iObj;

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

  /* Update for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' */
  if (rtb_DataTypeConversion3 == 0.0) {
    /* Signum: '<S34>/Sign' */
    if (rtb_pdemscale < 0.0) {
      rtb_Sum9 = -1.0;
    } else if (rtb_pdemscale > 0.0) {
      rtb_Sum9 = 1.0;
    } else if (rtb_pdemscale == 0.0) {
      rtb_Sum9 = 0.0;
    } else {
      rtb_Sum9 = rtb_pdemscale;
    }

    /* Signum: '<S34>/Sign1' */
    if (rtb_Add1_k4 < 0.0) {
      rtb_Product1 = -1.0;
    } else if (rtb_Add1_k4 > 0.0) {
      rtb_Product1 = 1.0;
    } else if (rtb_Add1_k4 == 0.0) {
      rtb_Product1 = 0.0;
    } else {
      rtb_Product1 = rtb_Add1_k4;
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
    if (((rtb_Add1_k4 >= 3.1415926535897931) || (rtb_Add1_k4 <=
          -3.1415926535897931) || rtb_LogicalOperator_dn) && (rtb_Sum9 ==
         rtb_Product1)) {
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

  /* Update for DiscreteIntegrator: '<S51>/Discrete-Time Integrator' */
  if (rtb_DataTypeConversion3 == 0.0) {
    /* Signum: '<S50>/Sign' */
    if (rtb_Add_b < 0.0) {
      rtb_Sum9 = -1.0;
    } else if (rtb_Add_b > 0.0) {
      rtb_Sum9 = 1.0;
    } else if (rtb_Add_b == 0.0) {
      rtb_Sum9 = 0.0;
    } else {
      rtb_Sum9 = rtb_Add_b;
    }

    /* Signum: '<S50>/Sign1' */
    if (rtb_Add1_nm < 0.0) {
      rtb_Add1_nm = -1.0;
    } else if (rtb_Add1_nm > 0.0) {
      rtb_Add1_nm = 1.0;
    } else {
      if (rtb_Add1_nm == 0.0) {
        rtb_Add1_nm = 0.0;
      }
    }

    /* Switch: '<S51>/Switch' incorporates:
     *  Constant: '<S51>/Constant'
     *  Logic: '<S50>/Logical Operator'
     *  RelationalOperator: '<S50>/Relational Operator'
     *  Signum: '<S50>/Sign'
     *  Signum: '<S50>/Sign1'
     */
    if (rtb_LogicalOperator_dn && (rtb_Sum9 == rtb_Add1_nm)) {
      rtb_Add_b = 0.0;
    }

    /* End of Switch: '<S51>/Switch' */
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

  /* End of Update for DiscreteIntegrator: '<S51>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S49>/UD' */
  gru_quadcl_DW.UD_DSTATE_n = rtb_TSamp_e;

  /* Weighted Moving Average Block: '<S43>/Weighted Moving Average'
   */
  {
    /*
     * the top state is the current input
     */
    gru_quadcl_DW.WeightedMovingAverage_TapDela_f = gru_quadcl_B.Product2;
  }

  /* Update for DiscreteIntegrator: '<S32>/Discrete-Time Integrator' */
  if (rtb_DataTypeConversion3 == 0.0) {
    /* Signum: '<S31>/Sign' */
    if (rtb_pdemscale1 < 0.0) {
      rtb_Sum9 = -1.0;
    } else if (rtb_pdemscale1 > 0.0) {
      rtb_Sum9 = 1.0;
    } else if (rtb_pdemscale1 == 0.0) {
      rtb_Sum9 = 0.0;
    } else {
      rtb_Sum9 = rtb_pdemscale1;
    }

    /* Signum: '<S31>/Sign1' */
    if (rtb_Add1_fo < 0.0) {
      rtb_Product1 = -1.0;
    } else if (rtb_Add1_fo > 0.0) {
      rtb_Product1 = 1.0;
    } else if (rtb_Add1_fo == 0.0) {
      rtb_Product1 = 0.0;
    } else {
      rtb_Product1 = rtb_Add1_fo;
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
    if (((rtb_Add1_fo >= 3.1415926535897931) || (rtb_Add1_fo <=
          -3.1415926535897931) || rtb_RelationalOperator) && (rtb_Sum9 ==
         rtb_Product1)) {
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

  /* Update for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' */
  if (rtb_DataTypeConversion3 == 0.0) {
    /* Signum: '<S46>/Sign' */
    if (rtb_Add_pu < 0.0) {
      rtb_Sum9 = -1.0;
    } else if (rtb_Add_pu > 0.0) {
      rtb_Sum9 = 1.0;
    } else if (rtb_Add_pu == 0.0) {
      rtb_Sum9 = 0.0;
    } else {
      rtb_Sum9 = rtb_Add_pu;
    }

    /* Signum: '<S46>/Sign1' */
    if (rtb_Add1_k < 0.0) {
      rtb_Add1_k = -1.0;
    } else if (rtb_Add1_k > 0.0) {
      rtb_Add1_k = 1.0;
    } else {
      if (rtb_Add1_k == 0.0) {
        rtb_Add1_k = 0.0;
      }
    }

    /* Switch: '<S47>/Switch' incorporates:
     *  Constant: '<S47>/Constant'
     *  Logic: '<S46>/Logical Operator'
     *  RelationalOperator: '<S46>/Relational Operator'
     *  Signum: '<S46>/Sign'
     *  Signum: '<S46>/Sign1'
     */
    if (rtb_RelationalOperator && (rtb_Sum9 == rtb_Add1_k)) {
      rtb_Add_pu = 0.0;
    }

    /* End of Switch: '<S47>/Switch' */
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

  /* End of Update for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S45>/UD' */
  gru_quadcl_DW.UD_DSTATE_h = rtb_TSamp_j;

  /* Weighted Moving Average Block: '<S42>/Weighted Moving Average'
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

  gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_i = 0.0;
  gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_l = 0.0;
  gru_quadcl_DW.UD_DSTATE_n = 0.0;
  gru_quadcl_DW.WeightedMovingAverage_TapDela_f = 0.0;
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

  /* InitializeConditions for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */
  gru_quadcl_DW.DiscreteTimeIntegrator_PrevRese = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' */
  gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_i = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S51>/Discrete-Time Integrator' */
  gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S32>/Discrete-Time Integrator' */
  gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_c = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' */
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
