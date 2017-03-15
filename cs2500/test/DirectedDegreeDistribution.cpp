/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Type:    Directed Weighted Graph Input
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
 * w is the edge weight or path cost
 */
 
int vertices, edges;
int u, v, w;
int i, j;
 
void InputGraph(){
    printf("Enter vertices and Edges:\n");
    scanf("%d%d", &vertices, &edges);
 
    // Reset graph
    for(i = 0; i < vertices; ++i)
        for(j = 0; j < vertices; ++j)
            Graph[i][j] = 0;
 
    // Input Graph
    printf("Enter (u v w):\n");
    for(i = 0; i < edges; ++i){
        scanf("%d%d%d", &u, &v, &w);
        Graph[u][v] = w;
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
 
int inDirWeight()
{
	int tempInCount = 0;
	
	cout<<"\nHighest In Degree (Weighted): "<<endl;
	for(int i = 0; i < vertices; ++i)
	{
		for(int j = 0; j < vertices; ++j)
		{
			tempInCount += Graph[j][i];
		}
		cout<<"Vertex "<<i<<": "<<tempInCount<<endl;
		tempInCount = 0;
	}
	cout<<endl;
	return 0;
}

int outDirWeight()
{
	int tempOutCount = 0;
	
	cout<<"\nHighest Out Degree (Weighted): "<<endl;
	for(int i = 0; i < vertices; ++i)
	{
		for(int j = 0; j < vertices; ++j)
		{
			tempOutCount += Graph[i][j];
		}
		cout<<"Vertex "<<i<<": "<<tempOutCount<<endl;
		tempOutCount = 0;
	}
	cout<<endl;
	return 0;
}

int inDirUnweight()
{
	int tempInCount = 0;
	
	cout<<"\nHighest In Degree (Unweighted): "<<endl;
	for(int i = 0; i < vertices; ++i)
	{
		for(int j = 0; j < vertices; ++j)
		{
			if(Graph[j][i] != 0)
			{
				tempInCount += 1;
			}
		}
		cout<<"Vertex "<<i<<": "<<tempInCount<<endl;
		tempInCount = 0;
	}
	cout<<endl;
	return 0;
}

int outDirUnweight()
{
	int tempOutCount = 0;
	
	cout<<"\nHighest Out Degree (Unweighted): "<<endl;
	for(int i = 0; i < vertices; ++i)
	{
		for(int j = 0; j < vertices; ++j)
		{
			if(Graph[i][j] != 0)
			{
				tempOutCount += 1;
			}
		}
		cout<<"Vertex "<<i<<": "<<tempOutCount<<endl;
		tempOutCount = 0;
	}
	cout<<endl;
	return 0;
}

int main(){
 
    printf("Directed Weighted Graph:\n");
    printf("============================\n\n");
 
    InputGraph();
    PrintGraph();
	
	inDirWeight();
	outDirWeight();
	
	inDirUnweight();
	outDirUnweight();
	
    return 0;
}