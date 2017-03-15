//Programmer: Dylan Elznic

#ifndef PATIENT_H
#define PAITIENT_H

#include <iostream>
using namespace std;

class patient
{
  public:
    patient(const int amntMoney, const int condition, string patName);   
    void pay_out();
    void modify_health();
    void kill();
    
  private:
    float  m_amntMoney;   //Amount of money patient has
    bool   m_is_alive;    //Signifies if dead or not
    string m_patName;     //Patient's name
    int    m_condition;   //Ranks patient's overall health 
                          //  (0 = dead, 100 = perfect health)
};

#endif
