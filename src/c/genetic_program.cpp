#include "c/genetic_program.h"

void run_gp(GeneticProgram* gp){
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

	for(size_t a = 0; a != NUM_OF_EVOLUTIONARY_CYCLES; ++a){
		free(gp->pop);
		gp->pop = malloc_population();
		printf("#####################\n"
				"Evolutionray cycle %li\n", a);
		clock_t start_evo_cycle = clock();
		clock_t duration_optimize = 0;
		clock_t duration_of_gen = 0;
		clock_t duration_gen_operation = 0;
		clock_t duration_cal_fit = 0;

		// Check if final solution is in the initialy generated population
		calculate_fitness(gp->pop);
		size_t i = 1;
		if(check_fitness_less_than(gp->pop, END_CONDITION_FITTNESS_LESS_THAN) == true){
			std::ofstream out_run_file;
			out_run_file.open(OUTPUT_RUN_FILE, std::ios_base::app);
			out_run_file << "Found solution in initial population,";
			out_run_file.close();
			put_best_to_file(gp->pop);
			break;
		}
		else{
			for(i = 0; i != NUM_OF_GENERATION; ++i){
				printf("Generation: %ld \n", i);
				clock_t start_generation = clock();

				Population* new_pop = (Population*)(malloc(sizeof(Population)));

				clock_t start_optimize = clock();
				*new_pop = optimize(gp->pop);
				duration_optimize += clock() - start_optimize;
				
				clock_t start_cal_fit = clock();
				calculate_fitness(new_pop);
				duration_cal_fit += clock() - start_cal_fit;

				if(check_fitness_less_than(new_pop, END_CONDITION_FITTNESS_LESS_THAN) == true){
					std::ofstream out_run_file;
					out_run_file.open(OUTPUT_RUN_FILE, std::ios_base::app);
					out_run_file << "Found solution after optimization,";
					out_run_file.close();
					put_best_to_file(new_pop);
					free(new_pop);
					break;
				};

				free(new_pop);
				clock_t start_gen_operation = clock();
				new_pop = genetic_operations(gp->pop, MUTAION_RATE, CROSSOUVER_RATE);
				duration_gen_operation += clock() - start_gen_operation;
				calculate_fitness(new_pop);

				if(check_fitness_less_than(new_pop, END_CONDITION_FITTNESS_LESS_THAN) == true){
					std::ofstream out_run_file;
					out_run_file.open(OUTPUT_RUN_FILE, std::ios_base::app);
					out_run_file << "Found solution after genetic operation,";
					out_run_file.close();
					put_best_to_file(new_pop);
					free(new_pop);
					break;
				};

				*gp->pop = *new_pop;
				free(new_pop);

				duration_of_gen += clock() - start_generation;
			}
			if(i == NUM_OF_GENERATION){
				std::ofstream out_run_file;
				out_run_file.open(OUTPUT_RUN_FILE, std::ios_base::app);
				out_run_file << "Program did not satisfy end conditions,";
				put_best_to_file(gp->pop);
			}
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
	}
	clock_t duration_program = clock() - start_program;
	out_file.open(OUTPUT_FILE_NAME, std::ios_base::app);
	out_file << "Mean duration of evolutionary cycle," << ((double)duration_cycle/CLOCKS_PER_SEC)/NUM_OF_EVOLUTIONARY_CYCLES << '\n';
	out_file << "Duration of program," << ((double)duration_program/CLOCKS_PER_SEC) << '\n';
	out_file.close();
};
