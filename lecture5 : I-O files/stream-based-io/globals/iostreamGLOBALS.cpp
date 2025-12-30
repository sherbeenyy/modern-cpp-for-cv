#include <iostream>

int loadingFile()
{
    return -1;
}
int main()
{
    /*
    ?   why use cerr ? it seems like they all print to the standard output ?
    *   1) cerr can be redirected to an error log via 2> erroe.txt for example
    *   so you can seperate
    *   2)it signals that we are in logging error mode
    *   3) it is not buffered means that it will be printed right away!
    *   cout and clog are buffered so they wait and collect data then print
    *   The buffer is fulshed manually using .flush() or std::endl or automaticaly when the program is done
    */

    if (loadingFile() == -1)
        std::cerr << "error acocured!" << std::endl;

    std::cout << "hello world\n";
    return 0;
}