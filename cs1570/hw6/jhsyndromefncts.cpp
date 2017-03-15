//Programmer: Dylan Elznic     Section: A
//File: jhsyndromefncts.cpp
//Description: This file contains the functions for the jhsyndrome.cpp file

#include "jhsyndrome.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void greet() //Outputs greeting
{
  cout<<endl<<endl
      <<"Welcome to the Jejunal Hemorrhage Syndrome Diagnoser."
      <<endl;
  
  return;
}

string getPat() //Gets patient's name
{
  string patientname;
  cout<<"Please enter patient's name: ";
  cin>>patientname;
  return patientname;
}

void ringFlatA(int & p1, float & p2, int & p3) //Produces p1, p2, and p3 values
{
  cout<<endl<<endl<<"Ringing A Flat...";
  
  srand(time(NULL));
  p1 = rand()%P1_RANGE;
  if(p1<P1_UPPERLIM)
  {
    p1 = 0;
  }
  p2 = rand()%P2_RANGE/static_cast<float>(10);
  p3 = rand()%P3_RANGE;
  
  return;
}

void ringMiddleG(float & p2, int & p4) //Produces p2 and p4 values
{
  cout<<endl<<endl<<"Ringing Middle G...";
  
  float tempp2 = 0;
  srand(time(NULL));
  tempp2 = rand()%P2_RANGE/static_cast<float>(10);
  if(tempp2>p2)
  {
    p2 = tempp2;
  }
  p4 = rand()%P4_RANGE;
  
  return;
}

void ringFlatC(int & p1, int & p4, int & p5) //Produces p1, p4, and p5 values
{
  cout<<endl<<endl<<"Ringing C Flat...";
  
  float tempp1 = 0;
  float tempp4 = 0;
  srand(time(NULL));
  if(tempp1>p1)
  {
    p1 = tempp1;
  }
  
  if(p1<P1_UPPERLIM)
  {
    p1 = 0;
  }
  
  tempp4 = rand()%P4_RANGE;
  
  if(tempp4>p4)
  {
    p4 = tempp4;
  }
  p5 = rand()%P5_RANGE;
  return;
}  
    
void jhspositive(string patname) //Outputs positive JH Syndrome message
{
  cout<<endl<<"Patient "<<patname<<" has Jejunal Hemorrage Syndrome.";
  return;
}

void jhsnegative(string patname) //Outputs negative JH Syndrome message
{
  cout<<endl<<"Patient "<<patname<<" does not have Jejunal Hemorrage Syndrome.";
  return;
}
    
void JHSynDiag(const protein & prot, const string & patname) 
//Determines whether the patient has JH Syndrome
{
  if(prot.m_pro1 < P1_UPPERLIM)
  {
    jhsnegative(patname);
  }
  else if(prot.m_pro5 < P5_UPPERLIM)
  {
    if(prot.m_pro4 > P4_LOWERLIM && prot.m_pro4 < P4_UPPERLIM)
    {   
      if(prot.m_pro3 > P3_LOWERLIM)
      {
        jhspositive(patname);
      }
      else
      {
        jhsnegative(patname);
      }
    }
    else
    {
      jhsnegative(patname);
    }
  }
  else if(prot.m_pro5 >= P5_LOWERLIM)
  {
    if(prot.m_pro1 + prot.m_pro2 + prot.m_pro3 < P1P2P3_SUMLIM)
    {
      jhspositive(patname);
    }
    else
    {
      jhsnegative(patname);
    }
  }
  return;
}

int soundtest()
{
  srand(time(NULL));
    return rand()%SOUND_RANGE;
}
    
