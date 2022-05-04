#include "c/optimizer.h"


Population optimize(Population* pop){
	size_t* n_best_indexes_in_pop = get_n_indexes_of_best_ind_in_population(pop, SIZE_FOR_OPTIMIZATION);
	for(size_t i = 0; i != SIZE_FOR_OPTIMIZATION; ++i){
		Individual* ind = &pop->ind[n_best_indexes_in_pop[i]];
		Individual ind_2 = stochastic_hill_climbing_constants(*ind);
		ind_2.fitness = equation(ind_2);
		if(ind_2.fitness < ind->fitness){
			*ind = ind_2;
			//printf("Better solution found in optimizer \n");
		}
	}
	free(n_best_indexes_in_pop);
	return *pop;
}

Individual stochastic_hill_climbing_constants(Individual ind){
	for(size_t i = 0; i != NUM_OF_OPTIMIZATION; ++i){
		Individual ind_2 = random_all_constants(ind);
		ind_2.fitness = equation(ind_2);
		if(ind_2.fitness < ind.fitness){
			ind = ind_2;
		}
	}
	return ind;
}
