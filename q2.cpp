/*
1.
line 29, while (repeat = true)
issue:(repeat = true) assign the value of repeat to be true, instead of being a bool statement

fix: while (repeat)

2.
line 35, repeat == false;
issue: (repeat == false) returns the bool value, instead of assigning false to repeat

fix: repeat = false;

3.
line 39, int delta = inp - a;
issue: it creates a new inner variable delta inside the else, the global delta will not be updated

fix: delta = inp - a;

*/
#include <iostream>
using namespace std;
int main()
{
    int inp = 0;
    int a = 3;
    int delta = 0;
    bool repeat = true;
    while (repeat) //while (repeat = ture)
    {
        cin >> inp;

        if (inp == -1)
        {
            repeat = false; // repeat == flase;
        }
        else
        {
            delta = inp - a; // int delta = inp - a;
            cout << "Delta: " << delta << ". Enter -1 to exit.\n";
        }
    }

    cout << "Final Delta: " << delta << endl;
    return 0;
}