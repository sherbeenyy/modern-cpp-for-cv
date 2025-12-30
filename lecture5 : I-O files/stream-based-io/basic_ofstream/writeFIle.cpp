#include <fstream> //higher level interface to work with files
#include <iostream>

int main()
{
    std::ofstream myfile("file.txt"); // this creates the file and open it right away!
    // destructor automatically closes the file

    if (myfile.is_open())
    {
        std::cout << "the file handeler mapped the file sucessfuly" << std::endl;
    }

    myfile << "hello from the main.cpp\n"; // stream of data
    myfile << "hello from the main.cpp\n"; // stream of data
    myfile << "hello from the main.cpp\n"; // stream of data
    myfile << "hello from the main.cpp\n"; // stream of data
    myfile << "hello from the main.cpp\n"; // stream of data

    myfile.put('A'); // puts a char

    char a = 48;

    myfile << (int)a; // ascii value of the

    myfile.seekp(50); // change the postion of the pointer on the buffer
    myfile << "2";

    myfile.seekp(-2, std::ios_base::end); // this means move the pointer to the very end and move backwards 2 steps

    myfile << 50;

    return 0;
}