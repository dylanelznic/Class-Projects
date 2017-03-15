//Programmer: Dylan Elznic 12438548
//Instructor Armita  Section: C  09/09/2014
//BMI Calculator: This program calculates the user's BMI, or Body Mass Index,
//                and tells them whether they are over, under, or a healthy
//                weight.

#include<iostream>
using namespace std;

  int main()
  {
    short mass;                           //Mass in pounds
    short height;                         //Height in inches
    const short CONVERSION_FACTOR = 703;
    float BMI;                            //Body Mass Index
    
    
    //Welcome message
    cout<<"Welcome to the BMI calculator"<<endl;
    
    //Mass and weight inputs
    cout<<"Enter the Mass(pounds): ";
    cin>>mass;
    cout<<"Enter the Height(inches): ";
    cin>>height;
    
    //Calculate BMI
    BMI = (static_cast<float>(mass)*CONVERSION_FACTOR)/(height*height);
    
    //Display the result
    cout<<"The BMI value for "<<height<<" inches and "<<mass<<" pounds is "<<BMI
    <<endl;
    
  
    return 0;    
  }
