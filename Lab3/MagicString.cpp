/* 
 * File:   MagicString.cpp
 * Purpose: provide the definition of the MagicString class
 *
 * Author: (your name)
 *
 */
#include <iostream>
#include <stack>
#include "MagicString.h"

// initialize str with ini_str passing as a parameter
MagicString::MagicString(string ini_str)
{
    str = ini_str;
}

// return the current value of the private data member: str
string MagicString::getString() const
{
    return str;
}

// set the value of str to the passed in parameter input_str
void MagicString::setString(string input_str)
{
    str = input_str;
}

// return a reverse string
// using a loop to implement
// Note that the private data member named str, has not been changed
string MagicString::rev_loop() const
{
    string loop;
    for (int i = str.length() - 1; i >= 0; i--) {
	loop += str[i];
    }
    return loop;
}

// return a reverse string
// using recursion to implement
// Note that the private data member named str, has not been changed
string MagicString::rev_recursion() const
{
    string recursion;
    if (str.length() <= 1) {
	return str;
    }
    else {
	MagicString middle(str.substr(1, str.length() - 2)); // Make a class that extracts the middle of a string
	// Return a string that keeps extracting the middle using 
	// recursion and reverse the first and last characters
	return(str[(str.length() - 1)] + middle.rev_recursion() + str[0]); 	
    }
}

// return a reverse string
// using a stack to implement
// Note that the private data member named str, has not been changed
string MagicString::rev_stack() const
{
    if (str.length() <= 1) {
	return str;
    }
    else {
	// Make a stack
	stack<char> s;
	// Make a string to add the elements of the stack
	string stack;
	for (int i = 0; i < str.length(); i++) {
		// Add values to the stack
		s.push(str[i]);
	}
	while (!s.empty()) {
		// Add those values to the string
		stack += s.top();
		s.pop();
	}

	return stack;

    }
}

// return true if str is a palindrome
// otherwise return false
// A palindrome is defined as a sequence of characters which reads the same backward as forward
// calling member function to  implement
// Note that the private data member named str, has not been changed
bool MagicString::isPalindrome() const
{
    if (str.length() <= 1) {
	return true;
    }

    // left and right characters of the string
    int left = 0;
    int right = str.length() - 1;

    // check if the left and right characters are equal, and if they are, keep going
    while (left < right) {
	if (str[left] != str[right])
	{
		// If they are not equal, it is not a palindrome
		return false;
	}
	left++;
	right--;

    }


    return true;

}
        
// return true if str is a palindrome
// otherwise return false
// A palindrome is defined as a sequence of characters which reads the same backward as forward
// using recursion to implement
// Note that the private data member named str, has not been changed
bool MagicString::isPalindrome_recursion() const
{
    // base case
    if (str.length() <= 1)
	return true;
    else // recursive case
    {
	string middle = str.substr(1, str.length() - 2); // Extract middle portion of string
	MagicString shorter(middle); // Make an object with that string
	bool firstPair = (str[0] == str[str.length() - 1]); // Check if the first and last characters are the same
	return (firstPair && shorter.isPalindrome_recursion()); // Use recursion to check the rest of the string
    }
}
        
// displays str followed by a new line marker
// to the standard output
void MagicString::print() const
{
    cout << str << endl;
}
