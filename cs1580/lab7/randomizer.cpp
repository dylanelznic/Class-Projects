//Programmer: Dylan Elznic    Section: C
//File: randomizer.cpp
//Description: Returns 5 random numbers between 2 chosen boundaries.

#include "randomizer.h"
#include <iostream>
using namespace std;

int main()
{
  //variables
  int number1 = 0;
  int number2 = 0;

  //interface
  greet();
  readNumbers(number1, number2);
  randomGenerator(number1, number2);
  signoff();
 
  return 0;
}
