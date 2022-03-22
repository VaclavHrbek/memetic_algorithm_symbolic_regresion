#include "c/genetic_operation.h"

Population genetic_operations(const Population* pop, const float mut_rate, const float cross_rate){
	Population new_pop = { .size = 0 };
	for(size_t i = 0; i != pop->size; i++){
		float r = (float)(rand() % 10) / 10;
		if(r < mut_rate){
			Individual ind = turnament_selection(pop);
			mutation(ind, &new_pop);
		}
		else if((r > mut_rate && r < cross_rate) && (new_pop.size < (SIZE_OF_POPULAION - 1))){
			Individual ind_1 = turnament_selection(pop);
			Individual ind_2 = turnament_selection(pop);
			crossover(ind_1, ind_2, &new_pop);
		}
		else{
			Individual ind = turnament_selection(pop);
			push_to_pop(ind, &new_pop);
		}
	}
	return new_pop;
}

void crossover(Individual ind_1, Individual ind_2, Population* pop){
	size_t r = (size_t)(rand()) % ind_1.size;
	for(size_t i = 0; i != ind_1.size; i++){
		if(i >= r){
			Node tmp = ind_1.node[i];
			ind_1.node[i] = ind_2.node[i];
			ind_2.node[i] = tmp;
		}
	}
	push_to_pop(ind_1, pop);
	push_to_pop(ind_2, pop);
}

void mutation(Individual ind, Population* pop){
	size_t r = (size_t)(rand()) % ind.size;
	if(ind.node[r].type == FUNCTION){
		ind.node[r] = random_function();
	}else{
		ind.node[r] = random_terminal();
	}
	push_to_pop(ind, pop);
}

Individual turnament_selection(const Population* pop){
	size_t index_1 = (size_t)(rand()) % pop->size;
	size_t index_2 = (size_t)(rand()) % pop->size;
	if(index_1 == index_2){
		if(index_2 != pop->size-1){
			index_2++;
		}else {
			index_2--;
		}
	}
	if(pop->ind[index_1].fitness < pop->ind[index_2].fitness){
		return pop->ind[index_1];
	}
	else{
		return pop->ind[index_2];
	}
}
