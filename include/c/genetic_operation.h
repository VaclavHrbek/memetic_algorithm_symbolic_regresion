#pragma once

#include <stddef.h>
#include <stdlib.h>

#include "c/terminal.h"
#include "c/function.h"
#include "c/population.h"

// TODO In some future refactoring try use currying. This function has to 
// manny argument. It will be better (more suitable) it has only one.

#define MUTAION_RATE (float) 0.1
#define CROSSOUVER_RATE (float) 0.9

Population* genetic_operations(Population* pop, const float mut_rate, const float cross_rate);
Individual turnament_selection(const Population *pop);
Individual mutation(Individual ind);
void crossover(Individual ind_1, Individual ind_2, Population* pop);
void copy(const char* ind, char* pos, const size_t num_of_nodes);
Individual random_all_constants(Individual ind);
