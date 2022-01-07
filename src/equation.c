#include "equation.h"

// function calculating one individual starts with begin index in population and end with end index
float equation(const char* ind, const size_t offset){
	// don't forget to change the fit_case number
	size_t fit_case = 3;
	float x[3] = {1, 2, 3};
	
	// Actuall value that need to be found. 
	float y[3] = {3,4,5}; // = x + 2 (x = 1, 2, ,3)
	//float y[3] = {1,2,3}; // = x (x = 1, 2, ,3)

	float* fit_arr = (float*) malloc(sizeof(float)*(fit_case));
	for(size_t i = 0; i != fit_case; i++){
		float* arr = (float*) malloc(sizeof(float)*(offset));
		fill_values(arr, x[i], ind, offset);
		compute_values(arr, offset, ind, offset); 
		fit_arr[i] = arr[0];
		free(arr);
	}
	float fitness = sum_square_roots_of_deviation(fit_arr, y, fit_case);
	free(fit_arr);
	return fitness;
}

void fill_values(float* arr, const float x, const char* ind, const size_t offset){
	for(size_t i = 0; i != offset; i++){
		if(ind[i] == 'x'){
			arr[i] = x;
		}
		else if((ind[i] == '0') || (ind[i] == '1') || (ind[i] == '2') || (ind[i] == '3') || (ind[i] == '4') || (ind[i] == '5') || (ind[i] == '6') || (ind[i] == '7') || (ind[i] == '8') || (ind[i] == '9')){
			char tmp = ind[i];
			arr[i] = atof(&tmp);
		}
		else{
			arr[i] = 0;
		}
	}
}

void compute_values(float* arr, const size_t size_arr, const char* ind,
		const size_t offset){
	for(size_t i = (offset / 2) - 1; i != -1; i--){
		const char parent = ind[i];

		arr[i] = compute_tree_nodes(parent, arr[(i*2)+1], arr[(i*2)+2]);
	}
}


float compute_tree_nodes(const char n, const float a, const float b){
	float out = 0;
	switch(n){
		case 'a':
			out = a + b;
			return out;
		case 's':
			out = a - b;
			return out;
		case 'm':
			out = a * b;
			return out;
		case 'l': 
			out = a;
			return out;
		case 'r': 
			out = b;
			return out;
		case 'd':
			if(b <= 0){
				out = a;
				return out;
			}
			else{
				out = a / b;
				return out;
			};
		default:
			return a;
	}
}

float sum_square_roots_of_deviation(const float* fit_arr, const float* y,const size_t fit_case){
	float sum = 0;
	for(size_t i = 0; i != fit_case; i++){
		sum += (fit_arr[i] - y[i]) * (fit_arr[i] - y[i]);
	}
	return sum;
}
		


