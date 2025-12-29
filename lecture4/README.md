# Lecture 4: STL (Standard Template Library)

## Overview
This lecture covers the fundamentals of the C++ Standard Template Library (STL), including containers, algorithms, and utilities. The STL provides a rich collection of generic algorithms and data structures that form the backbone of modern C++ programming.


## Utilities Module
The project includes a unified utilities module for common operations:

### `utils.h` / `utils.cpp`
- **`printVector<T>()`** - Print any std::vector type
- **`printArray<T, N>()`** - Print any std::array type  
- **`printCArray<T, N>()`** - Print C-style arrays

**Usage:**
```cpp
#include "utils.h"

std::vector<int> vec{1, 2, 3};
printVector(vec);  // Displays formatted output
```

## Containers Covered

### 1. **std::array** (`containers/arrays.cpp`)
- Fixed-size array container
- Size known at compile time
- Zero overhead compared to C arrays
- Provides STL container interface

**Key Features:**
- `size()`, `at()`, `operator[]`
- Iterator support (`begin()`, `end()`)
- Bounds checking with `at()`

### 2. **std::vector** (`containers/vectors.cpp`) 
- Dynamic array container
- Automatic memory management
- Efficient random access

**Key Concepts:**
- **Size vs Capacity**: Size = current elements, Capacity = reserved memory
- **`reserve()`**: Pre-allocate memory to avoid reallocations
- **`push_back()`**: Add elements efficiently

### 3. **std::map** (`associative_containers/maps.cpp`)
- Key-value pair container
- Automatically sorted by key
- Efficient lookup, insertion, deletion

## Algorithms Covered

### 1. **std::sort** (`algorithms/sort.cpp`)
```cpp
std::vector<int> vec{50, 23, 14, 20, 1};

// Ascending order (default)
std::sort(vec.begin(), vec.end());

// Descending order
std::sort(vec.begin(), vec.end(), std::greater<int>());
```

### 2. **std::find** (`algorithms/find.cpp`)
```cpp
auto result = std::find(vec.begin(), vec.end(), target);

if (result != vec.end()) {
    std::cout << "Found: " << *result << std::endl;
} else {
    std::cout << "Not found" << std::endl;
}
```
**Important**: Always check `result != container.end()` before dereferencing!

### 3. **std::fill** (`algorithms/fill.cpp`) 
```cpp
std::fill(vec.begin(), vec.end(), value);  // Fill entire container
```

## More STL Algorithms

The STL provides **80+ algorithms** for various operations. The examples above represent just a small sample. For a comprehensive list, check out:

**Complete STL Algorithm Reference:**
[https://en.cppreference.com/w/cpp/algorithm](https://en.cppreference.com/w/cpp/algorithm)

### Popular Algorithm Categories:
- **Searching**: `find`, `find_if`, `binary_search`, `search`
- **Sorting**: `sort`, `partial_sort`, `nth_element`, `stable_sort`
- **Modifying**: `copy`, `move`, `transform`, `replace`, `remove`
- **Numeric**: `accumulate`, `inner_product`, `partial_sum`
- **Partitioning**: `partition`, `stable_partition`
- **Set operations**: `set_union`, `set_intersection`, `includes`

## Build Instructions

Each example can be compiled individually:
```bash
# Compile any example
g++ -std=c++17 -o example file.cpp

# Examples:
g++ -std=c++17 -o sort algorithms/sort.cpp
g++ -std=c++17 -o find algorithms/find.cpp
g++ -std=c++17 -o fill algorithms/fill.cpp
```

## Key Takeaways

1. **STL Containers** provide safe, efficient alternatives to raw arrays
2. **STL Algorithms** are highly optimized and well-tested
3. **Iterator-based design** makes algorithms work with any container
4. **Template-based** approach provides type safety and performance
5. **Always validate iterators** before dereferencing (especially with `find`)
6. **Use `reserve()`** for vectors when you know the approximate size


