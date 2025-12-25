#include <iostream>
#include "random"

using namespace std;

int main()
{
    int random, guess;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 99);
    random = dist(gen);

    cout << "enter a guess from 0 to 99" << endl;

    if (!(cin >> guess))
    {
        cout << "Error encountered, exiting..." << endl;
        return 1;
    }

    if (guess < 0 || guess > 99)
    {
        cerr << "[WARNING] : Number must be between 0 and 99" << endl;
        return 1;
    }

    while (guess != random)
    {
        if (guess > random)
            cout << "the random is lower " << endl;
        else if (guess < random)
            cout << "the random is higher" << endl;
        else
            break;

        cout << "enter a guess from 0 to 99" << endl;

        if (!(cin >> guess))
        {
            cout << "Error encountered, exiting..." << endl;
            return 1;
        }

        if (guess < 0 || guess > 99)
        {
            cerr << "[WARNING] : Number must be between 0 and 99" << endl;
            return 1;
        }
    }

    cout << "Congratulations! You guessed the number: " << random << endl;
    return 0;
}