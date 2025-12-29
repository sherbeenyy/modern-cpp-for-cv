#include <vector>
#include <iostream>
#include "../utils.h"

using std::cin;
using std::cout;
using std::endl;

void addingToVector(std::vector<int> &vec)
{
    int numberOfAddedItems;
    int value;
    cout << "enter the number of added items";
    cin >> numberOfAddedItems;

    for (int i = 0; i < numberOfAddedItems; i++)
    {
        cout << "enter the 'int' number " << i << endl;
        cin >> value;

        vec.push_back(value);
    }
}

int main()
{
    // a vector has a size and a capacity
    // the size is how many items are in this vector
    // the capacity is how many memeory the vector reserves for that items
    // so a std::vector<int> vec if we used vec.reserve(100) it will reserve 400 bytes and whenever we use push_back it wont reallocate untill we reach 100 elemnt
    // but if we didnt use reserve() the vector will keep alocatting doubling the capacity each time it reaches the end
    // so you better use reserve()
    std::vector<int> data{10, 20, 30, 40, 50};
    // printVector(data);
    // addingToVector(data);
    // printVector(data);
    cout << data.size() << endl;

    // address of the vector in memory
    cout << &data << endl;

    return 0;
}