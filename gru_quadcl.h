/*
 * File: gru_quadcl.h
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

#ifndef RTW_HEADER_gru_quadcl_h_
#define RTW_HEADER_gru_quadcl_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef gru_quadcl_COMMON_INCLUDES_
# define gru_quadcl_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* gru_quadcl_COMMON_INCLUDES_ */

#include "gru_quadcl_types.h"
#include "rt_zcfcn.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Diff;                         /* '<S24>/Diff' */
  real_T Product2;                     /* '<S43>/Product2' */
  real_T Product2_f;                   /* '<S42>/Product2' */
  real_T in;                           /* '<S38>/in' */
  real_T in_k;                         /* '<S27>/in' */
} B_gru_quadcl_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S26>/Discrete-Time Integrator' */
  real_T UD_DSTATE;                    /* '<S24>/UD' */
  real_T WeightedMovingAverage_TapDelayU[9];/* '<S3>/Weighted Moving Average' */
  real_T DiscreteTimeIntegrator_DSTATE_i;/* '<S35>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_l;/* '<S51>/Discrete-Time Integrator' */
  real_T UD_DSTATE_n;                  /* '<S49>/UD' */
  real_T WeightedMovingAverage_TapDela_f;/* '<S43>/Weighted Moving Average' */
  real_T DiscreteTimeIntegrator_DSTATE_k;/* '<S32>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_n;/* '<S47>/Discrete-Time Integrator' */
  real_T UD_DSTATE_h;                  /* '<S45>/UD' */
  real_T WeightedMovingAverage_TapDel_fo;/* '<S42>/Weighted Moving Average' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S26>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_i;/* '<S35>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S51>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_c;/* '<S32>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_d;/* '<S47>/Discrete-Time Integrator' */
} DW_gru_quadcl_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState grabheading_Trig_ZCE;     /* '<S6>/grab heading' */
  ZCSigState grabaltitude_Trig_ZCE;    /* '<S3>/grab altitude' */
  ZCSigState grabalt_Trig_ZCE;         /* '<S13>/grab alt' */
  ZCSigState grablatlongscaling_Trig_ZCE;/* '<S12>/grab lat//long scaling' */
} PrevZCX_gru_quadcl_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Expression: mgainval
   * Referenced by: '<S3>/Weighted Moving Average'
   */
  real_T WeightedMovingAverag[10];
} ConstP_gru_quadcl_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T rates[3];                     /* '<Root>/rates' */
  real_T accels[3];                    /* '<Root>/accels' */
  real_T magneto[3];                   /* '<Root>/magneto' */
  real_T airdata[3];                   /* '<Root>/airdata' */
  real_T rx[8];                        /* '<Root>/rx' */
  real_T gps[9];                       /* '<Root>/gps' */
  real_T ahrs[4];                      /* '<Root>/ahrs' */
  real_T power[3];                     /* '<Root>/power' */
  real_T extparams[64];                /* '<Root>/extparams' */
  real_T analogues[8];                 /* '<Root>/analogues' */
} ExtU_gru_quadcl_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T servos[8];                    /* '<Root>/servos' */
  real_T addlog[32];                   /* '<Root>/addlog' */
} ExtY_gru_quadcl_T;

/* Real-time Model Data Structure */
struct tag_RTM_gru_quadcl_T {
  const char_T * volatile errorStatus;
};

/* Block signals (auto storage) */
extern B_gru_quadcl_T gru_quadcl_B;

/* Block states (auto storage) */
extern DW_gru_quadcl_T gru_quadcl_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_gru_quadcl_T gru_quadcl_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_gru_quadcl_T gru_quadcl_Y;

/* Constant parameters (auto storage) */
extern const ConstP_gru_quadcl_T gru_quadcl_ConstP;

/* Model entry point functions */
extern void gru_quadcl_initialize(void);
extern void gru_quadcl_step(void);
extern void gru_quadcl_terminate(void);

