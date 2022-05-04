#include "cuda/optimizer.cuh"

__global__
void device_optimize(Population* d_pop, curandState* state, size_t* indexes);
__device__
Individual device_stochastic_hill_climbing_constants(Individual ind, curandState* state);
__global__ 
void setup_kernel(curandState *state);

void cuda_optimize(Population* d_pop){
	int total_threads = 256;
	dim3 block(total_threads);
	dim3 grid((SIZE_FOR_OPTIMIZATION / block.x) + 1); 
	size_t* d_n_best_indexes_in_pop;
	cudaMalloc(&d_n_best_indexes_in_pop, sizeof(size_t)*SIZE_FOR_OPTIMIZATION);
	curandState *dev_state;
	cudaMalloc((void**)&dev_state, (block.x * grid.x) * sizeof(curandState));

	setup_kernel<<<grid, block>>>(dev_state);
	device_get_n_indexes_of_best_ind_in_population<<<1,1>>>(d_pop, SIZE_FOR_OPTIMIZATION, d_n_best_indexes_in_pop);
	device_optimize<<<grid, block>>>(d_pop, dev_state, d_n_best_indexes_in_pop);
}

__global__ void setup_kernel(curandState *state)
{
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    /* Each thread gets same seed, a different sequence
       number, no offset */
	if(i < SIZE_FOR_OPTIMIZATION){
		curand_init(1234, i, 0, &state[i]);
	}
}

__global__
void device_optimize(Population* d_pop, curandState *state, size_t* indexes){
	int i = blockIdx.x*blockDim.x + threadIdx.x;
	if(i < SIZE_FOR_OPTIMIZATION){
		/* Copy state to local memory for efficiency */
		curandState local_state = state[i];
		Individual* ind = &d_pop->ind[indexes[i]];
		for(size_t i = 0; i != NUM_OF_OPTIMIZATION; ++i){
			Individual ind_2 = device_stochastic_hill_climbing_constants(*ind, &local_state);
			ind_2.fitness = device_equation(ind_2);
			if(ind_2.fitness < ind->fitness){
				*ind = ind_2;
				printf("Better solution found in optimizer \n");
			}
		}
	}
}

__device__
Individual device_stochastic_hill_climbing_constants(Individual ind, curandState* state){
	Individual ind_2 = device_random_all_constants(ind, state);
	return ind;
}
