#include "c/fitness.h"


void calculate_fitness(Population* pop){
	for(size_t i = 0; i != pop->size_pop; ++i){
		pop->fitness[i] = equation(pop->arr[i], pop->num_of_nodes_ind);
	}
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
