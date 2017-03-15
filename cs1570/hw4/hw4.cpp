//Programmer: Dylan Elznic  Date: 9/22/2014
//File: hw4.cpp             Class: cs1570    Section: A
//Purpose: Dispenses medicine according to operator's choice, and prompts
//         for payment.

#include <iostream>
using namespace std;

int main()
{
  /*-----Variables-----*/
  const float NAPROSYN_PRC = 10.00;
  const float KRYSTEXXA_PRC = 3.50;
  const float SCHRAUT_PRC = 4.00;
  const float XELJANZ_PRC = 6.75;
  const float QNASAL_PRC = 12.25;
  const float GOLYTELY_PRC = 14.33;
  
  const int NAPROSYN_PILLS = 15;
  const int KRYSTEXXA_PILLS = 30;
  const int SCHRAUT_PILLS = 20;
  const int XELJANZ_PILLS = 5;
  const int QNASAL_PILLS = 40;
  const int GOLYTELY_PILLS = 1;
  
  bool quit = false;
  
  int choice = 0;
  float payment = 0;
  
  int pillcount = 0;
  int pillcase = 0;

  /*-----Magic Code----*/
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  /*--------Menu-------*/
  do
  {
    cout<<endl<<endl
        <<"     INSTY-MEDS" <<endl
        <<"     ----------" <<endl
        <<"  1. Naprosyn            $10.00    " 
          "(pain relief)"   <<endl
        <<"  2. Krystexxa           $3.50     "  
          "(relief from gout - I think)" <<endl
        <<"  3. Schraut!            $4.00     "      
          "(for relief from diarrhea)"   <<endl
        <<"  4. Xeljanz             $6.75     " 
          "(relief from Hippopotomonstrosesquipedaliophobia)" <<endl
        <<"  5. Qnasl Dipropionate  $12.25    "
          "(for the treatment of nasally fitted Q-tips)" <<endl
        <<"  6. GoLytely            $14.33    "
          "(to treat gluttony)" <<endl
        <<"  7. Quit"
        <<"\n\nPlease enter your choice: ";
    cin>>choice;
    cout<<endl;
    
  /*-----Outputs-------*/
    switch (choice)
    {
      //Naprosyn
      case(1):
        cout<<"You have chosen to purchase "<<NAPROSYN_PILLS<<
              " pill(s) of Naprosyn.";
              
        pillcount=NAPROSYN_PILLS;
        if(pillcount<10)
          pillcase=10;
        else if(pillcount<25)
          pillcase=25;
        else if(pillcount<50)
          pillcase=50;
        else
          pillcase=100;
              
        cout<<"\nPlease have a "<<pillcase<<
              " count pill case ready."
              "\n\nYour total is $"<<NAPROSYN_PRC<<". Please enter payment: $";
        cin>>payment;
        cout<<endl;
        while(payment<NAPROSYN_PRC)
        {  
          cout<<"Error: Insufficient payment."
              <<"\nPlease enter payment: $";
          cin>>payment;
          cout<<endl;
        }
        if(payment==NAPROSYN_PRC)
        { 
          cout<<"Transaction completed." 
              <<"\nThank you for shopping at Insty-Meds!";
        }
        else
        { 
          cout<<"Your change is $"<<(payment-NAPROSYN_PRC)
              <<". Transaction completed."
              <<"\nThank you for shopping at Insty-Meds!";
        }
        break;
      
      //Krystexxa
      case(2):
        cout<<"You have chosen to purchase "<<KRYSTEXXA_PILLS<<
              " pill(s) of Krystexxa.";
              
        pillcount=KRYSTEXXA_PILLS;
        if(pillcount<10)
          pillcase=10;
        else if(pillcount<25)
          pillcase=25;
        else if(pillcount<50)
          pillcase=50;
        else
          pillcase=100;
        
        cout<<"\nPlease have a "<<pillcase<<
              " count pill case ready."
              "\n\nYour total is $"<<KRYSTEXXA_PRC<<". Please enter payment: $";
        cin>>payment;
        cout<<endl;
        while(payment<KRYSTEXXA_PRC)
        {
          cout<<"Error: Insufficient payment."
              <<"\nPlease enter payment: $";
          cin>>payment;
          cout<<endl;
        }
        if(payment==KRYSTEXXA_PRC)
        {
          cout<<"Transaction completed."
              <<"\nThank you for shopping at Insty-Meds!";
        }
        else
        {
          cout<<"Your change is $"<<(payment-KRYSTEXXA_PRC)
              <<". Transaction completed."
              <<"\nThank you for shopping at Insty-Meds!";
        }
        break;
      
      
      //Schraut!
      case(3):
        cout<<"You have chosen to purchase "<<SCHRAUT_PILLS<<
              " pill(s) of Schraut!.";
              
        pillcount=SCHRAUT_PILLS;
        if(pillcount<10)
          pillcase=10;
        else if(pillcount<25)
          pillcase=25;
        else if(pillcount<50)
          pillcase=50;
        else
          pillcase=100;
              
        cout<<"\nPlease have a "<<pillcase<<
              " count pill case ready."
              "\n\nYour total is $"<<SCHRAUT_PRC<<". Please enter payment: $";
        cin>>payment;
        cout<<endl;
        while(payment<SCHRAUT_PRC)
        {
          cout<<"Error: Insufficient payment."
              <<"\nPlease enter payment: $";
          cin>>payment;
          cout<<endl;
        }
        if(payment==SCHRAUT_PRC)
        {
          cout<<"Transaction completed."
              <<"\nThank you for shopping at Insty-Meds!";
        }
        else
        {
          cout<<"Your change is $"<<(payment-SCHRAUT_PRC)
              <<". Transaction completed."
              <<"\nThank you for shopping at Insty-Meds!";
        }
        break;
      
      //Xeljanz
      case(4):
        cout<<"You have chosen to purchase "<<XELJANZ_PILLS<<
              " pill(s) of Xeljanz."
              "\nYour purchase comes with "<<QNASAL_PILLS<<
              " complementary pill(s) of Xeljanz, and "<<GOLYTELY_PILLS<<
              " complementary pill(s) of GoLytely!";
             
        pillcount=XELJANZ_PILLS+QNASAL_PILLS+GOLYTELY_PILLS;
        if(pillcount<10)
          pillcase=10;
        else if(pillcount<25)
          pillcase=25;
        else if(pillcount<50)
          pillcase=50;
        else
          pillcase=100;
              
        cout<<"\nPlease have a "<<pillcase<<
              " count pill case ready."
              "\n\nYour total is $"<<XELJANZ_PRC<<". Please enter payment: $";
        cin>>payment;
        cout<<endl;
        while(payment<XELJANZ_PRC)
        {
          cout<<"Error: Insufficient payment."
              <<"\nPlease enter payment: $";
          cin>>payment;
          cout<<endl;
        }
        if(payment==XELJANZ_PRC)
        {
          cout<<"Transaction completed."
              <<"\nThank you for shopping at Insty-Meds!";
        }
        else
        {
          cout<<"Your change is $"<<(payment-XELJANZ_PRC)
              <<". Transaction completed."
              <<"\nThank you for shopping at Insty-Meds!";
        }
        break;
      
      //Qnasal Dipropionate
      case(5):
        cout<<"You have chosen to purchase "<<QNASAL_PILLS<<
              " pill(s) of Qnasal Dipropionate."
              "\nYour purchase comes with "<<GOLYTELY_PILLS<<
              " complementary pill(s) of GoLytely!";
              
        pillcount=QNASAL_PILLS+GOLYTELY_PILLS;
        if(pillcount<10)
          pillcase=10;
        else if(pillcount<25)
          pillcase=25;
        else if(pillcount<50)
          pillcase=50;
        else
          pillcase=100;
                
        cout<<"\nPlease have a "<<pillcase<<
              " count pill case ready."
              "\n\nYour total is $"<<QNASAL_PRC<<". Please enter payment: $";
        cin>>payment;
        cout<<endl;
        while(payment<QNASAL_PRC)
        {
          cout<<"Error: Insufficient payment."
              <<"\nPlease enter payment: $";
          cin>>payment;
          cout<<endl;
        }
        if(payment==QNASAL_PRC)
        {
          cout<<"Transaction completed."
              <<"\nThank you for shopping at Insty-Meds!";
        }
        else
        {
          cout<<"Your change is $"<<(payment-QNASAL_PRC)
              <<". Transaction completed."
              <<"\nThank you for shopping at Insty-Meds!";
        }
        break;
      
      //GoLytely        
      case(6):
        cout<<"You have chosen to purchase "<<GOLYTELY_PILLS<<
              " pill(s) of GoLytely.";
              
        pillcount=GOLYTELY_PILLS;
        if(pillcount<10)
          pillcase=10;
        else if(pillcount<25)
          pillcase=25;
        else if(pillcount<50)
          pillcase=50;
        else
          pillcase=100;
        
        cout<<"\nPlease have a "<<pillcase<<
              " count pill case ready."
              "\n\nYour total is $"<<GOLYTELY_PRC<<". Please enter payment: $";
        cin>>payment;
        cout<<endl;
        while(payment<GOLYTELY_PRC)
        {
          cout<<"Error: Insufficient payment."
              <<"\nPlease enter payment: $";
          cin>>payment;
          cout<<endl;
        }
        if(payment==GOLYTELY_PRC)
        {
          cout<<"Transaction completed."
              <<"\nThank you for shopping at Insty-Meds!";
        }
        else
        {
          cout<<"Your change is $"<<(payment-GOLYTELY_PRC)
              <<". Transaction completed."
              <<"\nThank you for shopping at Insty-Meds!";
        }
        break;
        
      case(7):
        quit = true;
        break;
    
      default:
        cout<<"Error: Not a valid choice."<<endl;
        break;
    }   
  
  }while(!quit);

   return 0;
  
}                                                                                                              
