#include <time.h>
#include <stddef.h>

#include "c/data_structures.h"
#include "c/population.h"
#include "c/fitness.h"
#include "cuda/fitness.cuh"
#include "c/genetic_operation.h"

int main(void){
	srand((unsigned int)time(NULL));	

	Population pop = { .size_pop = SIZE_OF_POPULAION, .num_of_nodes_ind = NUMBER_OF_NODES_IND};
	create_population(&pop);

	for(size_t i = 0; i != NUM_OF_GENERATION; ++i){
		cuda_calculate_fitness(&pop);

		if(final_solution(pop.fitness, pop.size_pop) == true){
			printf("Found best solution: \n");
			print_best_individual(&pop);
			return 0;
		}else{
			printf("Generation: %ld \n", i);
			print_best_individual(&pop);
		}

		Population new_pop = { .size_pop = SIZE_OF_POPULAION, .num_of_nodes_ind = NUMBER_OF_NODES_IND};
		new_pop = genetic_operations(&pop, MUTAION_RATE, CROSSOUVER_RATE);

		pop = new_pop;
		
	}
	return 0;
}