/* Real-time Model object */
extern RT_MODEL_gru_quadcl_T *const gru_quadcl_M;

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
 * '<Root>' : 'gru_quadcl'
 * '<S1>'   : 'gru_quadcl/RPAS + Safety Pilot mixer  theta phi r'
 * '<S2>'   : 'gru_quadcl/SNAP bus'
 * '<S3>'   : 'gru_quadcl/altitude control'
 * '<S4>'   : 'gru_quadcl/attitude control'
 * '<S5>'   : 'gru_quadcl/datalogging'
 * '<S6>'   : 'gru_quadcl/heading hold'
 * '<S7>'   : 'gru_quadcl/output mixer'
 * '<S8>'   : 'gru_quadcl/pilot att dems'
 * '<S9>'   : 'gru_quadcl/rate control'
 * '<S10>'  : 'gru_quadcl/SNAP bus/ahrs filter'
 * '<S11>'  : 'gru_quadcl/SNAP bus/ext bus create'
 * '<S12>'  : 'gru_quadcl/SNAP bus/gps bus create'
 * '<S13>'  : 'gru_quadcl/SNAP bus/hdaltitude'
 * '<S14>'  : 'gru_quadcl/SNAP bus/rx bus create'
 * '<S15>'  : 'gru_quadcl/SNAP bus/ahrs filter/condition angle to +//-pi'
 * '<S16>'  : 'gru_quadcl/SNAP bus/ahrs filter/condition angle to +//-pi1'
 * '<S17>'  : 'gru_quadcl/SNAP bus/gps bus create/RotateVelp'
 * '<S18>'  : 'gru_quadcl/SNAP bus/gps bus create/grab lat//long scaling'
 * '<S19>'  : 'gru_quadcl/SNAP bus/hdaltitude/grab alt'
 * '<S20>'  : 'gru_quadcl/SNAP bus/rx bus create/Compare To Constant'
 * '<S21>'  : 'gru_quadcl/SNAP bus/rx bus create/Compare To Zero'
 * '<S22>'  : 'gru_quadcl/SNAP bus/rx bus create/Compare To Zero1'
 * '<S23>'  : 'gru_quadcl/SNAP bus/rx bus create/normalise rx'
 * '<S24>'  : 'gru_quadcl/altitude control/Discrete Derivative'
 * '<S25>'  : 'gru_quadcl/altitude control/clamp'
 * '<S26>'  : 'gru_quadcl/altitude control/discrete int'
 * '<S27>'  : 'gru_quadcl/altitude control/grab altitude'
 * '<S28>'  : 'gru_quadcl/altitude control/saturation block with sat logical output'
 * '<S29>'  : 'gru_quadcl/attitude control/pitch att'
 * '<S30>'  : 'gru_quadcl/attitude control/roll att'
 * '<S31>'  : 'gru_quadcl/attitude control/pitch att/clamp'
 * '<S32>'  : 'gru_quadcl/attitude control/pitch att/discrete int'
 * '<S33>'  : 'gru_quadcl/attitude control/pitch att/saturation block with sat logical output'
 * '<S34>'  : 'gru_quadcl/attitude control/roll att/clamp'
 * '<S35>'  : 'gru_quadcl/attitude control/roll att/discrete int'
 * '<S36>'  : 'gru_quadcl/attitude control/roll att/saturation block with sat logical output'
 * '<S37>'  : 'gru_quadcl/heading hold/Dead Zone Dynamic'
 * '<S38>'  : 'gru_quadcl/heading hold/grab heading'
 * '<S39>'  : 'gru_quadcl/heading hold/heading error Condition to +//-pi'
 * '<S40>'  : 'gru_quadcl/heading hold/saturation block with sat logical output'
 * '<S41>'  : 'gru_quadcl/output mixer/denormalise rx'
 * '<S42>'  : 'gru_quadcl/rate control/pitch rate'
 * '<S43>'  : 'gru_quadcl/rate control/roll rate'
 * '<S44>'  : 'gru_quadcl/rate control/yaw rate'
 * '<S45>'  : 'gru_quadcl/rate control/pitch rate/Discrete Derivative'
 * '<S46>'  : 'gru_quadcl/rate control/pitch rate/clamp'
 * '<S47>'  : 'gru_quadcl/rate control/pitch rate/discrete int'
 * '<S48>'  : 'gru_quadcl/rate control/pitch rate/saturation block with sat logical output'
 * '<S49>'  : 'gru_quadcl/rate control/roll rate/Discrete Derivative'
 * '<S50>'  : 'gru_quadcl/rate control/roll rate/clamp'
 * '<S51>'  : 'gru_quadcl/rate control/roll rate/discrete int'
 * '<S52>'  : 'gru_quadcl/rate control/roll rate/saturation block with sat logical output'
 */
#endif                                 /* RTW_HEADER_gru_quadcl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
