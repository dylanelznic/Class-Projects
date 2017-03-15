//Programmer: Dylan Elznic     Section: A
//File: jhsyndrome.h
//Description: Header file for jhsyndrome.cpp

#ifndef JHSYNDROME_H
#define JHSYNDROME_H

#include <iostream>
using namespace std;

struct protein
{
  int m_pro1;
  float m_pro2;
  int m_pro3;
  int m_pro4;
  int m_pro5;
};

//Sound Test Constant
const int SOUND_RANGE = 21;

//Protein Ranges
const int P1_RANGE = 101;
const int P2_RANGE = 1000;
const int P3_RANGE = 11;
const int P4_RANGE = 41 + 10;
const int P5_RANGE = 11;

//Disease Conditions 1
const int P1_UPPERLIM = 10;
const int P5_UPPERLIM = 2;
const int P4_LOWERLIM = 20;
const int P4_UPPERLIM = 40;
const int P3_LOWERLIM = 6;

//Disease Conditions 2
const int P5_LOWERLIM = 2;
const int P1P2P3_SUMLIM = 75;

void greet();
//Description: Outputs greeting text to the user.
//Pre: none
//Post: A greeting message is displayed

string getPat();
//Description: Retrieves and returns the patient's name.
//Pre: patname must be declared.
//Post: The patient's name is returned to the main function.

void ringFlatA(int & p1, float & p2, int & p3);
//Description: Generates random values for p1, p2, and p3.
//Pre: p1, p2, and p3 must be positive.
//Post: A unique random value is generated for p1, p2 and p3.

void ringMiddleG(float & p2, int & p4);
//Description: Generates random values for p2, p4.
//Pre: p2 and p4 must be positive.
//Post: A unique random value is generated for p2 and p4.

void ringFlatC(int & p1, int & p4, int & p5);
//Description: Generates random values for p1, p4, and p5.
//Pre: p1, p4, and p5 must be positive.
//Post: A unique random value is generated for p1, p4 and p5.

void jhspostive(string patname);
//Description: Outputs a message confirming the presence of JH syndrome.
//Pre: Positive disease conditions must be satisfied.
//Post: A message is printed stating a confirmation of sickness.

void jhsnegative(string patname);
//Desctiption: Outputs a message denying the presence of JH syndrome.
//Pre: Negative disease conditions must be satisfied.
//Post: A message is printed stating a confirmation of the absence of sickness.

void JHSynDiag(const protein & prot, const string & patname);
//Description: Diagnoses whether the  patient possesses JH Syndrome.
//Pre: patname and the protein struct must be declared. Struct must be positive.
//Post: Outputs the jhpositive or jhnegative function.

int soundtest();
//Description: Accounts for the possible failure of the ring tones.
//Pre: SOUND_RANGE must positive.
//Post: A random %error for the ring tone is created.

#endif
