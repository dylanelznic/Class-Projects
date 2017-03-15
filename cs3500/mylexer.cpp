#include <iostream>
#include <string>
using namespace std;

string getSuffix(string email)
{
    int lastpd = email.find_last_of(".");
    string suffix = email.substr(lastpd + 1);
    return suffix;
}

bool recognize(string s, int j)
{
	int state = 0;
	int i = 0;
	int length = s.length();
	string suffix;
	
	/* KEYWORD BANK */
	string key1 = "while";
	string key2 = "else";
	string key3 = "if";
	string key4 = "print";
	
	/* SUFFIX BANK */
	string suffix1 = "com";
	string suffix2 = "net";
	string suffix3 = "edu";
	
	if(s.compare(key1) == 0 || s.compare(key2) == 0 || s.compare(key3) == 0 || s.compare(key4) == 0)
	{
		i = 100;
		state = 0;
	}
	
	while(i < length)
	{
		switch(state)
		{
			case 0:
				if(s[i] == '+' || s[i] == '-')
				{
					state = 1;
				}
				else if(isdigit(s[i]))
				{
					state = 18;
				}
				else if(isxdigit(s[i]))
				{
					state = 15;
				}
				else if(isalpha(s[i]))
				{	
					state = 8;
				}
				else						//INVALID
				{
					state = -1;
					i = 100;
				}
				break;
			
			case 1:
				if(isdigit(s[i]))
				{
					state = 2;
				}
				else						//INVALID
				{
					state = -1;
					i = 100;
				}
			
			case 2:
				if(isdigit(s[i]))			//INT ACCEPT STATE
				{
					state = 2;
				}
				else if(s[i] == '.' && i+1 != length)
				{
					state = 3;
				}
				else						//INVALID
				{
					state = -1;
					i = 100;
				}
				break;
			
			case 3:
				if(isdigit(s[i]))
				{
					state = 4;
				}
				else						//INVALID
				{
					state = -1;
					i = 100;
				}
				break;
				
			case 4:							//DECIMAL ACCEPT STATE
				if(isdigit(s[i]))
				{
					state = 4;
				}
				else if(s[i] == 'E')
				{
					state = 5;
				}
				else						//INVALID
				{
					state = -1;
					i = 100;
				}
				break;
				
			case 5:
				if(s[i] == '-')
				{
					state = 6;
				}
				else if(isdigit(s[i]) && s[i] != '0')
				{
					state = 7;
				}
				else						//INVALID
				{
					state = -1;
					i = 100;
				}
				break;
				
			case 6:							//SCIENTIFIC ACCEPT STATE
				if(isdigit(s[i]) && s[i] != '0')
				{
					state = 7;
				}
				else						//INVALID
				{
					state = -1;
					i = 100;
				}
				break;
			
			case 7:							//SCIENTIFIC ACCEPT STATE
				if(isdigit(s[i]))
				{
					state = 7;
				}
				else						//INVALID
				{
					state = -1;
					i = 100;
				}
				break;
				
			case 8:							//ID ACCEPT STATE
				if(isalnum(s[i]) || s[i] == '_')
				{
					state = 8;
				}
				else if(s[i] == '.' && i+1 != length)
				{
					state = 9;
				}
				else if(s[i] == '@')
				{
					state = 11;
				}
				else						//INVALID
				{
					state = -1;
					i = 100;
				}
				break;
				
			case 9:
				if(isalpha(s[i]))
				{
					state = 10;
				}
				else						//INVALID
				{
					state = -1;
					i = 100;
				}
				break;
			
			case 10:
				if(isalnum(s[i]) || s[i] == '_')
				{
					state = 10;
				}
				else if(s[i] == '.')
				{
					state = 9;
				}
				else if(s[i] == '@')
				{
					state = 11;
				}
				else						//INVALID
				{
					state = -1;
					i = 100;
				}
				break;
				
			case 11:
				if(isalpha(s[i]))
				{
					state = 12;
				}
				else						//INVALID
				{
					state = -1;
					i = 100;
				}
				break;
			
			case 12:
				suffix = getSuffix(s);
				if(suffix.compare(suffix1) == 0 || suffix.compare(suffix2) == 0 || suffix.compare(suffix3) == 0)
				{
					i = length-1;
					state = 14;
				}
				else if(isalnum(s[i]) || s[i] == '_')
				{
					state = 12;
				}
				else if(s[i] == '.' && i+1 != length)
				{
					state = 13;
				}
				else						//INVALID
				{
					state = -1;
					i = 100;
				}
				break;
			case 13:
				if(isalpha(s[i]))
				{
					state = 12;
				}
				else						//INVALID
				{
					state = -1;
					i = 100;
				}
				break;
			case 14:
				if(i != length)
				{
					state = -1;
					i = 100;
				}
				break;
				
			case 15:
				if(isxdigit(s[i]) && !isdigit(s[i]) && i+1 != length)
				{
					state = 15;
				}
				else if(s[i] == 'H')
				{
					state = 17;
				}
				else if(isalpha(s[i]))
				{
					state = 8;
				}
				else if(isdigit(s[i]))
				{
					state = 16;
				}
				else if(s[i] == '@')
				{
					state = 11;
				}
				else if(s[i] == '.')
				{
					state = 9;
				}
				else
				{
					state = -1;
					i = 100;
				}
				break;
				
			case 16:
				if(isxdigit(s[i]))
				{
					state = 16;
				}
				else if(s[i] == 'H')
				{
					state = 17;
				}
				else
				{
					state = -1;
					i = 100;
				}
				break;
				
			case 17:
				if(i != length)
				{
					state = -1;
					i = 100;
				}
				break;
			
			case 18:
				if(isdigit(s[i]))
				{
					state = 18;
				}
				else if(isxdigit(s[i]))
				{
					state = 19;
				}
				else if(s[i] == 'H')
				{
					state = 20;
				}
				else if(s[i] == '.' && i+1 != length)
				{
					state = 3;
				}
				else
				{
					state = -1;
					i = 100;
				}
				break;
			
			case 19:
				if(isxdigit(s[i]))
				{
					state = 19;
				}
				else if(s[i] == 'H')
				{
					state = 20;
				}
				else
				{
					state = -1;
					i = 100;
				}
				break;
				
			case 20:
			{
				if(i != length)
				{
					state = -1;
					i = 100;
				}
				break;
			}
				
		}								//end switch
		i++;
	}									//end while
	
	
	//CHECK FOR HEX WITHIN EMAIL
	if(state == 14)
	{
		int m = -1;

		while(m < length)
		{
			m++;
			if(s[m] == '.' || s[m] == '@' || (m == 0 && isxdigit(s[m])))
			{
				m++;
				while(isxdigit(s[m]))
				{
					m++;
					if(s[m] == 'H' && (s[m+1] == '.' || s[m+1] == '@'))
					{
						state = -1;
					}
					
				}
				m--;
			}
			if(state == -1)
			{
				break;
			}
		}
	}
	
	switch(state)
	{
		case -1:
			cout<<j<<": INVALID!"<<endl;
			break;
		case 0:
			cout<<j<<": Keyword."<<endl;
			break;
		case 2:
			cout<<j<<": Integer."<<endl;
			break;
		case 18:
			cout<<j<<": Integer."<<endl;
			break;
		case 4:
			cout<<j<<": Decimal"<<endl;
			break;
		case 7:
			cout<<j<<": Scientific."<<endl;
			break;
		case 8:
			cout<<j<<": Identifier."<<endl;
			break;
		case 16:
			cout<<j<<": Identifier."<<endl;
			break;
		case 14:
			cout<<j<<": Email."<<endl;
			break;
		case 17:
			cout<<j<<": Hexadecimal."<<endl;
			break;
		case 20:
			cout<<j<<": Hexadecimal"<<endl;
			break;
	}
	
	return false;

}

int main()
{
	string s;
	int count;
	cin>>count;
	cout<<count<<endl;
	
	for(int j = 0; j < count; j++)
	{
		cin>>s;
		recognize(s, j+1);
	}
	
	return 0;
}