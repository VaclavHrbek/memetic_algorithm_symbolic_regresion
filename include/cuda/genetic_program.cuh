#pragma once


#include <time.h>
#include <stddef.h>

#include "c/population.h"
#include "c/genetic_operation.h"
#include "c/optimizer.h"
#include "c/genetic_program.h"

#include "cuda/fitness.cuh"
#include "cuda/population.cuh"
#include "cuda/optimizer.cuh"

#ifdef __cplusplus
extern "C" {
#endif
	void run_gp_gpu(GeneticProgram* gp);
#ifdef __cplusplus
}
#endif

