#include <genetic_operation.h>
#include <stdio.h>

char* genetic_operations(const char* pop, const float* fit, const size_t depth_ind, 
		const size_t size_pop, const float mut_rate, const float cross_rate){
	size_t num_of_nodes = (2u << (depth_ind - 1u)) - 1u;
	char* new_population = (char*) malloc(size_pop * num_of_nodes * sizeof(char));
	for(size_t i = 0; i != size_pop; i++){
		float r = (float)(rand() % 10) / 10;
		if(r < mut_rate){
			const char* ind = turnament_selection(pop, fit, size_pop, num_of_nodes);
			mutation(ind, &new_population[i * num_of_nodes], num_of_nodes);
		}
		else if(r > mut_rate && r < cross_rate){
			const char* ind_1 = turnament_selection(pop, fit, size_pop, num_of_nodes);
			const char* ind_2 = turnament_selection(pop, fit, size_pop, num_of_nodes);
			crossover(ind_1, ind_2, &new_population[i * num_of_nodes], num_of_nodes);
		}
		else{
			const char* ind = turnament_selection(pop, fit, size_pop, num_of_nodes);
			copy(ind, &new_population[i * num_of_nodes], num_of_nodes);
		}
	}
	return new_population;

}

void copy(const char* ind, char* pos, const size_t num_of_nodes){
	for(size_t i = 0; i != num_of_nodes; i++){
			pos[i] = ind[i];
	}
}


void crossover(const char* ind_1, const char* ind_2, char* pos, const size_t num_of_nodes){
	size_t r = (size_t)(rand()) % num_of_nodes;
	for(size_t i = 0; i != num_of_nodes; i++){
		if(i > r){
			pos[i] = ind_1[i];
		}
		else{
			pos[i] = ind_2[i];
		}
	}
}

void mutation(const char* ind, char* pos, const size_t num_of_nodes){
	size_t r = (size_t)(rand()) % num_of_nodes;
	for(size_t i = 0; i != num_of_nodes; i++){
		if(i == r){
			if(i < ((num_of_nodes + 1) / 2) - 1){
				pos[i] = random_function();
			}
			else{
				pos[i] = random_terminal();
			}
		}
		else{
			pos[i] = ind[i];
		}
	}
}

// return two individuals in current population
const char* turnament_selection(const char* pop, const float* fit, 
		const size_t size_pop, const size_t num_of_nodes){
	size_t index_1 = (size_t)(rand()) % size_pop;
	size_t index_2 = (size_t)(rand()) % size_pop;
	if(fit[index_1] < fit[index_2]){
		return &pop[index_1 * num_of_nodes];
	}
	else{
		return &pop[index_2 * num_of_nodes];
	}
}
