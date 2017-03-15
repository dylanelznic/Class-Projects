//Dylan Elznic
//CS 1510
//Section 1B

#include <iostream>
#include <cstdlib>
#include "AbstractQueue.h"
using namespace std;

class ship
{
	public:
	
	int m_arrTime;
	string m_name;
	int m_fuelUnits;
	int m_arrFront;
	
	ship():m_arrTime(0),m_fuelUnits(0),m_arrFront(0){};
	
	void setValues(int time, string name, int fuel, int front)
	{
		m_arrTime = time;
		m_name = name;
		m_fuelUnits = fuel;
		m_arrFront = front;
	}
	
	ship& operator= (const ship & source)
	{
		if(this != &source)
		{
			m_arrTime = source.m_arrTime;
			m_name = source.m_name;
			m_fuelUnits = source.m_fuelUnits;
			m_arrFront = source.m_arrFront;
		}
		return *this;
	}

	bool operator!= (const ship & source)
	{
		if(this != &source)
		{
			if(m_name != source.m_name)
			{
				return true;
			}
		}
		return false;
	}
	
	friend ostream& operator<<(ostream& stream, const ship& spaceship)
	{
		stream<<"Arrival: "<<spaceship.m_arrTime<<" Name: "<<spaceship.m_name<<" Fuel Units: "
        <<spaceship.m_fuelUnits<<endl;
        
		return stream;
	}
};

template <typename T>
class LLQueue: public AbstractQueue<T>
{
	public:
	
	T m_data;
	LLQueue* m_next;
	int m_length;
	
	LLQueue():m_next(NULL), m_length(0){};
	
	void enqueue(const T& x);
	
	void dequeue();
	
	const T& front() const throw (Oops);
	
	const T& back() const throw (Oops);
	
	bool isEmpty() const;
	
	void clear();
	
};

template <typename T>
void LLQueue<T>::enqueue(const T& x)
{
	if(m_next == NULL)
	{
		m_next = new LLQueue<T>;
		m_next -> m_next = m_next;
		m_next -> m_data = x;
	}
	
	else
	{
		LLQueue<T>* tmp = new LLQueue;
		tmp -> m_data = x;
		tmp -> m_next = m_next -> m_next;
		m_next -> m_next = tmp;
		m_next = tmp;
	}
	
	return;
}

template <typename T>
void LLQueue<T>::dequeue()
{
	if(m_next != NULL)
	{
		if(m_next == m_next -> m_next)
		{
			delete m_next;
			m_next = NULL;
		}
		
		else
		{
			LLQueue<T>* tmp = m_next -> m_next;
			m_next -> m_next = tmp -> m_next;
			delete tmp;
		}
	}
	
	return;
}

template <typename T>
const T& LLQueue<T>::front() const throw (Oops)
{
	Oops error("The Queue is empty.");
	
	if(!isEmpty())
	{
		return m_next -> m_next -> m_data;
	}
	
	else
	{
		throw error;
	}
}

template <typename T>
const T& LLQueue<T>::back() const throw (Oops)
{
	Oops error("The Queue is empty.");
	
	if(!isEmpty())
	{
		return m_next -> m_data;
	}
	
	else
	{
		throw error;
	}
}

template <typename T>
bool LLQueue<T>::isEmpty() const
{
	if(m_next != NULL)
	{
		return false;
	}
	
	else
	{
		return true;
	}
}

template <typename T>
void LLQueue<T>::clear()
{
	while(!isEmpty())
	{
		dequeue();
	}
	
	return;
}




//~^~ Main Starts Here ~^~//

