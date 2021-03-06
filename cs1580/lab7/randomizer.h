//Programmer: Dylan Elznic    Section: C
//File: randomizer.h
//Description: Returns 5 random numbers between 2 chosen boundaries. 

#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include <iostream>
using namespace std;

void greet();
//Description: This function welcomes the user with a greeting.
//Pre: n/a
//Post: The user is greeted by a welcome message on the screen.

void readNumbers(int & number1, int & number2);
//Description: This function reads two user number inputs
//             and returns them back to the calling fuction.
//Pre: Two numbers greater than 0, the second being greater than the first.
//Post: The function returns the two numbers back to the calling fuction.

void randomGenerator(int num1, int num2);
//Description: Generates and prints 5 random numbers between a 
//             lower boundary and an upper boundary.
//Pre: The values from readNumbers become the bondaries for the 
//     random generation.
//Post: Prints out 5 random numbers on the user's screen.

void signoff();
//Description: Provides the user with a closing message.
//Pre: n/a
//Post: The user recieves a goodbye message on the screen.

#endif
