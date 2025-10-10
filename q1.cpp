/*
Give your answer to part 1 here.

a.
This one is given to you as an example.

#include <iostream>
using namespace std;
int main() {
    char inp[8];
    cin >> inp;
    cout << inp << endl;
    return 0;
}

Runtime error.
The code declares an array of size 8 to hold a string input.
If the user inputs a string longer than 7 characters (plus the null terminator),
it will cause a buffer overflow, leading to a runtime error.



b.

int main() {
    int a = "hello" / "world";
    return 0;
}

Compilation error.
The / operation requires numeric types like int or float,
it doesnt support char* like "hello" and "world".



c.

#include <iostream>
using namespace std;
int main()
{
    int myNum = 5;
    if (myNum < 10)
    {
        cout << "myNum is greater than 10" << endl;
    }
    else
    {
        cout << "myNum is 10 or less" << endl;
    }
}

Logical error.
The if condition check myNum < 10, but the code prints "myNum is greater than 10",
which is opposite to the condition.



d.

int main()
{
    int a = 4;
    int b = 0;
    int c = a / b;
}

Runtime error.
Division by zero (a / b where b = 0) is an undefined behavior,
which causes crash during runtime.
It cant be detected while compiling, as the compiler only
checks the type of the operand, not the runtime value.


Your answers to parts b, c, and d should end before this line.
*/

/*
Part 2:
Explain the what the following code is trying to do.
Find the bug making the results wrong
Document why and how it happens.
Write a simple fix for it.


What is the code trying to do?

What is the bug?

Why and how does it happen?

How to fix it?

*/
/*
#include <iostream>
using namespace std;
int main()
{
    int a = 3;
    int b = 4;
    int percent = (a / b) * 100;
    cout << percent << "%" << endl;
    return 0;  // returning 0 for main() just means the program ended successfully
}
*/

/*
The code intends to print the equivalent persentage of a / b, which is 75%.

However, the program outputs 0% instead of 75%.

Since both a and b are integer, (a / b) performs an integer division,
trancating the fractional part(0.75) to zero.

To fix the bug, simply define all variables(a, b and percent) to be double, 
then (a / b) becomes a floating point division,
keeping all fractional part.
*/

/*
#include <iostream>
using namespace std;
int main()
{
    double a = 3;
    double b = 7;
    double percent = (a / b) * 100;
    cout << percent << "%" << endl;
    return 0;  // returning 0 for main() just means the program ended successfully
}
*/