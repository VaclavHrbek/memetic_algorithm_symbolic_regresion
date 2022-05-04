#pragma once

#include <stddef.h>
#include <stdbool.h>
#include <float.h>

#include "c/population.h"
#include "c/genetic_program.h"

#include "cuda/equation.cuh"
#include "cuda/individual.cuh"


#ifdef __cplusplus
extern "C" {
#endif
	void cuda_calculate_fitness(Population* d_pop);
#ifdef __cplusplus
}
#endif




