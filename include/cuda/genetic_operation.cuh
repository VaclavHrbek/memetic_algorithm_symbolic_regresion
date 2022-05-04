#pragma once

#include <cuda.h>
#include <curand_kernel.h>

#include "c/population.h"

#ifdef __cplusplus
extern "C" {
#endif
	__device__
		Individual device_random_all_constants(Individual ind, curandState* state);
#ifdef __cplusplus
}
#endif

