#pragma once

#include <stdlib.h>
#include <cuda.h>
#include <curand_kernel.h>

#include "c/data.h"
#include "c/individual.h"

#ifdef __cplusplus
extern "C" {
#endif
	__device__
		Data device_load_data();
	__device__
		Data_xy device_load_data_xy();
	__device__ 
		float device_equation(const Individual ind);
	__device__ 
		float device_equation_xy(const Individual ind);
	__device__
		float device_compute_tree_node(const Node par, const Node ch_1, const Node ch_2);
	__device__
		float device_sum_square_roots_of_deviation(const float* arr, const float* y,const size_t fit_case);
	__device__
		float device_sum_square_roots_of_deviation_xy(const float* arr, const Data_xy& data);
#ifdef __cplusplus
}
#endif

