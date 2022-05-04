#include "c/node.h"

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
