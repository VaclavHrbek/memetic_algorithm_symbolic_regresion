#include <stddef.h>

#include <population.h>

#define SIZE_OF_POPULAION (size_t) 1
#define DEPTH_OF_INDIVIDUAL (size_t) 2

#define NUM_OF_GENERATION (size_t) 1



int main(){
	char** population = create_population(SIZE_OF_POPULAION, DEPTH_OF_INDIVIDUAL);
	return 0;
}
