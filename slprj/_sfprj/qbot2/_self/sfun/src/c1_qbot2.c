/* Include files */

#include "blascompat32.h"
#include "qbot2_sfun.h"
#include "c1_qbot2.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "qbot2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[5] = { "nargin", "nargout", "range",
  "sonar", "angle" };

/* Function Declarations */
static void initialize_c1_qbot2(SFc1_qbot2InstanceStruct *chartInstance);
static void initialize_params_c1_qbot2(SFc1_qbot2InstanceStruct *chartInstance);
static void enable_c1_qbot2(SFc1_qbot2InstanceStruct *chartInstance);
static void disable_c1_qbot2(SFc1_qbot2InstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_qbot2(SFc1_qbot2InstanceStruct
  *chartInstance);
static void ext_mode_exec_c1_qbot2(SFc1_qbot2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_qbot2(SFc1_qbot2InstanceStruct
  *chartInstance);
static void set_sim_state_c1_qbot2(SFc1_qbot2InstanceStruct *chartInstance,
  const mxArray *c1_st);
static void finalize_c1_qbot2(SFc1_qbot2InstanceStruct *chartInstance);
static void sf_c1_qbot2(SFc1_qbot2InstanceStruct *chartInstance);
static void initSimStructsc1_qbot2(SFc1_qbot2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_qbot2InstanceStruct *chartInstance, const
  mxArray *c1_angle, const char_T *c1_identifier, real_T c1_y[3]);
static void c1_b_emlrt_marshallIn(SFc1_qbot2InstanceStruct *chartInstance, const
  mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_c_emlrt_marshallIn(SFc1_qbot2InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_d_emlrt_marshallIn(SFc1_qbot2InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_e_emlrt_marshallIn(SFc1_qbot2InstanceStruct *chartInstance,
  const mxArray *c1_is_active_c1_qbot2, const char_T *c1_identifier);
static uint8_T c1_f_emlrt_marshallIn(SFc1_qbot2InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_qbot2InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_qbot2(SFc1_qbot2InstanceStruct *chartInstance)
{
  int32_T *c1_sfEvent;
  uint8_T *c1_is_active_c1_qbot2;
  c1_is_active_c1_qbot2 = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c1_is_active_c1_qbot2 = 0U;
}

static void initialize_params_c1_qbot2(SFc1_qbot2InstanceStruct *chartInstance)
{
}

static void enable_c1_qbot2(SFc1_qbot2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_qbot2(SFc1_qbot2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_qbot2(SFc1_qbot2InstanceStruct
  *chartInstance)
{
}

static void ext_mode_exec_c1_qbot2(SFc1_qbot2InstanceStruct *chartInstance)
{
  c1_update_debugger_state_c1_qbot2(chartInstance);
}

static const mxArray *get_sim_state_c1_qbot2(SFc1_qbot2InstanceStruct
  *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_u[3];
  const mxArray *c1_b_y = NULL;
  int32_T c1_i1;
  real_T c1_b_u[3];
  const mxArray *c1_c_y = NULL;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  uint8_T *c1_is_active_c1_qbot2;
  real_T (*c1_sonar)[3];
  real_T (*c1_angle)[3];
  c1_angle = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_sonar = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_is_active_c1_qbot2 = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(3));
  for (c1_i0 = 0; c1_i0 < 3; c1_i0++) {
    c1_u[c1_i0] = (*c1_angle)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c1_y, 0, c1_b_y);
  for (c1_i1 = 0; c1_i1 < 3; c1_i1++) {
    c1_b_u[c1_i1] = (*c1_sonar)[c1_i1];
  }

  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_hoistedGlobal = *c1_is_active_c1_qbot2;
  c1_c_u = c1_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 2, c1_d_y);
  sf_mex_assign(&c1_st, c1_y);
  return c1_st;
}

static void set_sim_state_c1_qbot2(SFc1_qbot2InstanceStruct *chartInstance,
  const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[3];
  int32_T c1_i2;
  real_T c1_dv1[3];
  int32_T c1_i3;
  boolean_T *c1_doneDoubleBufferReInit;
  uint8_T *c1_is_active_c1_qbot2;
  real_T (*c1_angle)[3];
  real_T (*c1_sonar)[3];
  c1_angle = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_sonar = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_is_active_c1_qbot2 = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c1_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
                      "angle", c1_dv0);
  for (c1_i2 = 0; c1_i2 < 3; c1_i2++) {
    (*c1_angle)[c1_i2] = c1_dv0[c1_i2];
  }

  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
                      "sonar", c1_dv1);
  for (c1_i3 = 0; c1_i3 < 3; c1_i3++) {
    (*c1_sonar)[c1_i3] = c1_dv1[c1_i3];
  }

  *c1_is_active_c1_qbot2 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 2)), "is_active_c1_qbot2");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_qbot2(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_qbot2(SFc1_qbot2InstanceStruct *chartInstance)
{
}

static void sf_c1_qbot2(SFc1_qbot2InstanceStruct *chartInstance)
{
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  real_T c1_range[6];
  uint32_T c1_debug_family_var_map[5];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 2.0;
  real_T c1_sonar[3];
  real_T c1_angle[3];
  int32_T c1_i8;
  int32_T c1_i9;
  real_T c1_a[3];
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T *c1_sfEvent;
  real_T (*c1_b_sonar)[3];
  real_T (*c1_b_angle)[3];
  real_T (*c1_b_range)[6];
  c1_b_angle = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_sonar = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_range = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, *c1_sfEvent);
  for (c1_i4 = 0; c1_i4 < 6; c1_i4++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_range)[c1_i4], 0U);
  }

  for (c1_i5 = 0; c1_i5 < 3; c1_i5++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_sonar)[c1_i5], 1U);
  }

  for (c1_i6 = 0; c1_i6 < 3; c1_i6++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_angle)[c1_i6], 2U);
  }

  *c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, *c1_sfEvent);
  for (c1_i7 = 0; c1_i7 < 6; c1_i7++) {
    c1_range[c1_i7] = (*c1_b_range)[c1_i7];
  }

  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 0U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 1U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c1_range, 2U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_sonar, 3U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_angle, 4U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c1_sfEvent, 2);
  for (c1_i8 = 0; c1_i8 < 3; c1_i8++) {
    c1_sonar[c1_i8] = c1_range[c1_i8];
  }

  _SFD_EML_CALL(0U, *c1_sfEvent, 3);
  for (c1_i9 = 0; c1_i9 < 3; c1_i9++) {
    c1_a[c1_i9] = c1_range[c1_i9 + 3];
  }

  for (c1_i10 = 0; c1_i10 < 3; c1_i10++) {
    c1_angle[c1_i10] = c1_a[c1_i10] * 100.0;
  }

  _SFD_EML_CALL(0U, *c1_sfEvent, -3);
  sf_debug_symbol_scope_pop();
  for (c1_i11 = 0; c1_i11 < 3; c1_i11++) {
    (*c1_b_sonar)[c1_i11] = c1_sonar[c1_i11];
  }

  for (c1_i12 = 0; c1_i12 < 3; c1_i12++) {
    (*c1_b_angle)[c1_i12] = c1_angle[c1_i12];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *c1_sfEvent);
  sf_debug_check_for_state_inconsistency(_qbot2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc1_qbot2(SFc1_qbot2InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i13;
  real_T c1_b_inData[3];
  int32_T c1_i14;
  real_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc1_qbot2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i13 = 0; c1_i13 < 3; c1_i13++) {
    c1_b_inData[c1_i13] = (*(real_T (*)[3])c1_inData)[c1_i13];
  }

  for (c1_i14 = 0; c1_i14 < 3; c1_i14++) {
    c1_u[c1_i14] = c1_b_inData[c1_i14];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_qbot2InstanceStruct *chartInstance, const
  mxArray *c1_angle, const char_T *c1_identifier, real_T c1_y[3])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_angle), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_angle);
}

