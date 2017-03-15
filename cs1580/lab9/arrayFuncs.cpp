//Programmer: Dylan Elznic     Section: C
//File: arrayFuncs.cpp
//Description: Contains the functions for array.cpp
    
#include "array.h"
#include <iostream>
using namespace std;
    
void read_in(student students[], const int size)
{  
  for(int i = 0; i < size; i++)
  {
    cout<<endl<<"Please enter students name: ";
    cin>>students[i].name;
    
    for(int j = 0; j < size; j++)
    {
      cout<<"Enter student "<<(i+1)<<"'s grade for course #"<<(j+1)<<": ";
      cin>>students[i].grades[j];
    }
  }
  return;
}

int max_index(student students[], const int size, const int current_course)
{
  int max = students[0].grades[current_course];
  int index = 0;
  for(int i = 0; i < size; i++)
  {
    if(students[i].grades[current_course] > max)
    {
      max = students[i].grades[current_course];
      index = i;
    }
  }
  
  return index;
}

int min_index(student students[], const int size, const int current_course)
{
  int min = students[0].grades[current_course];
  int index = 0;
  for(int i = 0; i < size; i++)
  {
    if(students[i].grades[current_course] < min)
    {
      min = students[i].grades[current_course];
      index = i;
    }
  }
 
  return index;
} 
