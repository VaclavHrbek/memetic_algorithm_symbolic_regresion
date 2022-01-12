#include "c/genetic_operation.h"

Population genetic_operations(const Population* pop, const float mut_rate, const float cross_rate){
	Population new_pop = { .size_pop = SIZE_OF_POPULAION, .num_of_nodes_ind = NUMBER_OF_NODES_IND};
	for(size_t i = 0; i != pop->size_pop; i++){
		float r = (float)(rand() % 10) / 10;
		if(r < mut_rate){
			const char* ind = turnament_selection(pop);
			mutation(ind, new_pop.arr[i], pop->num_of_nodes_ind);
		}
		else if(r > mut_rate && r < cross_rate){
			const char* ind_1 = turnament_selection(pop);
			const char* ind_2 = turnament_selection(pop);
			crossover(ind_1, ind_2, new_pop.arr[i], pop->num_of_nodes_ind);
		}
		else{
			const char* ind = turnament_selection(pop);
			copy(ind, new_pop.arr[i], pop->num_of_nodes_ind);
		}
	}
	return new_pop;

}

void copy(const char* ind, char* pos, const size_t num_of_nodes){
	for(size_t i = 0; i != num_of_nodes; i++){
			pos[i] = ind[i];
	}
}


void crossover(const char* ind_1, const char* ind_2, char* pos, const size_t num_of_nodes){
	size_t r = (size_t)(rand()) % num_of_nodes;
	for(size_t i = 0; i != num_of_nodes; i++){
		if(i > r){
			pos[i] = ind_1[i];
		}
		else{
			pos[i] = ind_2[i];
		}
	}
}

void mutation(const char* ind, char* pos, const size_t num_of_nodes){
	size_t r = (size_t)(rand()) % num_of_nodes;
	for(size_t i = 0; i != num_of_nodes; i++){
		if(i == r){
			if(i < ((num_of_nodes + 1) / 2) - 1){
				pos[i] = random_function();
			}
			else{
				pos[i] = random_terminal();
			}
		}
		else{
			pos[i] = ind[i];
		}
	}
}

// return two individuals in current population
const char* turnament_selection(const Population* pop){
	size_t index_1 = (size_t)(rand()) % pop->size_pop;
	size_t index_2 = (size_t)(rand()) % pop->size_pop;
	if(pop->fitness[index_1] < pop->fitness[index_2]){
		return pop->arr[index_1];
	}
	else{
		return pop->arr[index_2];
	}
}
