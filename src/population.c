#include <population.h>


char* create_population(size_t size, size_t depth_ind){
	char* population = (char*) malloc(size * depth_ind * sizeof(char));
	return population;
}

