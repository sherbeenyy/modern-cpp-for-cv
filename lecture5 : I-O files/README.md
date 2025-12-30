# Lecture 5: Input/Output Files and Utilities

This lecture covers file I/O operations in C++ using stream-based approaches, as well as modern C++ utility features like `optional` and `tuple`.


## Topics Covered

### 1. File I/O Operations

#### File Reading ([readFile.cpp](stream-based-io/basic_ofstream/readFile.cpp))
- Using `std::ifstream` for reading files
- File existence checking with `is_open()`
- Line-by-line reading using `std::getline()`

```cpp
std::ifstream myfile("file.txt");
if (myfile.is_open()) {
    std::string line;
    while (std::getline(myfile, line)) {
        std::cout << line;
    }
}
```

**C++ Reference:** [std::ifstream](https://en.cppreference.com/w/cpp/io/basic_ifstream)

#### File Writing ([writeFIle.cpp](stream-based-io/basic_ofstream/writeFIle.cpp))
- Using `std::ofstream` for writing files
- Automatic file creation and management
- Stream operations and character output
- File positioning with `seekp()`
- Writing different data types

```cpp
std::ofstream myfile("file.txt");
myfile << "hello from the main.cpp\n";
myfile.put('A');
myfile.seekp(50); // Change buffer position
```

**C++ Reference:** [std::ofstream](https://en.cppreference.com/w/cpp/io/basic_ofstream)

### 2. Standard I/O Streams ([iostreamGLOBALS.cpp](stream-based-io/globals/iostreamGLOBALS.cpp))

Learn the differences between standard output streams:

- **`std::cout`**: Buffered standard output
- **`std::cerr`**: Unbuffered error output (immediate printing)
- **`std::clog`**: Buffered error output

**Key Benefits of `std::cerr`:**
1. Can be redirected to error logs (`2> error.txt`)
2. Signals error logging mode
3. Unbuffered - prints immediately
4. Separates error output from regular output

**C++ Reference:** 
- [std::cout](https://en.cppreference.com/w/cpp/io/cout)
- [std::cerr](https://en.cppreference.com/w/cpp/io/cerr)
- [std::clog](https://en.cppreference.com/w/cpp/io/clog)

### 3. Modern C++ Utilities

#### Optional Values ([optional.cpp](utils/optional.cpp))
`std::optional` allows functions to return values that may or may not exist:

```cpp
std::optional<int> isGreat(int num) {
    if (num > 1000)
        return 1;
    else
        return std::nullopt;
}
```

**C++ Reference:** [std::optional](https://en.cppreference.com/w/cpp/utility/optional)

#### Tuple Usage ([tuple.cpp](utils/tuple.cpp))
`std::tuple` allows grouping multiple values of different types:

```cpp
using Student = std::tuple<std::string, int, char>;
Student s1 = {"ahmed", 21, 'A'};
print(std::get<int>(s1));         // Access by type
print(std::get<std::string>(s1)); // Access by type
```

**C++ Reference:** [std::tuple](https://en.cppreference.com/w/cpp/utility/tuple)

##  Compilation

To compile any of the examples:

```bash
g++ -std=c++17 filename.cpp -o output
./output
```

##  Additional Resources

### C++ Reference Documentation
- [Input/Output Library](https://en.cppreference.com/w/cpp/io)
- [File I/O](https://en.cppreference.com/w/cpp/io#File_I.2FO)
- [Stream Positioning](https://en.cppreference.com/w/cpp/io/basic_ostream/seekp)
- [Utility Library](https://en.cppreference.com/w/cpp/utility)

### Key Concepts
1. **RAII**: File streams automatically close when destructors are called
2. **Buffering**: Understanding when output is flushed
3. **Type Safety**: Using `std::optional` for safer return values
4. **Data Structures**: `std::tuple` for heterogeneous data grouping
