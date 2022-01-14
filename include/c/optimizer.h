#pragma once

#include <string.h>
#include <float.h>

#include "c/data_structures.h"
#include "c/fitness.h"
#include "c/equation.h"
#include "c/genetic_operation.h"

Population optimize(Population pop);

bool optimize_ind(Population* pop, const size_t indx);
