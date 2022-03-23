#pragma once

#include <stddef.h>
#include <stdbool.h>
#include <float.h>

#include "c/equation.h"
#include "c/population.h"

void calculate_fitness(Population* pop);

bool final_solution(const float* arr, size_t size);