int main()
{
	LLQueue<ship> parkingLot;
	ship inShip;
	
	int tempTime = 0;
	string tempName;
	int tempFuel = 0;
	int tempFront = 1;
	int count = 1;
	
	LLQueue<ship> A; // Gas Pumps
	LLQueue<ship> B;
	LLQueue<ship> C;
	
	ship fuelingShipA;
	ship fuelingShipB;
	ship fuelingShipC;
	
	ship waitShipA;
	ship waitShipB;
	ship waitShipC;
	
	int time = 0;
	
	int longest = 0;
	int shortest = 0;
	int shortCount = 0;
	
	ship longestShip;
	ship shortestShip;
	
	/*     End Variables    */
	
	int N = 0; // # of ships
	cin>>N;
	
	for(int i = 0; i < N; i++)  // Generates ships
	{
		cin>>tempTime;
		cin>>tempName;
		cin>>tempFuel;
		inShip.setValues(tempTime, tempName, tempFuel, tempFront);
		parkingLot.enqueue(inShip); // Puts a ship in the parking lot
	}
	
	ship tempShip = parkingLot.front();
	
	cout<<endl;
	
	do
	{
		try
		{
			
			while(tempShip.m_arrTime == time && !parkingLot.isEmpty())
			{
				if(A.m_length <= B.m_length && A.m_length <= C.m_length)
				{
					A.enqueue(tempShip);
					cout<<"At time "<<time<<" "<<tempShip.m_name<<" joins port A."<<endl;
					parkingLot.dequeue();
					if(!parkingLot.isEmpty())
					{
						tempShip = parkingLot.front();
					}
					A.m_length++;
				}
				
				else if(A.m_length > B.m_length && B.m_length <= C.m_length)
				{
					B.enqueue(tempShip);
					cout<<"At time "<<time<<" "<<tempShip.m_name<<" joins port B."<<endl;
					parkingLot.dequeue();
					if(!parkingLot.isEmpty())
					{
						tempShip = parkingLot.front();
					}
					B.m_length++;
				}
				
				else
				{
					C.enqueue(tempShip);
					cout<<"At time "<<time<<" "<<tempShip.m_name<<" joins port C."<<endl;
					parkingLot.dequeue();
					if(!parkingLot.isEmpty())
					{
						tempShip = parkingLot.front();
					}
					C.m_length++;
				}
			}
			
			if(count != 1)
			{
			if(((fuelingShipA.m_fuelUnits*3)+(fuelingShipA.m_arrTime+
			(fuelingShipA.m_arrFront-fuelingShipA.m_arrTime))) == time)
			{
				A.dequeue();
				cout<<"At time "<<time<<" "<<fuelingShipA.m_name<<" is done fueling."<<endl;
				A.m_length--;
			}
			
			if(((fuelingShipB.m_fuelUnits*3)+(fuelingShipB.m_arrTime+
			(fuelingShipB.m_arrFront-fuelingShipB.m_arrTime))) == time)
			{
				B.dequeue();
				cout<<"At time "<<time<<" "<<fuelingShipB.m_name<<" is done fueling."<<endl;
				B.m_length--;
			}
			
			if(((fuelingShipC.m_fuelUnits*3)+(fuelingShipC.m_arrTime+
			(fuelingShipC.m_arrFront-fuelingShipC.m_arrTime))) == time)
			{
				C.dequeue();
				cout<<"At time "<<time<<" "<<fuelingShipC.m_name<<" is done fueling."<<endl;
				C.m_length--;
			}
			}
			
			if(!A.isEmpty())
			{
				if(fuelingShipA != A.front())
				{
					fuelingShipA = A.front();
					fuelingShipA.m_arrFront = time;
					
					if(shortCount == 0)
					{
						shortest = fuelingShipA.m_arrFront - fuelingShipA.m_arrTime + fuelingShipA.m_fuelUnits*3;
						shortCount++;
					}
					
					if(fuelingShipA.m_arrFront - fuelingShipA.m_arrTime + fuelingShipA.m_fuelUnits*3 > longest)
					{
						longest = fuelingShipA.m_arrFront - fuelingShipA.m_arrTime + fuelingShipA.m_fuelUnits*3;
						longestShip = fuelingShipA;
					}
					
					if(fuelingShipA.m_arrFront - fuelingShipA.m_arrTime + fuelingShipA.m_fuelUnits*3 < shortest)
					{
						shortest = fuelingShipA.m_arrFront - fuelingShipA.m_arrTime + fuelingShipA.m_fuelUnits*3;
						shortestShip = fuelingShipA;
					}
				}
				
			}
			
			if(!B.isEmpty())
			{
				if(fuelingShipB != B.front())
				{
					fuelingShipB = B.front();
					fuelingShipB.m_arrFront = time;
					if(fuelingShipB.m_arrFront - fuelingShipB.m_arrTime + fuelingShipB.m_fuelUnits*3 > longest)
					{
						longest = fuelingShipB.m_arrFront - fuelingShipB.m_arrTime + fuelingShipB.m_fuelUnits*3;
						longestShip = fuelingShipB;
					}
					
					if(fuelingShipB.m_arrFront - fuelingShipB.m_arrTime + fuelingShipB.m_fuelUnits*3 < shortest)
					{
						shortest = fuelingShipB.m_arrFront - fuelingShipB.m_arrTime + fuelingShipB.m_fuelUnits*3;
						shortestShip = fuelingShipB;
					}
				}
			}
			
			if(!C.isEmpty()) 
			{
				if(fuelingShipC != C.front())
				{
					fuelingShipC = C.front();
					fuelingShipC.m_arrFront = time;
					if(fuelingShipC.m_arrFront - fuelingShipC.m_arrTime + fuelingShipC.m_fuelUnits*3 > longest)
					{
						longest = fuelingShipC.m_arrFront - fuelingShipC.m_arrTime + fuelingShipC.m_fuelUnits*3;
						longestShip = fuelingShipC;
					}
					
					if(fuelingShipC.m_arrFront - fuelingShipC.m_arrTime + fuelingShipC.m_fuelUnits*3 < shortest)
					{
						shortest = fuelingShipC.m_arrFront - fuelingShipC.m_arrTime + fuelingShipC.m_fuelUnits*3;
						shortestShip = fuelingShipC;
					}
				}
			}
			
			time++;
			count++;
		}
		
		catch(Oops error)
		{
			cout<<error.getMsg();
		}
		
	}while(!A.isEmpty() || !B.isEmpty() || !C.isEmpty() || !parkingLot.isEmpty());
	
	cout<<endl<<"Longest wait: "<<longestShip.m_name<<", "<<longest<<" mins."<<endl;
	cout<<"Shortest wait: "<<shortestShip.m_name<<", "<<shortest<<" mins."<<endl<<endl;
	
	return 0;
}




