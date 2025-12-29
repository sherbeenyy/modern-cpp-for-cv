#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <memory>
#include <algorithm>
#include <tuple>

// Example 1: Basic auto usage
void basicAutoExamples()
{
    std::cout << "=== Basic auto Examples ===" << std::endl;

    // Simple type deduction
    auto intVar = 42;                      // int
    auto doubleVar = 3.14;                 // double
    auto stringVar = std::string("Hello"); // std::string
    auto charPtr = "World";                // const char*

    std::cout << "intVar: " << intVar << " (type: int)" << std::endl;
    std::cout << "doubleVar: " << doubleVar << " (type: double)" << std::endl;
    std::cout << "stringVar: " << stringVar << " (type: std::string)" << std::endl;
    std::cout << "charPtr: " << charPtr << " (type: const char*)" << std::endl;
    std::cout << std::endl;
}

// Example 2: auto with complex types
void complexTypeExamples()
{
    std::cout << "=== Complex Type Examples ===" << std::endl;

    // Vector with auto
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    auto vectorCopy = numbers; // std::vector<int>

    // Map with auto
    std::map<std::string, int> ageMap = {{"Alice", 25}, {"Bob", 30}};
    auto mapCopy = ageMap; // std::map<std::string, int>

    // Iterator with auto (much cleaner than full type!)
    auto it = numbers.begin(); // std::vector<int>::iterator

    std::cout << "First element via iterator: " << *it << std::endl;
    std::cout << "Alice's age: " << mapCopy["Alice"] << std::endl;
    std::cout << std::endl;
}

