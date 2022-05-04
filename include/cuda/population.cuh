#pragma once

#include "c/population.h"

#include "cuda/population.cuh"
#include "cuda/individual.cuh"

#ifdef __cplusplus
extern "C" {
#endif
		Population* cuda_malloc_population();
		void cuda_host_to_device_memcpy_population(Population* d_pop, Population* pop);
		void cuda_device_to_host_memcpy_population(Population* d_pop, Population* pop);
		__global__
			void device_get_n_indexes_of_best_ind_in_population(const Population* pop, const size_t n, size_t* indexes);
		__global__
			void device_print_best_so_far(const Population* d_pop);
		__global__
			void device_check_end_condition(const Population* d_pop);
#ifdef __cplusplus
}
#endif
