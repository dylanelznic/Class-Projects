//Programmer: Dylan Elznic  Section: C
//File: lab5.cpp
//Purpose: Prompts users(10) to vote on their favorite of four laptop brands.
//         The votes are counted, and displayed alongside their percantages.

#include <iostream>
using namespace std;

int main()
{
  /*-----Variables-----*/
  int applevotes = 0;
  int lenovovotes = 0;
  int dellvotes = 0;
  int hpvotes = 0;
  int wastedvotes = 0;
  
  int totalvotes = 0;
  
  float applepercentage = 0;
  float lenovopercentage = 0;
  float dellpercentage = 0;
  float hppercentage = 0;
  float wastedpercentage = 0;
  
  char choice;
  
  /*-----Voting-----*/
  cout<<endl<<endl
      <<"~~~Welcoem to E-Voting System~~~"<<endl<<endl
      <<"Here are Laptop brands:"<<endl
      <<"A: Apple" <<endl
      <<"B: Lenovo"<<endl
      <<"C: Dell"  <<endl
      <<"D: HP"    <<endl<<endl;
  
  for(int i = 1; i <= 10; i++)
  {
    cout<<"What brand of Laptop do you vote for: ";
    cin>>choice;
    switch(choice)
    {
      case 'A':
      case 'a':
        cout<<"You voted for Apple"<<endl;
        applevotes++;
        totalvotes++;
        break;
      case 'B':
      case 'b':
        cout<<"You voted for Lenovo"<<endl;
        lenovovotes++;
        totalvotes++;
        break;
      case 'C':
      case 'c':
        cout<<"You voted for Dell"<<endl;
        dellvotes++;
        totalvotes++;
        break;
      case 'D':
      case 'd':
        cout<<"You voted for HP"<<endl;
        hpvotes++;
        totalvotes++;
        break;
      default:
        cout<<"You wasted your vote"<<endl;
        wastedvotes++;
        totalvotes++;
        break;
    }
  } 
   
  /*-----Percentages-----*/
  applepercentage = static_cast<float>(applevotes)/totalvotes;
  lenovopercentage = static_cast<float>(lenovovotes)/totalvotes;
  dellpercentage = static_cast<float>(dellvotes)/totalvotes;
  hppercentage = static_cast<float>(hpvotes)/totalvotes;
  wastedpercentage = static_cast<float>(wastedvotes)/totalvotes;
  
  /*-----Summary-----*/
  cout<<endl
      <<"*~*Here is the E-Voting Summary*~*"<<endl<<endl
      <<"Laptops        Votes     Percentages(%)"<<endl
      <<"Apple            "<<applevotes <<"           "<<applepercentage<<endl
      <<"Lenovo           "<<lenovovotes<<"           "<<lenovopercentage<<endl
      <<"Dell             "<<dellvotes  <<"           "<<dellpercentage<<endl
      <<"HP               "<<hpvotes    <<"           "<<hppercentage<<endl
      <<"Wasted Votes     "<<wastedvotes<<"           "<<wastedpercentage<<endl<<endl;
  
  cout<<"Thanks for using the E-Voting system"<<endl
      <<"Have a nice day!"<<endl<<endl;
      
  return 0;
}
