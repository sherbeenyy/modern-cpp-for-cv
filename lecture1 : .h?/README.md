# Lecture 1: Creating and Linking Libraries in C++

This lecture demonstrates how to create a static library and link it through the linker during compilation.

## Overview

In this example, we have:
- **main.cpp**: The main application
- **tools.cpp**: Implementation of utility functions
- **tools.hpp**: Header file with function declarations
- **CMakeLists.txt**: Build configuration

## Manual Compilation and Linking

### Step 1: Compile the Library Source to Object File
```bash
g++ -c tools.cpp -o tools.o
```
This creates an object file `tools.o` from the library source.

### Step 2: Create a Static Library
```bash
ar rcs libtools.a tools.o
```
This creates a static library `libtools.a` from the object file using the archiver tool `ar`.

### Step 3: Compile Main Program and Link with Library
```bash
g++ main.cpp -L. -ltools -o main
```
- `-L.` tells the linker to look for libraries in the current directory
- `-ltools` links against `libtools.a` (the `lib` prefix and `.a` suffix are implied)
- `-o main` specifies the output executable name

### Alternative: Direct Linking
You can also link directly with the object file:
```bash
g++ main.cpp tools.o -o main
```

## Using CMake (Recommended)

CMake automates the build process. Run:
```bash
mkdir build && cd build
cmake ..
make
```

## Key Concepts

### Static Libraries
- **Extension**: `.a` (Linux/macOS) or `.lib` (Windows)
- **Linking**: Code is copied into the final executable at compile time
- **Benefits**: Self-contained executable, no runtime dependencies
- **Drawbacks**: Larger executable size, no shared code between programs

### Linker Flags
- **-L**: Specify library search directories
- **-l**: Link with a library (e.g., `-ltools` links with `libtools.a`)
- **-static**: Force static linking
- **-shared**: Create or link with shared libraries

### Library Naming Convention
- Static libraries: `lib[name].a`
- When linking: use `-l[name]` (without `lib` prefix and `.a` suffix)

## Build Output
After building, you'll get:
- **main**: The executable file
- **libtools.a**: The static library (if built manually)

## Running the Program
```bash
./main
```

This lecture provides the foundation for understanding how libraries are created and linked in C++ projects, which is essential for larger software development.