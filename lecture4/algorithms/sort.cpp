#include <vector>
#include <iostream>
#include <algorithm>
#include "../utils.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    std::vector<int> vec{50, 23, 14, 20, 1, 2, 96, 152, 1003, 1000};

    cout << "Before sorting:" << endl;
    printVector(vec);

    std::sort(vec.begin(), vec.end());

    cout << "After sorting:" << endl;
    printVector(vec);

    return 0;
}