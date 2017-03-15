//Programmer: Dylan Elznic     Section: A
//File: zombiestudy.h
//Description: Header file for zombiestudy.cpp

#ifndef ZOMBIESTUDY_H
#define ZOMBIESTUDY_H
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

const int SAMPLE_MAX = 5000;
const int SAMPLE_LOWER = 1;
const int DNA_SIZE = 128;

const int G_UPPER = 30;
const int T_UPPER = 53;
const int A_LOWER = 80;

struct person
{
  char dNA[DNA_SIZE];
  string bodyOdor;
  string brainDesire;
  string gait;
};

//Description: Outputs a greeting message
//Pre: n/a
//Post: Prints greeting text on the screen
void greeting();

//Description: Assigns random DNA strand
//Pre: Must have an array smaller than DNA_SIZE
//Post: Returns an array of chars representing DNA
void assignDNA(char dNA[]);

//Description: Assigns random odor state
//Pre: n/a
//Post: Returns a random body odor state
string assignBodyOdor();

//Description: Assigns random brain desire state
//Pre: n/a
//Post: Returns a random brain desire state
string assignBrainDesire();

//Description: Assigns random gait value
//Pre: n/a
//Post: Returns a random gait value
string assignGait();

//Description: Creates a sample group and assigns traits
//Pre:Must have a declared a struct, and a positive dataLength
//Post: Fills each member of the struct array with values
void getPeople(person people[], const int dataLength);

//Description: Gets % of sample that desires brains
//Pre: Must have a filled in sample group
//Post: Passes back the percentage of the sample desiring brains
void brainDesireTest(person people[],const int dataLength, 
                     float & brainDesPercent);                                   

//Description: Gets % of sample that smells SP and rotten
//Pre: Must have a filled in sample group
//Post: Passes back the percentage of the sample that smells SP and rotten
void bodyOdorTest(person people[], const int dataLength, float & smellPercent);

//Description: Gets % of sample that shuffles or crawls
//Pre: Must have a filled in sample group
//Post: Passes back the percentage of the sample that shuffles and crawls
void gaitTest(person people[], const int dataLength, float & gaitPercent);                                    

//Description: Gets % of sample that has all zombie traits
//Pre: Must have a filld in sample group
//Post: Passes back the percentage of the sample that has all zombie traits
void physZombTest(person people[], const int dataLength, 
                  float & physZombPercent);

//Description: Gets % of sample that has GTAC in their DNA
//Pre: Must have a filledin sample group
//Post: Passes back the percentage of the sample that has GTAC in their DNA
void dNAZombTest(person people[], const int dataLength, 
                 float & dNAZombPercent);

//Description: Gets % of sample that has all zombie traits and GTAC in their DNA
//Pre: Must have a filled in sample size
//Post: Passes back the percentage of the sample that has all zombie traits and
//      has GTAC in thier DNA
void combZombTest(person people[], const int dataLength, 
                  float & combZombPercent);

//Description: Outputs a closing message
//Pre: n/a
//Post: Prints closing text on the screen
void closing();

#endif
