#pragma once

#include <stddef.h>
#include <stdio.h>
#include <fstream>

#include "c/node.h"
#include "c/data.h"

#define NUMBER_OF_NODES_IND (size_t) 15

typedef struct individual {
	Node node[NUMBER_OF_NODES_IND];
	size_t size;
	float fitness;
} Individual;

void print_ind(Individual* ind);
void put_ind_to_file(Individual* ind);
