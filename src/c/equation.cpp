#include "c/equation.h"

float equation(const Individual ind){
	const Data data = load_data();
	float arr[data.size];
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
				new_ind.node[a].value.constant = compute_tree_node(new_ind.node[a], new_ind.node[(a*2)+1], new_ind.node[(a*2)+2]);
				new_ind.node[a].flag = CONST;
			}
		}while(a != 0);
		arr[i] = new_ind.node[0].value.constant;
	}
	float fitness = sum_square_roots_of_deviation(arr, data.y, data.size);
	return fitness;
}

float equation_xy(const Individual ind){
	const Data_xy data = load_data_xy();
	float arr[data.size];
	for(size_t i = 0; i != data.size; i++){
		Individual new_ind = ind;
		size_t a = new_ind.size;
		do{
			a--;
			if(new_ind.node[a].flag == VAR && new_ind.node[a].type == TERMINAL){
				if(new_ind.node[a].value.variable == X){
					new_ind.node[a].value.constant = data.x[i];
				}
				else if(new_ind.node[a].value.variable == Y){
					new_ind.node[a].value.constant = data.y[i];
				}
				else{
				}
				new_ind.node[a].flag = CONST;
			} 
			if(new_ind.node[a].flag == VAR && new_ind.node[a].type == FUNCTION){
				new_ind.node[a].value.constant = compute_tree_node(new_ind.node[a], new_ind.node[(a*2)+1], new_ind.node[(a*2)+2]);
				new_ind.node[a].flag = CONST;
			}
		}while(a != 0);
		arr[i] = new_ind.node[0].value.constant;
	}
	float fitness = sum_square_roots_of_deviation_xy(arr, data);
	return fitness;
}

float compute_tree_node(const Node par, const Node ch_1, const Node ch_2){
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
			if(ch_2.value.constant == 0){
				return ch_1.value.constant;
			}
			else{
				return (ch_1.value.constant / ch_2.value.constant);
			};
		default:
			return ch_1.value.constant;
	}
}

float sum_square_roots_of_deviation(const float* fit_arr, const float* y,const size_t fit_case){
	float sum = 0;
	for(size_t i = 0; i != fit_case; i++){
		sum += (fit_arr[i] - y[i]) * (fit_arr[i] - y[i]);
	}
	return sum;
}

float sum_square_roots_of_deviation_xy(const float* f_xy_predict, const Data_xy& data){
	float sum = 0;
	for(size_t i = 0; i != data.size; i++){
		sum += (f_xy_predict[i] - data.f_xy[i]) * (f_xy_predict[i] - data.f_xy[i]);
	}
	return sum;
}

