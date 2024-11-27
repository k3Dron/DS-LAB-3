#include<stdio.h>

void main() {
    int graph_type, edges, vertices, v1, v2, adjmat[100][100];
    printf("Enter 1 for Undirected graph and 2 for Directed graph : ");
    scanf("%d" , &graph_type);
    printf("Enter number of vertices : ");
    scanf("%d" , &vertices);
    if(graph_type == 1) {
        edges = vertices*(vertices-1)/2; 
    } else {
        edges = vertices*(vertices-1);
    }
    for(int i = 0; i < edges; i++) {
        printf("Enter the edge %d (-1, -1 to exit) : ", i);
        scanf("%d %d", &v1, &v2);
        if(v1 == -1 && v2 == -1) {
            printf("Program Exited");
            break;
        }
        if(v1 >= 0 && v2 >= 0 && v1 < vertices && v2 < vertices) {
            adjmat[v1][v2] = 1;
            if(graph_type == 1) adjmat[v2][v1] = 1;
        } else {
            printf("Invalid input\n");
            i--;
        }
    }
    printf("Displaying Adjacency Matrix\n");
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices ; j++) {
            printf(" %d ", adjmat[i][j]);
        }
        printf("\n");
    }
}