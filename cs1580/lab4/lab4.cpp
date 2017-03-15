//Programmer: Dylan Elznic  //Date: 9/16/14
//File: lab4.cpp  //Section: C
//Program Name: Number Averager
//Program Description: Takes the sum of numbers between 0 and 50 and divisible 
//                     by 3 or 5 and averages them.

#include <iostream>
using namespace std;

int main()
{
  /*-----Variables-----*/
  
  int inNum = 0;      //Number entered by user
  int sumNum = 0;     //Sum of current numbers
  int count = -1;      //Amount of entries
  float average;
  char cont;          //(y/n)
  
  /*-----Menu----------*/
    
  do
  {
    if((inNum % 5 == 0 || inNum % 3 == 0) && (inNum >= 0 && inNum <= 50))
    {
      sumNum += inNum;
      count++;
    }      
    cout<<"Would you like to enter a number (y/n): ";
    cin>>cont;
    cout<<endl;
    if (cont == 'y')
    {
      cout<<"Enter a Number: ";
      cin>>inNum;
      cout<<endl;
    }
  }while (cont == 'y');

  average = static_cast<float>(sumNum)/count;
  cout<<"The average is: "<<average<<endl<<endl;

  return 0;
}
