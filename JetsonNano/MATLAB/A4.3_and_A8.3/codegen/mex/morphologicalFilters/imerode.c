/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * imerode.c
 *
 * Code generation for function 'imerode'
 *
 */

/* Include files */
#include "imerode.h"
#include "MorphologicalFilters_data.h"
#include "rt_nonfinite.h"
#include "libmwbwpackctbb.h"
#include "libmwbwunpackctbb.h"
#include "libmwmorphop_packed.h"
#include <string.h>

/* Function Definitions */
void imerode(const boolean_T A[728160], boolean_T B[728160])
{
  real_T asizeT[2];
  real_T nsizeT[2];
  int32_T i;
  uint32_T Apadpack[22940];
  uint32_T b_B[22940];
  boolean_T nhood[20];
  asizeT[0] = 984.0;
  nsizeT[0] = 31.0;
  asizeT[1] = 740.0;
  nsizeT[1] = 740.0;
  bwPackingtbb(&A[0], &asizeT[0], &Apadpack[0], &nsizeT[0], true);
  for (i = 0; i < 20; i++) {
    nhood[i] = true;
  }

  asizeT[0] = 31.0;
  nsizeT[0] = 20.0;
  asizeT[1] = 740.0;
  nsizeT[1] = 1.0;
  erode_packed_uint32(&Apadpack[0], &asizeT[0], 2.0, &nhood[0], &nsizeT[0], 2.0,
                      984.0, &b_B[0], true);
  memcpy(&Apadpack[0], &b_B[0], 22940U * sizeof(uint32_T));
  for (i = 0; i < 20; i++) {
    nhood[i] = true;
  }

  asizeT[0] = 31.0;
  nsizeT[0] = 1.0;
  asizeT[1] = 740.0;
  nsizeT[1] = 20.0;
  erode_packed_uint32(&Apadpack[0], &asizeT[0], 2.0, &nhood[0], &nsizeT[0], 2.0,
                      984.0, &b_B[0], true);
  nsizeT[0] = 31.0;
  asizeT[0] = 984.0;
  nsizeT[1] = 740.0;
  asizeT[1] = 740.0;
  bwUnpackingtbb(&b_B[0], &nsizeT[0], &B[0], &asizeT[0], true);
}

/* End of code generation (imerode.c) */
