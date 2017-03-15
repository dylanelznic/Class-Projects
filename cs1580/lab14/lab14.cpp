//Programmer: Dylan Elznic   Section: C
//File: lab14.cpp
//Description: This program creates an array class template with constructrs
//             and overloaded operators.

#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class Array_Class
{
  private:
    T m[4];
  
  public:
    
    //Constructor for individual inputs
    Array_Class(T m_0, T m_1, T m_2, T m_3)
    {
      m[0] = m_0;
      m[1] = m_1;
      m[2] = m_2;
      m[3] = m_3;
    }
    
    //Constructor for full array inputs
    Array_Class(T _m[])
    {
      for(int i = 0; i < 4; i++)
      {
        m[i] = _m[i];
      }
    }
    
    //Defaults constructor, sets all values to 0
    Array_Class()
    {
      for(int i = 0; i < 4; i++)
      {
        m[i] = 0;
      }
    }
   
    //Description: *= operator multiplies each value in one array
    //             to its corresponding value in a second array 
    //Pre: Must have two full Array_Class objects
    //Post: Returns an Array_Class object 
    Array_Class operator *=(const Array_Class & array)
    {
      for(int i = 0; i < 4; i++)
      {
        m[i]*= array.m[i];
      }
      return *this;
    }
    
    //Description: + operators adds each value in one array
    //             to its corresponding value in a second array
    //Pre: Must have two full Array_Class objects
    //Post: Returns an Array_Class object
    friend Array_Class <T> & operator+ (const Array_Class <T> & array1, 
                                       const Array_Class <T> & array2)
    {
      Array_Class<T> ans;
      for(int i = 0; i < 4; i++)
      {
        ans.m[i]=array1.m[i]+array2.m[i];
      }
      return ans;
    }
    
    //Description: Prints each value in an Array_Class object
    //Pre: Must have a full Array_Class object
    //Post: Prints out an organized output of an Array_Class object
    friend ostream & operator<<(ostream & out, const Array_Class<T> & array)
    {
      out<<"["<<array.m[0]<<","<<array.m[1]<<","<<array.m[2]<<","
         <<array.m[3]<<"]";
      return out;
    }
 }; 
    
int main()
{
  int arr[4] = {3,2,3,5};
      
  Array_Class<int>A(1,2,3,4);
  Array_Class<int>B(arr);
  Array_Class<int>C;
  cout<<"A: "<<A<<endl<<"B: "<<B<<endl<<"C: "<<C<<endl;
  B*=A;
  C=A+B;
  cout<<endl<<"A: "<<A<<endl<<"B: "<<B<<endl<<"C: "<<C<<endl;
      
  return 0;
}
