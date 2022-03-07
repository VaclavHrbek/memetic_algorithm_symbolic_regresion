#include "cuda/fitness.cuh"

__global__
void device_calculate_fitness(Population* pop);

void cuda_calculate_fitness(Population* pop){
	Population* d_pop;
	if(cudaMalloc(&d_pop, sizeof(Population)) != cudaSuccess){
		// Implement error handlig
		return;
	};
	cudaMemcpy(d_pop, pop, sizeof(Population), cudaMemcpyHostToDevice);

	dim3 block(1023);
	dim3 grid((pop->size_pop / block.x) + 1); 
	device_calculate_fitness<<<grid, block>>>(d_pop);

	cudaMemcpy(pop, d_pop, sizeof(Population), cudaMemcpyDeviceToHost);
	cudaFree(d_pop);
}

__global__
void device_calculate_fitness(Population* pop){
	int i = blockIdx.x*blockDim.x + threadIdx.x;
	if(i < pop->size_pop){
		pop->fitness[i] = device_equation(pop->arr[i], pop->num_of_nodes_ind);
	}
}	
