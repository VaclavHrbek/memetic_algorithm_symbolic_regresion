#include "cuda/fitness.cuh"

__global__
void device_calculate_fitness(Population* pop);

void cuda_calculate_fitness(Population* d_pop){
	dim3 block(256);
	dim3 grid((SIZE_OF_POPULAION / block.x) + 1); 
	device_calculate_fitness<<<grid, block>>>(d_pop);
	cudaDeviceSynchronize();
}

__global__
void device_calculate_fitness(Population* pop){
	int i = blockIdx.x*blockDim.x + threadIdx.x;
	if(i < pop->size){
		pop->ind[i].fitness = device_equation_xy(pop->ind[i]); 
		if(pop->ind[i].fitness <= END_CONDITION_FITTNESS_LESS_THAN){
			printf("Found best solution with fitness: %f.\nOn index %i in population.\n", pop->ind[i].fitness, i);
			device_print_ind(&pop->ind[i]);
		}
	}
}	
