#include <vector>
#include <iostream>
#include <algorithm>
#include "../utils.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    const int number = 0;
    std::vector<int> vec{50, 23, 14, 20, 1, 2, 96, 152, 1003, 1000};

    cout << "vector before filling:" << endl;
    printVector(vec);

    std::fill(vec.begin(), vec.end(), number);

    cout << "vector after filling:" << endl;
    printVector(vec);

    return 0;
}