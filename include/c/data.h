#pragma once

#include <stddef.h>
#include <stdlib.h>

typedef struct data {
	float x[21];
	float y[21];
	size_t size;
} Data;

Data load_data(void);
Data* malloc_data(void);
