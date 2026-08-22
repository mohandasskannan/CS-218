/*
 * Course: CS218-00x
 * Project: Lab 1 Demo
 * Purpose: display the version of C++ which the compiler supports
 * This can also be done by typing the following command:
 *  $g++ -x c++ -E -dM -< /dev/null | grep __cplusplus
 * Author: (your name)
 */

#include <iostream>

using namespace std;

int main()
{
    cout << "C++ compiler version of my Virtual Machine is: " << endl;
    cout << __cplusplus << endl;
    return 0;
}



