/* Include files */

#include "blascompat32.h"
#include "qbot2_sfun.h"
#include "c2_qbot2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "qbot2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[6] = { "magx", "magy", "nargin",
  "nargout", "mag", "heading" };

/* Function Declarations */
static void initialize_c2_qbot2(SFc2_qbot2InstanceStruct *chartInstance);
static void initialize_params_c2_qbot2(SFc2_qbot2InstanceStruct *chartInstance);
static void enable_c2_qbot2(SFc2_qbot2InstanceStruct *chartInstance);
static void disable_c2_qbot2(SFc2_qbot2InstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_qbot2(SFc2_qbot2InstanceStruct
  *chartInstance);
static void ext_mode_exec_c2_qbot2(SFc2_qbot2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_qbot2(SFc2_qbot2InstanceStruct
  *chartInstance);
static void set_sim_state_c2_qbot2(SFc2_qbot2InstanceStruct *chartInstance,
  const mxArray *c2_st);
static void finalize_c2_qbot2(SFc2_qbot2InstanceStruct *chartInstance);
static void sf_c2_qbot2(SFc2_qbot2InstanceStruct *chartInstance);
static void initSimStructsc2_qbot2(SFc2_qbot2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_qbot2InstanceStruct *chartInstance, const
  mxArray *c2_heading, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_qbot2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[15]);
static void c2_eml_scalar_eg(SFc2_qbot2InstanceStruct *chartInstance);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_c_emlrt_marshallIn(SFc2_qbot2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_d_emlrt_marshallIn(SFc2_qbot2InstanceStruct *chartInstance,
  const mxArray *c2_is_active_c2_qbot2, const char_T *c2_identifier);
static uint8_T c2_e_emlrt_marshallIn(SFc2_qbot2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_qbot2InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_qbot2(SFc2_qbot2InstanceStruct *chartInstance)
{
  int32_T *c2_sfEvent;
  uint8_T *c2_is_active_c2_qbot2;
  c2_is_active_c2_qbot2 = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c2_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c2_is_active_c2_qbot2 = 0U;
}

static void initialize_params_c2_qbot2(SFc2_qbot2InstanceStruct *chartInstance)
{
}

static void enable_c2_qbot2(SFc2_qbot2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_qbot2(SFc2_qbot2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_qbot2(SFc2_qbot2InstanceStruct
  *chartInstance)
{
}

static void ext_mode_exec_c2_qbot2(SFc2_qbot2InstanceStruct *chartInstance)
{
  c2_update_debugger_state_c2_qbot2(chartInstance);
}

static const mxArray *get_sim_state_c2_qbot2(SFc2_qbot2InstanceStruct
  *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T *c2_heading;
  uint8_T *c2_is_active_c2_qbot2;
  c2_heading = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_is_active_c2_qbot2 = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2));
  c2_hoistedGlobal = *c2_heading;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *c2_is_active_c2_qbot2;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_qbot2(SFc2_qbot2InstanceStruct *chartInstance,
  const mxArray *c2_st)
{
  const mxArray *c2_u;
  boolean_T *c2_doneDoubleBufferReInit;
  real_T *c2_heading;
  uint8_T *c2_is_active_c2_qbot2;
  c2_heading = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_is_active_c2_qbot2 = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c2_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_heading = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 0)), "heading");
  *c2_is_active_c2_qbot2 = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 1)), "is_active_c2_qbot2");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_qbot2(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_qbot2(SFc2_qbot2InstanceStruct *chartInstance)
{
}

static void sf_c2_qbot2(SFc2_qbot2InstanceStruct *chartInstance)
{
  int32_T c2_i0;
  int32_T c2_i1;
  real_T c2_mag[3];
  uint32_T c2_debug_family_var_map[6];
  real_T c2_magx;
  real_T c2_magy;
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  real_T c2_heading;
  real_T c2_y;
  real_T c2_x;
  real_T c2_b_y;
  real_T c2_b_x;
  real_T c2_r;
  real_T c2_a;
  real_T c2_c_y;
  real_T c2_A;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_d_y;
  real_T c2_f_x;
  real_T c2_xk;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T *c2_b_heading;
  int32_T *c2_sfEvent;
  real_T (*c2_b_mag)[3];
  c2_b_heading = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_mag = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  c2_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, *c2_sfEvent);
  for (c2_i0 = 0; c2_i0 < 3; c2_i0++) {
    _SFD_DATA_RANGE_CHECK((*c2_b_mag)[c2_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_b_heading, 1U);
  *c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, *c2_sfEvent);
  for (c2_i1 = 0; c2_i1 < 3; c2_i1++) {
    c2_mag[c2_i1] = (*c2_b_mag)[c2_i1];
  }

  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_magx, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_magy, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 2U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 3U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c2_mag, 4U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_heading, 5U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c2_sfEvent, 2);
  c2_magx = -41.956587966488947;
  _SFD_EML_CALL(0U, *c2_sfEvent, 3);
  c2_magy = 13.73076923076923;
  _SFD_EML_CALL(0U, *c2_sfEvent, 4);
  c2_y = c2_mag[0] - c2_magx;
  c2_x = c2_mag[1] - c2_magy;
  c2_eml_scalar_eg(chartInstance);
  c2_b_y = c2_y;
  c2_b_x = c2_x;
  c2_r = muDoubleScalarAtan2(c2_b_y, c2_b_x);
  c2_a = c2_r;
  c2_c_y = c2_a * 180.0;
  c2_A = c2_c_y;
  c2_c_x = c2_A;
  c2_d_x = c2_c_x;
  c2_e_x = c2_d_x;
  c2_d_y = c2_e_x / 3.1415926535897931;
  c2_f_x = c2_d_y;
  c2_eml_scalar_eg(chartInstance);
  c2_xk = c2_f_x;
  c2_g_x = c2_xk;
  c2_eml_scalar_eg(chartInstance);
  c2_h_x = c2_g_x / 360.0;
  c2_i_x = c2_h_x;
  c2_i_x = muDoubleScalarFloor(c2_i_x);
  c2_heading = c2_g_x - c2_i_x * 360.0;
  _SFD_EML_CALL(0U, *c2_sfEvent, -4);
  sf_debug_symbol_scope_pop();
  *c2_b_heading = c2_heading;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *c2_sfEvent);
  sf_debug_check_for_state_inconsistency(_qbot2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc2_qbot2(SFc2_qbot2InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc2_qbot2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_qbot2InstanceStruct *chartInstance, const
  mxArray *c2_heading, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_heading), &c2_thisId);
  sf_mex_destroy(&c2_heading);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_qbot2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_heading;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc2_qbot2InstanceStruct *)chartInstanceVoid;
  c2_heading = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_heading), &c2_thisId);
  sf_mex_destroy(&c2_heading);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i2;
  real_T c2_b_inData[3];
  int32_T c2_i3;
  real_T c2_u[3];
  const mxArray *c2_y = NULL;
  SFc2_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc2_qbot2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i2 = 0; c2_i2 < 3; c2_i2++) {
    c2_b_inData[c2_i2] = (*(real_T (*)[3])c2_inData)[c2_i2];
  }

  for (c2_i3 = 0; c2_i3 < 3; c2_i3++) {
    c2_u[c2_i3] = c2_b_inData[c2_i3];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

const mxArray *sf_c2_qbot2_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[15];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i4;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 15));
  for (c2_i4 = 0; c2_i4 < 15; c2_i4++) {
    c2_r0 = &c2_info[c2_i4];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i4);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i4);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i4);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i4);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i4);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i4);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i4);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i4);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[15])
{
  c2_info[0].context = "";
  c2_info[0].name = "atan2";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c2_info[0].fileTimeLo = 58765312U;
  c2_info[0].fileTimeHi = 30108053U;
  c2_info[0].mFileTimeLo = 0U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c2_info[1].name = "eml_scalar_eg";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[1].fileTimeLo = 978765312U;
  c2_info[1].fileTimeHi = 30108053U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c2_info[2].name = "eml_scalexp_alloc";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[2].fileTimeLo = 978765312U;
  c2_info[2].fileTimeHi = 30108053U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c2_info[3].name = "eml_scalar_atan2";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m";
  c2_info[3].fileTimeLo = 218765312U;
  c2_info[3].fileTimeHi = 30108053U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context = "";
  c2_info[4].name = "mtimes";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[4].fileTimeLo = 4198852096U;
  c2_info[4].fileTimeHi = 30114324U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context = "";
  c2_info[5].name = "mrdivide";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[5].fileTimeLo = 2742915840U;
  c2_info[5].fileTimeHi = 30130960U;
  c2_info[5].mFileTimeLo = 4198852096U;
  c2_info[5].mFileTimeHi = 30114324U;
  c2_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[6].name = "rdivide";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[6].fileTimeLo = 1458765312U;
  c2_info[6].fileTimeHi = 30108053U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[7].name = "eml_div";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[7].fileTimeLo = 4293732608U;
  c2_info[7].fileTimeHi = 30108052U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context = "";
  c2_info[8].name = "mod";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  c2_info[8].fileTimeLo = 458765312U;
  c2_info[8].fileTimeHi = 30108053U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  c2_info[9].name = "eml_scalar_mod";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c2_info[9].fileTimeLo = 318765312U;
  c2_info[9].fileTimeHi = 30108053U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c2_info[10].name = "eml_scalar_floor";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[10].fileTimeLo = 278765312U;
  c2_info[10].fileTimeHi = 30108053U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c2_info[11].name = "eml_scalar_round";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c2_info[11].fileTimeLo = 3558852096U;
  c2_info[11].fileTimeHi = 30114324U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m!scalar_round";
  c2_info[12].name = "eps";
  c2_info[12].dominantType = "char";
  c2_info[12].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[12].fileTimeLo = 4173732608U;
  c2_info[12].fileTimeHi = 30108052U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[13].name = "eml_is_float_class";
  c2_info[13].dominantType = "char";
  c2_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c2_info[13].fileTimeLo = 838765312U;
  c2_info[13].fileTimeHi = 30108053U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c2_info[14].name = "eml_scalar_abs";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[14].fileTimeLo = 138765312U;
  c2_info[14].fileTimeHi = 30108053U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
}

