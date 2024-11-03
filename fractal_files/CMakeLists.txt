cmake_minimum_required(VERSION 3.15)
project(BasicFractalProject C)

set(CMAKE_C_STANDARD 99)

# Include SDL2 headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Link SDL2 library directory
link_directories(${CMAKE_SOURCE_DIR}/lib)

# Enable OpenMP
find_package(OpenMP REQUIRED)
if (OpenMP_C_FOUND)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_C_FLAGS}")
endif()

# Create the executable
add_executable(BasicFractalProject main.c draw_mandelbrot.c draw_juliaset.c)

# Link SDL2 libraries and OpenMP
target_link_libraries(BasicFractalProject SDL2main SDL2 OpenMP::OpenMP_C)
