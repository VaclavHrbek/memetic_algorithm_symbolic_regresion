#include <equation.h>

#include <stdio.h>

// function calculating one individual starts with begin index in population and end with end index
float equation(const char* pop, const size_t begin, const size_t end){
	size_t fit_case = 10;
	float x[10] = {1, 2, 3, 4, 5, 6, 6, 8, 9, 10};
	
	// Actuall value that need to be found. 
	float y[10] = {4, 9, 8, 7, 6, 5, 4, 3, 2, 1};

	float* fit_arr = (float*) malloc(sizeof(float)*(fit_case));
	for(size_t i = 0; i != fit_case; i++){
		float* arr = (float*) malloc(sizeof(float)*(end - begin));
		fill_values(arr, x[i], pop, begin, end);
		compute_values(arr, (end - begin), pop, begin);
		fit_arr[i] = arr[0];
		free(arr);
	}
	float fitness = sum_square_roots_of_deviation(fit_arr, y, fit_case);
	free(fit_arr);
	return fitness;
}

void fill_values(float* arr, const float x, const char* pop,
		const size_t begin, const size_t end){
	for(size_t i = begin; i != end; i++){
		if(pop[i] == 'x'){
			arr[i - begin] = x;
		}
		else if((pop[i] == '0') || (pop[i] == '1') || (pop[i] == '2') || (pop[i] == '3') || (pop[i] == '4') || (pop[i] == '5') || (pop[i] == '6') || (pop[i] == '7') || (pop[i] == '8') || (pop[i] == '9')){
			char tmp = pop[i];
			arr[i - begin] = atof(&tmp);
		}
		else{
			arr[i - begin] = 0;
		}
	}
}

void compute_values(float* arr, const size_t size_arr, const char* pop,
		const size_t begin){
	for(size_t i = size_arr - 1; i > 0; i = i - 2){
		const char parent = pop[(((begin + i) - 2) / 2)];
		float val_child_1 = arr[i];
		float val_child_2 = arr[i - 1];
		float* val_parent = &arr[((i - 2) / 2)];
		*val_parent = compute_tree_nodes(parent, val_child_1, val_child_2);
	}
}


float compute_tree_nodes(const char n, const float a, const float b){
	switch(n){
		case 'a':
			return a + b;
		case 's':
			return a - b;
		case 'm':
			return a * b;
		case '/': 
			  return a;
		case '\\': 
			  return b;
		case 'd':
			if(b <= 0){
				return a;
			}
			else{
				return a / b;
			};
	}
}

float sum_square_roots_of_deviation(const float* fit_arr, const float* y,const size_t fit_case){
	float sum = 0;
	for(size_t i = 0; i != fit_case; i++){
		sum += (fit_arr[i] - y[i]) * (fit_arr[i] - y[i]);
	}
	return sum;
}
		


