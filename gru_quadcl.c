/*
 * File: gru_quadcl.c
 *
 * Code generated for Simulink model 'gru_quadcl'.
 *
 * Model version                  : 1.1213
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Sun Aug 09 13:31:23 2015
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
  real_T rtb_DataTypeConversion3;
  real_T rtb_Switch1_k;
  real_T rtb_u_j;
  real_T rtb_Gain[8];
  real_T rtb_pdemscale;
  real_T rtb_Switch_l;
  real_T rtb_Add_o;
  boolean_T rtb_LogicalOperator_dp;
  real_T rtb_Add1_j;
  real_T rtb_Saturation_j;
  real_T rtb_Add_b;
  real_T rtb_Product1_a;
  real_T rtb_TSamp;
  real_T rtb_Add_j;
  real_T rtb_Add1_ms;
  real_T rtb_Add_ay;
  real_T rtb_TSamp_l;
  real_T rtb_snapact;
  real_T rtb_Add1;
  boolean_T rtb_LogicalOperator_p;
  real_T rtb_Switch2;
  real_T rtb_u;
  real_T rtb_u_cy;
  int16_T i;

  /* Gain: '<S13>/Gain' incorporates:
   *  Constant: '<S13>/Constant'
   *  Inport: '<Root>/rx'
   *  Sum: '<S13>/Add'
   */
  for (i = 0; i < 8; i++) {
    rtb_Gain[i] = (gru_quadcl_U.rx[i] - 15000.0) * 0.0002;
  }

  /* End of Gain: '<S13>/Gain' */

  /* Gain: '<S5>/p dem scale' incorporates:
   *  Inport: '<Root>/extparams'
   *  Product: '<S5>/Product1'
   */
  rtb_pdemscale = rtb_Gain[2] * gru_quadcl_U.extparams[6] * 0.017453292519943295;

  /* Sum: '<S15>/Add' incorporates:
   *  Inport: '<Root>/ahrs'
   */
  rtb_Add_o = rtb_pdemscale - gru_quadcl_U.ahrs[0];

  /* DataTypeConversion: '<S9>/Data Type Conversion3' incorporates:
   *  Constant: '<S10>/Constant'
   *  Logic: '<S9>/Logical Operator'
   *  RelationalOperator: '<S10>/Compare'
   */
  rtb_DataTypeConversion3 = !(rtb_Gain[0] >= -0.6);

  /* DiscreteIntegrator: '<S20>/Discrete-Time Integrator' */
  if ((rtb_DataTypeConversion3 != 0.0) ||
      (gru_quadcl_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
    gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
  }

  /* Sum: '<S15>/Add1' incorporates:
   *  DiscreteIntegrator: '<S20>/Discrete-Time Integrator'
   *  Inport: '<Root>/extparams'
   *  Product: '<S15>/Product'
   *  Product: '<S15>/Product1'
   */
  rtb_Add1_j = rtb_Add_o * gru_quadcl_U.extparams[4] + gru_quadcl_U.extparams[5]
    * gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE;

  /* Saturate: '<S21>/Saturation' */
  if (rtb_Add1_j > 3.1415926535897931) {
    rtb_Saturation_j = 3.1415926535897931;
  } else if (rtb_Add1_j < -3.1415926535897931) {
    rtb_Saturation_j = -3.1415926535897931;
  } else {
    rtb_Saturation_j = rtb_Add1_j;
  }

  /* End of Saturate: '<S21>/Saturation' */

  /* Switch: '<S33>/Switch' incorporates:
   *  Abs: '<S33>/Abs'
   */
  if (fabs(rtb_pdemscale) >= 0.65) {
    /* Switch: '<S33>/Switch1' incorporates:
     *  Constant: '<S33>/Constant'
     */
    if (rtb_pdemscale >= 0.0) {
      rtb_Switch_l = 9.42477796076938;
    } else {
      rtb_Switch_l = -9.42477796076938;
    }
  } else {
    /* Switch: '<S33>/Switch1' */
    rtb_Switch_l = rtb_Saturation_j;
  }

  /* End of Switch: '<S33>/Switch' */

  /* Sum: '<S24>/Add' incorporates:
   *  Inport: '<Root>/rates'
   */
  rtb_Add_b = rtb_Switch_l - gru_quadcl_U.rates[0];

  /* DiscreteIntegrator: '<S32>/Discrete-Time Integrator' */
  if ((rtb_DataTypeConversion3 != 0.0) ||
      (gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_p != 0)) {
    gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_l = 0.0;
  }

  rtb_u_j = gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_l;

  /* End of DiscreteIntegrator: '<S32>/Discrete-Time Integrator' */

  /* Product: '<S24>/Product1' incorporates:
   *  Inport: '<Root>/extparams'
   */
  rtb_Product1_a = gru_quadcl_U.extparams[10] * rtb_u_j;

  /* UnaryMinus: '<S24>/Unary Minus' incorporates:
   *  Inport: '<Root>/rates'
   */
  rtb_u_j = -gru_quadcl_U.rates[0];

  /* SampleTimeMath: '<S30>/TSamp'
   *
   * About '<S30>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = rtb_u_j * 200.0;

  /* Sum: '<S30>/Diff' incorporates:
   *  UnitDelay: '<S30>/UD'
   */
  gru_quadcl_B.Diff = rtb_TSamp - gru_quadcl_DW.UD_DSTATE;

  /* Weighted Moving Average Block: '<S24>/Weighted Moving Average'
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
    rtb_u_j = gru_quadcl_B.Diff * 0.5;
    yTemp1 = gru_quadcl_DW.WeightedMovingAverage_TapDelayU * 0.5;
    rtb_u_j = rtb_u_j + yTemp1;
  }

  /* Sum: '<S24>/Add1' incorporates:
   *  Inport: '<Root>/extparams'
   *  Product: '<S24>/Product'
   *  Product: '<S24>/Product2'
   */
  rtb_Add1 = (rtb_Add_b * gru_quadcl_U.extparams[0] + rtb_Product1_a) +
    gru_quadcl_U.extparams[11] * rtb_u_j;

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Constant'
   */
  if (rtb_Gain[0] >= -0.8) {
    /* Saturate: '<S34>/Saturation' */
    if (rtb_Add1 > 0.3) {
      rtb_u_j = 0.3;
    } else if (rtb_Add1 < -0.3) {
      rtb_u_j = -0.3;
    } else {
      rtb_u_j = rtb_Add1;
    }

    /* End of Saturate: '<S34>/Saturation' */
  } else {
    rtb_u_j = 0.0;
  }

  /* End of Switch: '<S4>/Switch' */

  /* Sum: '<S14>/Add' incorporates:
   *  Gain: '<S5>/p dem scale1'
   *  Gain: '<S9>/Gain3'
   *  Inport: '<Root>/ahrs'
   *  Inport: '<Root>/extparams'
   *  Product: '<S5>/Product2'
   */
  rtb_Add_j = -rtb_Gain[3] * gru_quadcl_U.extparams[6] * 0.017453292519943295 -
    gru_quadcl_U.ahrs[1];

  /* DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
  if ((rtb_DataTypeConversion3 != 0.0) ||
      (gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_c != 0)) {
    gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_k = 0.0;
  }

  /* Sum: '<S14>/Add1' incorporates:
   *  DiscreteIntegrator: '<S17>/Discrete-Time Integrator'
   *  Inport: '<Root>/extparams'
   *  Product: '<S14>/Product'
   *  Product: '<S14>/Product1'
   */
  rtb_Add1_ms = rtb_Add_j * gru_quadcl_U.extparams[4] + gru_quadcl_U.extparams[5]
    * gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_k;

  /* Saturate: '<S18>/Saturation' */
  if (rtb_Add1_ms > 3.1415926535897931) {
    rtb_Switch2 = 3.1415926535897931;
  } else if (rtb_Add1_ms < -3.1415926535897931) {
    rtb_Switch2 = -3.1415926535897931;
  } else {
    rtb_Switch2 = rtb_Add1_ms;
  }

  /* Sum: '<S23>/Add' incorporates:
   *  Inport: '<Root>/rates'
   *  Saturate: '<S18>/Saturation'
   */
  rtb_Add_ay = rtb_Switch2 - gru_quadcl_U.rates[1];

  /* DiscreteIntegrator: '<S28>/Discrete-Time Integrator' */
  if ((rtb_DataTypeConversion3 != 0.0) ||
      (gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_d != 0)) {
    gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_n = 0.0;
  }

  rtb_Switch1_k = gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_n;

  /* End of DiscreteIntegrator: '<S28>/Discrete-Time Integrator' */

  /* Product: '<S23>/Product1' incorporates:
   *  Inport: '<Root>/extparams'
   */
  rtb_Product1_a = gru_quadcl_U.extparams[16] * rtb_Switch1_k;

  /* UnaryMinus: '<S23>/Unary Minus' incorporates:
   *  Inport: '<Root>/rates'
   */
  rtb_Switch1_k = -gru_quadcl_U.rates[1];

  /* SampleTimeMath: '<S26>/TSamp'
   *
   * About '<S26>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_l = rtb_Switch1_k * 200.0;

  /* Sum: '<S26>/Diff' incorporates:
   *  UnitDelay: '<S26>/UD'
   */
  gru_quadcl_B.Diff_i = rtb_TSamp_l - gru_quadcl_DW.UD_DSTATE_h;

  /* Weighted Moving Average Block: '<S23>/Weighted Moving Average'
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
    rtb_Switch1_k = gru_quadcl_B.Diff_i * 0.5;
    yTemp1 = gru_quadcl_DW.WeightedMovingAverage_TapDela_c * 0.5;
    rtb_Switch1_k = rtb_Switch1_k + yTemp1;
  }

  /* Sum: '<S23>/Add1' incorporates:
   *  Inport: '<Root>/extparams'
   *  Product: '<S23>/Product'
   *  Product: '<S23>/Product2'
   */
  rtb_Product1_a = (rtb_Add_ay * gru_quadcl_U.extparams[15] + rtb_Product1_a) +
    gru_quadcl_U.extparams[17] * rtb_Switch1_k;

  /* Switch: '<S4>/Switch1' incorporates:
   *  Constant: '<S4>/Constant'
   */
  if (rtb_Gain[0] >= -0.8) {
    /* Saturate: '<S29>/Saturation' */
    if (rtb_Product1_a > 0.4) {
      rtb_Switch1_k = 0.4;
    } else if (rtb_Product1_a < -0.4) {
      rtb_Switch1_k = -0.4;
    } else {
      rtb_Switch1_k = rtb_Product1_a;
    }

    /* End of Saturate: '<S29>/Saturation' */
  } else {
    rtb_Switch1_k = 0.0;
  }

  /* End of Switch: '<S4>/Switch1' */

  /* Switch: '<S4>/Switch2' incorporates:
   *  Constant: '<S4>/Constant'
   */
  if (rtb_Gain[0] >= -0.8) {
    /* Product: '<S25>/Product' incorporates:
     *  Gain: '<S5>/p dem scale2'
     *  Inport: '<Root>/extparams'
     *  Inport: '<Root>/rates'
     *  Product: '<S5>/Product3'
     *  Sum: '<S25>/Add'
     */
    rtb_Switch2 = (rtb_Gain[4] * gru_quadcl_U.extparams[3] *
                   0.017453292519943295 - gru_quadcl_U.rates[2]) *
      gru_quadcl_U.extparams[1];

    /* Saturate: '<S25>/Saturation' */
    if (rtb_Switch2 > 0.2) {
      rtb_Switch2 = 0.2;
    } else {
      if (rtb_Switch2 < -0.2) {
        rtb_Switch2 = -0.2;
      }
    }

    /* End of Saturate: '<S25>/Saturation' */
  } else {
    rtb_Switch2 = 0.0;
  }

  /* End of Switch: '<S4>/Switch2' */

  /* Sum: '<S4>/Add3' */
  rtb_u = ((rtb_Gain[0] - rtb_u_j) + rtb_Switch1_k) + rtb_Switch2;

  /* Sum: '<S4>/Add2' */
  rtb_u_cy = ((rtb_Gain[0] + rtb_u_j) + rtb_Switch1_k) - rtb_Switch2;

  /* Sum: '<S4>/Add1' */
  rtb_snapact = ((rtb_Gain[0] + rtb_u_j) - rtb_Switch1_k) + rtb_Switch2;

  /* Sum: '<S4>/Add' */
  rtb_u_j = ((rtb_Gain[0] - rtb_u_j) - rtb_Switch1_k) - rtb_Switch2;

  /* Sum: '<S22>/Add1' incorporates:
   *  Constant: '<S22>/Constant'
   *  Constant: '<S22>/Constant1'
   *  Gain: '<S22>/Gain'
   *  Sum: '<S22>/Add'
   */
  rtb_u = (rtb_u + 1.0) * 5000.0 + 10000.0;

  /* Saturate: '<S4>/Saturation1' */
  if (rtb_u > 20000.0) {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[0] = 20000.0;
  } else if (rtb_u < 9000.0) {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[0] = 9000.0;
  } else {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[0] = rtb_u;
  }

  /* Sum: '<S22>/Add1' incorporates:
   *  Constant: '<S22>/Constant'
   *  Constant: '<S22>/Constant1'
   *  Gain: '<S22>/Gain'
   *  Sum: '<S22>/Add'
   */
  rtb_u = (rtb_u_cy + 1.0) * 5000.0 + 10000.0;

  /* Saturate: '<S4>/Saturation1' */
  if (rtb_u > 20000.0) {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[1] = 20000.0;
  } else if (rtb_u < 9000.0) {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[1] = 9000.0;
  } else {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[1] = rtb_u;
  }

  /* Sum: '<S22>/Add1' incorporates:
   *  Constant: '<S22>/Constant'
   *  Constant: '<S22>/Constant1'
   *  Gain: '<S22>/Gain'
   *  Sum: '<S22>/Add'
   */
  rtb_u = (rtb_snapact + 1.0) * 5000.0 + 10000.0;

  /* Saturate: '<S4>/Saturation1' */
  if (rtb_u > 20000.0) {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[2] = 20000.0;
  } else if (rtb_u < 9000.0) {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[2] = 9000.0;
  } else {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[2] = rtb_u;
  }

  /* Sum: '<S22>/Add1' incorporates:
   *  Constant: '<S22>/Constant'
   *  Constant: '<S22>/Constant1'
   *  Gain: '<S22>/Gain'
   *  Sum: '<S22>/Add'
   */
  rtb_u = (rtb_u_j + 1.0) * 5000.0 + 10000.0;

  /* Saturate: '<S4>/Saturation1' */
  if (rtb_u > 20000.0) {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[3] = 20000.0;
  } else if (rtb_u < 9000.0) {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[3] = 9000.0;
  } else {
    /* Outport: '<Root>/servos' */
    gru_quadcl_Y.servos[3] = rtb_u;
  }

  /* Outport: '<Root>/servos' incorporates:
   *  Constant: '<S22>/Constant1'
   *  Gain: '<S22>/Gain'
   *  Saturate: '<S4>/Saturation1'
   *  Sum: '<S22>/Add1'
   */
  gru_quadcl_Y.servos[4] = 15000.0;
  gru_quadcl_Y.servos[5] = 15000.0;
  gru_quadcl_Y.servos[6] = 15000.0;
  gru_quadcl_Y.servos[7] = 15000.0;

  /* Outport: '<Root>/addlog' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S3>/Constant1'
   *  DataTypeConversion: '<S9>/Data Type Conversion2'
   *  Gain: '<S9>/Gain3'
   *  Inport: '<Root>/extparams'
   *  Inport: '<Root>/rates'
   *  RelationalOperator: '<S11>/Compare'
   */
  gru_quadcl_Y.addlog[0] = (rtb_Gain[5] >= 0.0);
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
  gru_quadcl_Y.addlog[19] = 0.0;
  gru_quadcl_Y.addlog[20] = 0.0;
  gru_quadcl_Y.addlog[21] = 0.0;
  gru_quadcl_Y.addlog[22] = 0.0;
  gru_quadcl_Y.addlog[23] = 0.0;
  gru_quadcl_Y.addlog[24] = 0.0;
  gru_quadcl_Y.addlog[25] = 0.0;
  gru_quadcl_Y.addlog[26] = 0.0;
  gru_quadcl_Y.addlog[27] = 0.0;
  gru_quadcl_Y.addlog[28] = 0.0;
  gru_quadcl_Y.addlog[29] = rtb_pdemscale;
  gru_quadcl_Y.addlog[30] = rtb_Saturation_j;
  gru_quadcl_Y.addlog[31] = rtb_Switch_l;

  /* Logic: '<S29>/Logical Operator' incorporates:
   *  Constant: '<S29>/lower limit'
   *  Constant: '<S29>/upper limit'
   *  RelationalOperator: '<S29>/Relational Operator'
   *  RelationalOperator: '<S29>/Relational Operator1'
   */
  rtb_LogicalOperator_dp = ((rtb_Product1_a >= 0.4) || (rtb_Product1_a <= -0.4));

  /* Logic: '<S34>/Logical Operator' incorporates:
   *  Constant: '<S34>/lower limit'
   *  Constant: '<S34>/upper limit'
   *  RelationalOperator: '<S34>/Relational Operator'
   *  RelationalOperator: '<S34>/Relational Operator1'
   */
  rtb_LogicalOperator_p = ((rtb_Add1 >= 0.3) || (rtb_Add1 <= -0.3));

  /* Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' */
  if (rtb_DataTypeConversion3 == 0.0) {
    /* Signum: '<S19>/Sign' */
    if (rtb_Add_o < 0.0) {
      rtb_u = -1.0;
    } else if (rtb_Add_o > 0.0) {
      rtb_u = 1.0;
    } else if (rtb_Add_o == 0.0) {
      rtb_u = 0.0;
    } else {
      rtb_u = rtb_Add_o;
    }

    /* Signum: '<S19>/Sign1' */
    if (rtb_Add1_j < 0.0) {
      rtb_Switch2 = -1.0;
    } else if (rtb_Add1_j > 0.0) {
      rtb_Switch2 = 1.0;
    } else if (rtb_Add1_j == 0.0) {
      rtb_Switch2 = 0.0;
    } else {
      rtb_Switch2 = rtb_Add1_j;
    }

    /* Switch: '<S20>/Switch' incorporates:
     *  Constant: '<S20>/Constant'
     *  Constant: '<S21>/lower limit'
     *  Constant: '<S21>/upper limit'
     *  Logic: '<S15>/Logical Operator'
     *  Logic: '<S19>/Logical Operator'
     *  Logic: '<S21>/Logical Operator'
     *  RelationalOperator: '<S19>/Relational Operator'
     *  RelationalOperator: '<S21>/Relational Operator'
     *  RelationalOperator: '<S21>/Relational Operator1'
     *  Signum: '<S19>/Sign'
     *  Signum: '<S19>/Sign1'
     */
    if (((rtb_Add1_j >= 3.1415926535897931) || (rtb_Add1_j <=
          -3.1415926535897931) || rtb_LogicalOperator_p) && (rtb_u ==
         rtb_Switch2)) {
      rtb_Add_o = 0.0;
    }

    /* End of Switch: '<S20>/Switch' */
    gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE += 0.005 * rtb_Add_o;
  }

  if (rtb_DataTypeConversion3 > 0.0) {
    gru_quadcl_DW.DiscreteTimeIntegrator_PrevRese = 1;
  } else if (rtb_DataTypeConversion3 < 0.0) {
    gru_quadcl_DW.DiscreteTimeIntegrator_PrevRese = -1;
  } else if (rtb_DataTypeConversion3 == 0.0) {
    gru_quadcl_DW.DiscreteTimeIntegrator_PrevRese = 0;
  } else {
    gru_quadcl_DW.DiscreteTimeIntegrator_PrevRese = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S32>/Discrete-Time Integrator' */
  if (rtb_DataTypeConversion3 == 0.0) {
    /* Signum: '<S31>/Sign' */
    if (rtb_Add_b < 0.0) {
      rtb_u = -1.0;
    } else if (rtb_Add_b > 0.0) {
      rtb_u = 1.0;
    } else if (rtb_Add_b == 0.0) {
      rtb_u = 0.0;
    } else {
      rtb_u = rtb_Add_b;
    }

    /* Signum: '<S31>/Sign1' */
    if (rtb_Add1 < 0.0) {
      rtb_Add1 = -1.0;
    } else if (rtb_Add1 > 0.0) {
      rtb_Add1 = 1.0;
    } else {
      if (rtb_Add1 == 0.0) {
        rtb_Add1 = 0.0;
      }
    }

    /* Switch: '<S32>/Switch' incorporates:
     *  Constant: '<S32>/Constant'
     *  Logic: '<S31>/Logical Operator'
     *  RelationalOperator: '<S31>/Relational Operator'
     *  Signum: '<S31>/Sign'
     *  Signum: '<S31>/Sign1'
     */
    if (rtb_LogicalOperator_p && (rtb_u == rtb_Add1)) {
      rtb_Add_b = 0.0;
    }

    /* End of Switch: '<S32>/Switch' */
    gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_l += 0.005 * rtb_Add_b;
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

  /* End of Update for DiscreteIntegrator: '<S32>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S30>/UD' */
  gru_quadcl_DW.UD_DSTATE = rtb_TSamp;

  /* Weighted Moving Average Block: '<S24>/Weighted Moving Average'
   */
  {
    /*
     * the top state is the current input
     */
    gru_quadcl_DW.WeightedMovingAverage_TapDelayU = gru_quadcl_B.Diff;
  }

  /* Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
  if (rtb_DataTypeConversion3 == 0.0) {
    /* Signum: '<S16>/Sign' */
    if (rtb_Add_j < 0.0) {
      rtb_u = -1.0;
    } else if (rtb_Add_j > 0.0) {
      rtb_u = 1.0;
    } else if (rtb_Add_j == 0.0) {
      rtb_u = 0.0;
    } else {
      rtb_u = rtb_Add_j;
    }

    /* Signum: '<S16>/Sign1' */
    if (rtb_Add1_ms < 0.0) {
      rtb_Switch2 = -1.0;
    } else if (rtb_Add1_ms > 0.0) {
      rtb_Switch2 = 1.0;
    } else if (rtb_Add1_ms == 0.0) {
      rtb_Switch2 = 0.0;
    } else {
      rtb_Switch2 = rtb_Add1_ms;
    }

    /* Switch: '<S17>/Switch' incorporates:
     *  Constant: '<S17>/Constant'
     *  Constant: '<S18>/lower limit'
     *  Constant: '<S18>/upper limit'
     *  Logic: '<S14>/Logical Operator'
     *  Logic: '<S16>/Logical Operator'
     *  Logic: '<S18>/Logical Operator'
     *  RelationalOperator: '<S16>/Relational Operator'
     *  RelationalOperator: '<S18>/Relational Operator'
     *  RelationalOperator: '<S18>/Relational Operator1'
     *  Signum: '<S16>/Sign'
     *  Signum: '<S16>/Sign1'
     */
    if (((rtb_Add1_ms >= 3.1415926535897931) || (rtb_Add1_ms <=
          -3.1415926535897931) || rtb_LogicalOperator_dp) && (rtb_u ==
         rtb_Switch2)) {
      rtb_Add_j = 0.0;
    }

    /* End of Switch: '<S17>/Switch' */
    gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_k += 0.005 * rtb_Add_j;
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

  /* End of Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S28>/Discrete-Time Integrator' */
  if (rtb_DataTypeConversion3 == 0.0) {
    /* Signum: '<S27>/Sign' */
    if (rtb_Add_ay < 0.0) {
      rtb_u = -1.0;
    } else if (rtb_Add_ay > 0.0) {
      rtb_u = 1.0;
    } else if (rtb_Add_ay == 0.0) {
      rtb_u = 0.0;
    } else {
      rtb_u = rtb_Add_ay;
    }

    /* Signum: '<S27>/Sign1' */
    if (rtb_Product1_a < 0.0) {
      rtb_Product1_a = -1.0;
    } else if (rtb_Product1_a > 0.0) {
      rtb_Product1_a = 1.0;
    } else {
      if (rtb_Product1_a == 0.0) {
        rtb_Product1_a = 0.0;
      }
    }

    /* Switch: '<S28>/Switch' incorporates:
     *  Constant: '<S28>/Constant'
     *  Logic: '<S27>/Logical Operator'
     *  RelationalOperator: '<S27>/Relational Operator'
     *  Signum: '<S27>/Sign'
     *  Signum: '<S27>/Sign1'
     */
    if (rtb_LogicalOperator_dp && (rtb_u == rtb_Product1_a)) {
      rtb_Add_ay = 0.0;
    }

    /* End of Switch: '<S28>/Switch' */
    gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_n += 0.005 * rtb_Add_ay;
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

  /* End of Update for DiscreteIntegrator: '<S28>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S26>/UD' */
  gru_quadcl_DW.UD_DSTATE_h = rtb_TSamp_l;

  /* Weighted Moving Average Block: '<S23>/Weighted Moving Average'
   */
  {
    /*
     * the top state is the current input
     */
    gru_quadcl_DW.WeightedMovingAverage_TapDela_c = gru_quadcl_B.Diff_i;
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
    gru_quadcl_B.Diff_i = 0.0;
  }

  /* states (dwork) */
  (void) memset((void *)&gru_quadcl_DW, 0,
                sizeof(DW_gru_quadcl_T));
  gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
  gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_l = 0.0;
  gru_quadcl_DW.UD_DSTATE = 0.0;
  gru_quadcl_DW.WeightedMovingAverage_TapDelayU = 0.0;
  gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_k = 0.0;
  gru_quadcl_DW.DiscreteTimeIntegrator_DSTATE_n = 0.0;
  gru_quadcl_DW.UD_DSTATE_h = 0.0;
  gru_quadcl_DW.WeightedMovingAverage_TapDela_c = 0.0;

  /* external inputs */
  gru_quadcl_U.rates[0] = 0.0;
  gru_quadcl_U.rates[1] = 0.0;
  gru_quadcl_U.rates[2] = 0.0;

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      gru_quadcl_U.rx[i] = 0.0;
    }
  }

  gru_quadcl_U.ahrs[0] = 0.0;
  gru_quadcl_U.ahrs[1] = 0.0;
  gru_quadcl_U.ahrs[2] = 0.0;
  gru_quadcl_U.ahrs[3] = 0.0;

  {
    int_T i;
    for (i = 0; i < 64; i++) {
      gru_quadcl_U.extparams[i] = 0.0;
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

  /* InitializeConditions for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' */
  gru_quadcl_DW.DiscreteTimeIntegrator_PrevRese = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S32>/Discrete-Time Integrator' */
  gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
  gru_quadcl_DW.DiscreteTimeIntegrator_PrevRe_c = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S28>/Discrete-Time Integrator' */
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
