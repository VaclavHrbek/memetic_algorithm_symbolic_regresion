#include "c/optimizer.h"

Population optimize(Population pop){
	size_t optimize_indx[SIZE_FOR_OPTIMIZATION];
	for(size_t i = 0; i != SIZE_FOR_OPTIMIZATION; ++i){
		optimize_indx[i] = get_index_of_best(pop.fitness, pop.size_pop);
		pop.fitness[optimize_indx[i]] = FLT_MAX;	
	}
	for(size_t i = 0; i != SIZE_FOR_OPTIMIZATION; ++i){
		if(optimize_ind(&pop, optimize_indx[i]) == true){
			return pop;
		}
	}
	return pop;
}

bool optimize_ind(Population* pop, const size_t i){
	for(size_t a = 0; a != NUM_OF_OPTIMIZATION; ++a){
		pop->fitness[i] = equation(pop->arr[i], pop->num_of_nodes_ind);
		if(pop->fitness[i] == 0){
			return true; 
		}
		mutation(pop->arr[i], pop->arr[i], pop->num_of_nodes_ind);
	}
		return false;
}
