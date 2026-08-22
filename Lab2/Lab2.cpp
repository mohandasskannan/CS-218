/*
 * Course: CS218-00x
 * Project: Lab 2
 * Purpose: practice how to run unix command from C++ program
 *          system() is used to invoke an operating command from a C++ program
 *          demo cowsay command using three different cow files
 * Author: (your name)
 */

#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    ifstream infile("cowFiles.txt");
    if (!infile) {
    	cout << "Error: could not open file." << endl;
	return 1;
    }

    string cow;
    int count = 0;
    while (infile >> cow) {
    	string command_str = "cowsay -f /usr/share/cowsay/cows/";
        command_str = command_str + cow;
        command_str = command_str + " Hello, CS218 Students!";
        const char* command = command_str.c_str();
        system(command);
	count++;
    }
   
    cout << "I will demo cowsay command to you using " << count << " cow Files stored in my VM:)" << endl;
   
    
    cout << "There are " << count << " stored in my VM" << endl;

    infile.close();

    return 0;
}



