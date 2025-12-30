#include <fstream> //higher level interface to work with files
#include <iostream>

int main()
{
    std::ifstream myfile("file.txt"); // this opens the file for reading its in READ ONLY mode by deafult

    if (myfile.is_open())
    {
        std::string line;
        while (std::getline(myfile, line))
        {
            std::cout << line;
        }
    }
    return 0;
}