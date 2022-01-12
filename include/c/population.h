#pragma once

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "c/data_structures.h"
#include "c/terminal.h"
#include "c/function.h"

void create_population(Population* pop);

void print_population(const Population* pop);

void print_best_individual(const Population* pop);
