#include "cuda/genetic_program.cuh"

void run_gp_gpu(GeneticProgram* gp){
	srand((unsigned int)time(NULL));	
	clock_t start_program = clock();
	clock_t duration_cycle = 0;

	Population* d_pop = cuda_malloc_population();

	for(size_t a = 0; a != NUM_OF_EVOLUTIONARY_CYCLES; ++a){
		gp->pop = malloc_population();
		cuda_host_to_device_memcpy_population(d_pop, gp->pop);
		printf("#####################\n"
				"Evolutionray cycle %li\n", a);
		clock_t start_evo_cycle = clock();
		clock_t duration_optimize = 0;
		clock_t duration_of_gen = 0;
		clock_t duration_gen_operation = 0;
		clock_t duration_cal_fit = 0;

		cuda_calculate_fitness(d_pop);
		for(size_t i = 0; i != NUM_OF_GENERATION; ++i){
			printf("Generation: %ld \n", i);
			clock_t start_generation = clock();

			cuda_calculate_fitness(d_pop);
			//TODO use for_each algorithm on next function (if it is possible
			// because I don't use the containers).
			device_check_end_condition<<<1,1>>>(d_pop);
			device_print_best_so_far<<<1,1>>>(d_pop);

			clock_t start_optimize = clock();
			cuda_optimize(d_pop);
			duration_optimize += clock() - start_optimize;

			clock_t start_cal_fit = clock();
			cuda_calculate_fitness(d_pop);
			duration_cal_fit += clock() - start_cal_fit;
			device_check_end_condition<<<1,1>>>(d_pop);

			clock_t start_gen_operation = clock();
			cuda_device_to_host_memcpy_population(d_pop, gp->pop);	
			gp->pop = genetic_operations(gp->pop, MUTAION_RATE, CROSSOUVER_RATE);
			cuda_host_to_device_memcpy_population(d_pop, gp->pop);
			duration_gen_operation += clock() - start_gen_operation;

			duration_of_gen += clock() - start_generation;
		}
		printf("####################\n\n \
				Mean duration of optimization: %f s\n \
				Mean duration of generation: %f s\n \
				Mean duration of calculation fitness: %f s\n \
				Mean duration of genetic operation + plus transfer from device and to device: %f s\n \
				", ((double)duration_optimize/CLOCKS_PER_SEC)/NUM_OF_GENERATION
				, ((double)duration_of_gen/CLOCKS_PER_SEC)/NUM_OF_GENERATION
				, ((double)duration_cal_fit/CLOCKS_PER_SEC)/NUM_OF_GENERATION
				, ((double)duration_gen_operation/CLOCKS_PER_SEC)/NUM_OF_GENERATION);

		duration_cycle += clock() - start_evo_cycle;

	}
	printf("####################\n\n \
			Mean duration of evolutionary cycle: %f s\n \
			\n ######################", ((double)duration_cycle/CLOCKS_PER_SEC)/NUM_OF_EVOLUTIONARY_CYCLES);

	clock_t duration_program = clock() - start_program;
	printf("####################\n\n \
			Duration of program %f s\n \
			\n ######################", (double)duration_program/CLOCKS_PER_SEC);
	print_best_ind_from_population(gp->pop);
};
