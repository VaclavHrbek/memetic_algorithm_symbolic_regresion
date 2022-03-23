#pragma once

#include <stddef.h>

#define SIZE_OF_POPULAION (size_t) 500
#define DEPTH_OF_INDIVIDUAL (size_t) 3
#define NUMBER_OF_NODES_IND (size_t) 255 

#define MUTAION_RATE (float) 0.1
#define CROSSOUVER_RATE (float) 0.9

#define NUM_OF_GENERATION (size_t) 100   

#define NUM_OF_OPTIMIZATION (size_t) 10 // cycles
#define SIZE_FOR_OPTIMIZATION (size_t) 10 // number of ind
#define NUM_OF_EVOLUTIONARY_CYCLES (size_t) 1

typedef enum { TERMINAL, FUNCTION } Type ;
typedef enum  { CONST, VAR } Flag;
typedef enum { ADD, SUB, DIV, MUL, X, Y, PLEFT, PRIGHT } Variable;

typedef struct node {
	Type type;
	Flag flag;
	union Value {
		Variable variable;
		float constant;
	} value;
} Node;

typedef struct individual {
	Node node[NUMBER_OF_NODES_IND];
	size_t size;
	float fitness;
} Individual;

typedef struct population {
		size_t size;
		Individual ind[SIZE_OF_POPULAION];
} Population;

typedef struct data {
	float x[21];
	float y[21];
	size_t size;
} Data;
