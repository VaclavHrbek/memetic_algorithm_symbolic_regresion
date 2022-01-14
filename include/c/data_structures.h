#pragma once

#include <stddef.h>

#define SIZE_OF_POPULAION (size_t) 3 
#define DEPTH_OF_INDIVIDUAL (size_t) 3
#define NUMBER_OF_NODES_IND (size_t) 3 

#define MUTAION_RATE (float) 0.1
#define CROSSOUVER_RATE (float) 0.7

#define NUM_OF_GENERATION (size_t) 500

#define NUM_OF_OPTIMIZATION (size_t) 2
#define SIZE_FOR_OPTIMIZATION (size_t) 2

struct population {
		size_t num_of_nodes_ind;
		size_t size_pop;
		char arr[SIZE_OF_POPULAION][NUMBER_OF_NODES_IND];
		float fitness[SIZE_OF_POPULAION];
};

typedef struct population Population;

typedef struct data {
	float x[3];
	float y[3];
	size_t size;
} Data;

typedef struct opt_population {
		size_t num_of_nodes_ind;
		size_t size_pop;
		char arr[SIZE_FOR_OPTIMIZATION][NUMBER_OF_NODES_IND];
		float fitness[SIZE_FOR_OPTIMIZATION];
} OptPop;
