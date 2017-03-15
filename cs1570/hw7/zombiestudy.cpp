//Programmer: Dylan Elznic     Section: A
//File: zombiestudy.cpp
//Description: Generates a random sample of people for a zombie study.
//             Their attributes will be determined, and then they will
//             proceed to be tested to see if they possess the GTAC patern.

#include "zombiestudy.h"
#include <iostream>
using namespace std;

int main()
{
  //Variables
  int dataLength = 1;
  person people[SAMPLE_MAX];
 
  float brainDesPercent = 0; 
  float smellPercent = 0;
  float gaitPercent = 0;
 
  float physZombPercent = 0;
  float dNAZombPercent = 0;
  float combZombPercent = 0;
  
  //Process
  greeting();

  do
  {  
    cout<<"Enter the number of people in the test (1-5000): ";
    cin>>dataLength;
  }while(dataLength > SAMPLE_MAX || dataLength < SAMPLE_LOWER);
  
  getPeople(people,dataLength);

  brainDesireTest(people, dataLength, brainDesPercent);
  bodyOdorTest(people, dataLength, smellPercent);
  gaitTest(people, dataLength, gaitPercent);
  
  physZombTest(people, dataLength, physZombPercent);
  dNAZombTest(people, dataLength, dNAZombPercent);
  combZombTest(people, dataLength, combZombPercent);
  
  cout<<endl<<"Out of the "<<dataLength<<" people tested:"
  <<endl<<endl
  <<"     "<<brainDesPercent<<"% want to eat brains."
  <<endl<<endl
  <<"     "<<smellPercent<<"% have a slightly ripe or rotting stench smell."
  <<endl<<endl
  <<"     "<<gaitPercent<<"% do not walk normally."
  <<endl<<endl
  <<"     "<<physZombPercent<<"% qualify as zombies only by how they smell,"
                            <<" how they walk, and what they want to eat."
  <<endl<<endl
  <<"     "<<dNAZombPercent<<"% qualify as Zombies only by the DNA test."
  <<endl<<endl
  <<"     "<<combZombPercent<<"% qualify as zombies by both the DNA test and "
                            <<"how they walk, how they smell, and what they "
                            <<"want to eat."
  <<endl<<endl; 

  closing();
  
  return 0;
}
