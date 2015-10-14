/*
 * File: Arduino_250.c
 *
 * Code generated for Simulink model 'Arduino_250'.
 *
 * Model version                  : 1.1223
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Wed Oct 14 18:15:28 2015
 *
 * Target selection: ert_shrlib.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Arduino_250.h"
#include "Arduino_250_private.h"

/* Block signals (auto storage) */
B_Arduino_250_T Arduino_250_B;

/* Block states (auto storage) */
DW_Arduino_250_T Arduino_250_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Arduino_250_T Arduino_250_PrevZCX;

/* External inputs (root inport signals with auto storage) */
ExtU_Arduino_250_T Arduino_250_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Arduino_250_T Arduino_250_Y;

/* Real-time model */
RT_MODEL_Arduino_250_T Arduino_250_M_;
RT_MODEL_Arduino_250_T *const Arduino_250_M = &Arduino_250_M_;

/* Model step function */
void Arduino_250_step(void)
{
  /* local block i/o variables */
  real_T rtb_DataTypeConversion3;
  real_T rtb_Switch1_k;
  real_T rtb_u_j;
  real_T rtb_Gain_l[8];
  real_T rtb_pdemscale;
  real_T rtb_Add_o;
  real_T rtb_Add1_j;
  real_T rtb_Add_b;
  real_T rtb_Product1_a;
  real_T rtb_TSamp;
  real_T rtb_Add_j;
  real_T rtb_Add1_ms;
  real_T rtb_Add_ay;
  real_T rtb_TSamp_l;
  real_T rtb_pdemscale2;
  boolean_T rtb_RelationalOperator;
  real_T rtb_snapact;
  real_T rtb_Add1_fm;
  real_T rtb_Add1;
  boolean_T rtb_LogicalOperator_dn;
  real_T rtb_Sum9;
  int16_T i;

  /* Gain: '<S15>/Gain' incorporates:
   *  Constant: '<S15>/Constant'
   *  Inport: '<Root>/rx'
   *  Sum: '<S15>/Add'
   */
  for (i = 0; i < 8; i++) {
    rtb_Gain_l[i] = (Arduino_250_U.rx[i] - 15000.0) * 0.0002;
  }

  /* End of Gain: '<S15>/Gain' */

  /* Gain: '<S6>/p dem scale' incorporates:
   *  Inport: '<Root>/extparams'
   *  Product: '<S6>/Product1'
   */
  rtb_pdemscale = rtb_Gain_l[2] * Arduino_250_U.extparams[6] *
    0.017453292519943295;

  /* Sum: '<S17>/Add' incorporates:
   *  Inport: '<Root>/ahrs'
   */
  rtb_Add_o = rtb_pdemscale - Arduino_250_U.ahrs[0];

  /* DataTypeConversion: '<S11>/Data Type Conversion3' incorporates:
   *  Constant: '<S12>/Constant'
   *  Logic: '<S11>/Logical Operator'
   *  RelationalOperator: '<S12>/Compare'
   */
  rtb_DataTypeConversion3 = !(rtb_Gain_l[0] >= -0.6);

  /* DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */
  if ((rtb_DataTypeConversion3 != 0.0) ||
      (Arduino_250_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
    Arduino_250_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
  }

  /* Sum: '<S17>/Add1' incorporates:
   *  DiscreteIntegrator: '<S22>/Discrete-Time Integrator'
   *  Inport: '<Root>/extparams'
   *  Product: '<S17>/Product'
   *  Product: '<S17>/Product1'
   */
  rtb_Add1_j = rtb_Add_o * Arduino_250_U.extparams[4] + Arduino_250_U.extparams
    [5] * Arduino_250_DW.DiscreteTimeIntegrator_DSTATE;

  /* Saturate: '<S23>/Saturation' */
  if (rtb_Add1_j > 3.1415926535897931) {
    rtb_Product1_a = 3.1415926535897931;
  } else if (rtb_Add1_j < -3.1415926535897931) {
    rtb_Product1_a = -3.1415926535897931;
  } else {
    rtb_Product1_a = rtb_Add1_j;
  }

  /* Sum: '<S30>/Add' incorporates:
   *  Inport: '<Root>/rates'
   *  Saturate: '<S23>/Saturation'
   */
  rtb_Add_b = rtb_Product1_a - Arduino_250_U.rates[0];

  /* DiscreteIntegrator: '<S38>/Discrete-Time Integrator' */
  if ((rtb_DataTypeConversion3 != 0.0) ||
      (Arduino_250_DW.DiscreteTimeIntegrator_PrevRe_p != 0)) {
    Arduino_250_DW.DiscreteTimeIntegrator_DSTATE_l = 0.0;
  }

  rtb_u_j = Arduino_250_DW.DiscreteTimeIntegrator_DSTATE_l;

  /* End of DiscreteIntegrator: '<S38>/Discrete-Time Integrator' */

  /* Product: '<S30>/Product1' incorporates:
   *  Inport: '<Root>/extparams'
   */
  rtb_Product1_a = Arduino_250_U.extparams[10] * rtb_u_j;

  /* UnaryMinus: '<S30>/Unary Minus' incorporates:
   *  Inport: '<Root>/rates'
   */
  rtb_u_j = -Arduino_250_U.rates[0];

  /* SampleTimeMath: '<S36>/TSamp'
   *
   * About '<S36>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = rtb_u_j * 200.0;

  /* Sum: '<S36>/Diff' incorporates:
   *  UnitDelay: '<S36>/UD'
   */
  Arduino_250_B.Diff = rtb_TSamp - Arduino_250_DW.UD_DSTATE;

  /* Weighted Moving Average Block: '<S30>/Weighted Moving Average'
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
    rtb_u_j = Arduino_250_B.Diff * 0.5;
    yTemp1 = Arduino_250_DW.WeightedMovingAverage_TapDelayU * 0.5;
    rtb_u_j = rtb_u_j + yTemp1;
  }

  /* Sum: '<S30>/Add1' incorporates:
   *  Inport: '<Root>/extparams'
   *  Product: '<S30>/Product'
   *  Product: '<S30>/Product2'
   */
  rtb_Add1 = (rtb_Add_b * Arduino_250_U.extparams[0] + rtb_Product1_a) +
    Arduino_250_U.extparams[11] * rtb_u_j;

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/Constant'
   */
  if (rtb_Gain_l[0] >= -0.8) {
    /* Saturate: '<S40>/Saturation' */
    if (rtb_Add1 > 0.3) {
      rtb_u_j = 0.3;
    } else if (rtb_Add1 < -0.3) {
      rtb_u_j = -0.3;
    } else {
      rtb_u_j = rtb_Add1;
    }

    /* End of Saturate: '<S40>/Saturation' */
  } else {
    rtb_u_j = 0.0;
  }

  /* End of Switch: '<S5>/Switch' */

  /* Sum: '<S16>/Add' incorporates:
   *  Gain: '<S11>/Gain3'
   *  Gain: '<S6>/p dem scale1'
   *  Inport: '<Root>/ahrs'
   *  Inport: '<Root>/extparams'
   *  Product: '<S6>/Product2'
   */
  rtb_Add_j = -rtb_Gain_l[3] * Arduino_250_U.extparams[6] * 0.017453292519943295
    - Arduino_250_U.ahrs[1];

  /* DiscreteIntegrator: '<S19>/Discrete-Time Integrator' */
  if ((rtb_DataTypeConversion3 != 0.0) ||
      (Arduino_250_DW.DiscreteTimeIntegrator_PrevRe_c != 0)) {
    Arduino_250_DW.DiscreteTimeIntegrator_DSTATE_k = 0.0;
  }

  /* Sum: '<S16>/Add1' incorporates:
   *  DiscreteIntegrator: '<S19>/Discrete-Time Integrator'
   *  Inport: '<Root>/extparams'
   *  Product: '<S16>/Product'
   *  Product: '<S16>/Product1'
   */
  rtb_Add1_ms = rtb_Add_j * Arduino_250_U.extparams[4] +
    Arduino_250_U.extparams[5] * Arduino_250_DW.DiscreteTimeIntegrator_DSTATE_k;

  /* Saturate: '<S20>/Saturation' */
  if (rtb_Add1_ms > 3.1415926535897931) {
    rtb_Product1_a = 3.1415926535897931;
  } else if (rtb_Add1_ms < -3.1415926535897931) {
    rtb_Product1_a = -3.1415926535897931;
  } else {
    rtb_Product1_a = rtb_Add1_ms;
  }

  /* Sum: '<S29>/Add' incorporates:
   *  Inport: '<Root>/rates'
   *  Saturate: '<S20>/Saturation'
   */
  rtb_Add_ay = rtb_Product1_a - Arduino_250_U.rates[1];

  /* DiscreteIntegrator: '<S34>/Discrete-Time Integrator' */
  if ((rtb_DataTypeConversion3 != 0.0) ||
      (Arduino_250_DW.DiscreteTimeIntegrator_PrevRe_d != 0)) {
    Arduino_250_DW.DiscreteTimeIntegrator_DSTATE_n = 0.0;
  }

  rtb_Switch1_k = Arduino_250_DW.DiscreteTimeIntegrator_DSTATE_n;

  /* End of DiscreteIntegrator: '<S34>/Discrete-Time Integrator' */

  /* Product: '<S29>/Product1' incorporates:
   *  Inport: '<Root>/extparams'
   */
  rtb_Product1_a = Arduino_250_U.extparams[16] * rtb_Switch1_k;

  /* UnaryMinus: '<S29>/Unary Minus' incorporates:
   *  Inport: '<Root>/rates'
   */
  rtb_Switch1_k = -Arduino_250_U.rates[1];

  /* SampleTimeMath: '<S32>/TSamp'
   *
   * About '<S32>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_l = rtb_Switch1_k * 200.0;

  /* Sum: '<S32>/Diff' incorporates:
   *  UnitDelay: '<S32>/UD'
   */
  Arduino_250_B.Diff_i = rtb_TSamp_l - Arduino_250_DW.UD_DSTATE_h;

  /* Weighted Moving Average Block: '<S29>/Weighted Moving Average'
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
    rtb_Switch1_k = Arduino_250_B.Diff_i * 0.5;
    yTemp1 = Arduino_250_DW.WeightedMovingAverage_TapDela_c * 0.5;
    rtb_Switch1_k = rtb_Switch1_k + yTemp1;
  }

  /* Sum: '<S29>/Add1' incorporates:
   *  Inport: '<Root>/extparams'
   *  Product: '<S29>/Product'
   *  Product: '<S29>/Product2'
   */
  rtb_Add1_fm = (rtb_Add_ay * Arduino_250_U.extparams[15] + rtb_Product1_a) +
    Arduino_250_U.extparams[17] * rtb_Switch1_k;

  /* Switch: '<S5>/Switch1' incorporates:
   *  Constant: '<S5>/Constant'
   */
  if (rtb_Gain_l[0] >= -0.8) {
    /* Saturate: '<S35>/Saturation' */
    if (rtb_Add1_fm > 0.4) {
      rtb_Switch1_k = 0.4;
    } else if (rtb_Add1_fm < -0.4) {
      rtb_Switch1_k = -0.4;
    } else {
      rtb_Switch1_k = rtb_Add1_fm;
    }

    /* End of Saturate: '<S35>/Saturation' */
  } else {
    rtb_Switch1_k = 0.0;
  }

  /* End of Switch: '<S5>/Switch1' */

  /* Gain: '<S6>/p dem scale2' incorporates:
   *  Inport: '<Root>/extparams'
   *  Product: '<S6>/Product3'
   */
  rtb_pdemscale2 = rtb_Gain_l[4] * Arduino_250_U.extparams[3] *
    0.017453292519943295;

  /* RelationalOperator: '<S4>/Relational Operator' incorporates:
   *  Abs: '<S4>/Abs'
   *  Inport: '<Root>/extparams'
   */
  rtb_RelationalOperator = (fabs(rtb_pdemscale2) < Arduino_250_U.extparams[13]);

  /* Outputs for Triggered SubSystem: '<S4>/grab heading' incorporates:
   *  TriggerPort: '<S25>/Trigger'
   */
  if (rtb_RelationalOperator && (Arduino_250_PrevZCX.grabheading_Trig_ZCE !=
       POS_ZCSIG)) {
    /* Inport: '<S25>/in' incorporates:
     *  Inport: '<Root>/ahrs'
     */
    Arduino_250_B.in = Arduino_250_U.ahrs[2];
  }

  Arduino_250_PrevZCX.grabheading_Trig_ZCE = (uint8_T)(rtb_RelationalOperator ?
    (int16_T)POS_ZCSIG : (int16_T)ZERO_ZCSIG);

  /* End of Outputs for SubSystem: '<S4>/grab heading' */

  /* Switch: '<S26>/Switch5' incorporates:
   *  Constant: '<S26>/360 deg'
   *  Inport: '<Root>/ahrs'
   *  Sum: '<S26>/Sum8'
   */
  if (Arduino_250_B.in >= 0.0) {
    rtb_Product1_a = Arduino_250_B.in;
  } else {
    rtb_Product1_a = Arduino_250_B.in + 6.2831853071795862;
  }

  if (Arduino_250_U.ahrs[2] >= 0.0) {
    rtb_Sum9 = Arduino_250_U.ahrs[2];
  } else {
    rtb_Sum9 = Arduino_250_U.ahrs[2] + 6.2831853071795862;
  }

  /* End of Switch: '<S26>/Switch5' */

  /* Sum: '<S26>/Sum9' */
  rtb_Sum9 = rtb_Product1_a - rtb_Sum9;

  /* Switch: '<S26>/Switch6' incorporates:
   *  Constant: '<S26>/360 deg'
   *  Sum: '<S26>/Sum10'
   */
  if (rtb_Sum9 >= 3.1415926535897931) {
    rtb_Sum9 -= 6.2831853071795862;
  }

  /* End of Switch: '<S26>/Switch6' */

  /* Switch: '<S26>/Switch7' incorporates:
   *  Constant: '<S26>/360 deg'
   *  Sum: '<S26>/Sum11'
   */
  if (!(rtb_Sum9 >= -3.1415926535897931)) {
    rtb_Sum9 += 6.2831853071795862;
  }

  /* End of Switch: '<S26>/Switch7' */

  /* Switch: '<S5>/Switch2' incorporates:
   *  Constant: '<S5>/Constant'
   */
  if (rtb_Gain_l[0] >= -0.8) {
    /* Switch: '<S4>/Switch' incorporates:
     *  Inport: '<Root>/extparams'
     *  RelationalOperator: '<S24>/u_GTE_up'
     *  RelationalOperator: '<S24>/u_GT_lo'
     *  Sum: '<S24>/Diff'
     *  Switch: '<S24>/Switch'
     *  Switch: '<S24>/Switch1'
     *  UnaryMinus: '<S4>/Unary Minus'
     */
    if (rtb_RelationalOperator) {
      /* Product: '<S4>/Product' incorporates:
       *  Inport: '<Root>/extparams'
       */
      rtb_Product1_a = rtb_Sum9 * Arduino_250_U.extparams[12];

      /* Saturate: '<S27>/Saturation' */
      if (rtb_Product1_a > 0.52359877559829882) {
        rtb_Product1_a = 0.52359877559829882;
      } else {
        if (rtb_Product1_a < -0.52359877559829882) {
          rtb_Product1_a = -0.52359877559829882;
        }
      }

      /* End of Saturate: '<S27>/Saturation' */
    } else {
      if (rtb_pdemscale2 >= Arduino_250_U.extparams[13]) {
        /* Switch: '<S24>/Switch' incorporates:
         *  Inport: '<Root>/extparams'
         */
        rtb_Sum9 = Arduino_250_U.extparams[13];
      } else if (rtb_pdemscale2 > -Arduino_250_U.extparams[13]) {
        /* Switch: '<S24>/Switch1' incorporates:
         *  Switch: '<S24>/Switch'
         */
        rtb_Sum9 = rtb_pdemscale2;
      } else {
        /* Switch: '<S24>/Switch' incorporates:
         *  Inport: '<Root>/extparams'
         *  UnaryMinus: '<S4>/Unary Minus'
         */
        rtb_Sum9 = -Arduino_250_U.extparams[13];
      }

      rtb_Product1_a = rtb_pdemscale2 - rtb_Sum9;
    }

    /* End of Switch: '<S4>/Switch' */

    /* Product: '<S31>/Product' incorporates:
     *  Inport: '<Root>/extparams'
     *  Inport: '<Root>/rates'
     *  Sum: '<S31>/Add'
     */
    rtb_Product1_a = (rtb_Product1_a - Arduino_250_U.rates[2]) *
      Arduino_250_U.extparams[1];

    /* Saturate: '<S31>/Saturation' */
    if (rtb_Product1_a > 0.2) {
      rtb_Sum9 = 0.2;
    } else if (rtb_Product1_a < -0.2) {
      rtb_Sum9 = -0.2;
    } else {
      rtb_Sum9 = rtb_Product1_a;
    }

    /* End of Saturate: '<S31>/Saturation' */
  } else {
    rtb_Sum9 = 0.0;
  }

  /* End of Switch: '<S5>/Switch2' */

  /* Sum: '<S5>/Add3' */
  rtb_Product1_a = ((rtb_Gain_l[0] - rtb_u_j) + rtb_Switch1_k) + rtb_Sum9;

  /* Sum: '<S5>/Add2' */
  rtb_pdemscale2 = ((rtb_Gain_l[0] + rtb_u_j) + rtb_Switch1_k) - rtb_Sum9;

  /* Sum: '<S5>/Add1' */
  rtb_snapact = ((rtb_Gain_l[0] + rtb_u_j) - rtb_Switch1_k) + rtb_Sum9;

  /* Sum: '<S5>/Add' */
  rtb_u_j = ((rtb_Gain_l[0] - rtb_u_j) - rtb_Switch1_k) - rtb_Sum9;

  /* Sum: '<S28>/Add1' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S28>/Constant1'
   *  Gain: '<S28>/Gain'
   *  Sum: '<S28>/Add'
   */
  rtb_Product1_a = (rtb_Product1_a + 1.0) * 5000.0 + 10000.0;

  /* Saturate: '<S5>/Saturation1' */
  if (rtb_Product1_a > 20000.0) {
    /* Outport: '<Root>/servos' */
    Arduino_250_Y.servos[0] = 20000.0;
  } else if (rtb_Product1_a < 9000.0) {
    /* Outport: '<Root>/servos' */
    Arduino_250_Y.servos[0] = 9000.0;
  } else {
    /* Outport: '<Root>/servos' */
    Arduino_250_Y.servos[0] = rtb_Product1_a;
  }

  /* Sum: '<S28>/Add1' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S28>/Constant1'
   *  Gain: '<S28>/Gain'
   *  Sum: '<S28>/Add'
   */
  rtb_Product1_a = (rtb_pdemscale2 + 1.0) * 5000.0 + 10000.0;

  /* Saturate: '<S5>/Saturation1' */
  if (rtb_Product1_a > 20000.0) {
    /* Outport: '<Root>/servos' */
    Arduino_250_Y.servos[1] = 20000.0;
  } else if (rtb_Product1_a < 9000.0) {
    /* Outport: '<Root>/servos' */
    Arduino_250_Y.servos[1] = 9000.0;
  } else {
    /* Outport: '<Root>/servos' */
    Arduino_250_Y.servos[1] = rtb_Product1_a;
  }

  /* Sum: '<S28>/Add1' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S28>/Constant1'
   *  Gain: '<S28>/Gain'
   *  Sum: '<S28>/Add'
   */
  rtb_Product1_a = (rtb_snapact + 1.0) * 5000.0 + 10000.0;

  /* Saturate: '<S5>/Saturation1' */
  if (rtb_Product1_a > 20000.0) {
    /* Outport: '<Root>/servos' */
    Arduino_250_Y.servos[2] = 20000.0;
  } else if (rtb_Product1_a < 9000.0) {
    /* Outport: '<Root>/servos' */
    Arduino_250_Y.servos[2] = 9000.0;
  } else {
    /* Outport: '<Root>/servos' */
    Arduino_250_Y.servos[2] = rtb_Product1_a;
  }

  /* Sum: '<S28>/Add1' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S28>/Constant1'
   *  Gain: '<S28>/Gain'
   *  Sum: '<S28>/Add'
   */
  rtb_Product1_a = (rtb_u_j + 1.0) * 5000.0 + 10000.0;

  /* Saturate: '<S5>/Saturation1' */
  if (rtb_Product1_a > 20000.0) {
    /* Outport: '<Root>/servos' */
    Arduino_250_Y.servos[3] = 20000.0;
  } else if (rtb_Product1_a < 9000.0) {
    /* Outport: '<Root>/servos' */
    Arduino_250_Y.servos[3] = 9000.0;
  } else {
    /* Outport: '<Root>/servos' */
    Arduino_250_Y.servos[3] = rtb_Product1_a;
  }

  /* Outport: '<Root>/servos' incorporates:
   *  Constant: '<S28>/Constant1'
   *  Gain: '<S28>/Gain'
   *  Saturate: '<S5>/Saturation1'
   *  Sum: '<S28>/Add1'
   */
  Arduino_250_Y.servos[4] = 15000.0;
  Arduino_250_Y.servos[5] = 15000.0;
  Arduino_250_Y.servos[6] = 15000.0;
  Arduino_250_Y.servos[7] = 15000.0;

  /* Outport: '<Root>/addlog' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S3>/Constant1'
   *  DataTypeConversion: '<S11>/Data Type Conversion2'
   *  Gain: '<S11>/Gain3'
   *  Inport: '<Root>/extparams'
   *  Inport: '<Root>/rates'
   *  RelationalOperator: '<S13>/Compare'
   */
  Arduino_250_Y.addlog[0] = (rtb_Gain_l[5] >= 0.0);
  Arduino_250_Y.addlog[1] = Arduino_250_U.extparams[10];
  Arduino_250_Y.addlog[2] = Arduino_250_U.extparams[11];
  Arduino_250_Y.addlog[3] = Arduino_250_U.extparams[15];
  Arduino_250_Y.addlog[4] = Arduino_250_U.extparams[16];
  Arduino_250_Y.addlog[5] = Arduino_250_U.extparams[17];
  Arduino_250_Y.addlog[6] = Arduino_250_U.extparams[1];
  Arduino_250_Y.addlog[7] = rtb_Gain_l[0];
  Arduino_250_Y.addlog[8] = rtb_Gain_l[2];
  Arduino_250_Y.addlog[9] = -rtb_Gain_l[3];
  Arduino_250_Y.addlog[10] = rtb_Gain_l[4];
  Arduino_250_Y.addlog[11] = rtb_DataTypeConversion3;
  Arduino_250_Y.addlog[12] = Arduino_250_U.extparams[2];
  Arduino_250_Y.addlog[13] = Arduino_250_U.extparams[2];
  Arduino_250_Y.addlog[14] = Arduino_250_U.extparams[3];
  Arduino_250_Y.addlog[15] = Arduino_250_U.extparams[14];
  Arduino_250_Y.addlog[16] = Arduino_250_U.rates[0];
  Arduino_250_Y.addlog[17] = Arduino_250_U.rates[1];
  Arduino_250_Y.addlog[18] = Arduino_250_U.rates[2];
  Arduino_250_Y.addlog[19] = 0.0;
  Arduino_250_Y.addlog[20] = 0.0;
  Arduino_250_Y.addlog[21] = 0.0;
  Arduino_250_Y.addlog[22] = 0.0;
  Arduino_250_Y.addlog[23] = 0.0;
  Arduino_250_Y.addlog[24] = 0.0;
  Arduino_250_Y.addlog[25] = 0.0;
  Arduino_250_Y.addlog[26] = 0.0;
  Arduino_250_Y.addlog[27] = 0.0;
  Arduino_250_Y.addlog[28] = 0.0;
  Arduino_250_Y.addlog[29] = rtb_pdemscale;
  Arduino_250_Y.addlog[30] = 0.0;

  /* Switch: '<S39>/Switch' incorporates:
   *  Abs: '<S39>/Abs'
   */
  if (fabs(rtb_pdemscale) >= 0.65) {
    /* Switch: '<S39>/Switch1' */
    if (rtb_pdemscale >= 0.0) {
      /* Outport: '<Root>/addlog' incorporates:
       *  Constant: '<S39>/Constant'
       */
      Arduino_250_Y.addlog[31] = 9.42477796076938;
    } else {
      /* Outport: '<Root>/addlog' */
      Arduino_250_Y.addlog[31] = -9.42477796076938;
    }

    /* End of Switch: '<S39>/Switch1' */
  } else {
    /* Outport: '<Root>/addlog' */
    Arduino_250_Y.addlog[31] = 0.0;
  }

  /* End of Switch: '<S39>/Switch' */

  /* Logic: '<S35>/Logical Operator' incorporates:
   *  Constant: '<S35>/lower limit'
   *  Constant: '<S35>/upper limit'
   *  RelationalOperator: '<S35>/Relational Operator'
   *  RelationalOperator: '<S35>/Relational Operator1'
   */
  rtb_RelationalOperator = ((rtb_Add1_fm >= 0.4) || (rtb_Add1_fm <= -0.4));

  /* Logic: '<S40>/Logical Operator' incorporates:
   *  Constant: '<S40>/lower limit'
   *  Constant: '<S40>/upper limit'
   *  RelationalOperator: '<S40>/Relational Operator'
   *  RelationalOperator: '<S40>/Relational Operator1'
   */
  rtb_LogicalOperator_dn = ((rtb_Add1 >= 0.3) || (rtb_Add1 <= -0.3));

  /* Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */
  if (rtb_DataTypeConversion3 == 0.0) {
    /* Signum: '<S21>/Sign' */
    if (rtb_Add_o < 0.0) {
      rtb_Sum9 = -1.0;
    } else if (rtb_Add_o > 0.0) {
      rtb_Sum9 = 1.0;
    } else if (rtb_Add_o == 0.0) {
      rtb_Sum9 = 0.0;
    } else {
      rtb_Sum9 = rtb_Add_o;
    }

    /* Signum: '<S21>/Sign1' */
    if (rtb_Add1_j < 0.0) {
      rtb_Product1_a = -1.0;
    } else if (rtb_Add1_j > 0.0) {
      rtb_Product1_a = 1.0;
    } else if (rtb_Add1_j == 0.0) {
      rtb_Product1_a = 0.0;
    } else {
      rtb_Product1_a = rtb_Add1_j;
    }

    /* Switch: '<S22>/Switch' incorporates:
     *  Constant: '<S22>/Constant'
     *  Constant: '<S23>/lower limit'
     *  Constant: '<S23>/upper limit'
     *  Logic: '<S17>/Logical Operator'
     *  Logic: '<S21>/Logical Operator'
     *  Logic: '<S23>/Logical Operator'
     *  RelationalOperator: '<S21>/Relational Operator'
     *  RelationalOperator: '<S23>/Relational Operator'
     *  RelationalOperator: '<S23>/Relational Operator1'
     *  Signum: '<S21>/Sign'
     *  Signum: '<S21>/Sign1'
     */
    if (((rtb_Add1_j >= 3.1415926535897931) || (rtb_Add1_j <=
          -3.1415926535897931) || rtb_LogicalOperator_dn) && (rtb_Sum9 ==
         rtb_Product1_a)) {
      rtb_Add_o = 0.0;
    }

    /* End of Switch: '<S22>/Switch' */
    Arduino_250_DW.DiscreteTimeIntegrator_DSTATE += 0.005 * rtb_Add_o;
  }

  if (rtb_DataTypeConversion3 > 0.0) {
    Arduino_250_DW.DiscreteTimeIntegrator_PrevRese = 1;
  } else if (rtb_DataTypeConversion3 < 0.0) {
    Arduino_250_DW.DiscreteTimeIntegrator_PrevRese = -1;
  } else if (rtb_DataTypeConversion3 == 0.0) {
    Arduino_250_DW.DiscreteTimeIntegrator_PrevRese = 0;
  } else {
    Arduino_250_DW.DiscreteTimeIntegrator_PrevRese = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S38>/Discrete-Time Integrator' */
  if (rtb_DataTypeConversion3 == 0.0) {
    /* Signum: '<S37>/Sign' */
    if (rtb_Add_b < 0.0) {
      rtb_Sum9 = -1.0;
    } else if (rtb_Add_b > 0.0) {
      rtb_Sum9 = 1.0;
    } else if (rtb_Add_b == 0.0) {
      rtb_Sum9 = 0.0;
    } else {
      rtb_Sum9 = rtb_Add_b;
    }

    /* Signum: '<S37>/Sign1' */
    if (rtb_Add1 < 0.0) {
      rtb_Add1 = -1.0;
    } else if (rtb_Add1 > 0.0) {
      rtb_Add1 = 1.0;
    } else {
      if (rtb_Add1 == 0.0) {
        rtb_Add1 = 0.0;
      }
    }

    /* Switch: '<S38>/Switch' incorporates:
     *  Constant: '<S38>/Constant'
     *  Logic: '<S37>/Logical Operator'
     *  RelationalOperator: '<S37>/Relational Operator'
     *  Signum: '<S37>/Sign'
     *  Signum: '<S37>/Sign1'
     */
    if (rtb_LogicalOperator_dn && (rtb_Sum9 == rtb_Add1)) {
      rtb_Add_b = 0.0;
    }

    /* End of Switch: '<S38>/Switch' */
    Arduino_250_DW.DiscreteTimeIntegrator_DSTATE_l += 0.005 * rtb_Add_b;
  }

  if (rtb_DataTypeConversion3 > 0.0) {
    Arduino_250_DW.DiscreteTimeIntegrator_PrevRe_p = 1;
  } else if (rtb_DataTypeConversion3 < 0.0) {
    Arduino_250_DW.DiscreteTimeIntegrator_PrevRe_p = -1;
  } else if (rtb_DataTypeConversion3 == 0.0) {
    Arduino_250_DW.DiscreteTimeIntegrator_PrevRe_p = 0;
  } else {
    Arduino_250_DW.DiscreteTimeIntegrator_PrevRe_p = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S38>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S36>/UD' */
  Arduino_250_DW.UD_DSTATE = rtb_TSamp;

  /* Weighted Moving Average Block: '<S30>/Weighted Moving Average'
   */
  {
    /*
     * the top state is the current input
     */
    Arduino_250_DW.WeightedMovingAverage_TapDelayU = Arduino_250_B.Diff;
  }

  /* Update for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' */
  if (rtb_DataTypeConversion3 == 0.0) {
    /* Signum: '<S18>/Sign' */
    if (rtb_Add_j < 0.0) {
      rtb_Sum9 = -1.0;
    } else if (rtb_Add_j > 0.0) {
      rtb_Sum9 = 1.0;
    } else if (rtb_Add_j == 0.0) {
      rtb_Sum9 = 0.0;
    } else {
      rtb_Sum9 = rtb_Add_j;
    }

    /* Signum: '<S18>/Sign1' */
    if (rtb_Add1_ms < 0.0) {
      rtb_Product1_a = -1.0;
    } else if (rtb_Add1_ms > 0.0) {
      rtb_Product1_a = 1.0;
    } else if (rtb_Add1_ms == 0.0) {
      rtb_Product1_a = 0.0;
    } else {
      rtb_Product1_a = rtb_Add1_ms;
    }

    /* Switch: '<S19>/Switch' incorporates:
     *  Constant: '<S19>/Constant'
     *  Constant: '<S20>/lower limit'
     *  Constant: '<S20>/upper limit'
     *  Logic: '<S16>/Logical Operator'
     *  Logic: '<S18>/Logical Operator'
     *  Logic: '<S20>/Logical Operator'
     *  RelationalOperator: '<S18>/Relational Operator'
     *  RelationalOperator: '<S20>/Relational Operator'
     *  RelationalOperator: '<S20>/Relational Operator1'
     *  Signum: '<S18>/Sign'
     *  Signum: '<S18>/Sign1'
     */
    if (((rtb_Add1_ms >= 3.1415926535897931) || (rtb_Add1_ms <=
          -3.1415926535897931) || rtb_RelationalOperator) && (rtb_Sum9 ==
         rtb_Product1_a)) {
      rtb_Add_j = 0.0;
    }

    /* End of Switch: '<S19>/Switch' */
    Arduino_250_DW.DiscreteTimeIntegrator_DSTATE_k += 0.005 * rtb_Add_j;
  }

  if (rtb_DataTypeConversion3 > 0.0) {
    Arduino_250_DW.DiscreteTimeIntegrator_PrevRe_c = 1;
  } else if (rtb_DataTypeConversion3 < 0.0) {
    Arduino_250_DW.DiscreteTimeIntegrator_PrevRe_c = -1;
  } else if (rtb_DataTypeConversion3 == 0.0) {
    Arduino_250_DW.DiscreteTimeIntegrator_PrevRe_c = 0;
  } else {
    Arduino_250_DW.DiscreteTimeIntegrator_PrevRe_c = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S34>/Discrete-Time Integrator' */
  if (rtb_DataTypeConversion3 == 0.0) {
    /* Signum: '<S33>/Sign' */
    if (rtb_Add_ay < 0.0) {
      rtb_Sum9 = -1.0;
    } else if (rtb_Add_ay > 0.0) {
      rtb_Sum9 = 1.0;
    } else if (rtb_Add_ay == 0.0) {
      rtb_Sum9 = 0.0;
    } else {
      rtb_Sum9 = rtb_Add_ay;
    }

    /* Signum: '<S33>/Sign1' */
    if (rtb_Add1_fm < 0.0) {
      rtb_Add1_fm = -1.0;
    } else if (rtb_Add1_fm > 0.0) {
      rtb_Add1_fm = 1.0;
    } else {
      if (rtb_Add1_fm == 0.0) {
        rtb_Add1_fm = 0.0;
      }
    }

    /* Switch: '<S34>/Switch' incorporates:
     *  Constant: '<S34>/Constant'
     *  Logic: '<S33>/Logical Operator'
     *  RelationalOperator: '<S33>/Relational Operator'
     *  Signum: '<S33>/Sign'
     *  Signum: '<S33>/Sign1'
     */
    if (rtb_RelationalOperator && (rtb_Sum9 == rtb_Add1_fm)) {
      rtb_Add_ay = 0.0;
    }

    /* End of Switch: '<S34>/Switch' */
    Arduino_250_DW.DiscreteTimeIntegrator_DSTATE_n += 0.005 * rtb_Add_ay;
  }

  if (rtb_DataTypeConversion3 > 0.0) {
    Arduino_250_DW.DiscreteTimeIntegrator_PrevRe_d = 1;
  } else if (rtb_DataTypeConversion3 < 0.0) {
    Arduino_250_DW.DiscreteTimeIntegrator_PrevRe_d = -1;
  } else if (rtb_DataTypeConversion3 == 0.0) {
    Arduino_250_DW.DiscreteTimeIntegrator_PrevRe_d = 0;
  } else {
    Arduino_250_DW.DiscreteTimeIntegrator_PrevRe_d = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S34>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S32>/UD' */
  Arduino_250_DW.UD_DSTATE_h = rtb_TSamp_l;

  /* Weighted Moving Average Block: '<S29>/Weighted Moving Average'
   */
  {
    /*
     * the top state is the current input
     */
    Arduino_250_DW.WeightedMovingAverage_TapDela_c = Arduino_250_B.Diff_i;
  }
}

/* Model initialize function */
void Arduino_250_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Arduino_250_M, (NULL));

  /* block I/O */
  {
    Arduino_250_B.Diff = 0.0;
    Arduino_250_B.Diff_i = 0.0;
    Arduino_250_B.in = 0.0;
  }

  /* states (dwork) */
  (void) memset((void *)&Arduino_250_DW, 0,
                sizeof(DW_Arduino_250_T));
  Arduino_250_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
  Arduino_250_DW.DiscreteTimeIntegrator_DSTATE_l = 0.0;
  Arduino_250_DW.UD_DSTATE = 0.0;
  Arduino_250_DW.WeightedMovingAverage_TapDelayU = 0.0;
  Arduino_250_DW.DiscreteTimeIntegrator_DSTATE_k = 0.0;
  Arduino_250_DW.DiscreteTimeIntegrator_DSTATE_n = 0.0;
  Arduino_250_DW.UD_DSTATE_h = 0.0;
  Arduino_250_DW.WeightedMovingAverage_TapDela_c = 0.0;

  /* external inputs */
  Arduino_250_U.rates[0] = 0.0;
  Arduino_250_U.rates[1] = 0.0;
  Arduino_250_U.rates[2] = 0.0;

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      Arduino_250_U.rx[i] = 0.0;
    }
  }

  Arduino_250_U.ahrs[0] = 0.0;
  Arduino_250_U.ahrs[1] = 0.0;
  Arduino_250_U.ahrs[2] = 0.0;

  {
    int_T i;
    for (i = 0; i < 64; i++) {
      Arduino_250_U.extparams[i] = 0.0;
    }
  }

  /* external outputs */
  {
    int_T i;
    for (i = 0; i < 8; i++) {
      Arduino_250_Y.servos[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 32; i++) {
      Arduino_250_Y.addlog[i] = 0.0;
    }
  }

  Arduino_250_PrevZCX.grabheading_Trig_ZCE = POS_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */
  Arduino_250_DW.DiscreteTimeIntegrator_PrevRese = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S38>/Discrete-Time Integrator' */
  Arduino_250_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' */
  Arduino_250_DW.DiscreteTimeIntegrator_PrevRe_c = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S34>/Discrete-Time Integrator' */
  Arduino_250_DW.DiscreteTimeIntegrator_PrevRe_d = 0;
}

/* Model terminate function */
void Arduino_250_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
