#pragma once

#include <stddef.h>
#include <stdbool.h>

#include "equation.h"
#include "data_structures.h"

void calculate_fitness(Population* pop);

bool final_solution(const float* arr, size_t size);

size_t get_index_of_best(const float* arr, const size_t size);
