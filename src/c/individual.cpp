#include "c/individual.h"

void print_ind(Individual* ind){
	printf("Best with fitness: %f \n", ind->fitness);
	for(size_t i = 0; i != ind->size; ++i){
			print_node(&ind->node[i]);
			printf(", ");
	}
	printf("\n");
}

void put_ind_to_file(Individual* ind){
	std::ofstream out_file;
	out_file.open(OUTPUT_RUN_FILE, std::ios_base::app);
	out_file << ind->fitness << ',';
	for(size_t i = 0; i != ind->size; ++i){
			out_file << node_value(&ind->node[i]) << ',';
	}
	out_file << '\n';
	out_file.close();

}
