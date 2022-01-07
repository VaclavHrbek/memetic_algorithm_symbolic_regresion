#pragma once

#include <stddef.h>

#define SIZE_OF_POPULAION (size_t) 10
#define DEPTH_OF_INDIVIDUAL (size_t) 3
#define NUMBER_OF_NODES_IND (size_t) 7

#define MUTAION_RATE (float) 0.1
#define CROSSOUVER_RATE (float) 0.7

#define NUM_OF_GENERATION (size_t) 5000

struct population {
		size_t num_of_nodes_ind;
		size_t size_pop;
		char arr[SIZE_OF_POPULAION][NUMBER_OF_NODES_IND];
		float fitness[SIZE_OF_POPULAION];
};

typedef struct population Population;