// Example 3: auto with range-based for loops
void rangeBasedForExamples()
{
    std::cout << "=== Range-based For Loop Examples ===" << std::endl;

    std::vector<std::string> fruits = {"apple", "banana", "orange"};

    // auto with value (copy)
    std::cout << "Fruits (by value): ";
    for (auto fruit : fruits)
    {
        std::cout << fruit << " ";
    }
    std::cout << std::endl;

    // auto with reference (no copy)
    std::cout << "Fruits (by reference): ";
    for (const auto &fruit : fruits)
    {
        std::cout << fruit << " ";
    }
    std::cout << std::endl;

    // Modifying elements with auto&
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    for (auto &num : numbers)
    {
        num *= 2; // Double each number
    }

    std::cout << "Doubled numbers: ";
    for (const auto &num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl
              << std::endl;
}

// Example 4: auto with function return types (C++14)
auto addInts(int a, int b)
{
    return a + b; // Return type deduced as int
}

auto multiplyDoubles(double x, double y)
{
    return x * y; // Return type deduced as double
}

// Example 5: auto with trailing return type (C++11)
auto divideNumbers(double a, double b) -> double
{
    if (b != 0.0)
    {
        return a / b;
    }
    return 0.0;
}

// Example 6: auto with lambda expressions
void lambdaExamples()
{
    std::cout << "=== Lambda Examples with auto ===" << std::endl;

    // Simple lambda
    auto simpleLambda = [](int x)
    { return x * x; };
    std::cout << "Square of 5: " << simpleLambda(5) << std::endl;

    // Lambda with capture
    int multiplier = 3;
    auto captureLambda = [multiplier](int x)
    { return x * multiplier; };
    std::cout << "5 * 3 = " << captureLambda(5) << std::endl;

    // Using lambda with algorithms
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Count even numbers
    auto isEven = [](int n)
    { return n % 2 == 0; };
    auto evenCount = std::count_if(numbers.begin(), numbers.end(), isEven);
    std::cout << "Even numbers count: " << evenCount << std::endl;
    std::cout << std::endl;
}

// Example 7: auto with smart pointers
void smartPointerExamples()
{
    std::cout << "=== Smart Pointer Examples ===" << std::endl;

    // auto with unique_ptr
    auto uniquePtr = std::make_unique<int>(42);
    std::cout << "Unique ptr value: " << *uniquePtr << std::endl;

    // auto with shared_ptr
    auto sharedPtr = std::make_shared<std::string>("Hello Smart Pointers!");
    std::cout << "Shared ptr value: " << *sharedPtr << std::endl;

    // auto with weak_ptr
    auto weakPtr = std::weak_ptr<std::string>(sharedPtr);
    if (auto locked = weakPtr.lock())
    {
        std::cout << "Weak ptr locked value: " << *locked << std::endl;
    }
    std::cout << std::endl;
}

// Example 8: When NOT to use auto
void avoidAutoExamples()
{
    std::cout << "=== When NOT to Use auto ===" << std::endl;

    // Bad: Type is unclear
    // auto result = getSomeValue();  // What type is this?

    // Better: Be explicit when type matters
    double preciseValue = 3.14159265359;           // Clearly a double
    int intValue = static_cast<int>(preciseValue); // Explicit conversion

    std::cout << "Precise value: " << preciseValue << std::endl;
    std::cout << "Int value: " << intValue << std::endl;

    // Bad: auto with narrowing conversions
    // auto badNarrowing = someFloatFunction();  // Unclear if intentional

    // Better: Explicit type shows intention
    float specificFloat = 3.14f; // Clearly want float, not double
    std::cout << "Specific float: " << specificFloat << std::endl;
    std::cout << std::endl;
}

// Example 9: auto with template functions
template <typename T>
auto templateFunction(const T &a, const T &b)
{
    return a + b; // Return type depends on T
}

void templateExamples()
{
    std::cout << "=== Template Examples ===" << std::endl;

    auto intResult = templateFunction(5, 10);                                          // Returns int
    auto doubleResult = templateFunction(3.14, 2.86);                                  // Returns double
    auto stringResult = templateFunction(std::string("Hello "), std::string("World")); // Returns std::string

    std::cout << "Int result: " << intResult << std::endl;
    std::cout << "Double result: " << doubleResult << std::endl;
    std::cout << "String result: " << stringResult << std::endl;
    std::cout << std::endl;
}
// Example 10: Returning multiple values with tuple
std::tuple<int, double, std::string> getMultipleValues()
{
    return std::make_tuple(42, 3.14, "Hello");
}

// Using structured bindings (C++17)
auto getPersonInfo()
{
    return std::make_tuple(std::string("Alice"), 25, 175.5);
}

// Alternative: pair for two values
std::pair<int, int> divideWithRemainder(int dividend, int divisor)
{
    return std::make_pair(dividend / divisor, dividend % divisor);
}

void multipleReturnValuesExamples()
{
    std::cout << "=== Multiple Return Values Examples ===" << std::endl;

    // Method 1: Using auto with tuple
    auto result = getMultipleValues();
    auto intVal = std::get<0>(result);
    auto doubleVal = std::get<1>(result);
    auto stringVal = std::get<2>(result);

    std::cout << "Tuple values: " << intVal << ", " << doubleVal << ", " << stringVal << std::endl;

    // Method 2: Direct unpacking with auto
    auto [quotient, remainder] = divideWithRemainder(17, 5);
    std::cout << "17 / 5 = " << quotient << " remainder " << remainder << std::endl;

    // Method 3: C++17 structured bindings
    auto [name, age, height] = getPersonInfo();
    std::cout << "Person: " << name << ", Age: " << age << ", Height: " << height << "cm" << std::endl;

    // Method 4: Using std::tie for existing variables
    int q, r;
    std::tie(q, r) = divideWithRemainder(23, 7);
    std::cout << "23 / 7 = " << q << " remainder " << r << std::endl;

    std::cout << std::endl;
}
int main()
{
    std::cout << "Modern C++ auto Examples" << std::endl;
    std::cout << "=========================" << std::endl
              << std::endl;

    basicAutoExamples();
    complexTypeExamples();
    rangeBasedForExamples();

    // Function return type examples
    std::cout << "=== Function Return Type Examples ===" << std::endl;
    std::cout << "addInts(5, 3): " << addInts(5, 3) << std::endl;
    std::cout << "multiplyDoubles(2.5, 4.0): " << multiplyDoubles(2.5, 4.0) << std::endl;
    std::cout << "divideNumbers(10.0, 3.0): " << divideNumbers(10.0, 3.0) << std::endl;
    std::cout << std::endl;

    lambdaExamples();
    smartPointerExamples();
    avoidAutoExamples();
    templateExamples();
    multipleReturnValuesExamples();

    std::cout << "Key Takeaways:" << std::endl;
    std::cout << "1. auto reduces verbosity and prevents type errors" << std::endl;
    std::cout << "2. Use const auto& for read-only access to avoid copies" << std::endl;
    std::cout << "3. Be explicit when type clarity is important" << std::endl;
    std::cout << "4. auto works great with complex template types" << std::endl;
    std::cout << "5. Use std::make_tuple for returning multiple values" << std::endl;
    std::cout << "6. C++17 structured bindings make tuple unpacking cleaner" << std::endl;

    return 0;
}