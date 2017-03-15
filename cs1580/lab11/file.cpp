//Programmer: Dylan Elznic     Section: C
//File: file.cpp
//Description: Reads a data file and outputs first name, last name, 
//             and generates a user id for each input

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
  //Variables
  ifstream in;
  ofstream out;

  string first_name;
  string last_name;
  char first_temp[10];
  char last_temp[10];
  char user_id[20];
  
  //Opens input and output files
  in.open("input.txt");
  out.open("output.txt");
  
  //Value Transfer
  while(in>>first_name)
  {  
    out<<first_name<<" ";
    strcpy(first_temp, first_name.c_str()); //Saves first_name value to a cstring
    
    in>>last_name;
    strcpy(last_temp, last_name.c_str()); //Saves last_name value to a cstring
    out<<last_name<<" ";
    
    int i = 0;
    while(i < 10)
    {
      if(first_temp[i] == 'e')
        first_temp[i] = 'X';
      if(last_temp[i] == 'e')
        last_temp[i] = 'X';
      i++;
    }
    
    int last_char = strlen(last_temp);

    last_temp[last_char] = '_';
    last_temp[last_char+1] = NULL;

    first_temp[0] = toupper(first_temp[0]);
    last_temp[0] = toupper(last_temp[0]);

    strcpy(user_id, last_temp);
    strcat(user_id, first_temp);
  
    out<<user_id<<endl;
   }
  
  //Closes input and output files
  in.close();
  out.close();


  return 0;
}
