//Programmer: Dylan Elznic    Section: C
//File: randomizerfncts.cpp
//Description: Returns 5 random number between 2 chosen boundaries.

#include "randomizer.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void greet()
{
  cout<<endl<<endl<<"~*~ Welcome to the Random Number Generator ~*~"<<endl<<endl;
  return;
}

void readNumbers(int & number1, int & number2)
{
  int lowbound = 0;
  int highbound = 0;

  do
  {
    cout<<"Enter the lower limit [>0]: ";
    cin>>lowbound;
  }while(lowbound <= 0);
  
  cout<<endl;
  
  do
  {
    cout<<"Enter the upper limit [>"<<lowbound<<"]: ";
    cin>>highbound;
  }while(highbound < lowbound * 2);
  
  cout<<endl;
  
  number1 = lowbound;
  number2 = highbound;
  
  return;
}

void randomGenerator(int num1, int num2)
{
  for(int i = 0; i <= 4; i++)
  {
    cout<<"Random Number between "<<num1<<" and "<<num2<<", inclusively, is: "
        <<num1+rand()%(num2+1-num1)<<endl;
  }
  
  return;
 }

void signoff()
{
  cout<<endl<<"Have a Good Day!"<<endl<<endl;
  return;
}



