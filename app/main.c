#include <time.h>
#include <stddef.h>

#include "data_structures.h"
#include "population.h"
#include "fitness.h"
#include "genetic_operation.h"


int main(void){
	srand((unsigned int)time(NULL));	

	Population pop = { .size_pop = SIZE_OF_POPULAION, .num_of_nodes_ind = NUMBER_OF_NODES_IND};

	create_population(&pop);

	//for(size_t i = 0; i != NUM_OF_GENERATION; ++i){
		calculate_fitness(&pop);
	//}
	print_population(&pop);

/*
		char* new_population = genetic_operations(population, fitness, DEPTH_OF_INDIVIDUAL, SIZE_OF_POPULAION, MUTAION_RATE, CROSSOUVER_RATE);

		free(population);
		population = new_population;
		free(new_population);

		if(final_solution(fitness, SIZE_OF_POPULAION) == true){
			size_t best = get_index_of_best(fitness, SIZE_OF_POPULAION);
			const char* ind = get_ptr_ind_by_index(best, population, num_of_nodes);
			print_individual(ind, fitness[best], num_of_nodes);

			free(fitness);
			free(population);
			free(new_population);
			return 0;
		}

		free(fitness);

	}
	*/
	
	
	puts("");
	//print_population(population, fitness, DEPTH_OF_INDIVIDUAL, SIZE_OF_POPULAION);
	puts("");

	return 0;
}
