//Programmers: Ryan Stoughton & Dylan Elznic //Section: A
//File: autodiag.h
//Description: Header file for autodiag.cpp

#ifndef AUTODIAG_H
#define AUTODIAG_H

#include <iostream>
#include <sstream>
using namespace std;

const int MAX_WORDS = 100;
const int MAX_CHARS = 2000;
const int SURGERY_MAX = 75;
const int SURGERY_CHANCE = 101;

const int KWL_HEAD = 3;
const int KWL_TORSO = 4;
const int KWL_HAND = 3;
const int KWL_NOSE = 3;
const int KWL_LEG = 2;

const int NUM_FEED = 5;
const int NUM_SCRIPT = 4;

//Pre: n/a
//Post: Prints a greeting message on the screen
//Description: Prints a greeting message on the screen
void greeting();

//Pre: Must be no longer than 2000 characters and 100 words.
//     Words must be no more than 20 characters a piece.
//Post: Stores user complaint in a string
//Description: Reads in the patient's complaint and stores it in a string
void readComplaint(string & complaint);

//Pre: Complaint must be present and have data
//Post: Returns the length of the string
//Description: Returns the string length of the patient's complaint
int getLength(const string complaint);

//Pre: Complaint must be present and have data
//Post: Returns the number of words in the string
//Description: Counts the number of words in the patient's complaint
void getWords(const string complaint, const int numChars, int & numWords);

//Pre: Complaint must be present and have data
//Post: Stores each word as a separate array value in complaintWords
//Description: Separates the complaint into single word string values 
//             in an array
void sortWords(const string complaint, string complaintWords[],
               const int numChars);

//Pre: ComplaintChars must be present and have data
//Post: Determines presence of keywords through booleans
//Description: Searches the che complaint for the list of keywords
void keywordSearch(const char complaintChars[], const int numChars,
                   bool & is_head, bool & is_torso, bool & is_hand,
                   bool & is_nose, bool & is_leg);

//Pre: is_head == true
//Post: Returns a random prognosis for a head injury
//Description: Returns a random prognosis for a head injury
void headDiag(ifstream & in);

//Pre: is_torso == true
//Post: Returns a random prognosis for a torso injury
//Description: Returns a random prognosis for a torso injury
void torsoDiag(ifstream & in);

//Pre: is_hand == true
//Post: Returns a random prognosis for a hand injury
//Description: Returns a random prognosis for a hand injury
void handDiag(ifstream & in);

//Pre: is_nose == true
//Post: Returns a random prognosis for a nose injury
//Description: Returns a random prognosis for a nose injury
void noseDiag(ifstream & in);

//Pre: is_leg == true
//Post: Returns a random prognosis for a leg injury 
//Description:  Returns a random prognosis for a leg injury
void legDiag(ifstream & in);

//Pre: complaintWords must be present
//Post: Prints 5 random words as a sentence
//Description: Returns 5 random words to simulate attentiveness of the doctor
void wordFeedback(const string complaintWords[], const int numWords);

//Pre: numWords must be present
//Post: Returns the numWords as the number of pills perscribed
//Description: Returns the amount of pills perscribed to the patient
void pillPerscription(const int numWords);

//Pre: n/a
//Post: Prints 4 random prefixes as a single pill name
//Description: Connects 4 random prefixes to form the name of a pill
void scriptDiag(ifstream & in);

//Pre: n/a
//Post: Prints a random surgery 75% of the time
//Description: Returns a 75% chance of a random surgery
void getSurgery(ifstream & in);

//Pre: n/a
//Post: Prints a closing message on the screen
//Description: Prints a closing message on the screen
void closing();

#endif
