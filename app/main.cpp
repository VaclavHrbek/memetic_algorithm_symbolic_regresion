
#include "c/genetic_program.h"
#include "cuda/genetic_program.cuh"


int main(){
	GeneticProgram* gp = (GeneticProgram*)(malloc(sizeof(GeneticProgram)));
	gp->pop = malloc_population();
	gp->data = malloc_data();

	printf("Settings: \n"
			"Number of evolutionary cycles: %li \n"
			"Number of generation: %li \n"
			"Size of the population: %li \n"
			"Size of the tree: %li \n"
			"Mutation constant: %f \n"
			"Crossover constan: %f \n"
			"Number of optimization cycles: %li \n"
			"Number of best individual to optimize: %li \n:"
			, NUM_OF_EVOLUTIONARY_CYCLES,
			NUM_OF_GENERATION,
			SIZE_OF_POPULAION,
			NUMBER_OF_NODES_IND,
			MUTAION_RATE,
			CROSSOUVER_RATE,
			NUM_OF_OPTIMIZATION,
			SIZE_FOR_OPTIMIZATION);
	
	run_gp(gp);
	//run_gp_gpu(gp);

	free(gp->data);
	free(gp->pop);
	free(gp);
	return 0;
}


