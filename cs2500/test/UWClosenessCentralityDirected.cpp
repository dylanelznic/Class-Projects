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

void closeCentralityDir(){
	
	for(int i = 0; i < vertices; ++i)
	{
		for(int j = 0; j < vertices; ++j)
		{
			for(int k = 0; k < vertices; ++k)
			{
				if((Graph[i][k] * Graph[k][j] != 0) && (i != j))
				{
					if((Graph[i][k] + Graph[k][j] < Graph[i][j])
						|| (Graph[i][j] == 0))
						{
							Graph[i][j] = Graph[i][k] + Graph[k][j];
						}
				}
			}
		}
	}
	
	double edgeCount = 0;
	double shortPathCount = 0;
	
	for(int m = 0; m < vertices; ++m)
	{
		for(int n = 0; n < vertices; ++n)
		{
			if(m != n)
			{
				if(Graph[m][n] != 0)
				{
					edgeCount++;
					shortPathCount += Graph[m][n];
				}
			}
		}
		
		cout<<endl<<"Closeness centrality for node "<<m<<": ";
		
		if(edgeCount != 0)
		{
			cout<<(shortPathCount/edgeCount)<<endl;
		}
		
		else
		{
			cout<<"No paths found"<<endl;
		}
		
		cout<<endl;
		
		edgeCount = 0;
		shortPathCount = 0;
	}

	return;
}
 
int main(){
 
    printf("Directed Unweighted Graph:\n");
    printf("============================\n\n");
 
    InputGraph();
    PrintGraph();
	
	closeCentralityDir();

    return 0;
}