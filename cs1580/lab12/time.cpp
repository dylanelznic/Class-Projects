//Programmer: Dylan Elznic   Section: C
//File: time.cpp
//Description: Prints a time that is one second past the user inputted time

#include <iostream>
#include "time.h"

using namespace std;

int main()
{
  Time userInput;
  userInput.read_in();
  userInput.print_out();
  userInput.nextSecond();
    
  return 0;
}
