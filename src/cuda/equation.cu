#include "cuda/equation.cuh"

__device__
float device_equation(const Individual ind){
	 Data data = device_load_data();
	float* arr = (float*) malloc(sizeof(size_t) * data.size);
	for(size_t i = 0; i != data.size; i++){
		Individual new_ind = ind;
		size_t a = new_ind.size;
		do{
			a--;
			if(new_ind.node[a].flag == VAR && new_ind.node[a].type == TERMINAL){
				new_ind.node[a].value.constant = data.x[i];
				new_ind.node[a].flag = CONST;
			} 
			if(new_ind.node[a].flag == VAR && new_ind.node[a].type == FUNCTION){
				new_ind.node[a].value.constant = device_compute_tree_node(new_ind.node[a], new_ind.node[(a*2)+1], new_ind.node[(a*2)+2]);
				new_ind.node[a].flag = CONST;
			}
		}while(a != 0);
		arr[i] = new_ind.node[0].value.constant;
	}
	float fitness = device_sum_square_roots_of_deviation(arr, data.y, data.size);
	free(arr);
	return fitness;
}

__device__
Data device_load_data(){
	Data data = {
		{1, 2, 3},	// x
		{2, 3, 4},	// y
		3			//size of the array
	};
	return data;
}

__device__
float device_compute_tree_node(const Node par, const Node ch_1, const Node ch_2){
	switch(par.value.variable){
		case ADD:
			return (ch_1.value.constant + ch_2.value.constant);
		case SUB:
			return (ch_1.value.constant - ch_2.value.constant);
		case MUL:
			return (ch_1.value.constant * ch_2.value.constant);
		case PLEFT:
			return ch_1.value.constant;
		case PRIGHT:
			return ch_2.value.constant;
		case DIV:
			if(ch_2.value.constant <= 0){
				return ch_2.value.constant;
			}
			else{
				return (ch_1.value.constant / ch_2.value.constant);
			};
		default:
			return ch_1.value.constant;
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
