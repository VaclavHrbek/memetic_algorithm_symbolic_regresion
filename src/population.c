#include <population.h>


char* create_population(size_t depth_ind, size_t size){
	size_t num_of_nodes = (2u << (depth_ind - 1)) - 1u;
	char* population = (char*) malloc(size * num_of_nodes * sizeof(char));
	initialize_population(population, num_of_nodes, size);
	return population;
}

void initialize_population(char* pop, size_t num_of_nodes, size_t size_pop){
	for(size_t i = 0; i != size_pop; i++){
		create_individual(pop,  num_of_nodes, sizeof(char)*i*num_of_nodes);
	}
}

void create_individual(char* pop, size_t num_of_nodes, size_t offset){
	for(size_t i = 0; i != num_of_nodes; i++){
		if(i < ((num_of_nodes + 1) / 2) - 1){
			pop[i + offset] = random_function();
		}
		else{
			pop[i + offset] = random_terminal();
		}
	}
}

void print_population(const char* pop, const float* fit, size_t depth_ind, size_t size_pop){
	size_t num_of_nodes = (2u << (depth_ind - 1)) - 1u;
	for(size_t i = 0; i != size_pop; i++){
		for(size_t a = 0; a != num_of_nodes; a++){
			printf("%c ", pop[(i* num_of_nodes) + a]);
		}
		printf("fitness: %f", fit[i]); 
		puts("");
	}
}
