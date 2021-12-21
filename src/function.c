#include <function.h>

char random_function(){
	int r = rand() % 6;	
	switch(r){
		case 0:
			return 'a'; // addition
		case 1:
			return 's'; // substraction
		case 2:
			return 'm'; // multiplication
		case 3:
			return 'd'; // division
		case 4:
			return '/'; // pass left child
		case 5:
			return '\\'; // pass right child
		default:
			return 'a';
	}	
}
