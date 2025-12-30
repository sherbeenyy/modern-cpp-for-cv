#include <utility>
#include <optional>
#include <iostream>
#define print(x) std::cout << x << std::endl

std::optional<int> isGreat(int num) // this allows you to make a return optional !
{
    if (num > 1000)
        return 1;
    else
        return std::nullopt;
}

int main()
{
    auto result = isGreat(80000);

    if (result)
    {
        print("great");
    }
    else
        print("not great");
    return 0;
}