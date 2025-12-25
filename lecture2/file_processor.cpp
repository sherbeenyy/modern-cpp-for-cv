#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Function to extract the integer part from filename
int extractNumber(const string &filename)
{
    size_t dotPos = filename.find('.');
    if (dotPos == string::npos)
    {
        cerr << "Invalid filename format" << endl;
        exit(1);
    }

    string numberStr = filename.substr(0, dotPos);
    try
    {
        return stoi(numberStr);
    }
    catch (const exception &e)
    {
        cerr << "Invalid number in filename" << endl;
        exit(1);
    }
}

// Function to extract the extension from filename
string extractExtension(const string &filename)
{
    size_t dotPos = filename.find('.');
    if (dotPos == string::npos)
    {
        cerr << "Invalid filename format" << endl;
        exit(1);
    }

    return filename.substr(dotPos + 1);
}

int main(int argc, char *argv[])
{
    // Check for exactly 2 arguments
    if (argc != 3)
    {
        cerr << "Error: Exactly two arguments required" << endl;
        return 1;
    }

    string file1 = argv[1];
    string file2 = argv[2];

    // Extract numbers and extensions
    int num1 = extractNumber(file1);
    int num2 = extractNumber(file2);
    string ext1 = extractExtension(file1);
    string ext2 = extractExtension(file2);

    cout << "Processing files: " << file1 << " and " << file2 << endl;
    cout << "Numbers extracted: " << num1 << " and " << num2 << endl;
    cout << "Extensions: " << ext1 << " and " << ext2 << endl;

    if (ext1 == "txt" && ext2 == "txt")
    {
        double mean = (num1 + num2) / 2.0;
        cout << "Result: " << mean << endl;
    }
    else if (ext1 == "png" && ext2 == "png")
    {
        int sum = num1 + num2;
        cout << "Result: " << sum << endl;
    }
    else if (ext1 == "txt" && ext2 == "png")
    {
        if (num2 == 0)
        {
            cerr << "Error: Division by zero" << endl;
            return 1;
        }
        int result = num1 % num2;
        cout << "Result: " << result << endl;
    }
    else
    {
        // Invalid extensions
        cerr << "Error: Unsupported file extensions" << endl;
        return 1;
    }

    return 0;
}