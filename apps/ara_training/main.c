// Copyright 2020 ETH Zurich and University of Bologna.
//
// SPDX-License-Identifier: Apache-2.0
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Author: Matheus Cavalcante, ETH Zurich

#include <stdint.h>
#include <string.h>

#include "intrinsics.h"
#include "printf.h"
#include "runtime.h"

#include "ex1/ex1.h"
#include "ex2/ex2.h"
#include "ex3/ex3.h"

#include "sew.h"

// Size of the vector arrays.
// Should be defined through the Makefile!
// #define SIZE 64

// Allocate the vector arrays on the L2, and align them on 128-bit boundaries.
velement_t a[SIZE * SIZE]
    __attribute__((aligned(32 * NR_LANES), section(".l2")));
velement_t b[SIZE * SIZE]
    __attribute__((aligned(32 * NR_LANES), section(".l2")));
velement_t c[SIZE * SIZE]
    __attribute__((aligned(32 * NR_LANES), section(".l2")));

int main(void) {
  printf("SoCDAML -- 20/04/2021\n\n");

#if (EX1 == 1)
  printf("\n-- Exercise 1 --\n");
  ex1();
#endif

#if (EX2 == 1)
  printf("\n-- Exercise 2 --\n");
  ex2(c, a, b);
#endif

#if (EX3 == 1)
  printf("\n-- Exercise 3 --\n");
  ex3(c, a, b);
#endif

  printf("Done.\n\n");
  return 0;
}
