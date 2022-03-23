#include "c/terminal.h"

Node random_terminal(){
	int r = rand() % 2;
	int constant = rand() % 90;
	Node node;
	node.type = TERMINAL;
	switch(r){
		case 0:
			node.value.variable = X;
			node.flag = VAR;
			return node;
		case 1:
			node.value.constant = constant;
			node.flag = CONST;
			return node;
		default:
			node.value.variable = X;
			node.flag = VAR;
			return node;
	}
}

