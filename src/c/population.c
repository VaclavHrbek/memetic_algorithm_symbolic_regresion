#include "c/population.h"

Population create_population(const size_t s, const size_t n){
	Population pop = { .size = s};
	for(size_t i = 0; i != pop.size; ++i){
		pop.ind[i].size = n;
		for(size_t a = 0; a != pop.ind[i].size; ++a){
			if(a < (pop.ind[i].size / 2)){
				pop.ind[i].node[a] = random_function();
			}
			else{
				pop.ind[i].node[a] = random_terminal();
			}
		}
	}
	return pop;
}

void push_to_pop(Individual ind, Population* pop){
	if(pop->size != SIZE_OF_POPULAION){
		pop->ind[pop->size] = ind;
		pop->size++;
	}
//TODO
// make exception here to know that hte population 
// is full and can't add another individual. 

}

size_t get_index_of_best(Population *pop){
	float best = FLT_MAX;
	size_t best_index = 0;
	for(size_t i = 0; i != pop->size; i++){
		if(pop->ind[i].fitness < best){
			best = pop->ind[i].fitness;
			best_index = i;
		}
	}
	return best_index;
}

bool check_zero_fitness(Population* pop){
	for(size_t i = 0; i != pop->size; ++i){
		if(pop->ind[i].fitness <= 0.2){
			return true;
		}
	}
	return false;
}

Individual get_best_ind(Population* pop){
	float best = FLT_MAX;
	size_t best_index = 0;
	for(size_t i = 0; i != pop->size; i++){
		if(pop->ind[i].fitness < best){
			best = pop->ind[i].fitness;
			best_index = i;
			pop->ind[i].fitness = FLT_MAX;
		}
	}
	return pop->ind[best_index];
}

void print_best_ind_from_population(Population* pop){
	size_t idx = get_index_of_best(pop);	
	print_ind(&pop->ind[idx]);
}

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

void print_node(Node* n){
	if(n->type == FUNCTION){
		switch(n->value.variable){
			case ADD:
				printf("ADD");				
				break;
			case SUB:
				printf("SUB");				
				break;
			case DIV:
				printf("DIV");				
				break;
			case MUL:
				printf("MUL");				
				break;
			case PLEFT:
				printf("PLEFT");				
				break;
			case PRIGHT:
				printf("PRIGHT");				
				break;
			default:
				printf("Unknow Value");
				break;
		}
	}
	else{
		if(n->flag == CONST){
			printf("%f", n->value.constant);
		}
		else{
			switch(n->value.variable){
				case X:
					printf("X");
					break;
				case Y:
					printf("Y");
					break;
				default:
					printf("Unknow Value");
					break;
			}
		}
	}
}
 
//void print_population(const Population* pop){
//	for(size_t i = 0; i != pop->size_pop; i++){
//		for(size_t a = 0; a != pop->num_of_nodes_ind; a++){
//			printf("%c ", pop->arr[i][a]);
//		}
//		printf("fitness: %f", pop->fitness[i]); 
//		puts("");
//	}
//}
//
//void print_best_individual(const Population* pop){
//	float best = 10000;
//	size_t indx = 0;
//	for(size_t i = 0; i != pop->size_pop; i++){
//		if(pop->fitness[i] < best){
//			best = pop->fitness[i];
//			indx = i;
//		}
//	}
//	for(size_t a = 0; a != pop->num_of_nodes_ind; a++){
//		printf("%c ", pop->arr[indx][a]);
//	}
//	printf("fitness: %f", pop->fitness[indx]); 
//	puts("");
//}
//
