//Programmer: Dylan Elznic   Section: C
//File: array.h
//Description: Containts the prototypes, consts, and struct for array.cpp

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

const int size = 3;
const int course_number = 3;

struct student
{
  string name;
  int grades[3];
};

void read_in(student students[], const int size);
//Description: Get ALL information for each student as input from user
//Pre: Struct student and size must be declared and positive
//Post: Stores student's names and grades in an array

int max_index(student students[], const int size, const int course_number);
//Description: Calculate the index of student who got the maximum grade
//             in each course
//Pre: Struct student, size, and course_number must be decalred and positive
//Post: Returns the location of the highest grade in selected course

int min_index(student students[], const int size, const int course_number);
//Description: Calculate the index of student who got the minimum grade
//             in each course
//Pre: Struct student, size, and course_number must be declared and positive
//Post: Returns the location of the lowest grade in selected course

#endif
