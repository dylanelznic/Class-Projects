/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Type:    Undirected Weighted Graph Input
 */
 
#include<stdio.h>
 
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
        // For undirected edge (u,v) = (v,u)
        Graph[u][v] = Graph[v][u] = w;
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
 
int main(){
 
    printf("Undirected Weighted Graph:\n");
    printf("============================\n\n");
 
    InputGraph();
    PrintGraph();
 
    return 0;
}