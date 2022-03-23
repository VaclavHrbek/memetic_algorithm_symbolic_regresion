#pragma once

#include "c/node.h"

#define NUMBER_OF_NODES_IND (size_t) 255 

typedef struct individual {
	Node node[NUMBER_OF_NODES_IND];
	size_t size;
	float fitness;
} Individual;
