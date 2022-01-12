#pragma once

#include <stdlib.h>

typedef struct data {
	float x[3];
	float y[3];
	size_t size;
} Data;

const Data load_data();

float equation(const char* ind, const size_t offset);

void fill_values(float* arr, const float x, const char* ind,
		const size_t offset);

void compute_values(float* arr,  const char* ind,
		const size_t offset);

float compute_tree_nodes(const char n, const float a, const float b);

float sum_square_roots_of_deviation(const float* fit_arr, const float* y,const size_t fit_case);
