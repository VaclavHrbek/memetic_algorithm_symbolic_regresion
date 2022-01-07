#include "terminal.h"

char random_terminal(){
	int r = rand() % 2;
	int constant = rand() % 9;
	switch(r){
		case 0:
			return 'x';
		case 1:
			return constant + '0';
		default:
			return 'x';
	}	
}
