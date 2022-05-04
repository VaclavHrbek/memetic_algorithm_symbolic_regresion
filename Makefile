SHELL = /bin/sh

.SUFFIXES:

CC = nvcc 
CFLAGS = -O0 -c -I$(include_dir) -I/usr/local/cuda/include
LDFLAGS = -lm -lstdc++ 
NVCC = nvcc
NVCFLAGS = -O0 -arch=sm_52 -dc -I$(include_dir) -I/usr/local/cuda/include  
NVCLDFLAGS =  -L/usr/local/cuda/lib64 -lcudart -lcurand -lcuda -lfile

file_dir = .
build_dir = $(file_dir)/build
src_dir = $(file_dir)/src
build_sub_dirs = $(patsubst $(src_dir)/%, %, $(wildcard $(src_dir)/*))
c_src_dir = $(file_dir)/src/c
#openacc_src_dir = $(file_dir)/src/openacc
cuda_src_dir = $(file_dir)/src/cuda
app_dir = $(file_dir)/app
include_dir = $(file_dir)/include

c_src_files := $(wildcard $(c_src_dir)/*.cpp)
app_src_files := $(wildcard $(app_dir)/*.cpp)
#openacc_src_files := $(wildcard $(openacc_src_dir)/*.c) 
cuda_src_files := $(wildcard $(cuda_src_dir)/*.cu)

cuda_obj_files := $(patsubst %.cu, %.o ,$(patsubst $(src_dir)/%, $(build_dir)/%, $(cuda_src_files)))

c_obj_files := $(patsubst %.cpp, %.o ,$(patsubst $(src_dir)/%, $(build_dir)/%, $(c_src_files)))
c_obj_files += $(patsubst $(app_dir)/%.cpp, $(build_dir)/%.o, $(app_src_files))

all: executable

debug: CFLAGS += -g -O0 
debug: NVCFLAGS += -g -G
debug: executable

asan: CFLAGS += -g -O0 -fsanitize=address
asan: LDFLAGS += -fsanitize=address
asan: NVCFLAGS += -g -G
asan: executable

coverage: CFLAGS += -fprofile-arcs -ftest-coverage
coverage: LDFLAGS += -lgcov --coverage
coverage: executable

profile: CFLAGS += -pg -g
profile: LDFLAGS += -pg
profile: executable

executable: $(c_obj_files) main

$(c_obj_files): | $(build_dir)

$(build_dir)/c/%.o: $(c_src_dir)/%.cpp
	$(CC) $(CFLAGS) $< -o $@
	
$(build_dir)/%.o: $(app_dir)/%.cpp
	$(CC) $(CFLAGS) $< -o $@

$(build_dir)/cuda/%.o: $(cuda_src_dir)/%.cu
	$(NVCC) $(NVCFLAGS) $< -o $@

$(build_dir)/link_device_code.o: $(cuda_obj_files)
	$(NVCC) $(NVCLDFLAGS) $^ -o $@

main: $(c_obj_files) $(cuda_obj_files) 
	$(CC) $(LDFLAGS) $(NVCLDFLAGS) $^ -o $(build_dir)/$@ 

$(build_dir):
	$(foreach i, $(build_sub_dirs), $(shell mkdir -p  $(build_dir)/$(i)))

.PHONY:
	clean

clean:
	rm -rf $(file_dir)/build


