#include "cuda/genetic_program.cuh"

void run_gp_gpu(GeneticProgram* gp){
	srand((unsigned int)time(NULL));	
	clock_t start_program = clock();
	clock_t duration_cycle = 0;
	std::ofstream out_file;
	out_file.open(OUTPUT_FILE_NAME, std::ios_base::app);
	out_file << "Mean duration of generation," <<
	"Mean duration of optimization," <<
	"Mean duration of calculation fitness," <<
	"Mean duration of genetic operation," <<
	"Number of generation required to found solution\n";
	out_file.close();

	Population* d_pop = cuda_malloc_population();

	for(size_t a = 0; a != NUM_OF_EVOLUTIONARY_CYCLES; ++a){
		gp->pop = malloc_population();
		int *flag;
		cudaMallocManaged(&flag, sizeof(int));
		flag[0] = 0;
		cuda_host_to_device_memcpy_population(d_pop, gp->pop);
		printf("#####################\n"
				"Evolutionray cycle %li\n", a);
		clock_t start_evo_cycle = clock();
		clock_t duration_optimize = 0;
		clock_t duration_of_gen = 0;
		clock_t duration_gen_operation = 0;
		clock_t duration_cal_fit = 0;

		cuda_calculate_fitness(d_pop);
		size_t i = 0;
		for(i = 0; i != NUM_OF_GENERATION; ++i){
			//printf("Generation: %ld \n", i);
			clock_t start_generation = clock();

			cuda_calculate_fitness(d_pop);
			//TODO use for_each algorithm on next function (if it is possible
			// because I don't use the containers).
			device_check_end_condition<<<1,1>>>(d_pop, flag);
			cudaDeviceSynchronize();
			if(flag[0] == 1){
				break;
			}
			//device_print_best_so_far<<<1,1>>>(d_pop);

			clock_t start_optimize = clock();
			cuda_optimize(d_pop);
			duration_optimize += clock() - start_optimize;

			clock_t start_cal_fit = clock();
			cuda_calculate_fitness(d_pop);
			duration_cal_fit += clock() - start_cal_fit;

			device_check_end_condition<<<1,1>>>(d_pop, flag);
			cudaDeviceSynchronize();
			if(flag[0] == 1){
				break;
			}

			clock_t start_gen_operation = clock();
			cuda_device_to_host_memcpy_population(d_pop, gp->pop);	
			gp->pop = genetic_operations(gp->pop, MUTAION_RATE, CROSSOUVER_RATE);
			if(check_fitness_less_than(gp->pop, END_CONDITION_FITTNESS_LESS_THAN) == true){
				std::ofstream out_run_file;
				out_run_file.open(OUTPUT_RUN_FILE, std::ios_base::app);
				out_run_file << "Found solution after genetic operation,";
				out_run_file.close();
				put_best_to_file(gp->pop);
				break;
			};
			cuda_host_to_device_memcpy_population(d_pop, gp->pop);
			duration_gen_operation += clock() - start_gen_operation;

			duration_of_gen += clock() - start_generation;
		}
		std::ofstream out_file;
		out_file.open(OUTPUT_FILE_NAME, std::ios_base::app);
		out_file << ((double)duration_of_gen/CLOCKS_PER_SEC)/i << ',' <<
			 ((double)duration_optimize/CLOCKS_PER_SEC)/i << ',' <<
			 ((double)duration_cal_fit/CLOCKS_PER_SEC)/i<< ',' <<
			 ((double)duration_gen_operation/CLOCKS_PER_SEC)/i << 
			 ',' << i << '\n';
		duration_cycle += clock() - start_evo_cycle;
		out_file.close();
		duration_cycle += clock() - start_evo_cycle;
	}
	clock_t duration_program = clock() - start_program;
	out_file.open(OUTPUT_FILE_NAME, std::ios_base::app);
	out_file << "Mean duration of evolutionary cycle," << ((double)duration_cycle/CLOCKS_PER_SEC)/NUM_OF_EVOLUTIONARY_CYCLES << '\n';
	out_file << "Duration of program," << ((double)duration_program/CLOCKS_PER_SEC) << '\n';
	out_file.close();
};
