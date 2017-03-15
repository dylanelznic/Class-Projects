//Programmer: Dylan Elznic   Section: C
//File: time.h
//Description: Header file for time.cpp

#ifndef TIME_H
#define TIME_H

const int MAX_HR_IN = 12;
const int MAX_MIN_IN = 59;
const int MAX_SEC_IN = 59;

const int TRANSSEC = 60;
const int TRANSMIN = 60;
const int TRANSHR = 13;

const int FRSHSEC = 0;
const int FRSHMIN = 0;
const int FRSHHR = 1;

  /* Class Description */
//This class contains the hour, minute, and second values 
//to fill out a timestamp. 

  /* void read_in() */
//Description: Reads in user inputted hours, minutes, and seconds,
//             and assigns them to private variables
//pre: n/a
//post: Assigns the user inputted values to the private
//      class variables

  /*  void print_out() */
//Description: Prints out the private variables as a timestamp.
//pre: Must have assigned privated variables
//post: Prints out a timestamp using the private variables

  /* void nextSecond(); */
//Description: Prints out a timestamp that is one second later
//             than print_out()'s timestamp
//pre: Must have assigned private variables
//post: Prints out a timestamp using the private variables, but one
//      second later

class Time
{
  public:
    void read_in();
    void print_out();
    void nextSecond();
  
  private:
    int m_hour;
    int m_minute;
    int m_second;
};

#endif
