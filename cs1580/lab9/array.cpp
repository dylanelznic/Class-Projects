//Programmer: Dylan Elznic     Section: C
//File: array.cpp
//Description: Determines the highest and lowest grades among three students
//             for three courses.

#include "array.h"
#include <iostream>
using namespace std;

int main()
{
  //Variables
  int current_course = 0;
  int index = 0;
  student students[size];
  
  //Process
  read_in(students, size);
  cout<<endl;
   
  for(int i = 0; i < course_number; i++)
  { 
    current_course = i;
  
    index = max_index(students, size, current_course); 
    cout<<students[index].name<<" has the highest grade in course #"
        <<(i+1)<<" which is: "<<students[index].grades[current_course]
        <<endl;
    
    index = min_index(students, size, current_course);
    cout<<students[index].name<<" has the lowest grade in course #"
        <<(i+1)<<" which is: "<<students[index].grades[current_course]
        <<endl<<endl;
  }               
    
  return 0;
}