static void c1_b_emlrt_marshallIn(SFc1_qbot2InstanceStruct *chartInstance, const
  mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3])
{
  real_T c1_dv2[3];
  int32_T c1_i15;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv2, 1, 0, 0U, 1, 0U, 1, 3);
  for (c1_i15 = 0; c1_i15 < 3; c1_i15++) {
    c1_y[c1_i15] = c1_dv2[c1_i15];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_angle;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[3];
  int32_T c1_i16;
  SFc1_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc1_qbot2InstanceStruct *)chartInstanceVoid;
  c1_angle = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_angle), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_angle);
  for (c1_i16 = 0; c1_i16 < 3; c1_i16++) {
    (*(real_T (*)[3])c1_outData)[c1_i16] = c1_y[c1_i16];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i17;
  real_T c1_b_inData[6];
  int32_T c1_i18;
  real_T c1_u[6];
  const mxArray *c1_y = NULL;
  SFc1_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc1_qbot2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i17 = 0; c1_i17 < 6; c1_i17++) {
    c1_b_inData[c1_i17] = (*(real_T (*)[6])c1_inData)[c1_i17];
  }

  for (c1_i18 = 0; c1_i18 < 6; c1_i18++) {
    c1_u[c1_i18] = c1_b_inData[c1_i18];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc1_qbot2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static real_T c1_c_emlrt_marshallIn(SFc1_qbot2InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc1_qbot2InstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_qbot2_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[1];
  c1_ResolvedFunctionInfo (*c1_b_info)[1];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i19;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_b_info = (c1_ResolvedFunctionInfo (*)[1])c1_info;
  (*c1_b_info)[0].context = "";
  (*c1_b_info)[0].name = "mtimes";
  (*c1_b_info)[0].dominantType = "double";
  (*c1_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[0].fileTimeLo = 4198852096U;
  (*c1_b_info)[0].fileTimeHi = 30114324U;
  (*c1_b_info)[0].mFileTimeLo = 0U;
  (*c1_b_info)[0].mFileTimeHi = 0U;
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 1));
  for (c1_i19 = 0; c1_i19 < 1; c1_i19++) {
    c1_r0 = &c1_info[c1_i19];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i19);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i19);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i19);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i19);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i19);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i19);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i19);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i19);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc1_qbot2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static int32_T c1_d_emlrt_marshallIn(SFc1_qbot2InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i20;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i20, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i20;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc1_qbot2InstanceStruct *)chartInstanceVoid;
  c1_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_sfEvent), &c1_thisId);
  sf_mex_destroy(&c1_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_qbot2InstanceStruct *chartInstance,
  const mxArray *c1_is_active_c1_qbot2, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_is_active_c1_qbot2),
    &c1_thisId);
  sf_mex_destroy(&c1_is_active_c1_qbot2);
  return c1_y;
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_qbot2InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_qbot2InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c1_qbot2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3801914030U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1345187521U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2151100796U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(403237573U);
}

