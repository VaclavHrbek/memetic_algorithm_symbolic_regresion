#pragma once

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <stdbool.h>
#include <math.h>

#include "c/terminal.h"
#include "c/function.h"
#include "c/individual.h"

#define SIZE_OF_POPULAION (size_t) 2000

typedef struct population {
		size_t size;
		Individual ind[SIZE_OF_POPULAION];
} Population;

Population* create_population(const size_t s, const size_t n);
void push_to_pop(Individual ind, Population* pop);
Individual get_best_ind(Population* pop);
bool check_fitness_less_than(Population* pop, float val);
void print_best_ind_from_population(Population* pop);
Population* malloc_population(void);
size_t get_index_of_best_in_population(const Population* pop);
size_t* get_n_indexes_of_best_ind_in_population(const Population* pop, const size_t n);
void put_best_to_file(Population* pop);
