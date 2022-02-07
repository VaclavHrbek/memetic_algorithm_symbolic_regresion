#include <time.h>
#include <stddef.h>

#include "c/data_structures.h"
#include "c/population.h"
#include "c/fitness.h"
#include "cuda/fitness.cuh"
#include "c/genetic_operation.h"
#include "c/optimizer.h"

int main(void){
	srand((unsigned int)time(NULL));	

	Population pop = create_population(SIZE_OF_POPULAION, NUMBER_OF_NODES_IND);

	for(size_t i = 0; i != NUM_OF_GENERATION; ++i){
		printf("Generation: %ld \n", i);
		calculate_fitness(&pop);

		Population new_pop = optimize(pop);
		if(final_solution(new_pop.fitness, new_pop.size_pop) == true){
			printf("Found best solution using optimalization: \n");
			print_best_individual(&new_pop);
			return 0;
		}

		new_pop = genetic_operations(&pop, MUTAION_RATE, CROSSOUVER_RATE);
		calculate_fitness(&new_pop);
		if(final_solution(new_pop.fitness, new_pop.size_pop) == true){
			printf("Found best solution using genetic operation: \n");
			print_best_individual(&new_pop);
			return 0;
		}
		print_best_individual(&pop);

		pop = new_pop;
	}
	return 0;
}


