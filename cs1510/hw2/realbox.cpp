//Dylan Elznic
//CS 1510 Section 1B

#include "realbox.h"
#include <iostream>
using namespace std;

RealBox::RealBox(int s, float a)
{
	m_reals = new float[s];
	m_boxsize = s;
	
	int i = 0;
	while(i<m_boxsize)
	{
	  m_reals[i]=a;
	  i++;
	}

}

RealBox::~RealBox()
{
	delete []m_reals;
}

const RealBox& RealBox::operator=(const RealBox& rhs)
{
	if(this != &rhs)
	{
		if(m_boxsize != rhs.m_boxsize && m_boxsize != 0)
		{
			delete []m_reals;
		}
		
		m_boxsize = rhs.m_boxsize;
		m_reals = new float[m_boxsize];
		for(int i = 0; i < m_boxsize; i++)
		{
			m_reals[i] = rhs.m_reals[i];
		}
	}
	
	return *this;
}

RealBox::RealBox(const RealBox& rhs)
{
	m_boxsize = rhs.m_boxsize;
	*this = rhs;
}

void RealBox::set(int i, float x)
{
    if(i < 0 || i > m_boxsize)
	{
		cout<<"Error: Invalid i";
	}
	
	else
	{
		m_reals[i] = x;
	}

	return;
}

ostream& operator<<(ostream& out, const RealBox& box)
{
	out<<"[ ";
	for(int i = 0; i < box.m_boxsize; i++)
	{
		out<<box.m_reals[i]<<", ";
	}
	out<<"]";
	
	return out;
}