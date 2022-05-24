#include "c/fitness.h"

void calculate_fitness(Population* pop){
	for(size_t i = 0; i != pop->size; ++i){
		pop->ind[i].fitness = equation_xy(pop->ind[i]);
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

