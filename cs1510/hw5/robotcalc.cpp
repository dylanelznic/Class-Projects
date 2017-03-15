//Dylan Elznic
//CS 1510
//Section 1B

#include <iostream>
#include <cstdlib>
#include "AbstractStack.h"
using namespace std;

template <typename T>
class LLStack: public AbstractStack<T>
{
	public:
	
	T m_data;
	LLStack* m_next;
	
	LLStack():m_next(NULL){};
	
    bool isEmpty() const
	{
		if(m_next == NULL)
		{
			return true;
		}
		else
		{	
			return false;
		}
	}
	
	const T& top() const throw (Oops)
	{
		Oops error ("The Stack is empty.");
		
		if(!isEmpty())
		{
			return m_data;
		}
		else
		{
			throw error;
		}
	}
	
    void push(const T& x)
	{
		LLStack* tmp = new LLStack;
		tmp -> m_data = m_data;
		tmp -> m_next = m_next;
		
		m_data = x;
		m_next = tmp;
	}
    
    void pop()
	{
		LLStack* tmp = m_next;
		if(m_next != NULL)
		{
			m_data = tmp -> m_data;
			m_next = tmp -> m_next;
		}
		
		delete tmp;
	}
    
    void clear()
	{
		LLStack* tmp = this;
		LLStack* tmp_next = tmp->m_next;
		
		while (tmp_next != NULL)
		{
			tmp = tmp_next;
			tmp_next = tmp_next->m_next;
			delete tmp;
		}
		
		tmp = NULL;
		tmp_next = NULL;
		m_next = NULL;
		
		return;
	}
	
	void print()
	{
		LLStack* tmp = m_next;
		
		cout<<"[ ";
		
		if(m_next != NULL)
		{
			cout<<m_data;
			if(tmp->m_next != NULL)
			{
				cout<<", ";
			}
			
			while(tmp->m_next != NULL)
			{
				cout<<tmp->m_data;
				tmp=tmp->m_next;
				
				if(tmp->m_next != NULL)
				{
					cout<<", ";
				}
			}
		}
		cout<<" ]"<<endl;
		tmp = NULL;
		
		return;
	}
	
};

int main()
{
	LLStack<int> p;
	string in_data;
	int a = 0;
	int b = 0;
	
	do
	{
		try
		{
			cin>>in_data;
			
			//Sum Operator
			if(in_data == "SUM")
			{
				if(!p.isEmpty())
				{
					a = p.top();
					p.pop();
					
					while(!p.isEmpty())
					{
						b =p. top();
						p.pop();
						a += b;
					}
					p.push(a);
				}
			}
			
			//Reverse Operator
			else if(in_data == "R")
			{
				LLStack<int> tmpStk;
				
				while(!p.isEmpty())
				{
					tmpStk.push(p.top());
					p.pop();
				}
				
				p.clear();
				LLStack<int>tmpStk2;
				
				while(!tmpStk.isEmpty())
				{
					tmpStk2.push(tmpStk.top());
					tmpStk.pop();
				}
				
				while(!tmpStk2.isEmpty())
				{
					p.push(tmpStk2.top());
					tmpStk2.pop();
				}
				
			}
			
			//Negate Operator
			else if(in_data =="!")
			{
				if(!p.isEmpty())
				{
					a = p.top();
					p.pop();
					a = a * -1;
					p.push(a);
				}
			}
			
			//Plus Operator
			else if(in_data == "+")
			{
				if(!p.isEmpty())
				{
					a = p.top();
					p.pop();
					
					if(!p.isEmpty())
					{
						b = p.top();
						p.pop();
					}
					
					a = a + b;
					p.push(a);
				}
			}
			
			//Minus Operator
			else if(in_data == "-")
			{
				if(!p.isEmpty())
				{
					a = p.top();
					p.pop();
					
					if(!p.isEmpty())
					{
						b = p.top();
						p.pop();
					}
					
					a = a - b;
					p.push(a);
				}
			}
			
			
			//Multiplication Operator
			else if(in_data == "*")
			{
				if(!p.isEmpty())
				{
					a = p.top();
					p.pop();
					
					if(!p.isEmpty())
					{
						b = p.top();
						p.pop();
					}
					
					a = a * b;
					p.push(a);
				}
			}
			
			//Division Operator
			else if(in_data == "/")
			{
				try
				{
					a = p.top();
					Oops error("Error: Division by 0");
					if(a == 0) throw error;
					
					else
					{
						if(!p.isEmpty())
						{
							p.pop();
							
							if(!p.isEmpty())
							{
								b = p.top();
								p.pop();
							}
							
							a = b / a;
							p.push(a);
						}
					}
				}
				
				catch(Oops error)
				{
					cout<<error.getMsg()<<endl;
				}
			}
			
			//Mod Operator
			else if(in_data == "%")
			{
				try
				{
					a = p.top();
					Oops error("Error: Mod by 0");
					if(a == 0) throw error;
					
					else
					{
						if(!p.isEmpty())
						{
							p.pop();
							
							if(!p.isEmpty())
							{
								b = p.top();
								p.pop();
							}
							
							a = a % b;
							p.push(a);
						}
					}
				}
				
				catch(Oops error)
				{
					cout<<error.getMsg()<<endl;
				}
			}
			
			//Clear Operator
			else if(in_data == "$")
			{
				p.clear();
			}
			
			//Top Error Check
			else if(in_data == "M")
			{
				p.top();
			}
			
			//Print Operator
			else if(in_data == "#")
			{
				p.print();
			}
			
			//Integer output
			else
			{
				a = atoi(in_data.c_str());
				p.push(a);
			}
		}	
		
		catch(Oops error)
		{
			cout<<error.getMsg();
		}
		
	}while(in_data != "@");	
	
	p.clear();
	return 0;
}