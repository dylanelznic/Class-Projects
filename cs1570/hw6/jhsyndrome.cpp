//Programmer: Dylan Elznic     Section: A
//File: jhsyndrome.cpp
//Description: Scans patient's protein levels using and determines whether they
//             possess Jejunal Hemorrage Syndrome or not.
//             This is the main file containing the process.

#include "jhsyndrome.h"
#include <iostream>
using namespace std;

int main()
{
  //Variables
  string patname;
  int quit = 0;
  char terminate;
  
  int   p1 = 0;
  float p2 = 0;
  int   p3 = 0;
  int   p4 = 0;
  int   p5 = 0;  

  protein pro1;
  int audiolevel = 0;

  //Interface
  greet();
  
  //Loop Start
  quit = false;
  while(quit == false)
  {
    patname = getPat();
    
    ringFlatA(p1, p2, p3);         //p1, p2, p3 (legs)
    audiolevel = soundtest();
    if(audiolevel != 0)
    {
      cout<<endl<<"Current Protein Levels"<<endl;
      cout<<"Protein 1: "<<p1<<endl;
      cout<<"Protein 2: "<<p2<<endl;
      cout<<"Protein 3: "<<p3<<endl;
      
      ringMiddleG(p2, p4);         //p3, p4 (antennae)
      audiolevel = soundtest();
      if(audiolevel != 0)
      {
        cout<<endl<<"Current Protein Levels"<<endl;
        cout<<"Protein 2: "<<p2<<endl;
        cout<<"Protein 4: "<<p4<<endl;
  
        ringFlatC(p1, p4, p5);     //p1, p4, p5 (head)
        if(audiolevel != 0)
        {
          cout<<endl<<"Current Protein Levels"<<endl;
          cout<<"Protein 1: "<<p1<<endl;
          cout<<"Protein 4: "<<p4<<endl;
          cout<<"Protein 5: "<<p5<<endl;
          
          pro1.m_pro1 = p1;
          pro1.m_pro2 = p2;
          pro1.m_pro3 = p3;
          pro1.m_pro4 = p4;
          pro1.m_pro5 = p5;
          JHSynDiag(pro1, patname);
        }
        else
          cout<<"Error: Insufficient Data";
      }
      else
        cout<<"Error: Insufficient Data";
    }
    else
      cout<<"Error: Insufficient Data";
      
    cout<<endl<<endl;
    
    do
    {
      cout<<"Continue to next patient?(y/n): ";
      cin>>terminate;
      
      if(terminate == 'n' || terminate == 'N')
      {
        quit = true;
      }
    }while(terminate != 'n' && terminate != 'N' 
           && terminate != 'y' && terminate != 'Y');  
  
  }        
  
  return 0;
}
