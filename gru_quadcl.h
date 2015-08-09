/*
 * File: gru_quadcl.h
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

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Diff;                         /* '<S30>/Diff' */
  real_T Diff_i;                       /* '<S26>/Diff' */
} B_gru_quadcl_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S20>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_l;/* '<S32>/Discrete-Time Integrator' */
  real_T UD_DSTATE;                    /* '<S30>/UD' */
  real_T WeightedMovingAverage_TapDelayU;/* '<S24>/Weighted Moving Average' */
  real_T DiscreteTimeIntegrator_DSTATE_k;/* '<S17>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_n;/* '<S28>/Discrete-Time Integrator' */
  real_T UD_DSTATE_h;                  /* '<S26>/UD' */
  real_T WeightedMovingAverage_TapDela_c;/* '<S23>/Weighted Moving Average' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S20>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S32>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_c;/* '<S17>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_d;/* '<S28>/Discrete-Time Integrator' */
} DW_gru_quadcl_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T rates[3];                     /* '<Root>/rates' */
  real_T rx[8];                        /* '<Root>/rx' */
  real_T ahrs[4];                      /* '<Root>/ahrs' */
  real_T extparams[64];                /* '<Root>/extparams' */
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
 * '<S1>'   : 'gru_quadcl/SNAP bus'
 * '<S2>'   : 'gru_quadcl/attitude control'
 * '<S3>'   : 'gru_quadcl/datalogging'
 * '<S4>'   : 'gru_quadcl/output mixer'
 * '<S5>'   : 'gru_quadcl/pilot att dems'
 * '<S6>'   : 'gru_quadcl/rate control'
 * '<S7>'   : 'gru_quadcl/SNAP bus/ahrs filter'
 * '<S8>'   : 'gru_quadcl/SNAP bus/ext bus create'
 * '<S9>'   : 'gru_quadcl/SNAP bus/rx bus create'
 * '<S10>'  : 'gru_quadcl/SNAP bus/rx bus create/Compare To Constant'
 * '<S11>'  : 'gru_quadcl/SNAP bus/rx bus create/Compare To Zero'
 * '<S12>'  : 'gru_quadcl/SNAP bus/rx bus create/Compare To Zero1'
 * '<S13>'  : 'gru_quadcl/SNAP bus/rx bus create/normalise rx'
 * '<S14>'  : 'gru_quadcl/attitude control/pitch att'
 * '<S15>'  : 'gru_quadcl/attitude control/roll att'
 * '<S16>'  : 'gru_quadcl/attitude control/pitch att/clamp'
 * '<S17>'  : 'gru_quadcl/attitude control/pitch att/discrete int'
 * '<S18>'  : 'gru_quadcl/attitude control/pitch att/saturation block with sat logical output'
 * '<S19>'  : 'gru_quadcl/attitude control/roll att/clamp'
 * '<S20>'  : 'gru_quadcl/attitude control/roll att/discrete int'
 * '<S21>'  : 'gru_quadcl/attitude control/roll att/saturation block with sat logical output'
 * '<S22>'  : 'gru_quadcl/output mixer/denormalise rx'
 * '<S23>'  : 'gru_quadcl/rate control/pitch rate'
 * '<S24>'  : 'gru_quadcl/rate control/roll rate'
 * '<S25>'  : 'gru_quadcl/rate control/yaw rate'
 * '<S26>'  : 'gru_quadcl/rate control/pitch rate/Discrete Derivative'
 * '<S27>'  : 'gru_quadcl/rate control/pitch rate/clamp'
 * '<S28>'  : 'gru_quadcl/rate control/pitch rate/discrete int'
 * '<S29>'  : 'gru_quadcl/rate control/pitch rate/saturation block with sat logical output'
 * '<S30>'  : 'gru_quadcl/rate control/roll rate/Discrete Derivative'
 * '<S31>'  : 'gru_quadcl/rate control/roll rate/clamp'
 * '<S32>'  : 'gru_quadcl/rate control/roll rate/discrete int'
 * '<S33>'  : 'gru_quadcl/rate control/roll rate/looping'
 * '<S34>'  : 'gru_quadcl/rate control/roll rate/saturation block with sat logical output'
 */
#endif                                 /* RTW_HEADER_gru_quadcl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
