/*
 * File: Arduino_250.h
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

#ifndef RTW_HEADER_Arduino_250_h_
#define RTW_HEADER_Arduino_250_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef Arduino_250_COMMON_INCLUDES_
# define Arduino_250_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Arduino_250_COMMON_INCLUDES_ */

#include "Arduino_250_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Diff;                         /* '<S36>/Diff' */
  real_T Diff_i;                       /* '<S32>/Diff' */
  real_T in;                           /* '<S25>/in' */
} B_Arduino_250_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S22>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_l;/* '<S38>/Discrete-Time Integrator' */
  real_T UD_DSTATE;                    /* '<S36>/UD' */
  real_T WeightedMovingAverage_TapDelayU;/* '<S30>/Weighted Moving Average' */
  real_T DiscreteTimeIntegrator_DSTATE_k;/* '<S19>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_n;/* '<S34>/Discrete-Time Integrator' */
  real_T UD_DSTATE_h;                  /* '<S32>/UD' */
  real_T WeightedMovingAverage_TapDela_c;/* '<S29>/Weighted Moving Average' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S22>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S38>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_c;/* '<S19>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_d;/* '<S34>/Discrete-Time Integrator' */
} DW_Arduino_250_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState grabheading_Trig_ZCE;     /* '<S4>/grab heading' */
} PrevZCX_Arduino_250_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T rates[3];                     /* '<Root>/rates' */
  real_T rx[8];                        /* '<Root>/rx' */
  real_T ahrs[3];                      /* '<Root>/ahrs' */
  real_T extparams[64];                /* '<Root>/extparams' */
} ExtU_Arduino_250_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T servos[8];                    /* '<Root>/servos' */
  real_T addlog[32];                   /* '<Root>/addlog' */
} ExtY_Arduino_250_T;

/* Real-time Model Data Structure */
struct tag_RTM_Arduino_250_T {
  const char_T * volatile errorStatus;
};

/* Block signals (auto storage) */
extern B_Arduino_250_T Arduino_250_B;

/* Block states (auto storage) */
extern DW_Arduino_250_T Arduino_250_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_Arduino_250_T Arduino_250_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_Arduino_250_T Arduino_250_Y;

/* Model entry point functions */
extern void Arduino_250_initialize(void);
extern void Arduino_250_step(void);
extern void Arduino_250_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Arduino_250_T *const Arduino_250_M;

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
 * '<Root>' : 'Arduino_250'
 * '<S1>'   : 'Arduino_250/SNAP bus'
 * '<S2>'   : 'Arduino_250/attitude control'
 * '<S3>'   : 'Arduino_250/datalogging'
 * '<S4>'   : 'Arduino_250/heading hold'
 * '<S5>'   : 'Arduino_250/output mixer'
 * '<S6>'   : 'Arduino_250/pilot att dems'
 * '<S7>'   : 'Arduino_250/pilot_rate_dem'
 * '<S8>'   : 'Arduino_250/rate control'
 * '<S9>'   : 'Arduino_250/SNAP bus/ahrs filter'
 * '<S10>'  : 'Arduino_250/SNAP bus/ext bus create'
 * '<S11>'  : 'Arduino_250/SNAP bus/rx bus create'
 * '<S12>'  : 'Arduino_250/SNAP bus/rx bus create/Compare To Constant'
 * '<S13>'  : 'Arduino_250/SNAP bus/rx bus create/Compare To Zero'
 * '<S14>'  : 'Arduino_250/SNAP bus/rx bus create/Compare To Zero1'
 * '<S15>'  : 'Arduino_250/SNAP bus/rx bus create/normalise rx'
 * '<S16>'  : 'Arduino_250/attitude control/pitch att'
 * '<S17>'  : 'Arduino_250/attitude control/roll att'
 * '<S18>'  : 'Arduino_250/attitude control/pitch att/clamp'
 * '<S19>'  : 'Arduino_250/attitude control/pitch att/discrete int'
 * '<S20>'  : 'Arduino_250/attitude control/pitch att/saturation block with sat logical output'
 * '<S21>'  : 'Arduino_250/attitude control/roll att/clamp'
 * '<S22>'  : 'Arduino_250/attitude control/roll att/discrete int'
 * '<S23>'  : 'Arduino_250/attitude control/roll att/saturation block with sat logical output'
 * '<S24>'  : 'Arduino_250/heading hold/Dead Zone Dynamic'
 * '<S25>'  : 'Arduino_250/heading hold/grab heading'
 * '<S26>'  : 'Arduino_250/heading hold/heading error Condition to +//-pi'
 * '<S27>'  : 'Arduino_250/heading hold/saturation block with sat logical output'
 * '<S28>'  : 'Arduino_250/output mixer/denormalise rx'
 * '<S29>'  : 'Arduino_250/rate control/pitch rate'
 * '<S30>'  : 'Arduino_250/rate control/roll rate'
 * '<S31>'  : 'Arduino_250/rate control/yaw rate'
 * '<S32>'  : 'Arduino_250/rate control/pitch rate/Discrete Derivative'
 * '<S33>'  : 'Arduino_250/rate control/pitch rate/clamp'
 * '<S34>'  : 'Arduino_250/rate control/pitch rate/discrete int'
 * '<S35>'  : 'Arduino_250/rate control/pitch rate/saturation block with sat logical output'
 * '<S36>'  : 'Arduino_250/rate control/roll rate/Discrete Derivative'
 * '<S37>'  : 'Arduino_250/rate control/roll rate/clamp'
 * '<S38>'  : 'Arduino_250/rate control/roll rate/discrete int'
 * '<S39>'  : 'Arduino_250/rate control/roll rate/looping'
 * '<S40>'  : 'Arduino_250/rate control/roll rate/saturation block with sat logical output'
 */
#endif                                 /* RTW_HEADER_Arduino_250_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
