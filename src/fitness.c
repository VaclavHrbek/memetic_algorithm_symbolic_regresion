#include <fitness.h>


float* calculate_fitness(const char* pop, const size_t depth_ind, const size_t size_pop){
	float* fit_arr = (float*) malloc(sizeof(float) * size_pop);
	for(size_t i = 0; i != size_pop; i++){
		size_t begin = i * ((2u << (depth_ind - 1)) - 1u);
		size_t end = begin + ((2u << (depth_ind - 1)) - 1u);
		fit_arr[i] = equation(pop, begin, end);
	}
	return fit_arr;
}
