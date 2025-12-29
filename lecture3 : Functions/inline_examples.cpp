#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <tuple>

// Example 1: Basic inline function
inline int square(int x)
{
    return x * x;
}

// Example 2: Non-inline version for comparison
int squareNotInline(int x)
{
    return x * x;
}

// Example 3: Inline function with multiple statements
inline double calculateCircleArea(double radius)
{
    const double PI = 3.14159265359;
    return PI * radius * radius;
}

// Example 4: Larger function - NOT a good candidate for inlining
inline double complexCalculation(double x)
{
    double result = 0.0;
    for (int i = 1; i <= 100; ++i)
    {
        result += std::sin(x / i) * std::cos(x * i);
        result *= std::sqrt(i);
        result /= (i + 1);
    }
    return result; // Compiler will likely ignore the inline hint here
}

// Example 5: Class with inline member functions
class Point
{
private:
    double x, y;

public:
    // Constructor (implicitly inline)
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    // Getters (implicitly inline - defined in class)
    double getX() const { return x; }
    double getY() const { return y; }

    // Setters (implicitly inline)
    void setX(double newX) { x = newX; }
    void setY(double newY) { y = newY; }

    // More complex function - explicitly inline
    inline double distanceFromOrigin() const
    {
        return std::sqrt(x * x + y * y);
    }

    // Function defined outside class - needs inline keyword
    inline double distanceTo(const Point &other) const;

    // Static inline function
    static inline Point origin()
    {
        return Point(0.0, 0.0);
    }
};

// Definition outside class - must be inline to avoid multiple definition errors
inline double Point::distanceTo(const Point &other) const
{
    double dx = x - other.x;
    double dy = y - other.y;
    return std::sqrt(dx * dx + dy * dy);
}

// Example 6: Template functions (automatically considered for inlining)
template <typename T>
inline T max(const T &a, const T &b)
{
    return (a > b) ? a : b;
}

template <typename T>
inline T min(const T &a, const T &b)
{
    return (a < b) ? a : b;
}

// Example 7: Performance comparison
void performanceTest()
{
    std::cout << "=== Performance Comparison ===" << std::endl;

    const int iterations = 10000000;
    auto start = std::chrono::high_resolution_clock::now();

    // Test inline version
    long long sum1 = 0;
    for (int i = 0; i < iterations; ++i)
    {
        sum1 += square(i % 1000);
    }

    auto mid = std::chrono::high_resolution_clock::now();

    // Test non-inline version
    long long sum2 = 0;
    for (int i = 0; i < iterations; ++i)
    {
        sum2 += squareNotInline(i % 1000);
    }

    auto end = std::chrono::high_resolution_clock::now();

    auto inline_time = std::chrono::duration_cast<std::chrono::milliseconds>(mid - start).count();
    auto non_inline_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - mid).count();

    std::cout << "Inline function time: " << inline_time << " ms" << std::endl;
    std::cout << "Non-inline function time: " << non_inline_time << " ms" << std::endl;
    std::cout << "Sum results (should be equal): " << sum1 << " vs " << sum2 << std::endl;

    if (inline_time < non_inline_time)
    {
        std::cout << "Inline version was faster by " << (non_inline_time - inline_time) << " ms" << std::endl;
    }
    else if (non_inline_time < inline_time)
    {
        std::cout << "Non-inline version was faster by " << (inline_time - non_inline_time) << " ms" << std::endl;
    }
    else
    {
        std::cout << "Both versions performed equally" << std::endl;
    }
    std::cout << "Note: Results may vary based on compiler optimization" << std::endl;
    std::cout << std::endl;
}

// Example 8: Good candidates for inlining
namespace InlineCandidates
{

    // Mathematical operations
    inline double celsius_to_fahrenheit(double celsius)
    {
        return celsius * 9.0 / 5.0 + 32.0;
    }

    inline bool is_even(int number)
    {
        return number % 2 == 0;
    }

    inline int abs_value(int x)
    {
        return (x < 0) ? -x : x;
    }

    // Simple utility functions
    inline bool is_vowel(char c)
    {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }

    inline double square_double(double x)
    {
        return x * x;
    }
}

// Example 9: Poor candidates for inlining
namespace PoorInlineCandidates
{

