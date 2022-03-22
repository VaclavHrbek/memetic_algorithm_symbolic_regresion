#pragma once

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <stdbool.h>

#include "c/data_structures.h"
#include "c/terminal.h"
#include "c/function.h"

Population create_population(const size_t s, const size_t n);

void push_to_pop(Individual ind, Population* pop);

Individual get_best_ind(Population* pop);

size_t get_index_of_best(Population *pop);

bool check_zero_fitness(Population* pop);

void print_best_ind_from_population(Population* pop);

void print_ind(Individual* ind);

void print_node(Node* n);
