#include <fitness.h>


float* calculate_fitness(const char* pop, const size_t depth_ind, const size_t size_pop){
	float* fit_arr = (float*) malloc(sizeof(float) * size_pop);
	size_t num_of_nodes = ((2u << (depth_ind - 1)) - 1u);
	for(size_t i = 0; i != size_pop; i++){

		size_t begin = i * num_of_nodes;
		fit_arr[i] = equation(&pop[begin], num_of_nodes);
	}
	return fit_arr;
}

bool final_solution(const float* arr, size_t size){
	for(size_t i = 0; i != size; i++){
		if(arr[i] == 0){
			return true;
		}
	}
	return false;
}


size_t get_index_of_best(const float* arr, const size_t size){
	float best = 1000000;
	size_t best_index = 0;
	for(size_t i = 0; i != size; i++){
		if(arr[i] < best){
			best = arr[i];
			best_index = i;
		}
	}
	return best_index;
}
