//Programmer: Dylan Elznic     Section: C
//File: areafuncs.cpp
//Description:

#include "area.h"
#include <iostream>
using namespace std;

void greet()
{
  cout<<endl<<endl<<"~*~Welcome to Area Calculator~*~"<<endl<<endl;
  return;
}

float read()
{
  float numvar = 0;
  cin>>numvar;
  
  while(numvar <= 0)
  {
    cout<<"Error: Invalid Value"<<endl
        <<"Please Try Again: ";
    cin>>numvar;        
  }
  
  return numvar;
}

float area(const circle & circ)
{
  float areaCirc = PI*(circ.radius*circ.radius);
  return areaCirc;
}

float area(const rectangle & rect)
{
  float areaRect = rect.height*rect.width;
  return areaRect;
}

void signoff()
{
  cout<<endl<<"Have a Good Day!"<<endl<<endl;
  return;
}
