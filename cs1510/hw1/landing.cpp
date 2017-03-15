//Dylan Elznic
//CS1510 1B

#include <iostream>
using namespace std;

int main()
{
	
	//Variables
	const int EDGE_CHECK = 2;
        const int L_ZONE = 3;
	int numMaps = 0;
	int height,width = 0;
	int **p;
	
	int xCoord = 0;
	int yCoord = 0;
	int flowerTest = 0; 
	int flowerFinal = 0;
	
	cin>>numMaps;
	
	for(int i = 0; i < numMaps; i++)
	{
		//Grid Creation
		cin>>width;
		cin>>height;
		
		p = new int*[width];
		
		for(int j = 0; j < width; j++)
		{
			p[j] = new int[height];
		}
		
		//Grid Input
		for(int j = 0; j < height; j++)
		{
			for(int k = 0; k < width; k++)
			{
				cin>>p[k][j];
			}
		}	
		
		//Finding the Landing Zone
		for(int y = 0; y < height-EDGE_CHECK; y++)
		{
			for(int x = 0; x < width-EDGE_CHECK; x++)
			{
		        //Start 3x3 Count
				for(int j = 0; j < L_ZONE; j++)
				{
					for(int k = 0; k < L_ZONE; k++)
					{
						flowerTest += p[k+x][j+y];
					}
				}
				//End Loop
				
				if(y == 0 && x == 0)
				{
					flowerFinal = flowerTest;
				}
				
				if(flowerTest < flowerFinal)
				{
					flowerFinal = flowerTest;
					xCoord = x;
					yCoord = y;
				}
				flowerTest = 0;
			}
		}
		
		cout<<"#"<<i<<": "<<"("<<xCoord<<", "<<yCoord<<") "<<flowerFinal<<endl;
		
		//Grid Deletion
		for(int j = 0; j < width; j++)
		{
			delete[]p[j];
			p[j]= NULL;
		}
		
		delete []p;
		p = NULL;
		flowerFinal = 0;
	}

return 0;
}	
