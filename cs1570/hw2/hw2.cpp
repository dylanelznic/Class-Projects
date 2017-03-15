//Programmer: Dylan Elznic    Date: 9/10/14
//File: hw2.cpp    Section: A
//Purpose: Outputs the correct dosage for perscription medicine
//         in accordance to the patient's information.

#include <iostream>
using namespace std;

int main()
{
  int Age;    //Age
  float Wt;   //Weight
  int IQ;     //IQ
  int Gen;    //Gender
  int Freq;   //Frequency
  
  const short TSTRENGTH = 250;   //Tablet Strength
  const short DEC = 20;          //Dr. Eloe's Constant
  
  float Dosage;  //Perscribed Dosage 
  
  /*-----Inputs-----*/
  cout<<"Welcome! To calculate your dosage,"<<endl;
  cout<<"Please enter your..."<<endl;
  cout<<"  Age: ";
  cin>>Age;
  cout<<"  Weight(kg): ";
  cin>>Wt;
  cout<<"  IQ: ";
  cin>>IQ;
  cout<<"  Gender(Female 0, Male 1): ";
  cin>>Gen;
  cout<<"  Frequency: ";
  cin>>Freq;
  cout<<endl;
  
  /*-----Calculations-----*/
  Dosage=(static_cast<float>(Age)/IQ)*((Wt/Freq)+1)*
  ((static_cast<float>(TSTRENGTH)/1000)+Gen)+DEC;
  
  Dosage=static_cast<int>(Dosage)+(Dosage-static_cast<int>(Dosage) >.5);

  /*-----Outputs-----*/
  cout<<"Dr. Eloe:"<<endl;
  cout<<"For the values input:"<<endl;
  cout<<"  Age = "<<Age<<endl;
  cout<<"  Weight(kg) = "<<Wt<<endl;
  cout<<"  IQ = "<<IQ<<endl;
  cout<<"  Gender = "<<Gen<<endl;
  cout<<"  Frequency = "<<Freq<<endl;
  cout<<"  Tab Strength of 250mg"<<endl;
  cout<<"The reccomended dosage is "<<Dosage<<" tablets"<<endl;
  
  return 0;  
}
