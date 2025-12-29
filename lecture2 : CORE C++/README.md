# Lecture 2: Core C++ Concepts - File Processing and Data Extraction

This lecture covers fundamental C++ concepts through practical file processing examples, demonstrating how to work with datasets by extracting meaningful information from filenames.

## Learning Objectives

- Understanding command-line argument processing (`argc`, `argv`)
- String manipulation and parsing techniques
- File extension analysis and pattern matching
- Error handling and program flow control
- Core C++ features: functions, conditionals, and data types

## Project: File Processor

### Problem Statement
When working with datasets, file naming conventions often encode important information. Our file processor extracts numerical data from filename patterns and performs operations based on file extensions.

**Filename Format**: `<INTEGER>.<EXTENSION>`
- Examples: `10.txt`, `25.png`, `data42.csv`

### Core C++ Concepts Demonstrated

#### 1. Command-Line Arguments
```cpp
int main(int argc, char* argv[])
```
- `argc`: Argument count (includes program name)
- `argv[]`: Array of argument strings
- Essential for processing external input

#### 2. String Processing
```cpp
string::find('.')           // Locate delimiter
string::substr(start, len)  // Extract substrings  
stoi(string)               // String to integer conversion
```

#### 3. Error Handling Patterns
- Input validation and bounds checking
- Exception handling with try-catch blocks
- Graceful program termination with meaningful error messages

#### 4. Function Design
- **Single Responsibility**: Each function has one clear purpose
- **Parameter Passing**: Using const references for efficiency
- **Return Values**: Clear success/failure indication

### Supported Operations

| File Extensions | Operation | Description |
|----------------|-----------|-------------|
| `.txt` + `.txt` | Mean | Average of two numbers |
| `.png` + `.png` | Sum | Addition of two numbers |
| `.txt` + `.png` | Modulo | Remainder division (first % second) |
| Other combinations | Error | Unsupported format |

### Usage Examples

```bash
# Compile the program
g++ file_processor.cpp -o file_processor

# Test different scenarios
./file_processor 15.txt 25.txt    # Output: Mean = 20
./file_processor 10.png 5.png     # Output: Sum = 15
./file_processor 17.txt 3.png     # Output: Modulo = 2

# Error cases
./file_processor 10.pdf 20.txt    # Error: Unsupported extensions
./file_processor 10.txt            # Error: Wrong argument count
```

## Key C++ Features Explored

### 1. String Manipulation
- **`find()`**: Locate specific characters or substrings
- **`substr()`**: Extract portions of strings
- **`npos`**: Special value indicating "not found"

### 2. Type Conversion
- **`stoi()`**: Safe string-to-integer conversion
- **Exception handling**: Managing conversion failures

### 3. Program Flow Control
- **Conditional logic**: Multiple if-else branches
- **Early termination**: Using `exit()` for error conditions
- **Return codes**: 0 for success, 1 for errors

### 4. Memory Management
- **Automatic variables**: Stack-allocated strings and integers
- **Parameter passing**: Efficient const reference usage

## Real-World Applications

This file processing pattern is commonly used in:

- **Data Science**: Processing dataset files with encoded parameters
- **Image Processing**: Extracting metadata from filename conventions
- **Log Analysis**: Parsing structured log file names
- **Batch Processing**: Automated file organization and analysis

## Core C++ Takeaways

1. **Robust Input Validation**: Always check user input before processing
2. **Clear Function Interfaces**: Functions should have single, clear purposes
3. **Meaningful Error Messages**: Help users understand what went wrong
4. **Standard Library Usage**: Leverage `<string>` and other standard tools
5. **Program Structure**: Separate concerns into logical functions

This lecture demonstrates how C++'s core features enable powerful, reliable data processing applications that form the foundation of larger software systems.