# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name and language
project(MemeticAlgorithm LANGUAGES CUDA CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files to the project
set(APP
    app/main.cu
)

set(HEADERS
    include/
)

set(SOURCES
	src/node.cu
)

add_library(memeticAlgo ${SOURCES})
set_target_properties(memeticAlgo PROPERTIES LINKER_LANGUAGE CUDA)

# Add CUDA include directories
target_include_directories(memeticAlgo 
	PUBLIC ${HEADERS}
	PUBLIC ${CUDA_INCLUDE_DIRS}
	)

# Add CUDA libraries
target_link_libraries(memeticAlgo 
	PUBLIC ${CUDA_LIBRARIES}
	)

# Add the executable target
add_executable(app ${APP})

target_link_libraries(app 
	PUBLIC memeticAlgo
	)

# Add CUDA flags
set(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS} -arch=sm_60")

