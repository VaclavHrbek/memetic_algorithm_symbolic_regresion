#pragma once

#include <time.h>
#include <stddef.h>

#include "c/population.h"
#include "c/fitness.h"
#include "c/genetic_operation.h"
#include "c/optimizer.h"

#define NUM_OF_GENERATION (size_t) 1000
#define NUM_OF_EVOLUTIONARY_CYCLES (size_t) 5
#define END_CONDITION_FITTNESS_LESS_THAN (float) 0.1

typedef struct gp {
	Population* pop;
	Data* data;
} GeneticProgram;

void run_gp(GeneticProgram* gp);

