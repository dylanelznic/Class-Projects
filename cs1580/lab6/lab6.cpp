//Programmer: Dylan Elznic
//Instructor: Armita  Section: C  9/30/14
//File: lab6.cpp
//Description: Takes three positive floats and returns their 
//             arithmetic mean and harmonic mean.

#include <iostream>
using namespace std;

/*-----Prototypes-----*/
void greet();
float readNumber();
float arithmeticMean(float number1, float number2, float number3);
float harmonicMean(float number1, float number2, float number3);
void printResult(float arithmetic, float harmonic);
void signoff();

/*-----Main-----*/
int main()
{
  float number1;
  float number2;
  float number3;
  
  float arithmetic;
  float harmonic;
  
  greet(); 
  
  number1 = readNumber();
  number2 = readNumber();
  number3 = readNumber();
    
  arithmetic =  arithmeticMean(number1, number2, number3);
  harmonic = harmonicMean(number1, number2, number3);
  
  printResult(arithmetic, harmonic);
  
  signoff();
  
  return 0;
}


/*-----Definitions-----*/
void greet()
{
  cout<<endl<<endl<<"~*~Welcome to the Arithmetic Mean and"
                  <<" Harmonic Mean Calculator~*~"<<endl<<endl;
  return;
}

float readNumber()
{
  float value_to_get;
  do
  {
    cout<<"Enter a positive integer: ";
    cin>>value_to_get;
    if(value_to_get <= 0)
      cout<<"Invalid number! Try again."<<endl<<endl;
  }while(value_to_get <= 0);
  
  cout<<endl;
  return value_to_get;
}

float arithmeticMean(float number1, float number2, float number3)
{
  float arithmetic = 0;
  arithmetic = (number1+number2+number3)/3;
  return arithmetic;
}

float harmonicMean(float number1, float number2, float number3)
{
  float harmonic = 0;
  harmonic = 3/((1/number1)+(1/number2)+(1/number3));
  return harmonic;
}

void printResult(float arithmetic, float harmonic)
{
  cout<<"Arithmetic Mean: "<<arithmetic<<endl;
  cout<<"Harmonic Mean: "<<harmonic<<endl;
  return;
}

void signoff()
{
  cout<<endl<<"Have a Good Day!"<<endl<<endl;
  return;
}
