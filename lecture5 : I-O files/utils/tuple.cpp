#include <utility>
#include <tuple>
#include <iostream>
#define print(x) std::cout << x << std::endl

using Student = std::tuple<std::string, int, char>;
int main()
{
    Student s1 = {"ahmed", 21, 'A'};

    print(std::get<int>(s1));         // gets the int part
    print(std::get<std::string>(s1)); // gets the string part

    return 0;
}
