//Programmer: Dylan Elznic  Section: C
//File: lab15.cpp
//Description: This lab is designed to help familiarize the programmer with
//             the Catch and Throw functions.

#include <cstring>
#include <cstdlib>
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
//Variables
  const int MAX_ARRAY_SIZE = 50;
  int input, input_length = 1;
  bool is_armstrong = false, run_again = true;
  int inputarray[MAX_ARRAY_SIZE];
  int input_summation = 0;
  char again;

//Process

  do
  {
    cout<<endl<<"    Enter an Integer:  ";
    cin>>input;

//Check for valid numeric input

    try
    {
      if(!cin.good())
        throw 0;
    }
  
    catch(int e)
    {
    cout<<"    Invalid input dummy"<<endl;
    }

//Finish check

    int input_length_find = input;
    while(input_length_find/=10)
    {
      input_length++;
    }
    
    int input_array_mkr = input; 
    int temp_input_length = input_length;
    while(temp_input_length--)
    {
      inputarray[temp_input_length] = input_array_mkr%10;
      input_array_mkr/=10;
    }

    for(int i = 0; i<input_length; i++)
    {
      input_summation +=  pow(inputarray[i], input_length);
    }
  
    if(input_summation == input)
    {
      is_armstrong = true;
    }
     
    cout<<"The entered number: "<<input<<(is_armstrong?" is":" is not")
    <<" an Armstrong Number."<<endl<<endl;

    cout<<"Another Number?(y,n):  ";
    cin>>again;
  
    if(again == 'y' || again == 'Y')
    {
      run_again = true;
    }
  
    else if(again == 'n' || again == 'N')
    {
      run_again = false;
    }
  
    else
    {
      exit(14);
    }
  
  }while(run_again == true);


  return 0;
}
  