/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Type:    Directed Unweighted Graph Input
 */
 
#include<stdio.h>
#include<iostream>
using namespace std;
 
#define N 100
 
/*
 * Graph is the graph representation in adjacency matrix
 */
int Graph[N][N];
 
/*
 * u is the current or source vertex
 * v is the next or destination vertex
 */
 
int vertices, edges;
int u, v;
int i, j;
 
void InputGraph(){
    printf("Enter vertices and Edges:\n");
    scanf("%d%d", &vertices, &edges);
 
    // Reset graph
    for(i = 0; i < vertices; ++i)
        for(j = 0; j < vertices; ++j)
            Graph[i][j] = 0;
 
    // Input Graph
    printf("Enter (u v):\n");
    for(i = 0; i < edges; ++i){
        scanf("%d%d", &u, &v);
        // For directed graph edges (u,v) != (v,u)
        Graph[u][v] = 1;
    }
}
 
void PrintGraph(){
    // Print the current Graph
    printf("\n");
    printf("Graph:\n");
    for(i = 0; i < vertices; ++i){
        for(j = 0; j < vertices; ++j)
            printf("%d ", Graph[i][j]);
        printf("\n");
    }
    printf("\n");
}

void btwnCentralityDir(){
	
	int* points;
	points = new int[vertices];
	int* edgeCount;
	edgeCount = new int[edges*2];
	
	for(int k = 0; k < vertices; ++k)
	{
		for(int i = 0; i < vertices; ++i)
		{
			for(int j = 0; j < vertices; ++j)
			{
				if((Graph[i][k] * Graph[k][j] != 0) && (i != j))
				{
					if((Graph[i][k] + Graph[k][j] < Graph[i][j])
						|| (Graph[i][j] == 0))
						{
							Graph[i][j] = Graph[i][k] + Graph[k][j];
							points[k]++;
							edgeCount[i]++;
						}
				}
			}

		}
	}
	for(int z = 0; z < edges; ++z)
	{
		cout<<"Edge "<<z<<"-"<<z+1<<" count: "<<edgeCount[z]<<endl;
		cout<<"Edge "<<z+1<<"-"<<z<<" count: "<<edgeCount[z+1]<<endl;
	}
	cout<<endl;
	
	for(int m = 0; m < vertices; ++m)
	{
		cout<<"BC for node "<<m<<": "<<points[m]<<endl;
	}
	cout<<endl;

	return;
}
 
int main(){
 
    printf("Directed Unweighted Graph:\n");
    printf("============================\n\n");
 
    InputGraph();
    PrintGraph();
	
	btwnCentralityDir();
	
    return 0;
}