#include "c/individual.h"

void print_ind(Individual* ind){
	printf("Best with fitness: %f \n", ind->fitness);
	int last_height = 0;
	int new_height = 0;
	for(size_t i = 0; i != ind->size; ++i){
			print_node(&ind->node[i]);
			printf(", ");
	}
	printf("\n");
}
