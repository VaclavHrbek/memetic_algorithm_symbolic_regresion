#pragma once

#include <stddef.h>
#include <stdio.h>

#include "c/node.h"

#define NUMBER_OF_NODES_IND (size_t) 127

typedef struct individual {
	Node node[NUMBER_OF_NODES_IND];
	size_t size;
	float fitness;
} Individual;

void print_ind(Individual* ind);
