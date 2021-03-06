#include <iostream>
#include <fstream>

using namespace std;

class Rectangle
{
 private:
     int length;
     int width;

 public:
     Rectangle();
     Rectangle(int rect_length, int rect_width);
     
     void operator !();
     Rectangle & operator *= (const Rectangle & rec);

     friend Rectangle operator + (const Rectangle &rec1 , const Rectangle &rec2);
     friend ostream & operator << (ostream & stream, const Rectangle & rec);
};

int main()
{
	Rectangle A(3, 2);
	Rectangle B(9,5);
	Rectangle C;
	cout <<"A: " << A;
	cout <<"B: " << B;
	cout <<"C: " << C;
	C = A + B;
	cout <<"C = A + B ==> C: " << C;
	C *= A;
	cout <<"C *= A    ==> C: " << C;
	!C;
	cout <<"!C        ==> C: " << C;

	return 0;
}
//// here Define your functions

Rectangle::Rectangle() : length(1), width(1) {}

Rectangle::Rectangle(const int rect_length, const int rect_width)
{
  length = rect_length;
  width = rect_width;
}  
  
void Rectangle::operator !()
{
  width -= 2;
  if(width < 2)
    width = 1;
  
  length -= 2;
  if(length < 2)
    length = 1;
  
  return;
}


Rectangle & Rectangle::operator *=(const Rectangle & rec)
{
  width  *= rec.width;
  length *= rec.length;

  return(*this);
}

Rectangle operator +(const Rectangle & rec1, const Rectangle & rec2)
{    
  Rectangle temp;
  
  temp.width = rec1.width + rec2.width;
  temp.length = rec1.length + rec2.length;
  
  return temp; 
}

ostream & operator <<(ostream & stream, const Rectangle & rec)
{
  cout<<"("<<rec.length<<","<<rec.width<<")"<<endl;
  return stream;
}
