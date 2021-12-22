#include <time.h>
#include <stddef.h>

#include <population.h>
#include <fitness.h>
#include <genetic_operation.h>

#define SIZE_OF_POPULAION (size_t) 10
#define DEPTH_OF_INDIVIDUAL (size_t) 2

#define MUTAION_RATE (float) 0.1
#define CROSSOUVER_RATE (float) 0.7

#define NUM_OF_GENERATION (size_t) 50



int main(void){
	struct population {
			char arr[SIZE_OF_POPULAION][DEPTH_OF_INDIVIDUAL];
			size_t size;
			size_t depth_ind;
			size_t num_of_nodes_ind;
			float fitness[SIZE_OF_POPULAION];
	};
	struct population *pop; 
	pop = (struct population *) malloc(sizeof(struct population));
/*
	srand((unsigned int)time(NULL));	
	size_t num_of_nodes = (2u << (DEPTH_OF_INDIVIDUAL - 1)) - 1u;

	char* population = create_population(DEPTH_OF_INDIVIDUAL, SIZE_OF_POPULAION);

	for(size_t i = 0; i != NUM_OF_GENERATION; i++){

		float* fitness = calculate_fitness(population, DEPTH_OF_INDIVIDUAL, SIZE_OF_POPULAION);
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
