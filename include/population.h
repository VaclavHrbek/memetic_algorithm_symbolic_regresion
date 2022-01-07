#pragma once

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "data_structures.h"
#include "terminal.h"
#include "function.h"

void create_population(Population* pop);

void print_population(const Population* pop);

void print_best_individual(const Population* pop);
