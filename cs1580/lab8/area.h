//Programmer: Dylan Elznic     Section: C
//File: area.h
//Description:

#ifndef AREA_H
#define AREA_H

#include <iostream>
using namespace std;

struct polygon
{
  float base;
  float height;
};
        
struct circle
{
  float radius;
};
          
struct rectangle
{
  float height;
  float width;
};

void greet();
//Description: Outputs greeting text to the user.
//Pre: none
//Post: A greeting message is displayed.

float read();
//Description: Ensures that a value is positive.
//Pre: The user must prompt for the data.
//Post: A positive number is returned. 

template <typename T>
float area(const T & shape)
{
  float areaShape = shape.height*shape.base*(0.5);
  return areaShape;
}
//Description: This calculates the area of a given shape.
//Pre: The shape must be a defined type.
//Post: The area is accurately calculated.

float area(const circle & circ);
//Description: This calculates the area of a cicle.
//Pre: The circle must be a defined type.
//Post: The area is accurately calculated.

float area(const rectangle & rect);
//Description: This calculates the area of a rectangle.
//Pre: The rectangle must be a defined type.
//Post: The area is accurately calculated.

void signoff();
//Description: Outputs signoff text to the user.
//Pre: none
//Post: A signoff message is displayed

const float PI = 3.14;

#endif
