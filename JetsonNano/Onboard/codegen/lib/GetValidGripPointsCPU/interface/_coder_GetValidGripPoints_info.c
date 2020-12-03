/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_GetValidGripPoints_info.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 03-Dec-2020 12:39:31
 */

/* Include Files */
#include "_coder_GetValidGripPoints_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void);

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : const mxArray *
 */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[7] = {
    "789ced58dd8ed240182d66dd9818d7bd3066bddb27a0bb05a331f1a2cb4f5b04d2a55d201a5d0a1da06e3b83ed14e9dee81b187d036f7c16bd726f34be8a77b6"
    "d0594a63ed9a2edd887c090c1fa79df39d6f8693295446a865288adaa2fcd8990db7dcd70717d8f6bfbe462d4618cff8e346282771dd457ebe99dd47f0f7eedb",
    "3b3fef2188c104cf12a818e0fc4e15191a5420969d11a04c60217d0cd429d2d774206b06908249ddcb8c72003a4f3cc8fb5c1882de89641b9439b4e615eac164"
    "da0f4fdf5940af573fd1bb412d461827fa8d887e6cfbfa09feacf4bcf0883eb28069d1526b57068ab15b058a0a4cba887ab60120b6684ec3bcdda559816b0822",
    "b3c7ecf1325d01d842b0ae4044d758b9ca1ed06c3e9b3b56a07acc3ecce6680ee0a6a26b2a676a231169ee345923a06f9450df56280feb23b85b86a84d805e05"
    "70808773fe4e42fecd48fecd29bf8aecae0e2e6f3db518bd045fe67a061a9925fb27ae9fb72fa82f3cceafbf31bdbeffe57b264dbe6f9fbebe48938fc455f14d",
    "22e6bbe8febc1bc147f627c1f725a7d01c8e8b155bb35b79f65432da8d437e5e8718c31357071591a735ffdab7ffacef668c3e824fa96554d52058e86f2721ff"
    "dffaf6e7847cfd18bd045fda7a061ae92de4aafa3555385bfb35b504bf6e60a15c721a45a6e9a8a02ae77305c81cacfdfa5ff1ebb709f5dd8bd14770018e5d69",
    "e0896b338682b59e25ba8f4c4365449ea7aecabf7f24e4c331fa09beb4f58d6cecec089e96ff0c52f6f3f6cee38f69f29158753fe74f0e4f2b9ce8e052abdee6"
    "5f092d09bdac1457c7cfff97df7bd2fd72274627c145c554741de8358491c9c2810e3013aca393b08eb4ff474131ba09bebcf3f86f1aea2eedfa5c7e497c7eac",
    "ba8f1f398332b7cfdbe3d7487970bf3baa3f651c6705cee5bf004edc8800", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 6168U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/*
 * Arguments    : void
 * Return Type  : mxArray *
 */
mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *epFieldName[6] = { "Name", "NumberOfInputs", "NumberOfOutputs",
    "ConstantInputs", "FullPath", "TimeStamp" };

  const char_T *propFieldName[4] = { "Version", "ResolvedFunctions",
    "EntryPoints", "CoverageInfo" };

  xEntryPoints = emlrtCreateStructMatrix(1, 1, 6, epFieldName);
  xInputs = emlrtCreateLogicalMatrix(1, 7);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString(
    "GetValidGripPoints"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(7.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (5.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "C:\\Users\\SW Team Leader\\Documents\\GitHub\\AIGRIP2020HT\\JetsonNano\\MATLAB\\A4.3_and_A8.3\\GetValidGripPoints.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (738128.5218865741));
  xResult = emlrtCreateStructMatrix(1, 1, 4, propFieldName);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.9.0.1495850 (R2020b) Update 1"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/*
 * File trailer for _coder_GetValidGripPoints_info.c
 *
 * [EOF]
 */
