#include "cuda/fitness.cuh"

__global__
void device_calculate_fitness(Population* pop);

void cuda_calculate_fitness(Population* pop){
	Population* d_pop;
	cudaMalloc(&d_pop, sizeof(Population));
	cudaMemcpy(d_pop, pop, sizeof(Population), cudaMemcpyHostToDevice);
	device_calculate_fitness<<<1, SIZE_OF_POPULAION>>>(d_pop);
	cudaMemcpy(pop, d_pop, sizeof(Population), cudaMemcpyDeviceToHost);
	cudaFree(d_pop);
}

__global__
void device_calculate_fitness(Population* pop){
	int i = blockIdx.x*blockDim.x + threadIdx.x;
	pop->fitness[i] = device_equation(pop->arr[i], pop->num_of_nodes_ind);
}	