mxArray *sf_c1_qbot2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3551802366U);
    pr[1] = (double)(1395432361U);
    pr[2] = (double)(2787251355U);
    pr[3] = (double)(2738685585U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c1_qbot2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[6],T\"angle\",},{M[1],M[5],T\"sonar\",},{M[8],M[0],T\"is_active_c1_qbot2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_qbot2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_qbot2InstanceStruct *chartInstance;
    chartInstance = (SFc1_qbot2InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_qbot2MachineNumber_,
          1,
          1,
          1,
          3,
          0,
          0,
          0,
          0,
          0,
          &(chartInstance->chartNumber),
          &(chartInstance->instanceNumber),
          ssGetPath(S),
          (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_qbot2MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_qbot2MachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_qbot2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"range");
          _SFD_SET_DATA_PROPS(1,2,0,1,"sonar");
          _SFD_SET_DATA_PROPS(2,2,0,1,"angle");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,91);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        {
          real_T (*c1_range)[6];
          real_T (*c1_sonar)[3];
          real_T (*c1_angle)[3];
          c1_angle = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
          c1_sonar = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c1_range = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_range);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_sonar);
          _SFD_SET_DATA_VALUE_PTR(2U, *c1_angle);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_qbot2MachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S, "qbot2",
      "qbot2", 1, "dworkChecksum");
    if (mxRTWDWorkChecksum != NULL) {
      double *pr = mxGetPr(mxRTWDWorkChecksum);
      if ((uint32_T)pr[0] != sfunDWorkChecksum[0] ||
          (uint32_T)pr[1] != sfunDWorkChecksum[1] ||
          (uint32_T)pr[2] != sfunDWorkChecksum[2] ||
          (uint32_T)pr[3] != sfunDWorkChecksum[3]) {
        sf_mex_error_message("Code generation and simulation targets registered different sets of persistent variables for the block. "
                             "External or Rapid Accelerator mode simulation requires code generation and simulation targets to "
                             "register the same set of persistent variables for this block. "
                             "This discrepancy is typically caused by MATLAB functions that have different code paths for "
                             "simulation and code generation targets where these code paths define different sets of persistent variables. "
                             "Please identify these code paths in the offending block and rewrite the MATLAB code so that "
                             "the set of persistent variables is the same between simulation and code generation.");
      }
    }
  }
}

