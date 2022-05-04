
#include "c/genetic_program.h"
#include "cuda/genetic_program.cuh"


int main(){
	GeneticProgram* gp = (GeneticProgram*)(malloc(sizeof(GeneticProgram)));
	gp->pop = malloc_population();
	gp->data = malloc_data();

	
	//run_gp(gp);
	run_gp_gpu(gp);

	free(gp->data);
	free(gp->pop);
	free(gp);
	return 0;
}


