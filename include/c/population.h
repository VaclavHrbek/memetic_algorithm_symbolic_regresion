#pragma once

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "c/data_structures.h"
#include "c/terminal.h"
#include "c/function.h"

Population create_population(size_t size, size_t num_nodes_ind);

void print_population(const Population* pop);

void print_best_individual(const Population* pop);
