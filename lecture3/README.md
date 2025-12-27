# Lecture 3: Functions in Modern C++

## Learning Objectives
By the end of this lecture, you will understand:
- The `auto` keyword and type deduction
- Dangers of returning references to local variables
- The `inline` keyword and its implications
- Best practices for function design in modern C++

## 1. The `auto` Keyword

### What is `auto`?
The `auto` keyword tells the compiler to automatically deduce the type of a variable from its initializer. Introduced in C++11, it simplifies code and reduces redundancy.

### Basic Usage
```cpp
auto x = 42;        // int
auto y = 3.14;      // double
auto z = "Hello";   // const char*
auto w = std::string("World"); // std::string
```

### `auto` with Functions

#### Return Type Deduction (C++14)
```cpp
auto add(int a, int b) {
    return a + b;  // Return type deduced as int
}

auto multiply(double x, double y) {
    return x * y;  // Return type deduced as double
}
```

#### Trailing Return Type (C++11)
```cpp
auto divide(double a, double b) -> double {
    return a / b;
}
```

### Benefits of `auto`
1. **Reduces verbosity**: No need to write long type names
2. **Prevents type mismatches**: Compiler ensures correct type
3. **Easier maintenance**: Type changes propagate automatically
4. **Template-friendly**: Works well with complex template types

### When to Use `auto`
**Good cases:**
- Complex iterator types
- Lambda expressions
- Template type deduction
- Range-based for loops

**Avoid when:**
- Type clarity is important for readability
- You need specific type conversions
- Working with numeric types where precision matters

## 2. Dangers of Returning References to Local Variables

### The Problem
One of the most dangerous mistakes in C++ is returning a reference to a local variable. Local variables are destroyed when the function exits, making the reference invalid.

### Example of Dangerous Code
```cpp
// DANGEROUS! Never do this!
int& getBadReference() {
    int localVar = 42;
    return localVar;  // Returns reference to local variable
}  // localVar is destroyed here!

// Usage leads to undefined behavior
int& ref = getBadReference();  // ref points to destroyed memory
std::cout << ref << std::endl; // Undefined behavior!
```

### Why This Happens
1. **Stack allocation**: Local variables are stored on the stack
2. **Automatic destruction**: Stack variables are destroyed when function exits
3. **Dangling reference**: Reference points to invalid memory location
4. **Undefined behavior**: Accessing invalid memory can crash or give random values

### Safe Alternatives

#### Return by Value
```cpp
int getValue() {
    int localVar = 42;
    return localVar;  // Safe: returns a copy
}
```

#### Return Reference to Parameter
```cpp
int& getReference(int& parameter) {
    // Safe: parameter exists outside this function
    return parameter;
}
```

#### Return Reference to Static/Global Variable
```cpp
int& getStaticReference() {
    static int staticVar = 42;  // Static variable survives function exit
    return staticVar;  // Safe: staticVar has static storage duration
}
```

#### Use Smart Pointers or Dynamic Allocation
```cpp
std::unique_ptr<int> createInt() {
    return std::make_unique<int>(42);  // Dynamic allocation
}
```

### Compiler Warnings
Modern compilers often warn about this mistake:
```
warning: reference to local variable 'localVar' returned [-Wreturn-local-addr]
```

Always enable and heed compiler warnings!

## 3. The `inline` Keyword

### What is `inline`?
The `inline` keyword is a hint to the compiler to replace function calls with the actual function code, potentially improving performance by eliminating function call overhead.

### Basic Usage
```cpp
inline int square(int x) {
    return x * x;
}
```

### How Inlining Works
1. **Compile-time substitution**: Function call replaced with function body
2. **No function call overhead**: Eliminates push/pop operations and jumps
3. **Code expansion**: Function code is copied at each call site

### Automatic Inlining
The compiler can inline functions automatically without the `inline` keyword if:
- Function is small and simple
- Function is called frequently
- Optimization flags are enabled

### When Inlining Helps
**Good candidates:**
- Small functions (1-3 lines)
- Functions called frequently in tight loops
- Getter/setter functions
- Simple mathematical operations

**Poor candidates:**
- Large functions (increases code size)
- Recursive functions
- Functions with complex control flow

### Modern C++ and Inlining

#### Implicit Inlining
Functions defined inside class definitions are implicitly inline:
```cpp
class MyClass {
public:
    int getValue() const { return value; }  // Implicitly inline
private:
    int value = 0;
};
```

#### Lambda Functions
Lambda functions are often inlined automatically:
```cpp
auto lambda = [](int x) { return x * x; };  // Often inlined
```

### Important Notes
1. **`inline` is a hint**: Compiler may ignore it
2. **One Definition Rule**: Inline functions can be defined in headers
3. **Binary size**: Excessive inlining can increase executable size
4. **Template functions**: Template instantiations are often inlined

## 4. Returning Multiple Values with Tuples

### Using `std::make_tuple`
Modern C++ provides elegant ways to return multiple values from functions using tuples:

```cpp
#include <tuple>

// Return multiple values using make_tuple
std::tuple<int, double, std::string> getMultipleValues() {
    return std::make_tuple(42, 3.14, "Hello");
}

// Using auto to capture the result
auto result = getMultipleValues();
auto intVal = std::get<0>(result);
auto doubleVal = std::get<1>(result);
auto stringVal = std::get<2>(result);
```

### Structured Bindings (C++17)
C++17 introduced structured bindings for cleaner unpacking:

```cpp
auto [value, pi, text] = getMultipleValues();
// Now you can use value, pi, and text directly
```

### Alternative: Using `std::pair`
For two values, `std::pair` is simpler:

```cpp
std::pair<int, int> divideWithRemainder(int dividend, int divisor) {
    return std::make_pair(dividend / divisor, dividend % divisor);
}

auto [quotient, remainder] = divideWithRemainder(17, 5);
```

### Using `std::tie` for Existing Variables
```cpp
int q, r;
std::tie(q, r) = divideWithRemainder(23, 7);
```

## 5. Best Practices for Modern C++ Functions

### Function Design Principles
1. **Single Responsibility**: Each function should do one thing well
2. **Pure functions**: Avoid side effects when possible
3. **Const correctness**: Use `const` for parameters that shouldn't change
4. **Move semantics**: Use `std::move` for expensive-to-copy objects

### Modern Function Features
```cpp
// Default parameters
void processData(const std::vector<int>& data, bool verbose = false);

// Function overloading
int add(int a, int b);
double add(double a, double b);

// Template functions
template<typename T>
T max(const T& a, const T& b) {
    return (a > b) ? a : b;
}

// Constexpr functions (compile-time evaluation)
constexpr int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}
```

## 6. Common Pitfalls and How to Avoid Them

### Pitfall 1: Reference to Temporary
```cpp
const std::string& getName() {
    return std::string("John");  // Returns reference to temporary!
}
```

### Pitfall 2: Auto with References
```cpp
auto x = someFunction();   // Copy
auto& y = someFunction();  // Reference (be careful with temporaries!)
```

### Pitfall 3: Inline Everything
Don't inline large or complex functions just because you can.

## Summary
- **`auto`**: Powerful type deduction, use wisely for cleaner code
- **References**: Never return references to local variables
- **`inline`**: Performance hint for small, frequently called functions
- **Best practices**: Focus on clear, safe, and maintainable code

## Files in This Lecture
- `auto_examples.cpp`: Demonstrates various uses of the auto keyword
- `dangerous_references.cpp`: Shows dangerous and safe reference patterns
- `inline_examples.cpp`: Illustrates inline function usage and performance