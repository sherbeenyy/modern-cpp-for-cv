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

    cout << "vector:" << endl;
    printVector(vec);

    auto result = std::find(vec.begin(), vec.end(), number); // this returns an iterator you derefrence it using *ref

    if (result != vec.end())
    {
        cout << "found: " << *result << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    return 0;
}