static void c2_eml_scalar_eg(SFc2_qbot2InstanceStruct *chartInstance)
{
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc2_qbot2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static int32_T c2_c_emlrt_marshallIn(SFc2_qbot2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i5;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i5, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i5;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc2_qbot2InstanceStruct *)chartInstanceVoid;
  c2_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_sfEvent), &c2_thisId);
  sf_mex_destroy(&c2_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_d_emlrt_marshallIn(SFc2_qbot2InstanceStruct *chartInstance,
  const mxArray *c2_is_active_c2_qbot2, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_is_active_c2_qbot2),
    &c2_thisId);
  sf_mex_destroy(&c2_is_active_c2_qbot2);
  return c2_y;
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_qbot2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_qbot2InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c2_qbot2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3631105825U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(141074859U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2451366507U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3771794258U);
}

mxArray *sf_c2_qbot2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3526050963U);
    pr[1] = (double)(1524707916U);
    pr[2] = (double)(413623781U);
    pr[3] = (double)(1008953511U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c2_qbot2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"heading\",},{M[8],M[0],T\"is_active_c2_qbot2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_qbot2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_qbot2InstanceStruct *chartInstance;
    chartInstance = (SFc2_qbot2InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_qbot2MachineNumber_,
          2,
          1,
          1,
          2,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"mag");
          _SFD_SET_DATA_PROPS(1,2,0,1,"heading");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,159);
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
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);

        {
          real_T *c2_heading;
          real_T (*c2_mag)[3];
          c2_heading = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_mag = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_mag);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_heading);
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
      "qbot2", 2, "dworkChecksum");
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

