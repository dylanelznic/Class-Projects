//Programmer: Dylan Elznic

#ifndef X_RAYER_H
#define X_RAYER_H

#include <iostream>
using namespace std;

class patient;

class x_rayer
{
  public:
    x_rayer(): m_num_uses(0), m_cost_per_use(500){}
    void  charge_patient(patient & pat);
    void  apply(patient & pat);
    
    float getCost()   {return m_cost_per_use;};
    short getNumUse() {return m_num_uses;};
    void  setCost(const int cost);
    void  setNumUse(const int numUses); 
      
  private:
    float m_cost_per_use;  //Cost per use of the x-ray
    short m_num_uses;      //Number of uses of the x-ray
};

#endif
