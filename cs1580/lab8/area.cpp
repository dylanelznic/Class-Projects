//Programmer: Dylan Elznic     Section: C
//File: area.cpp
//Description:

#include "area.h"
#include <iostream>
using namespace std;

int main()
{
  /*-----Variables-----*/
  polygon shape;
  circle circ;
  rectangle rect;
  
  float areaTri = 0;
  float areaDia = 0;
  float areaCirc = 0;
  float areaRect = 0; 

  /*-----Interface-----*/
  greet();

  cout<<"Enter the Base of a Triangle: ";
  shape.base = read();
  cout<<"Enter the Height of a Triangle: ";
  shape.height = read();
  areaTri = area(shape);
  cout<<endl;
  
  cout<<"Enter the Base of a Diamond: ";
  shape.base = read();
  cout<<"Enter the Height of a Diamond: ";
  shape.height = read();
  areaDia = area(shape);
  cout<<endl; 
    
  cout<<"Enter the Height of a Rectangle: ";
  rect.height = read();
  cout<<"Enter the Width of a Rectangle: ";
  rect.width = read();
  areaRect = area(rect); 
  cout<<endl;

  cout<<"Enter the Radius of a Cricle: ";
  circ.radius = read();
  areaCirc = area(circ);
  cout<<endl;
  
  cout<<"Area of a Triangle is: " <<areaTri<<endl
      <<"Area of a Diamond is: "  <<areaDia<<endl
      <<"Area of a Rectangle is: "<<areaRect<<endl
      <<"Area of a Circle is: "   <<areaCirc<<endl;

  signoff();

  return 0;
}
