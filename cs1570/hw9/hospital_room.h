//Programmer: Dylan Elznic

#include "x_rayer.h"
#include <iostream>
using namespace std;

class hospital_room
{
  public:
    hospital_room(const float numSchraut);
    void admit();
    
  private:  
    x_rayer m_the_machine();  //The x-ray machine
    float m_numSchraut;       //Number of oz of Schraut in each room
};
