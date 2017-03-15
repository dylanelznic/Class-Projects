//Programmer: Dylan Elznic / Ryan Stoughton   Section: A
//File: doctor.h
//Description: Contains the doctor class, used to administer patients

/*
  >doctor()
   Description: Default constructor
   Pre: none
   Post: m_doc_name addigned passed value, schraut_eaten and doc funds
         assigned constants

  >eat()
   Description: Passes m_schraut value to schraut_eaten
   Pre: none
   Post: m_schraut_eaten is incremented. if CO's m_schraut_eaten >=
         EAT_NUM, puke() is called
      
  >puke()      
   Description: Outputs throw up
   Pre: none
   Post: m_schraut_eaten set to 0, outputs throw up
    
  >getEaten()       
   Description: Accessor
   Pre: none
   Post: CO's m_schraut_eaten returned
    
  >Overloaded << Operator      
   Description: Outputs the doctor class
   Pre: none
   Post: Pre formatted message outputted to screen              

*/

#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
using namespace std;

const short DEF_SCHRAUT = 0;
const float DEF_FUNDS = 0;

const int PUKE = 25;

class doctor
{
  public:
    //Cosntructor
    doctor(const string name):m_doc_name(name),m_schraut_eaten(DEF_SCHRAUT),
                              m_doc_funds(DEF_FUNDS){}
    
    void eat(const short amount);
    void puke();
    void pay(const int money);
    
    //Getter
    short getEaten()const {return m_schraut_eaten;}
    
    //Print
    friend ostream& operator<<(ostream& stream, const doctor & doc);
                                
  private:
    string m_doc_name;      //Doctor's name
    short m_schraut_eaten;  //Amount of Schraut eaten
    float m_doc_funds;      //Amount of doctor's money
    
};

#endif