static void sf_opaque_initialize_c1_qbot2(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc1_qbot2InstanceStruct*) chartInstanceVar)->S);
  chart_debug_initialization(((SFc1_qbot2InstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c1_qbot2((SFc1_qbot2InstanceStruct*) chartInstanceVar);
  initialize_c1_qbot2((SFc1_qbot2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_qbot2(void *chartInstanceVar)
{
  enable_c1_qbot2((SFc1_qbot2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_qbot2(void *chartInstanceVar)
{
  disable_c1_qbot2((SFc1_qbot2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_qbot2(void *chartInstanceVar)
{
  sf_c1_qbot2((SFc1_qbot2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c1_qbot2(void *chartInstanceVar)
{
  ext_mode_exec_c1_qbot2((SFc1_qbot2InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_qbot2(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_qbot2((SFc1_qbot2InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_qbot2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c1_qbot2(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_qbot2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_qbot2((SFc1_qbot2InstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_qbot2(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_qbot2(S);
}

static void sf_opaque_set_sim_state_c1_qbot2(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c1_qbot2(S, st);
}

static void sf_opaque_terminate_c1_qbot2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_qbot2InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_qbot2((SFc1_qbot2InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_qbot2((SFc1_qbot2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_qbot2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_qbot2((SFc1_qbot2InstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c1_qbot2_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c1_qbot2\",T\"is_active_c1_qbot2\"}}"
  };

  mxArray *mxTpInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  return mxTpInfo;
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  const char *dworkEncStr[] = {
    "100 S1x4'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"int32\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 4, 10);
}

static uint32_T* sf_get_sfun_dwork_checksum()
{
  static uint32_T checksum[4] = { 3851270630U, 3363230343U, 1651207761U,
    946165807U };

  return checksum;
}

static void mdlSetWorkWidths_c1_qbot2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"qbot2","qbot2",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"qbot2","qbot2",1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"qbot2","qbot2",1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"qbot2","qbot2",1,1);
      sf_mark_chart_reusable_outputs(S,"qbot2","qbot2",1,2);
    }

    sf_set_rtw_dwork_info(S,"qbot2","qbot2",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2347573854U));
  ssSetChecksum1(S,(3522237647U));
  ssSetChecksum2(S,(685500691U));
  ssSetChecksum3(S,(2203358262U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_qbot2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "qbot2", "qbot2",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_qbot2(SimStruct *S)
{
  SFc1_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc1_qbot2InstanceStruct *)malloc(sizeof
    (SFc1_qbot2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_qbot2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_qbot2;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_qbot2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_qbot2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_qbot2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_qbot2;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_qbot2;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_qbot2;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_qbot2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_qbot2;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_qbot2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_qbot2;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c1_qbot2;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_qbot2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_qbot2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_qbot2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_qbot2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_qbot2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
