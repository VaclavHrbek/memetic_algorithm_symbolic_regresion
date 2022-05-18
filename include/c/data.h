#pragma once

#include <stddef.h>
#include <stdlib.h>

#define OUTPUT_FILE_NAME "Keijzer_4.csv"
#define OUTPUT_RUN_FILE "Keijzer_4_run.csv"

typedef struct data {
	float x[21];
	float y[21];
	size_t size;
} Data;

Data load_data(void);
Data* malloc_data(void);
