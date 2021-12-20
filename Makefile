CC = gcc
CFLAGS = -I$(DEP_DIR) 

BUILD_DIR = ./build
EXEC = main

SRC_DIR = ./src
DEP_DIR = ./include
APP_DIR = ./app



$(BUILD_DIR)/$(EXEC): $(BUILD_DIR)/main.o $(BUILD_DIR)/population.o 
	$(CC) -o $@ $^

$(BUILD_DIR)/main.o: $(APP_DIR)/main.c $(DEP_DIR)/population.h | $(BUILD_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BUILD_DIR)/population.o: $(SRC_DIR)/population.c $(DEP_DIR)/population.h
	$(CC) -c -o $@ $< $(CFLAGS)


print:
	@echo $(OBJ)

$(BUILD_DIR):
	mkdir -p $@

.PHONY: clean
clean:
	@rm -rf build
