#include "terminal.h"

char decide_value(int val);

char random_terminal(){
	int r = rand() % 2;
	int constant = rand() % 9;
	switch(r){
		case 0:
			return 'x';
		case 1:
			return decide_value(constant);
		default:
			return 'x';
	}	
}

char decide_value(int val){
	switch(val){
		case 0:
			return '0';
		case 1:
			return '1';
		case 2:
			return '2';
		case 3:
			return '3';
		case 4:
			return '4';
		case 5:
			return '5';
		case 6:
			return '6';
		case 7:
			return '7';
		case 8:
			return '8';
		case 9:
			return '9';
		default: 
			return '0';
	}
}
