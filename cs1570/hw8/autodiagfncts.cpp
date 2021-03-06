//Programmers: Ryan Stoughton & Dylan Elznic //Section: A
//File: autodiagfncts.cpp
//Description: Function file for autodiag.cpp

#include "autodiag.h"
#include <iostream>
#include <string.h>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>

using namespace std;

void greeting()
{
  cout<<endl<<endl
      <<" ~^*^~ Dr. Eloe's Health-o-Matic ~^*^~ "
      <<endl<<endl;
      
  return;  
}  
  
void readComplaint(string & complaint)
{
  cout<<"What is your issue: ";
  getline(cin, complaint);  
  
  return;
}

int getLength(const string complaint)
{
  return strlen(complaint.c_str());
}

void getWords(const string complaint, const int numChars, 
              int & numWords)
{
  for(int i = 0; i < numChars; i++)
  {
    if(complaint.c_str()[i] == ' ')
      numWords++;
  }

  return;
}

void sortWords(const string complaint, string complaintWords[], 
               const int numWords)
{

  for(int j = 0; j < MAX_WORDS; j++)
  {
    complaintWords[j] = "\0";
  }
          
  istringstream is(complaint);
  for(int i = 0; i < numWords; i++)
  {
    is>>complaintWords[i];
  }

  return;
}

void keywordSearch(const char complaintChars[], const int numChars,
                   bool & is_head, bool & is_torso, bool & is_hand,
                   bool & is_nose, bool & is_leg)
{
    int i = 0;
    while(i<numChars - KWL_HEAD)
    {
      if((complaintChars[i] == 'h' || complaintChars[i] == 'H') &&
         complaintChars[i+1] == 'e' && complaintChars[i+2] == 'a' &&
         complaintChars[i+3] == 'd')
         {
           is_head = true;
         }
      i++;
    }
    i= 0;
    while(i<numChars - KWL_TORSO)
    {
      if((complaintChars[i] == 't' || complaintChars[i] == 'T') &&
         complaintChars[i+1] == 'o' && complaintChars[i+2] == 'r' &&
         complaintChars[i+3] == 's' && complaintChars[i+4] == 'o')
         {
           is_torso = true;
         }
      i++;
    }
    i = 0;
    while(i<numChars - KWL_HAND)
    {
      if((complaintChars[i] == 'h' || complaintChars[i] == 'H') && 
         complaintChars[i+1] == 'a' && complaintChars[i+2] == 'n' &&
         complaintChars[i+3] == 'd')
         {
           is_hand = true;
         }
      i++;
    }
    i = 0;
    while(i<numChars - KWL_NOSE)
    {
      if((complaintChars[i] == 'n' || complaintChars[i] == 'N') &&
         complaintChars[i+1] == 'o' && complaintChars[i+2] == 's' &&
         complaintChars[i+3] == 'e')
         {
           is_nose = true;
         }
      i++;
    }
    i = 0;
    while(i<numChars - KWL_LEG)
    {
      if((complaintChars[i] == 'l' || complaintChars[i] == 'L') &&
         complaintChars[i+1] == 'e' && complaintChars[i+2] == 'g')
         {
           is_leg = true;
         }
      i++;    
    }
    
  return;
}

void headDiag(ifstream & in)
{
  int headLength;
  string next_prog;
        
  in.open("Head.dat");
          
  in>>headLength;
              
  int randLimit = rand()%(headLength)+1;
                
  for(int i = 0; i < randLimit; i++)
  {
    getline(in,next_prog);
  }
  string randDiag = next_prog;
  cout<<" It is clear you have "<<randDiag<<"."<<endl;
  in.seekg(0);                            
  in.close();
                                
  return;
}
                                  
void torsoDiag(ifstream & in)
{
  int torsoLength;
  string next_prog;
  
  in.open("Torso.dat");

  in>>torsoLength;
  
  int randLimit = rand()%(torsoLength)+1;
  
  for(int i = 0; i < randLimit; i++)
  {
    getline(in,next_prog);
  }
  
  string randDiag = next_prog;
  cout<<" It is clear you have "<<randDiag<<"."<<endl;
  in.seekg(0);
  in.close();
    
  return;
}

void handDiag(ifstream & in)
{
  int handLength;
  string next_prog;

  in.open("Hand.dat");

  in>>handLength;

  int randLimit = rand()%(handLength)+1;

  for(int i = 0; i < randLimit; i++)
  {
    getline(in,next_prog);
  }

  string randDiag = next_prog;
  cout<<" It is clear you have "<<randDiag<<"."<<endl;
  in.seekg(0);
  in.close();

  return;
}

void noseDiag(ifstream & in)
{
  int noseLength;
  string next_prog;

  in.open("Nose.dat");

  in>>noseLength;

  int randLimit = rand()%(noseLength)+1;
  for(int i = 0; i < randLimit; i++)
  {
    getline(in,next_prog);
  }

  string randDiag = next_prog;
  cout<<" It is clear you have "<<randDiag<<"."<<endl;
  in.seekg(0);
  in.close();

  return;
}

void legDiag(ifstream & in)
{
  int legLength;
  string next_prog;

  in.open("Leg.dat");

  in>>legLength;

  int randLimit = rand()%(legLength)+1;

  for(int i = 0; i < randLimit; i++)
  {
    getline(in,next_prog);
  }

  string randDiag = next_prog;
  cout<<" It is clear you have "<<randDiag<<"."<<endl;
  in.seekg(0);
  in.close();

  return;
}

void wordFeedback(const string complaintWords[], const int numWords)
{
  cout<<endl<<"So,";
  for(int i = 0; i < NUM_FEED; i++)
  {
    cout<<" "<<complaintWords[rand()%((numWords/2)+1)];
  }  
  cout<<"?";
  
  return;
}

void pillPerscription(const int numWords)
{
  cout<<endl
      <<"Your perscription is to take "<<numWords<<" pill(s) a"
      <<" day of 20 mg. ";

  return;
}

void scriptDiag(ifstream & in)
{
  int scriptLength;
  string next_prog;
  
  in.open("Scripts.dat");
  
  in>>scriptLength;
  
  for(int i = 0; i < NUM_SCRIPT; i++)
  {
    int randLimit = rand()%(scriptLength);

    for(int j = 0; j < randLimit; j++)
    {
      getline(in,next_prog);
    }
  
    string randDiag = next_prog;
    
    while(i == 0)
    {
      randDiag = randDiag.c_str();
      randDiag[0] = toupper(randDiag[0]);
      break;
    }
    
    in.seekg(0);      
    cout<<randDiag;
  }
  in.close();
  cout<<".";

  return;
}

void getSurgery(ifstream & in)
{
  string surgery;
  int numSurgeries = 0;
  int do_surgery = rand()%SURGERY_CHANCE;
  if(do_surgery < SURGERY_MAX)
  {
    do
    {
      in.clear();
      in.open("Surgeries.dat"); 
    }while(!in);
    
    in>>numSurgeries;
    int randMax = rand()%(numSurgeries+1);
    for(int i = 0; i < randMax; i++)
    {
      getline(in, surgery);
    }
    cout<<endl<<endl
    <<"I also suggest undergoing a(n) "<<surgery<<" operation.";
    }
 
  return;
}

void closing()
{
  cout<<"Thank you for visiting!"
      <<endl<<endl;
              
  return;
}
                
