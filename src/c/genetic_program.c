
#include "c/genetic_program.h"

void run_gp(GeneticProgram* gp){
	srand((unsigned int)time(NULL));	
	clock_t t = clock();
	for(size_t a = 0; a != NUM_OF_EVOLUTIONARY_CYCLES; ++a){
		t = clock();

		//Population pop = create_population(SIZE_OF_POPULAION, NUMBER_OF_NODES_IND);
		calculate_fitness(gp->pop);
		//cuda_calculate_fitness(&pop);
		if(check_fitness_less_than(gp->pop, END_CONDITION_FITTNESS_LESS_THAN) == true){
			printf("Found solution in initial population\n");
			print_best_ind_from_population(gp->pop);
			return;
		};

		for(size_t i = 0; i != NUM_OF_GENERATION; ++i){
			printf("Generation: %ld \n", i);

			Population* new_pop = (Population*)(malloc(sizeof(Population)));
			*new_pop = optimize(gp->pop);
			calculate_fitness(new_pop);
			//cuda_calculate_fitness(&new_pop);

			if(check_fitness_less_than(new_pop, END_CONDITION_FITTNESS_LESS_THAN) == true){
				printf("Found solution after optimization\n");
				print_best_ind_from_population(new_pop);
				t = clock()-1;
				double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
				printf("Cycle took %f seconds to execute \n", time_taken);
				return;
			};

			*new_pop = genetic_operations(gp->pop, MUTAION_RATE, CROSSOUVER_RATE);
			calculate_fitness(new_pop);
			//cuda_calculate_fitness(&new_pop);

			if(check_fitness_less_than(new_pop, END_CONDITION_FITTNESS_LESS_THAN) == true){
				printf("Found solution after genetic operation\n");
				print_best_ind_from_population(new_pop);
				t = clock()-1;
				double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
				printf("Cycle took %f seconds to execute \n", time_taken);
				return;
			};

			*gp->pop = *new_pop;
			free(new_pop);
		}
		t = clock()-t;
		double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
		printf("Cycle took %f seconds to execute \n", time_taken);
		print_best_ind_from_population(gp->pop);
	}
};

void run_gp_gpu(GeneticProgram* gp){
	srand((unsigned int)time(NULL));	
	clock_t t = clock();
	for(size_t a = 0; a != NUM_OF_EVOLUTIONARY_CYCLES; ++a){
		t = clock();

		cuda_calculate_fitness(gp->pop);
		if(check_fitness_less_than(gp->pop, END_CONDITION_FITTNESS_LESS_THAN) == true){
			printf("Found solution in initial population\n");
			print_best_ind_from_population(gp->pop);
			return;
		};

		for(size_t i = 0; i != NUM_OF_GENERATION; ++i){
			printf("Generation: %ld \n", i);

			Population* new_pop = (Population*)(malloc(sizeof(Population)));
			*new_pop = optimize(gp->pop);
			cuda_calculate_fitness(new_pop);

			if(check_fitness_less_than(new_pop, END_CONDITION_FITTNESS_LESS_THAN) == true){
				printf("Found solution after optimization\n");
				print_best_ind_from_population(new_pop);
				t = clock()-1;
				double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
				printf("Cycle took %f seconds to execute \n", time_taken);
				return;
			};

			*new_pop = genetic_operations(gp->pop, MUTAION_RATE, CROSSOUVER_RATE);
			cuda_calculate_fitness(new_pop);

			if(check_fitness_less_than(new_pop, END_CONDITION_FITTNESS_LESS_THAN) == true){
				printf("Found solution after genetic operation\n");
				print_best_ind_from_population(new_pop);
				t = clock()-1;
				double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
				printf("Cycle took %f seconds to execute \n", time_taken);
				return;
			};

			*gp->pop = *new_pop;
			free(new_pop);
		}
		t = clock()-t;
		double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
		printf("Cycle took %f seconds to execute \n", time_taken);
		print_best_ind_from_population(gp->pop);
	}
};
