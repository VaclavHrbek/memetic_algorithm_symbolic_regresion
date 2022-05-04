#include "cuda/individual.cuh"


__device__
void device_print_ind(Individual* ind){
	for(size_t i = 0; i != ind->size; ++i){
	if(ind->node[i].type == FUNCTION){
		switch(ind->node[i].value.variable){
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
		if(ind->node[i].flag == CONST){
			printf("%f", ind->node[i].value.constant);
		}
		else{
			switch(ind->node[i].value.variable){
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
			printf(", ");
	}
	printf("\n");
}