static void sf_opaque_initialize_c2_qbot2(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc2_qbot2InstanceStruct*) chartInstanceVar)->S);
  chart_debug_initialization(((SFc2_qbot2InstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c2_qbot2((SFc2_qbot2InstanceStruct*) chartInstanceVar);
  initialize_c2_qbot2((SFc2_qbot2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_qbot2(void *chartInstanceVar)
{
  enable_c2_qbot2((SFc2_qbot2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_qbot2(void *chartInstanceVar)
{
  disable_c2_qbot2((SFc2_qbot2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_qbot2(void *chartInstanceVar)
{
  sf_c2_qbot2((SFc2_qbot2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c2_qbot2(void *chartInstanceVar)
{
  ext_mode_exec_c2_qbot2((SFc2_qbot2InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_qbot2(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_qbot2((SFc2_qbot2InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_qbot2();/* state var info */
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

extern void sf_internal_set_sim_state_c2_qbot2(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_qbot2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_qbot2((SFc2_qbot2InstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_qbot2(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_qbot2(S);
}

static void sf_opaque_set_sim_state_c2_qbot2(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_qbot2(S, st);
}

static void sf_opaque_terminate_c2_qbot2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_qbot2InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_qbot2((SFc2_qbot2InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_qbot2((SFc2_qbot2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_qbot2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_qbot2((SFc2_qbot2InstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c2_qbot2_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c2_qbot2\",T\"is_active_c2_qbot2\"}}"
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

static void mdlSetWorkWidths_c2_qbot2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"qbot2","qbot2",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"qbot2","qbot2",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"qbot2","qbot2",2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"qbot2","qbot2",2,1);
      sf_mark_chart_reusable_outputs(S,"qbot2","qbot2",2,1);
    }

    sf_set_rtw_dwork_info(S,"qbot2","qbot2",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2669602421U));
  ssSetChecksum1(S,(4205539184U));
  ssSetChecksum2(S,(2863016206U));
  ssSetChecksum3(S,(2322845426U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_qbot2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "qbot2", "qbot2",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_qbot2(SimStruct *S)
{
  SFc2_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc2_qbot2InstanceStruct *)malloc(sizeof
    (SFc2_qbot2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_qbot2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_qbot2;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_qbot2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_qbot2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_qbot2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_qbot2;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_qbot2;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_qbot2;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_qbot2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_qbot2;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_qbot2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_qbot2;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c2_qbot2;
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

void c2_qbot2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_qbot2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_qbot2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_qbot2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_qbot2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
