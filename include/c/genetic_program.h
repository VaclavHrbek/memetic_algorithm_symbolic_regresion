#pragma once

#include <time.h>
#include <stddef.h>

#include "c/population.h"
#include "c/fitness.h"
#include "cuda/fitness.cuh"
#include "c/genetic_operation.h"
#include "c/optimizer.h"

#define NUM_OF_GENERATION (size_t) 10   
#define NUM_OF_EVOLUTIONARY_CYCLES (size_t) 1
#define END_CONDITION_FITTNESS_LESS_THAN (float) 0.2

typedef struct gp {
	Population* pop;
	Data* data;
} GeneticProgram;

void run_gp(GeneticProgram* gp);
void run_gp_gpu(GeneticProgram* gp);

