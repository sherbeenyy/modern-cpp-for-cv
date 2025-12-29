cmake_minimum_required(VERSION 3.10)

# Project name
project(Lecture3Functions LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable compiler warnings
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Wreturn-local-addr)
endif()

# Set optimization flags for performance testing
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    if(MSVC)
        add_compile_options(/O2)
    else()
        add_compile_options(-O2)
    endif()
endif()

# Auto examples executable
add_executable(auto_examples auto_examples.cpp)

# Dangerous references executable
add_executable(dangerous_references dangerous_references.cpp)

# Inline examples executable
add_executable(inline_examples inline_examples.cpp)

# Create a target to run all examples
add_custom_target(run_all_examples
    COMMAND echo "Running auto examples..."
    COMMAND auto_examples
    COMMAND echo ""
    COMMAND echo "Running dangerous references examples..."
    COMMAND dangerous_references
    COMMAND echo ""
    COMMAND echo "Running inline examples..."
    COMMAND inline_examples
    DEPENDS auto_examples dangerous_references inline_examples
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)