CC = gcc
CFLAGS = -I$(DEP_DIR) -Wall -Wextra -std=c17 -Wpedantic -Wconversion -Wunused -g
NVCC = nvcc

BUILD_DIR = ./build
EXEC = main

SRC_DIR = ./src
DEP_DIR = ./include
APP_DIR = ./app

all: $(BUILD_DIR)/$(EXEC)

valgrind: $(BUILD_DIR)/$(EXEC)
	valgrind --leak-check=full $(BUILD_DIR)/$(EXEC) 

$(BUILD_DIR)/$(EXEC): $(BUILD_DIR)/main.o $(BUILD_DIR)/population.o $(BUILD_DIR)/terminal.o \
	$(BUILD_DIR)/function.o $(BUILD_DIR)/fitness.o $(BUILD_DIR)/equation.o $(BUILD_DIR)/genetic_operation.o $(BUILD_DIR)/optimization.o
	$(CC) -o $@ $^

$(BUILD_DIR)/main.o: $(APP_DIR)/main.c $(DEP_DIR)/population.h | $(BUILD_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BUILD_DIR)/population.o: $(SRC_DIR)/population.c \
							$(DEP_DIR)/terminal.h $(DEP_DIR)/function.h $(DEP_DIR)/population.h $(DEP_DIR)/data_structures.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(BUILD_DIR)/terminal.o: $(SRC_DIR)/terminal.c $(DEP_DIR)/terminal.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(BUILD_DIR)/function.o: $(SRC_DIR)/function.c $(DEP_DIR)/function.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(BUILD_DIR)/fitness.o: $(SRC_DIR)/fitness.c $(DEP_DIR)/fitness.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(BUILD_DIR)/equation.o: $(SRC_DIR)/equation.c $(DEP_DIR)/equation.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(BUILD_DIR)/genetic_operation.o: $(SRC_DIR)/genetic_operation.c $(DEP_DIR)/genetic_operation.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(BUILD_DIR)/optimization.o: $(SRC_DIR)/optimization.c $(DEP_DIR)/optimization.h
	$(CC) -c -o $@ $< $(CFLAGS)


print: 
	@echo $($CFLAGS)

$(BUILD_DIR):
	mkdir -p $@

.PHONY: clean
clean:
	@rm -rf build
