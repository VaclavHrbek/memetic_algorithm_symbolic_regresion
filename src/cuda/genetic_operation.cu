#include "cuda/genetic_operation.cuh"

__device__ 
Individual device_random_all_constants(Individual ind, curandState *state){
	for(size_t i = 0; i != ind.size; i++){
		if(ind.node[i].type == TERMINAL){
			if(ind.node[i].flag == CONST){
				ind.node[i].value.constant = curand_uniform(state)*100;
			}
		}
	}
	return ind;
}

