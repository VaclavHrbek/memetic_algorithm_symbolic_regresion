#include <time.h>
#include <stddef.h>

#include <population.h>
#include <fitness.h>
#include <genetic_operation.h>

#define SIZE_OF_POPULAION (size_t) 2
#define DEPTH_OF_INDIVIDUAL (size_t) 2

#define MUTAION_RATE (float) 0.1
#define CROSSOUVER_RATE (float) 0.7

#define NUM_OF_GENERATION (size_t) 1



int main(){
	srand((unsigned int)time(NULL));	

	char* population = create_population(DEPTH_OF_INDIVIDUAL, SIZE_OF_POPULAION);
	float* fitness = calculate_fitness(population, DEPTH_OF_INDIVIDUAL, SIZE_OF_POPULAION);

	char* new_population = genetic_operations(population, fitness, DEPTH_OF_INDIVIDUAL, SIZE_OF_POPULAION,
			MUTAION_RATE, CROSSOUVER_RATE);
	float* new_fitness = calculate_fitness(new_population, DEPTH_OF_INDIVIDUAL, SIZE_OF_POPULAION);
	
	print_population(population, fitness, DEPTH_OF_INDIVIDUAL, SIZE_OF_POPULAION);
	puts("");
	print_population(new_population, new_fitness, DEPTH_OF_INDIVIDUAL, SIZE_OF_POPULAION);

	free(new_population);
	free(new_fitness);
	free(population);
	free(fitness);
	return 0;
}
