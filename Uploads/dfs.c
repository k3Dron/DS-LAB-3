#include <stdio.h>
#include <stdlib.h>

#define INI 1
#define WAT 2
#define VIS 3
#define FIN 4
#define MAX 10

int adjmat[MAX][MAX] = {0};
int state[MAX] = {0};
int stack[MAX];
int top = -1;

void add_vert() {
    int n;
    printf("Enter the vertex value (less than 10): ");
    scanf("%d", &n);
    if (state[n] > 0) {
        printf("Vertex already exists\n");
        return;
    }
    state[n] = INI;
}

void add_edge() {
    int v1, v2;
    printf("Enter the edge (less than 10): ");
    scanf("%d %d", &v1, &v2);
    if (adjmat[v1][v2] > 0) {
        printf("Edge already exists\n");
        return;
    }
    adjmat[v1][v2] = 1;
}

void del_vert() {
    int v;
    printf("Enter the vertex to be deleted: ");
    scanf("%d", &v);
    if (state[v] == 0) {
        printf("Vertex does not exist\n");
        return;
    }
    state[v] = 0;
    for (int i = 0; i < MAX; i++) {
        adjmat[v][i] = 0;
        adjmat[i][v] = 0;
    }
}

void del_edge() {
    int v1, v2;
    printf("Enter the edge to be deleted: ");
    scanf("%d %d", &v1, &v2);
    if (adjmat[v1][v2] == 0) {
        printf("No such edge exists\n");
        return;
    }
    adjmat[v1][v2] = 0;
    printf("Edge is deleted\n");
}

void push(int v) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = v;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int empty() {
    return (top == -1);
}

void dfs(int v) {
    printf("%d", v);
    state[v] = VIS;
    for(int i = 0; i < MAX ; i++) {
        if(adjmat[v][i] == 1 && state[v] == INI) {
            dfs(i);
        }
    }
    state[v] = FIN;
}

void dfs_traversal() {
    int v;
    printf("Enter the vertex to start from: ");
    scanf("%d", &v);
    dfs(v);
    for (int i = 0; i < MAX; i++) {
        if (state[i] == INI) {
            dfs(i);
        }
    }
    printf("\n");
}

void display() {
    for (int v = 0; v < MAX; v++) {
        printf("%d -> ", v);
        for (int e = 0; e < MAX; e++) {
            if (adjmat[v][e] == 1) {
                printf("%d ", e);
            }
        }
        printf("\n");
    }
}

int main() {
    int o;
    while (1) {
        printf("Enter 1 to add a new vertex\n");
        printf("Enter 2 to add an edge\n");
        printf("Enter 3 to delete an edge\n");
        printf("Enter 4 to delete a vertex\n");
        printf("Enter 5 to Display\n");
        printf("Enter 6 to perform DFS traversal\n");
        printf("Enter 0 to Exit\n");
        scanf("%d", &o);
        switch (o) {
            case 1: add_vert(); break;
            case 2: add_edge(); break;
            case 3: del_edge(); break;
            case 4: del_vert(); break;
            case 5: display(); break;
            case 6: dfs_traversal(); break;
            case 0: exit(0); break;
            default: printf("Invalid value\n"); break;
        }
    }
    return 0;
}
