#include "c/genetic_program.h"

void run_gp(GeneticProgram* gp){
	srand((unsigned int)time(NULL));	
	clock_t start_program = clock();
	clock_t duration_cycle = 0;

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
		if(check_fitness_less_than(gp->pop, END_CONDITION_FITTNESS_LESS_THAN) == true){
			printf("Found solution in initial population\n");
			print_best_ind_from_population(gp->pop);
			break;
		}
		else{
			for(size_t i = 0; i != NUM_OF_GENERATION; ++i){
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
					printf("Found solution after optimization\n");
					print_best_ind_from_population(new_pop);
					free(new_pop);
					break;
				};

				free(new_pop);
				clock_t start_gen_operation = clock();
				new_pop = genetic_operations(gp->pop, MUTAION_RATE, CROSSOUVER_RATE);
				duration_gen_operation += clock() - start_gen_operation;
				calculate_fitness(new_pop);

				if(check_fitness_less_than(new_pop, END_CONDITION_FITTNESS_LESS_THAN) == true){
					printf("Found solution after genetic operation\n");
					print_best_ind_from_population(new_pop);
					free(new_pop);
					break;
				};

				*gp->pop = *new_pop;
				free(new_pop);

				duration_of_gen += clock() - start_generation;
				print_best_ind_from_population(gp->pop);
			}
		}
		printf("####################\n\n \
				Mean duration of optimization: %f s\n \
				Mean duration of generation: %f s\n \
				Mean duration of calculation fitness: %f s\n \
				Mean duration of genetic operation: %f s\n \
				", ((double)duration_optimize/CLOCKS_PER_SEC)/NUM_OF_GENERATION
				, ((double)duration_of_gen/CLOCKS_PER_SEC)/NUM_OF_GENERATION
				, ((double)duration_cal_fit/CLOCKS_PER_SEC)/NUM_OF_GENERATION
				, ((double)duration_gen_operation/CLOCKS_PER_SEC)/NUM_OF_GENERATION);

		duration_cycle += clock() - start_evo_cycle;
		print_best_ind_from_population(gp->pop);
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
