#include<stdio.h>

void create() {
    int max_edges, origin, destin;
    printf("Enter the number of  vertices: ");
    scanf("%d", &n);
    max_edges = n*(n - 1);
    for(int i = 0; i < max_edges; i++) {
        printf("Enter edge %d (-1 -1 tp quit)");
        scanf("%d %d", &origin, &destin);
        if(origin == -1 && destin == -1) break;
        if(origin>=n || destin >= n || origin < 0 || destin < 0) {
            printf("Invalid Vertex");
            i--;
        } else adj[origin][destin] = 1;
    }
}

