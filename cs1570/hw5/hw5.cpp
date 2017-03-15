

#include <iostream>
using namespace std;

/*-----Prototypes-----*/

void greeting();
//Description: This function prints a greeting message
//Pre: none
//Post: Displays a greeting message

void getBMIValues(int & mass, int & height);
//Description: This function calls for the values of mass and height
//Pre: none
//Post: The values mass and height are sent back to the calling function

void getCreatineValues(int & age, int & weight, float & serum);
//Description:  This function calls for the values of age, weight, and serum
//Pre: none
//Post: The values age, weight, and serum are sent back to the calling function

void getCoronaryValues(float & bMI, char & heartDisease, short & baconlb);
//Description: This function calls for the values of BMI, heart disease, and
//             bacon eaten.
//Pre: none
//Post: The values of BMI, heart disease, and bacon eating are sen back to
//      the calling function

void getTotValues(float & leftlength, float & rightlength);
//Description: This function calls for the values of the left and right leg 
//             lengths
//Pre: none
//Post: The values of leftlength and rightlength are sent back to the calling
//      function

int bodyMassIndex(int & mass, int & height);
//Description: This function alculates the user's BMI
//Pre: Requires  mass and height values
//Post: Displays the user's calculated BMI

float creatineClearance(int & age, int & weight, float & serum);
//Description: This function calculates the user's Creatine Clearance
//Pre: Requires age, weight, and serum values
//Post: Displays the user's calculated Creatine Clearance

float coronaryRisk(float & bMI, char & heartDisease, short & baconlb);
//Description: This function calculates the user's Coronary Risk
//Pre: Requires BMI, heart disease, and bacon/lb values
//Post: Displays the user's calculated Coronary Risk

float totterIndex(float & leftlength, float & rightlength);
//Description: This function calculates the user's Totter Index
//Pre: Requires leftlength and rightlength values
//Post: Displays the user's calculated Totter Index

void goodbye();
//Description: This function prints a goodbye message
//Pre: none
//Post: Displays a goodbye message

void blanklines (const short num_lines);
//Description: This function outputs the specified amount of line breaks
//Pre: none
//Post: Displays the desired amount of blank lines

int main()
{
  /*-----Variables-----*/
  
  int menuChoice = 0;
  bool quit = false;

  int mass = 0;
  int height = 0;
  int age = 0;
  int weight = 0;
  float serum = 0;
  float bMI = 0;
  char heartDisease;
  short baconlb = 0;
  float leftlength = 0;
  float rightlength = 0;
  
  /*-----Menu-----*/

  greeting();  

  do
  {  
    cout<<"   Eloe's Health-o-Matic"  <<endl<<endl
        <<"1. Body Mass Index(BMI)"   <<endl
        <<"2. Creatine Clearance(CC)" <<endl
        <<"3. Coronary Risk(CR)"      <<endl
        <<"4. Totter Index(TI)"       <<endl
        <<"5. Quit"                   <<endl<<endl;
 
    cout<<"Choice: ";
    cin>>menuChoice;
    
    switch(menuChoice)
    {
      case 1:
        getBMIValues(mass,height);
        bodyMassIndex(mass,height);
        blanklines(2);
        break;
    
      case 2:
        getCreatineValues(age,weight,serum);
        creatineClearance(age,weight,serum);
        blanklines(2);
        break;
      
      case 3:
        getCoronaryValues(bMI,heartDisease,baconlb);
        coronaryRisk(bMI,heartDisease,baconlb);
        blanklines(2);
        break;
      
      case 4:
        getTotValues(leftlength,rightlength);
        totterIndex(leftlength,rightlength);
        blanklines(2);
        break;
      
      case 5:
        goodbye();
        quit = true;
        break;
      
      default:
        cout<<endl<<"Error: Invalid choice."<<endl<<endl;
        break;
    }
    
  }while(!quit);  
    
  return 0; 
}

/*-----Definitions-----*/

void greeting()
{
  cout<<endl<<endl<<"Welcome to Dr. Eloe's Health-o-Matic!"<<endl 
      <<"Please select an option to begin diagnosis."<<endl<<endl;
  return; 
}

void getBMIValues(int & mass, int & height)
{
  cout<<endl<<"Please enter your mass(lb): ";
  cin>>mass;

  cout<<"Please enter your height(in): ";
  cin>>height;
        
  return;
}

int bodyMassIndex(int & mass, int & height)
{
  float bodMassIndex = 0;
  bodMassIndex = (static_cast<float>(mass)/(height*height))*703;
  cout<<endl<<"BMI: "<<bodMassIndex<<".";
  return 0;
}

void getCreatineValues(int & age, int & weight, float & serum)
{
  cout<<endl<<"Please enter your age: ";
  cin>>age;

  cout<<"Please enter your weight(kg): ";
  cin>>weight;

  cout<<"Please enter serum value: ";
  cin>>serum;
            
  return;          
}

float creatineClearance(int & age, int & weight, float & serum)
{
  cout<<endl<<"Creatine Clearance: "
            <<static_cast<float>((140-age)*weight)/72*serum<<".";
  return 0;
}

void getCoronaryValues(float & bMI, char & heartDisease, short & baconlb)
{
  cout<<endl<<"Please enter your BMI: ";
  cin>>bMI;
  
  cout<<"Does the patient have heart disease (y/n): ";
  cin>>heartDisease;
    
  cout<<"How many pounds of bacon have they had for breakfast"
      <<" this morning: ";
  cin>>baconlb;
  
  return;
}

float coronaryRisk(float & bMI, char & heartDisease, short & baconlb)
{
  int surveycount = 0;
 
  if(bMI>30)
    surveycount+=2;
  
  if(heartDisease != 'y')
  {
    surveycount+=0;
  }
  else
  {
    surveycount+=1;
  }
  
  surveycount+=baconlb;
  
  cout<<endl<<"Coronary Risk: "<<surveycount<<endl<<endl;
  
  return 0;
}

void getTotValues(float & leftlength, float & rightlength)
{
  cout<<endl<<"Please enter the length of patient's left leg: ";
  cin>>leftlength;

  cout<<"Please enter the length of patient's right leg: ";
  cin>>rightlength;

  return;
}

float totterIndex(float & leftlength, float & rightlength)
{
  float totIndexValue = 0;

  while(leftlength > 0 && rightlength > 0)
  {
    totIndexValue = (leftlength/rightlength);
    break;
  }
  cout<<endl<<"Totter Index: "<<totIndexValue<<"."<<endl<<endl;

  return 0;
}

void goodbye()
{
  cout<<endl<<"Thank you for using Dr. Eloe's Health-o-Matic! Goodbye."
      <<endl<<endl;
  return;
}

void blanklines(const short num_lines)
{
  for(short i = 1; i <= num_lines; i++)
    cout<<endl;
  return;
}
