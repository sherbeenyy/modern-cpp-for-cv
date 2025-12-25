#include <iostream>
#include <string>

#define GREETING "Hello, Modern C++!"
#define MAX_COUNT 5

int main()
{
    std::string message = GREETING;
    std::cout << message << std::endl;

    for (int i = 1; i <= MAX_COUNT; ++i)
    {
        std::cout << "Count: " << i << std::endl;
    }

    return 0;
}