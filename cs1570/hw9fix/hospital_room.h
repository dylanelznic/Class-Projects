//Programmer: Dylan Elznic / Ryan Stoughton   Section: A
//File: hospital_room.h
//Description: Contains the hospital_room class and it's respective
//             function prototypes

#ifndef HOSPITAL_ROOM_H
#define HOSPITAL_ROOM_H

#include "x_rayer.h"
#include "doctor.h"

#include <fstream>
#include <iostream>
using namespace std;

class patient;

const float DEFAULT_SCHRAUT = 10.0;

const short MAX_SCHRAUT = 3;
const short MIN_SCHRAUT = 1;

const int EAT_NUM = 5;

/* 

  >hospital_room()
   Description: Deafault constructor for hospital_room class. Sets Schraut!
                to DEFAULT_SCHRAUT
   Pre: n/a
   Post: m_schraut is set to DEFAULT_SCHRAUT
   
  >void admit()
   Description: The calling object is passed to charge_patient() and apply()
   Pre: The passed object must already be declared
   Post: The passed object is pased to charge_patient() and apply()
   
  >ostream& operator<<()
   Description: Allows hospital_room class to be printed in a clean format
   Pre: Calling object must already be declared
   Post: hospital_room is printed on the screen
  
  >float get_schraut()
   Description: Returns m_schraut left
   Pre: n/a
   Post: The Calling object's m_schraut is returned

*/

template <class T_machine>
class hospital_room
{
  public:
    hospital_room(): m_schraut(DEFAULT_SCHRAUT){}
    void admit(patient & pat, doctor & doc);

    //print
    template <class U> 
    friend ostream& operator<<(ostream& stream, const hospital_room<U>& room);
    
  private:
    T_machine m_the_machine; //Default x_rayer object
    float   m_schraut;     //Schraut left

};

#include "hospital_room.hpp"

#endif
