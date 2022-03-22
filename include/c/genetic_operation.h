#pragma once

#include <stddef.h>
#include <stdlib.h>

#include "c/terminal.h"
#include "c/function.h"
#include "c/data_structures.h"
#include "c/population.h"

// TODO In some future refactoring try use currying. This function has to 
// manny argument. It will be better (more suitable) it has only one.

Population genetic_operations(const Population* pop, const float mut_rate, const float cross_rate);

Individual turnament_selection(const Population *pop);

void mutation(Individual ind, Population* pop);

void crossover(Individual ind_1, Individual ind_2, Population* pop);

void copy(const char* ind, char* pos, const size_t num_of_nodes);
