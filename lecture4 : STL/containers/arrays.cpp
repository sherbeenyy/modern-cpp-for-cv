#include <array>
#include <iostream>
#include "../utils.h"

using std::cout;
using std::endl;

// the array is a data structure where you should assgin a size and type in complie time
// the size will be fixed as it holds a block in memory with that size in complie time
// there is some usefull aliias in the array<> instead of creting one yourself
// there is no much about the array

int main()
{

    std::array<int, 3> data{10, 20, 30};

    // printing data before
    printArray(data);

    for (auto &item : data)
    {
        item += 5;
    }
    /// printing data after
    printArray(data);

    cout << "empty? " << data.empty() << endl;
    cout << "size? " << data.size() << endl;

    return 0;
}