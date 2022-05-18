#include "c/node.h"

std::string node_value(Node* n){
	std::string val;
	if(n->type == FUNCTION){
		switch(n->value.variable){
			case ADD:
				val = "ADD";				
				break;
			case SUB:
				val = "SUB";				
				break;
			case DIV:
				val = "DIV";				
				break;
			case MUL:
				val = "MUL";				
				break;
			case PLEFT:
				val = "PLEFT";				
				break;
			case PRIGHT:
				val = "PRIGHT";				
				break;
			default:
				val = "Unknow Value";
				break;
		}
	}
	else{
		if(n->flag == CONST){
			val = std::to_string(n->value.constant);
		}
		else{
			switch(n->value.variable){
				case X:
					val = "X";
					break;
				case Y:
					val = "Y";
					break;
				default:
					val = "Unknow Value";
					break;
			}
		}
	}
	return val;
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
