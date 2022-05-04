#pragma once

#include <cuda.h>
#include <curand_kernel.h>

#include "c/optimizer.h"

#include "cuda/population.cuh"
#include "cuda/genetic_operation.cuh"
#include "cuda/equation.cuh"

#ifdef __cplusplus
extern "C" {
#endif

	void cuda_optimize(Population* d_pop);
#ifdef __cplusplus
}
#endif
