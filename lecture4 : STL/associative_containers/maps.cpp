#include <map>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// maps are ordered associative containers means that it will be ordered by key once the value is inputed
// so key must accept '<' operator
// you can use and unordered_map
// the only diffrence that unorderned is faster beacuse no ordering required

using studentsMap = std::map<int, string>;

void printMap(studentsMap &map)
{
    for (const auto &[id, name] : map)
    {
        cout << id << " : " << name << endl;
    }
}

int main()
{
    studentsMap map;

    map.emplace(100, "ahmed");
    map.emplace(200, "mohamed");
    map.emplace(50, "ahmed");

    // automatically sorted !
    printMap(map);

    return 0;
}