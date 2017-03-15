//Programmer: Dylan Elznic   Section: C
//File: timefncts.cpp
//Description: Functions for time.cpp

#include <iostream>
#include "time.h"

using namespace std;

void Time::read_in()
{
  cout<<endl;
  
  do
  {
    cout<<"Enter the hour: ";
    cin>>m_hour;
    if(m_hour > MAX_HR_IN)
      cout<<endl<<"Error!"<<endl<<endl;
  }while(m_hour > MAX_HR_IN);
                  
  do
  {
    cout<<"Enter the minute: ";
    cin>>m_minute;
    if(m_minute > MAX_MIN_IN)
      cout<<endl<<"Error!"<<endl<<endl;
  }while(m_minute > MAX_MIN_IN);
  
  do
  {
    cout<<"Enter the second: ";
    cin>>m_second;
    if(m_second > MAX_SEC_IN)
      cout<<endl<<"Error!"<<endl<<endl;
  }while(m_second > MAX_SEC_IN);

  return;
}                              

void Time::print_out()
{
  cout<<endl<<"Time is: "
      <<m_hour<<":"<<m_minute<<":"<<m_second
      <<endl;
  return;
}

void Time::nextSecond()
{
  m_second = m_second+1;
  
  if(m_second == TRANSSEC)
  {
    m_minute = m_minute+1;
    m_second = FRSHSEC;
  }
  
  if(m_minute == TRANSMIN)
  {
    m_hour = m_hour+1;
    m_minute = FRSHMIN;
  }
  
  if(m_hour == TRANSHR)
  {
    m_hour = FRSHHR;
  }
  
  cout<<"Next Second is: "
      <<m_hour<<":"<<m_minute<<":"<<m_second
      <<endl<<endl;
  return;
}
