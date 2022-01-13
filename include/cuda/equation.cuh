#pragma once

#include <stdlib.h>

#include "c/data_structures.h"

#ifdef __cplusplus
extern "C" {

__device__ const Data device_load_data();

__device__ float device_equation(const char* ind, const size_t offset);

}
#endif

