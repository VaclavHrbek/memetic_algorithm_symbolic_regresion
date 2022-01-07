#pragma once

#include <stddef.h>
#include <stdlib.h>

#include "terminal.h"
#include "function.h"
#include "data_structures.h"

// TODO In some future refactoring try use currying. This function has to 
// manny argument. It will be better (more suitable) it has only one.

Population genetic_operations(const Population* pop, const float mut_rate, const float cross_rate);

const char* turnament_selection(const Population *pop);

void mutation(const char* ind, char* pos, const size_t num_of_nodes);

void crossover(const char* ind_1, const char* ind_2, char* pos, const size_t num_of_nodes);

void copy(const char* ind, char* pos, const size_t num_of_nodes);
