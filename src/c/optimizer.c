#include "c/optimizer.h"


Population optimize(Population pop){
	for(size_t a = 0; a != NUM_OF_OPTIMIZATION; ++a){
		Population new_pop = pop;
		for(size_t x = 0; x != new_pop.size; x++){
			new_pop.ind[x].fitness = FLT_MAX;
		}
		new_pop.size = 0;
		
		for(size_t i = 0; i != SIZE_FOR_OPTIMIZATION; ++i){
			mutation(get_best_ind(&pop), &new_pop);
		}

		calculate_fitness(&new_pop);
		if(check_zero_fitness(&new_pop) == true){
			return new_pop;
		};
		new_pop.size = pop.size;
		pop = new_pop;
	}
	return pop;
}
