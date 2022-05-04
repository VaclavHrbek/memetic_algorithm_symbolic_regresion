#include "cuda/population.cuh"

Population* cuda_malloc_population(){
	Population* d_pop;
	if(cudaMalloc(&d_pop, sizeof(Population)) != cudaSuccess){
		// TODO Implement error handlig
		printf("Cuda device allocation fail ");
	};
	return d_pop;
}

void cuda_host_to_device_memcpy_population(Population* d_pop, Population* pop){
	if(cudaMemcpy(d_pop, pop, sizeof(Population), cudaMemcpyHostToDevice) != cudaSuccess){
		// TODO Implement error handlig
		printf("Cuda host to device copy fail ");
	}
}
void cuda_device_to_host_memcpy_population(Population* d_pop, Population* pop){
	if(cudaMemcpy(pop, d_pop, sizeof(Population), cudaMemcpyDeviceToHost) != cudaSuccess){
		// TODO Implement error handlig
		printf("Cuda device to host copy fail ");
	}

}

__global__
void device_get_n_indexes_of_best_ind_in_population(const Population* pop, const size_t n, size_t* indexes){
	Population* new_pop = (Population*)(malloc(sizeof(Population)));
	*new_pop = *pop;
	for(size_t a = 0; a != n; a++){
		float best = FLT_MAX;
		size_t best_index = 0;
		for(size_t i = 0; i != pop->size; ++i){
			if(new_pop->ind[i].fitness < best){
				best = new_pop->ind[i].fitness;
				best_index = i;
			}
		}
		indexes[a] = best_index;
		new_pop->ind[best_index].fitness = FLT_MAX;
	}
	free(new_pop);
};	

__global__
void device_print_best_so_far(const Population* d_pop){
	Individual best;
	best.fitness = FLT_MAX;
	for(size_t i = 0; i != d_pop->size; ++i){
		if(d_pop->ind[i].fitness <= best.fitness){
			best = d_pop->ind[i];
		}
	}
	printf("Best so far:\n");
	device_print_ind(&best);
	printf("with fitness: %f.\n", best.fitness);
}

__global__
void device_check_end_condition(const Population* d_pop){
	Individual best;
	best.fitness = FLT_MAX;
	for(size_t i = 0; i != d_pop->size; ++i){
		if(d_pop->ind[i].fitness <= best.fitness){
			best = d_pop->ind[i];
		}
	}
	if(best.fitness <= 0.1){
		printf("############################\n");
		printf("Found solution: \n");
		device_print_ind(&best);
		printf("with fitness: %f.\n", best.fitness);
	}
}
