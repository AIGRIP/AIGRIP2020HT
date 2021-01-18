//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  morphopAlgo.cpp
//
//  Code generation for function 'morphopAlgo'
//


// Include files
#include "morphopAlgo.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace coder
{
  namespace images
  {
    namespace internal
    {
      namespace coder
      {
        void b_morphop_ver_hor_logical(const bool in[728160], bool o[728160])
        {
          int j;
          int k;
          int nz;
          int q1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(nz,k,j,q1)

          for (int i = 0; i < 984; i++) {
            nz = in[i];
            for (k = 0; k < 10; k++) {
              nz += in[i + 984 * (k + 1)];
            }

            o[i] = (nz == 11);
            for (j = 0; j < 9; j++) {
              q1 = in[i + 984 * (j + 11)];
              if (nz > MAX_int32_T - q1) {
                nz = MAX_int32_T;
              } else {
                nz += q1;
              }

              o[i + 984 * (j + 1)] = (nz == j + 12);
            }

            for (j = 0; j < 720; j++) {
              q1 = in[i + 984 * (j + 20)];
              if (nz > MAX_int32_T - q1) {
                k = MAX_int32_T;
              } else {
                k = nz + q1;
              }

              q1 = in[i + 984 * j];
              if (k < q1 + MIN_int32_T) {
                nz = MIN_int32_T;
              } else {
                nz = k - q1;
              }

              o[i + 984 * (j + 10)] = (nz == 20);
            }

            for (j = 0; j < 10; j++) {
              q1 = in[i + 984 * (j + 720)];
              if (nz < q1 + MIN_int32_T) {
                nz = MIN_int32_T;
              } else {
                nz -= q1;
              }

              o[i + 984 * (j + 730)] = (nz == 19 - j);
            }
          }
        }

        void c_morphop_ver_hor_logical(const bool in[728160], bool o[728160])
        {
          int i;
          int k;
          int nz;
          int q1;
          int q1_tmp;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(nz,k,i,q1_tmp,q1)

          for (int j = 0; j < 740; j++) {
            nz = in[984 * j];
            for (k = 0; k < 9; k++) {
              nz += in[(k + 984 * j) + 1];
            }

            o[984 * j] = (nz > 0);
            for (i = 0; i < 10; i++) {
              q1_tmp = i + 984 * j;
              q1 = in[q1_tmp + 10];
              if (nz > MAX_int32_T - q1) {
                nz = MAX_int32_T;
              } else {
                nz += q1;
              }

              o[q1_tmp + 1] = (nz > 0);
            }

            for (i = 0; i < 964; i++) {
              q1_tmp = i + 984 * j;
              q1 = in[q1_tmp + 20];
              if (nz > MAX_int32_T - q1) {
                k = MAX_int32_T;
              } else {
                k = nz + q1;
              }

              q1 = in[q1_tmp];
              if (k < q1 + MIN_int32_T) {
                nz = MIN_int32_T;
              } else {
                nz = k - q1;
              }

              o[q1_tmp + 11] = (nz > 0);
            }

            for (i = 0; i < 9; i++) {
              q1_tmp = i + 984 * j;
              q1 = in[q1_tmp + 964];
              if (nz < q1 + MIN_int32_T) {
                nz = MIN_int32_T;
              } else {
                nz -= q1;
              }

              o[q1_tmp + 975] = (nz > 0);
            }
          }
        }

        void d_morphop_ver_hor_logical(const bool in[728160], bool o[728160])
        {
          int j;
          int k;
          int nz;
          int q1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(nz,k,j,q1)

          for (int i = 0; i < 984; i++) {
            nz = in[i];
            for (k = 0; k < 9; k++) {
              nz += in[i + 984 * (k + 1)];
            }

            o[i] = (nz > 0);
            for (j = 0; j < 10; j++) {
              q1 = in[i + 984 * (j + 10)];
              if (nz > MAX_int32_T - q1) {
                nz = MAX_int32_T;
              } else {
                nz += q1;
              }

              o[i + 984 * (j + 1)] = (nz > 0);
            }

            for (j = 0; j < 720; j++) {
              q1 = in[i + 984 * (j + 20)];
              if (nz > MAX_int32_T - q1) {
                k = MAX_int32_T;
              } else {
                k = nz + q1;
              }

              q1 = in[i + 984 * j];
              if (k < q1 + MIN_int32_T) {
                nz = MIN_int32_T;
              } else {
                nz = k - q1;
              }

              o[i + 984 * (j + 11)] = (nz > 0);
            }

            for (j = 0; j < 9; j++) {
              q1 = in[i + 984 * (j + 720)];
              if (nz < q1 + MIN_int32_T) {
                nz = MIN_int32_T;
              } else {
                nz -= q1;
              }

              o[i + 984 * (j + 731)] = (nz > 0);
            }
          }
        }

        void morphop_ver_hor_logical(const bool in[728160], bool o[728160])
        {
          int i;
          int k;
          int nz;
          int q1;
          int q1_tmp;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(nz,k,i,q1_tmp,q1)

          for (int j = 0; j < 740; j++) {
            nz = in[984 * j];
            for (k = 0; k < 10; k++) {
              nz += in[(k + 984 * j) + 1];
            }

            o[984 * j] = (nz == 11);
            for (i = 0; i < 9; i++) {
              q1_tmp = i + 984 * j;
              q1 = in[q1_tmp + 11];
              if (nz > MAX_int32_T - q1) {
                nz = MAX_int32_T;
              } else {
                nz += q1;
              }

              o[q1_tmp + 1] = (nz == i + 12);
            }

            for (i = 0; i < 964; i++) {
              q1_tmp = i + 984 * j;
              q1 = in[q1_tmp + 20];
              if (nz > MAX_int32_T - q1) {
                k = MAX_int32_T;
              } else {
                k = nz + q1;
              }

              q1 = in[q1_tmp];
              if (k < q1 + MIN_int32_T) {
                nz = MIN_int32_T;
              } else {
                nz = k - q1;
              }

              o[q1_tmp + 10] = (nz == 20);
            }

            for (i = 0; i < 10; i++) {
              q1_tmp = i + 984 * j;
              q1 = in[q1_tmp + 964];
              if (nz < q1 + MIN_int32_T) {
                nz = MIN_int32_T;
              } else {
                nz -= q1;
              }

              o[q1_tmp + 974] = (nz == 19 - i);
            }
          }
        }
      }
    }
  }
}

// End of code generation (morphopAlgo.cpp)
