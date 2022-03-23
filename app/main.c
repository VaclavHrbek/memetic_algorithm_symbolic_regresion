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

		clock_t t = clock();
	for(size_t a = 0; a != NUM_OF_EVOLUTIONARY_CYCLES; ++a){
		t = clock();

		Population pop = create_population(SIZE_OF_POPULAION, NUMBER_OF_NODES_IND);
		calculate_fitness(&pop);
		//cuda_calculate_fitness(&pop);
		if(check_zero_fitness(&pop) == true){
			printf("Found solution in initial population\n");
			print_best_ind_from_population(&pop);
			return 0;
		};

		for(size_t i = 0; i != NUM_OF_GENERATION; ++i){
			printf("Generation: %ld \n", i);

			Population new_pop = optimize(pop);
			calculate_fitness(&new_pop);
			//cuda_calculate_fitness(&new_pop);

			if(check_zero_fitness(&new_pop) == true){
				printf("Found solution after optimization\n");
				print_best_ind_from_population(&new_pop);
				t = clock()-1;
				double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
				printf("Cycle took %f seconds to execute \n", time_taken);
				return 0;
			};

			new_pop = genetic_operations(&pop, MUTAION_RATE, CROSSOUVER_RATE);
			calculate_fitness(&new_pop);
			//cuda_calculate_fitness(&new_pop);

			if(check_zero_fitness(&new_pop) == true){
				printf("Found solution after genetic operation\n");
				print_best_ind_from_population(&new_pop);
				t = clock()-1;
				double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
				printf("Cycle took %f seconds to execute \n", time_taken);
				return 0;
			};

			pop = new_pop;
		}
		t = clock()-t;
		double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
		printf("Cycle took %f seconds to execute \n", time_taken);
		print_best_ind_from_population(&pop);
	}
	return 0;
}


