
#include "c/genetic_program.h"
#include "cuda/genetic_program.cuh"


int main(){
	GeneticProgram* gp = (GeneticProgram*)(malloc(sizeof(GeneticProgram)));
	gp->pop = malloc_population();
	gp->data = malloc_data();

	std::ofstream out_file;
	out_file.open(OUTPUT_FILE_NAME);
			out_file << "Number of evolutionary cycles, " << NUM_OF_EVOLUTIONARY_CYCLES << '\n';
			out_file << "Number of generation," << NUM_OF_GENERATION << '\n';
			out_file << "Size of the population," << SIZE_OF_POPULAION << '\n';
			out_file << "Size of the tree," << NUMBER_OF_NODES_IND << '\n';
			out_file << "Mutation constant," << MUTAION_RATE << '\n';
			out_file << "Crossover constant," << CROSSOUVER_RATE << '\n';
			out_file << "Number of optimization cycles," << NUM_OF_OPTIMIZATION << '\n';
			out_file << "Number of best individuals to optimize," << SIZE_FOR_OPTIMIZATION << '\n';
	out_file.close();
	
	run_gp(gp);
	
	out_file.open(OUTPUT_FILE_NAME, std::ios_base::app);
	out_file << "#######################\n";
	out_file << "Parallel execution below\n";
	out_file << "#######################\n";
	out_file.close();
	std::ofstream out_r;
	out_r.open(OUTPUT_RUN_FILE, std::ios_base::app);
	out_r << "#######################\n";
	out_r << "Parallel execution below\n";
	out_r << "#######################\n";
	out_r.close();

	free(gp->pop);
	gp->pop = malloc_population();
	run_gp_gpu(gp);

	free(gp->data);
	free(gp->pop);
	free(gp);
	return 0;
}


