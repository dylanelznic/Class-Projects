//Programmer: Dylan Elznic / Ryan Stoughton   Section: A
//File: driver.cpp
//Description: This program allows the creation of patients with traits
//             including their name, money, health, and whether or not
//             they're alive. These patients are sent to
//             a hospital room(class) and put into an x-ray machine(class).
//             The results are then printed. 

#include <iostream>
using namespace std;

#include <fstream>
#include <ctime>

#include "patient.h"
#include "pharmacy.h"
#include "organ_donor.h"
#include "doctor.h"
#include "liposuctionizer.h"
#include "hospital_room.h"
#include "lobotomizer.h"
#include "x_rayer.h"
#include "placeboizer.h"

const int NUM_PATS = 10;
const string DOC_NAME = "Eloe";

int main()
{
  srand(time(NULL));

  patient pat[NUM_PATS];
  doctor eloe(DOC_NAME);
  
  //Rooms
  hospital_room<lobotomizer>     lobo;
  hospital_room<organ_donor>     orgd;
  hospital_room<placeboizer>     plcbo;
  hospital_room<pharmacy>        pharm;
  hospital_room<liposuctionizer> lipo;
  hospital_room<x_rayer>         x_ray;
  
  for(int i = 0; i < NUM_PATS; i++)
  {
    cout<<endl<<endl<<">Patient "<<i+1<<":"<<endl<<endl;
    cout<<pat[i]<<endl<<eloe;
    
    lobo.admit(pat[i], eloe);
    cout<<endl<<lobo<<endl<<pat[i]<<endl<<eloe;
    
    orgd.admit(pat[i], eloe);
    cout<<endl<<orgd<<endl<<pat[i]<<endl<<eloe;
    
    plcbo.admit(pat[i], eloe);
    cout<<endl<<plcbo<<endl<<pat[i]<<endl<<eloe;

    pharm.admit(pat[i], eloe);
    cout<<endl<<pharm<<endl<<pat[i]<<endl<<eloe;

    lipo.admit(pat[i], eloe);
    cout<<endl<<lipo<<endl<<pat[i]<<endl<<eloe;

    x_ray.admit(pat[i], eloe);
    cout<<endl<<x_ray<<endl<<pat[i]<<endl<<eloe;
  }
  cout<<endl;
  
  for(int j = 0; j < 79; j++)
  {
    cout<<"=";
  }
  
  cout<<endl<<"Final Results:"<<endl;
  cout<<eloe;
  for(int k = 0; k < NUM_PATS; k++)
  {
    cout<<pat[k]<<endl<<endl;
  }
  
  cout<<endl<<endl;
  
  return 0;
}
