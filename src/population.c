#include <population.h>


void create_population(Population* pop){
	for(size_t i = 0; i != pop->size_pop; ++i){
		for(size_t a = 0; a != pop->num_of_nodes_ind; ++a){
			if(a < (pop->num_of_nodes_ind / 2)){
				pop->arr[i][a] = random_function();
			}
			else{
				pop->arr[i][a] = random_terminal();
			}
		}
	}
}

void print_population(const Population* pop){
	for(size_t i = 0; i != pop->size_pop; i++){
		for(size_t a = 0; a != pop->num_of_nodes_ind; a++){
			printf("%c ", pop->arr[i][a]);
		}
		printf("fitness: %f", pop->fitness[i]); 
		puts("");
	}
}
