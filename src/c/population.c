#include "c/population.h"

Population create_population(const size_t s, const size_t n){
	Population pop = { .size = s};
	for(size_t i = 0; i != pop.size; ++i){
		pop.ind[i].size = n;
		for(size_t a = 0; a != pop.ind[i].size; ++a){
			if(a < (pop.ind[i].size / 2)){
				pop.ind[i].node[a] = random_function();
			}
			else{
				pop.ind[i].node[a] = random_terminal();
			}
		}
	}
	return pop;
}

void push_to_pop(Individual ind, Population* pop){
	if(pop->size != SIZE_OF_POPULAION){
		pop->ind[pop->size] = ind;
		pop->size++;
	}
//TODO
// make exception here to know that hte population 
// is full and can't add another individual. 

}

//size_t get_index_of_best(Population *pop){
//	float best = FLT_MAX;
//	size_t best_index = 0;
//	for(size_t i = 0; i != pop->size; i++){
//		if(pop->ind[i].fitness < best){
//			best = pop->ind[i].fitness;
//			best_index = i;
//		}
//	}
//	return best_index;
//}

size_t* get_n_indexes_of_best_ind_in_population(const Population* pop, const size_t n){
	size_t* arr = (size_t*)(malloc(sizeof(size_t)*n));
	Population* new_pop = (Population*)(malloc(sizeof(Population)));
	*new_pop = *pop;
	for(size_t a = 0; a != n; a++){
		float best = FLT_MAX;
		size_t best_index = 0;
		for(size_t i = 0; i != pop->size; ++i){
			if(new_pop->ind[i].fitness < best){
				best = new_pop->ind[i].fitness;
				best_index = i;
			}
		}
		arr[a] = best_index;
		new_pop->ind[best_index].fitness = FLT_MAX;
	}
	free(new_pop);
	return arr;
};	

size_t get_index_of_best_in_population(const Population* pop){
	float best = FLT_MAX;
	size_t best_index = 0;
	for(size_t i = 0; i != pop->size; ++i){
		if(pop->ind[i].fitness < best){
			best = pop->ind[i].fitness;
			best_index = i;
		}
	}
	return best_index;
}
		

Individual get_best_ind(Population* pop){
	float best = FLT_MAX;
	size_t best_index = 0;
	for(size_t i = 0; i != pop->size; i++){
		if(pop->ind[i].fitness < best){
			best = pop->ind[i].fitness;
			best_index = i;
			pop->ind[i].fitness = FLT_MAX;
		}
	}
	return pop->ind[best_index];
}

bool check_fitness_less_than(Population* pop, float val){
	for(size_t i = 0; i != pop->size; ++i){
		if(pop->ind[i].fitness <= val){
			return true;
		}
	}
	return false;
}

void print_best_ind_from_population(Population* pop){
	size_t idx = get_index_of_best_in_population(pop);	
	print_ind(&pop->ind[idx]);
}

Population* malloc_population(void){
	Population* pop = (Population*)(malloc(sizeof(Population)));
	pop->size = SIZE_OF_POPULAION;
	for(size_t i = 0; i != pop->size; ++i){
		pop->ind[i].size = NUMBER_OF_NODES_IND;
		for(size_t a = 0; a != pop->ind[i].size; ++a){
			if(a < (pop->ind[i].size / 2)){
				pop->ind[i].node[a] = random_function();
			}
			else{
				pop->ind[i].node[a] = random_terminal();
			}
		}
	}
	return pop;
}

