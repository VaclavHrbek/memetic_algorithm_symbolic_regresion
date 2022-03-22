#include "c/function.h"

Node random_function(){
	int r = rand() % 6;	
	Node node;
	node.type = FUNCTION;
	node.flag = VAR;
	switch(r){
		case 0:
			node.value.variable = ADD;
			return node;
		case 1:
			node.value.variable = SUB;
			return node;
		case 2:
			node.value.variable = MUL;
			return node;
		case 3:
			node.value.variable = DIV;
			return node;
		case 4:
			node.value.variable = PLEFT;
			return node;
		case 5:
			node.value.variable = PRIGHT;
			return node;
		default:
			node.value.variable = ADD;
			return node;
	}	
}
