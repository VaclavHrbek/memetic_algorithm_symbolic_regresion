#pragma once

#include <stdlib.h>

#include "c/population.h"
#include "c/data.h"

float equation(const Individual ind);
float equation_xy(const Individual ind);

float compute_tree_node(const Node par, const Node ch_1, const Node ch_2);

float sum_square_roots_of_deviation(const float* arr, const float* y,const size_t fit_case);
float sum_square_roots_of_deviation_xy(const float* f_xy_predict, const Data_xy& data);
