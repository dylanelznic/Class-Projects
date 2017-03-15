//Programmer: Dylan Elznic     Section: A
//File: lab10.cpp
//Description: Simulates a user sign-up for an email account.

#include <iostream>
#include <string>
using namespace std;

const int MAX_LENGTH = 16;

struct account
{
  char firstname[MAX_LENGTH];
  char lastname[MAX_LENGTH];
  char username[MAX_LENGTH];
  char password[MAX_LENGTH];
};

//Description: Outputs a greeting message to the user
//Pre: n/a
//Post: Prints greeting text on the screen
void greeting();

//Description: Stores user inputted values in the accoutn struct
//Pre: inputs must be less than MAX_LENGTH
//Post: User struct has stored values for all members
void read_in(account &user);

//Description: Prints user read info
//Pre: User read info must meet read_in conditions
//Post: Prints account information on the screen
void print_out(account &user);

//Description: Prints password as asteriks
//Pre: user.password must have a stored value
//Post: Prints user.password's length in asteriks
void printPassword(char password[]);

//Description: Outputs a signoff message to the user
//Pre: n/a
//Post: Prints thank you text on the screen
void signoff();

int main()
{
  //Variables
  account user;
  
  //Prompt
  greeting();
  
  read_in(user);
  print_out(user);

  signoff();

  return 0;
}

void greeting()
{
  cout<<endl<<endl<<"Welcome! Please enter your information to sign up"
      <<endl<<endl;
  
  return;
}

void read_in(account & user)
{
  char confirm[MAX_LENGTH];
  bool theSame;
  int realCount = 0;
  int confirmCount = 0;

  cout<<"Enter your First Name: ";
  cin.getline(user.firstname,15);
    
  cout<<"Enter your Last Name: ";
  cin.getline(user.lastname,15);  
    
  do
  {
    theSame = true;
    
    cout<<"Enter your Password (7-15 characters): ";
    cin.getline(user.password, 15);
    
    cout<<"Confirm your password: ";
    cin.getline(confirm, 15); 
    
    int i = 0;
    
    while(user.password[i] != '\0')
    {
      realCount++;
      i++;
    }
    i = 0;
    
    while(confirm[i] != '\0')
    {
      confirmCount++;
      i++;
    }
    
    if (realCount != confirmCount)
      theSame = false;
    
    i = 0;
    confirmCount = 0;
    realCount = 0;
    
    while(user.password[i] != '\0')
    {
      if(user.password[i] != confirm[i])
      {
        theSame = false;
      }
      
      i++;
    }
  }while(theSame == false);
    
  return;
}

void print_out(account & user)
{
  cout<<endl
      <<"***********************"<<endl<<endl
      <<"Account Information Summary:"<<endl<<endl
      <<"First Name: "<<user.firstname<<endl
      <<"Last Name: "<<user.lastname<<endl
      <<"User ID: "<<user.lastname<<user.firstname<<endl
      <<"Password: ";
      
  printPassword(user.password);
  cout<<endl<<endl;   
     
  return;
}

void printPassword(char password[])
{
  int i = 0;
  while (password[i] != '\0')
  {
    cout<<"*";
    i++;
  }
  return;
}

void signoff()
{
  cout<<"Thanks!"<<endl<<endl;

  return;
}
