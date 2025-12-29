cmake_minimum_required(VERSION 3.16)
project(CompilationPhases)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Main executable
add_executable(main main.cpp)

# Custom targets to demonstrate compilation phases
add_custom_target(preprocessing
    COMMAND ${CMAKE_CXX_COMPILER} -E ${CMAKE_SOURCE_DIR}/main.cpp -o main.i
    COMMENT "Phase 1: Preprocessing - Creating main.i"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_custom_target(compilation
    COMMAND ${CMAKE_CXX_COMPILER} -S ${CMAKE_SOURCE_DIR}/main.cpp -o main.s
    COMMENT "Phase 2: Compilation - Creating main.s"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_custom_target(assembly
    COMMAND ${CMAKE_CXX_COMPILER} -c ${CMAKE_SOURCE_DIR}/main.cpp -o main.o
    COMMENT "Phase 3: Assembly - Creating main.o"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_custom_target(all_phases
    COMMAND ${CMAKE_CXX_COMPILER} -save-temps ${CMAKE_SOURCE_DIR}/main.cpp -o main_manual
    COMMENT "All phases with intermediate files saved"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

# Target to show assembly with different optimization levels
add_custom_target(compare_optimization
    COMMAND ${CMAKE_CXX_COMPILER} -S -O0 ${CMAKE_SOURCE_DIR}/main.cpp -o main_O0.s
    COMMAND ${CMAKE_CXX_COMPILER} -S -O2 ${CMAKE_SOURCE_DIR}/main.cpp -o main_O2.s
    COMMAND echo "Assembly files created: main_O0.s (no optimization) and main_O2.s (optimized)"
    COMMENT "Comparing optimization levels"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

# Clean intermediate files
add_custom_target(clean_phases
    COMMAND rm -f main.i main.s main.o main_manual main_O0.s main_O2.s main.ii
    COMMENT "Cleaning intermediate files"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)