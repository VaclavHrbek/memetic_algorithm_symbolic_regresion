#pragma once

#include <stddef.h>
#include <stdbool.h>

#include <equation.h>

float* calculate_fitness(const char* pop, const size_t depth_ind, const size_t size_pop);

bool final_solution(const float* arr, size_t size);

size_t get_index_of_best(const float* arr, const size_t size);