    // Large function with complex logic
    inline void print_multiplication_table(int n)
    { // Poor candidate!
        std::cout << "Multiplication table for " << n << ":" << std::endl;
        for (int i = 1; i <= 12; ++i)
        {
            for (int j = 1; j <= 12; ++j)
            {
                std::cout << i * j << "\t";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    // Recursive function
    inline long long fibonacci(int n)
    { // Poor candidate!
        if (n <= 1)
            return n;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }

    // Function with complex control flow
    inline std::string process_string(const std::string &input)
    { // Poor candidate!
        std::string result;
        for (char c : input)
        {
            if (std::isalpha(c))
            {
                if (std::islower(c))
                {
                    result += std::toupper(c);
                }
                else
                {
                    result += std::tolower(c);
                }
            }
            else if (std::isdigit(c))
            {
                result += c;
            }
            else if (c == ' ')
            {
                result += '_';
            }
            // More complex logic...
        }
        return result;
    }
}

// constexpr functions (implicitly inline) - defined at global scope
constexpr int constexpr_factorial(int n)
{
    return (n <= 1) ? 1 : n * constexpr_factorial(n - 1);
}

// Example 10: Modern C++ and inline
void modernInlineExamples()
{
    std::cout << "=== Modern C++ Inline Examples ===" << std::endl;

    // Lambda functions (often inlined automatically)
    auto lambda_square = [](int x)
    { return x * x; };
    std::cout << "Lambda square of 7: " << lambda_square(7) << std::endl;

    // Using the global constexpr function
    constexpr int fact5 = constexpr_factorial(5); // Computed at compile time!
    std::cout << "Compile-time factorial of 5: " << fact5 << std::endl;

    // Template functions with auto
    auto template_add = [](auto a, auto b)
    { return a + b; };
    std::cout << "Template add (int): " << template_add(5, 3) << std::endl;
    std::cout << "Template add (double): " << template_add(3.14, 2.86) << std::endl;

    std::cout << std::endl;
}

// Example 11: Inline variables (C++17)
#if __cplusplus >= 201703L
inline double PI = 3.14159265359; // C++17 inline variable
inline const std::string APP_NAME = "Inline Examples";
#endif

void testGoodInlineCandidates()
{
    std::cout << "=== Testing Good Inline Candidates ===" << std::endl;

    using namespace InlineCandidates;

    std::cout << "25°C = " << celsius_to_fahrenheit(25.0) << "°F" << std::endl;
    std::cout << "Is 42 even? " << (is_even(42) ? "Yes" : "No") << std::endl;
    std::cout << "Absolute value of -15: " << abs_value(-15) << std::endl;
    std::cout << "Is 'a' a vowel? " << (is_vowel('a') ? "Yes" : "No") << std::endl;
    std::cout << "Square of 3.5: " << square_double(3.5) << std::endl;

    std::cout << std::endl;
}

void demonstrateClassInlining()
{
    std::cout << "=== Class Inline Functions ===" << std::endl;

    Point p1(3.0, 4.0);
    Point p2(6.0, 8.0);

    std::cout << "Point 1: (" << p1.getX() << ", " << p1.getY() << ")" << std::endl;
    std::cout << "Point 2: (" << p2.getX() << ", " << p2.getY() << ")" << std::endl;

    std::cout << "Distance from origin (p1): " << p1.distanceFromOrigin() << std::endl;
    std::cout << "Distance between points: " << p1.distanceTo(p2) << std::endl;

    Point origin = Point::origin();
    std::cout << "Origin: (" << origin.getX() << ", " << origin.getY() << ")" << std::endl;

    std::cout << std::endl;
}

int main()
{
    std::cout << "Modern C++ Inline Function Examples" << std::endl;
    std::cout << "===================================" << std::endl
              << std::endl;

    // Basic inline usage
    std::cout << "=== Basic Inline Usage ===" << std::endl;
    std::cout << "Square of 5: " << square(5) << std::endl;
    std::cout << "Circle area (radius 3): " << calculateCircleArea(3.0) << std::endl;
    std::cout << std::endl;

    // Template functions
    std::cout << "=== Template Function Examples ===" << std::endl;
    std::cout << "Max of 10 and 20: " << max(10, 20) << std::endl;
    std::cout << "Max of 3.14 and 2.71: " << max(3.14, 2.71) << std::endl;
    std::cout << "Min of 'a' and 'z': " << min('a', 'z') << std::endl;
    std::cout << std::endl;

    demonstrateClassInlining();
    testGoodInlineCandidates();
    modernInlineExamples();

    // Performance test (compile with -O2 for better comparison)
    performanceTest();

    std::cout << "Key Inline Guidelines:" << std::endl;
    std::cout << "1. Good for small, frequently called functions" << std::endl;
    std::cout << "2. Avoid for large or complex functions" << std::endl;
    std::cout << "3. Compiler can ignore inline hints" << std::endl;
    std::cout << "4. Class member functions defined inside are implicitly inline" << std::endl;
    std::cout << "5. Template functions are often inlined automatically" << std::endl;
    std::cout << "6. constexpr functions are implicitly inline" << std::endl;
    std::cout << "7. Use compiler optimization flags (-O2, -O3) for better results" << std::endl;

#if __cplusplus >= 201703L
    std::cout << std::endl
              << "C++17 inline variables:" << std::endl;
    std::cout << "PI = " << PI << std::endl;
    std::cout << "App name: " << APP_NAME << std::endl;
#endif

    return 0;
}