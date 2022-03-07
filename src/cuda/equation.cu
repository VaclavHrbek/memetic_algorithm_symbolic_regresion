#include "cuda/equation.cuh"

__device__
float device_compute_tree_nodes(const char n, const float a, const float b);
__device__
float device_sum_square_roots_of_deviation(const float* fit_arr, const float* y,const size_t fit_case);
__device__
void device_fill_values(float* arr, const float x, const char* ind, const size_t offset);
__device__
void device_compute_values(float* arr,  const char* ind,
		const size_t offset);

// function calculating one individual starts with begin index in population and end with end index
__device__
float device_equation(const char* ind, const size_t offset){
	const Data data = device_load_data();
	float* fit_arr = (float*) malloc(sizeof(float)*(data.size));
	for(size_t i = 0; i != data.size; i++){
		float* arr = (float*) malloc(sizeof(float)*(offset));
		device_fill_values(arr, data.x[i], ind, offset);
		device_compute_values(arr, ind, offset); 
		fit_arr[i] = arr[0];
		free(arr);
	}
	float fitness = device_sum_square_roots_of_deviation(fit_arr, data.y, data.size);
	free(fit_arr);
	return fitness;
}

__device__
const Data device_load_data(){
	Data data = {
		{1, 2, 3},	// x
		{1, 2, 3},	// y
		3			//size of the array
	};
	return data;
}

__device__
void device_fill_values(float* arr, const float x, const char* ind, const size_t offset){
	for(size_t i = 0; i != offset; i++){
		if(ind[i] == 'x'){
			arr[i] = x;
		}
		else if((ind[i] == '0') || (ind[i] == '1') || (ind[i] == '2') || (ind[i] == '3') || (ind[i] == '4') || (ind[i] == '5') || (ind[i] == '6') || (ind[i] == '7') || (ind[i] == '8') || (ind[i] == '9')){
			char tmp = ind[i];
			// This is safe explicit conversion as long as tmp is up to 32 bit
			arr[i] = (float) (tmp - '0');
		}
		else{
			arr[i] = 0;
		}
	}
}

__device__
void device_compute_values(float* arr,  const char* ind,
		const size_t offset){
	size_t i = (offset / 2);
	do{
		--i;
		const char parent = ind[i];
		arr[i] = device_compute_tree_nodes(parent, arr[(i*2)+1], arr[(i*2)+2]);
	}while(i != 0);
}

__device__
float device_compute_tree_nodes(const char n, const float a, const float b){
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

__device__
float device_sum_square_roots_of_deviation(const float* fit_arr, const float* y,const size_t fit_case){
	float sum = 0;
	for(size_t i = 0; i != fit_case; i++){
		sum += (fit_arr[i] - y[i]) * (fit_arr[i] - y[i]);
	}
	return sum;
}
		


