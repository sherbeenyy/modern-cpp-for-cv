# Lecture 0: C++ Compilation Phases and Compiler Flags

This lecture demonstrates the different phases of C++ compilation using compiler flags to see each intermediate step.

## Theoretical Overview of Compilation Phases

### Phase 1: Preprocessing (Lexical Analysis Preparation)
**What it does conceptually:**
- **Text substitution**: The preprocessor works purely with text, treating the source code as a stream of characters
- **Directive processing**: Handles all directives that begin with `#` (hash symbol)
- **File inclusion**: When it encounters `#include <iostream>`, it literally copies and pastes the entire contents of the iostream header file into your source code
- **Macro expansion**: Replaces all occurrences of `#define` macros with their definitions
- **Conditional compilation**: Processes `#ifdef`, `#ifndef`, `#if` directives to include/exclude code blocks
- **Comment removal**: Strips all comments from the code since they're not needed for compilation

**Key insight**: The preprocessor doesn't understand C++ syntax - it's a sophisticated text manipulation tool.

### Phase 2: Compilation (Syntax Analysis & Code Generation)
**What it does conceptually:**
- **Lexical analysis**: Breaks the preprocessed code into tokens (keywords, identifiers, operators, literals)
- **Syntax analysis**: Parses tokens according to C++ grammar rules, building an Abstract Syntax Tree (AST)
- **Semantic analysis**: Checks for semantic correctness (type checking, variable declarations, function signatures)
- **Intermediate code generation**: Creates an intermediate representation of the program
- **Optimization**: Performs various optimizations (dead code elimination, loop optimization, etc.)
- **Code generation**: Translates the optimized intermediate code into target assembly language

**Key insight**: This is where the compiler truly "understands" your C++ code and converts high-level constructs into low-level instructions.

### Phase 3: Assembly (Machine Code Generation)
**What it does conceptually:**
- **Instruction encoding**: Converts human-readable assembly mnemonics into binary machine instructions
- **Address calculation**: Determines memory addresses for variables and functions (though some addresses remain symbolic)
- **Symbol table creation**: Creates a table of all symbols (functions, variables) defined in this compilation unit
- **Relocation information**: Marks locations where addresses need to be fixed up during linking
- **Object file formatting**: Packages everything into a standardized object file format (ELF on Linux, COFF on Windows)

**Key insight**: The assembler creates machine code but leaves "gaps" for symbols that will be resolved by the linker.

### Phase 4: Linking (Symbol Resolution & Address Binding)
**What it does conceptually:**
- **Symbol resolution**: Matches function calls and variable references with their definitions across multiple object files
- **Address assignment**: Assigns final memory addresses to all symbols
- **Library linking**: Links with standard libraries (like the C++ standard library) and any external libraries
- **Relocation**: Fixes up all the addresses that were marked as needing relocation
- **Executable generation**: Creates the final executable file with proper headers and metadata
- **Entry point setup**: Establishes the program's entry point and startup code

**Key insight**: The linker creates a complete, self-contained executable that the operating system can load and run.

## The 4 Phases of Compilation (Summary)

C++ compilation goes through these phases:
1. **Preprocessing** → Text manipulation: handles `#include`, `#define`, conditional compilation
2. **Compilation** → Language processing: syntax analysis, semantic checking, code generation to assembly
3. **Assembly** → Machine code generation: converts assembly to binary object files
4. **Linking** → Program composition: combines object files and libraries into final executable

## Demonstration Commands

### Phase 1: Preprocessing (`-E` flag)
```bash
g++ -E main.cpp -o main.i
```
- **Input**: `main.cpp` (source code)
- **Output**: `main.i` (preprocessed file)
- **What it does**: 
  - Expands `#include` directives
  - Substitutes `#define` macros
  - Removes comments
  - Handles conditional compilation

**Example output**: You'll see all standard library headers included and `GREETING` replaced with `"Hello, Modern C++!"`.

### Phase 2: Compilation (`-S` flag)
```bash
g++ -S main.cpp -o main.s
# Or from preprocessed file:
g++ -S main.i -o main.s
```
- **Input**: `main.cpp` or `main.i`
- **Output**: `main.s` (assembly file)
- **What it does**: Converts C++ code to assembly language instructions

**Example output**: Assembly instructions like `movq`, `call`, `ret`, etc.

### Phase 3: Assembly (`-c` flag)
```bash
g++ -c main.cpp -o main.o
# Or from assembly:
as main.s -o main.o
```
- **Input**: `main.cpp` or `main.s`
- **Output**: `main.o` (object file)
- **What it does**: Converts assembly to machine code (binary format)

**Note**: Object files contain binary data and are not human-readable.

### Phase 4: Linking (default behavior)
```bash
g++ main.cpp -o main
# Or from object file:
g++ main.o -o main
```
- **Input**: `main.cpp` or `main.o`
- **Output**: `main` (executable)
- **What it does**: 
  - Links with standard libraries
  - Resolves external symbols
  - Creates final executable

## Step-by-Step Manual Process

To see all phases explicitly:

```bash
# 1. Preprocessing
g++ -E main.cpp -o main.i
echo "=== Preprocessed file (first 20 lines) ==="
head -20 main.i

# 2. Compilation to Assembly
g++ -S main.i -o main.s
echo "=== Assembly file ==="
cat main.s

# 3. Assembly to Object
as main.s -o main.o
echo "=== Object file info ==="
file main.o
objdump -t main.o  # Symbol table

# 4. Linking
g++ main.o -o main
echo "=== Final executable ==="
./main
```

## Useful Inspection Commands

### View preprocessed output (human-readable)
```bash
g++ -E main.cpp | head -50
```

### View assembly with optimization
```bash
g++ -S -O2 main.cpp -o main_optimized.s
```

### Compare optimized vs unoptimized assembly
```bash
g++ -S -O0 main.cpp -o main_O0.s    # No optimization
g++ -S -O2 main.cpp -o main_O2.s    # Optimized
diff main_O0.s main_O2.s
```

### Examine object file symbols
```bash
nm main.o                    # Symbol table
objdump -d main.o           # Disassemble
readelf -h main.o           # ELF header info
```

### Examine final executable
```bash
ldd main                    # Dynamic library dependencies
size main                  # Size information
strip main                 # Remove debug symbols
```

## Additional Useful Flags

- **`-v`**: Verbose mode (shows all commands being executed)
- **`-save-temps`**: Keep all intermediate files
- **`-M`**: Generate dependency information
- **`-g`**: Include debug information
- **`-O0/O1/O2/O3`**: Optimization levels

## Complete Example with All Phases

```bash
# Clean start
rm -f main main.i main.s main.o

# All phases in one command with intermediate files saved
g++ -save-temps main.cpp -o main

# This creates:
# - main.ii (preprocessed)
# - main.s (assembly)  
# - main.o (object)
# - main (executable)

# Run the program
./main
```

## Key Learning Points

1. **Preprocessing** expands macros and includes headers
2. **Compilation** produces human-readable assembly code
3. **Assembly** creates binary object files with machine code
4. **Linking** combines everything into a runnable executable
5. Each phase can be controlled independently for debugging and learning

This understanding is crucial for:
- Debugging compilation errors
- Understanding optimization effects
- Working with makefiles and build systems
- Cross-compilation and embedded development