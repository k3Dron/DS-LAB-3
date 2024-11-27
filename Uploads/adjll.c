#include<stdio.h>
#include<stdlib.h>

struct vertex;  // Forward declaration

struct edge {
    struct edge *next_edge;
    struct vertex *dest_vert;
};

struct vertex {
    struct vertex *next_vert;
    struct edge *first_edge;
    int info;
} *start = NULL;

struct vertex *checkvert(int n) {
    struct vertex *ptr = start;
    if (ptr == NULL) {
        printf("Graph is empty\n");
        return NULL;
    }
    while (ptr != NULL && ptr->info != n) {
        ptr = ptr->next_vert;
    }
    if (ptr != NULL && ptr->info == n) {
        return ptr;
    } else {
        printf("Vertex not present\n");
        return NULL;
    }
}

void add_vert() {
    int u;
    struct vertex *temp = (struct vertex *)malloc(sizeof(struct vertex));
    struct vertex *ptr;
    printf("Enter the vertex to be inserted: ");
    scanf("%d", &u);
    temp->info = u;
    temp->next_vert = NULL;
    temp->first_edge = NULL;

    if (start == NULL) {
        start = temp;
        return;
    }

    ptr = start;
    while (ptr->next_vert != NULL) {
        if (ptr->info == u) {
            printf("Vertex already present\n");
            free(temp);
            return;
        }
        ptr = ptr->next_vert;
    }

    if (ptr->info == u) {
        printf("Vertex already present\n");
        free(temp);
        return;
    }

    ptr->next_vert = temp;
}

void add_edge() {
    int v1, v2;
    struct vertex *locv1, *locv2;
    struct edge *ptr, *temp = (struct edge *)malloc(sizeof(struct edge));
    printf("Enter the edge: ");
    scanf("%d %d", &v1, &v2);
    locv1 = checkvert(v1);
    locv2 = checkvert(v2);
    if (locv1 == NULL || locv2 == NULL) {
        printf("Does not Exist\n");
        free(temp);
        return;
    }
    ptr = locv1->first_edge;
    while (ptr != NULL && ptr->dest_vert != locv2) {
        ptr = ptr->next_edge;
    }
    if (ptr != NULL && ptr->dest_vert == locv2) {
        printf("Edge Already Exist\n");
        free(temp);
        return;
    }
    temp->dest_vert = locv2;
    temp->next_edge = locv1->first_edge;
    locv1->first_edge = temp;
}

void del_edge() {
    int v1, v2;
    struct vertex *locv1, *locv2;
    struct edge *ptr, *prev = NULL;
    printf("Enter the edge: ");
    scanf("%d %d", &v1, &v2);
    locv1 = checkvert(v1);
    locv2 = checkvert(v2);
    if (locv1 == NULL || locv2 == NULL) {
        printf("Does not Exist\n");
        return;
    }
    ptr = locv1->first_edge;
    while (ptr != NULL && ptr->dest_vert != locv2) {
        prev = ptr;
        ptr = ptr->next_edge;
    }
    if (ptr != NULL && ptr->dest_vert == locv2) {
        if (prev == NULL) {
            locv1->first_edge = ptr->next_edge;
        } else {
            prev->next_edge = ptr->next_edge;
        }
        free(ptr);
        printf("Edge was deleted\n");
    } else {
        printf("Edge not found\n");
    }
}

void del_vert() {
    int n;
    struct vertex *vert_ptr = start, *vert_prev = NULL;
    struct edge *edge_ptr, *edge_prev;
    printf("Enter the vertex to be deleted: ");
    scanf("%d", &n);

    if (vert_ptr == NULL) {
        printf("Empty Graph\n");
        return;
    }

    while (vert_ptr != NULL) {
        if (vert_ptr->info == n) {
            if (vert_prev == NULL) {
                start = vert_ptr->next_vert;
            } else {
                vert_prev->next_vert = vert_ptr->next_vert;
            }
            edge_ptr = vert_ptr->first_edge;
            while (edge_ptr != NULL) {
                edge_prev = edge_ptr;
                edge_ptr = edge_ptr->next_edge;
                free(edge_prev);
            }
            free(vert_ptr);
            printf("Vertex deleted\n");
            return;
        }
        vert_prev = vert_ptr;
        vert_ptr = vert_ptr->next_vert;
    }

    printf("Vertex not found\n");
}

void display() {
    struct vertex *vert_ptr;
    struct edge *edge_ptr;
    if(start == NULL) {
        printf("The graph is empty");
        return;
    }
    vert_ptr = start;
    while(vert_ptr != NULL) {
        printf("%d -> ", vert_ptr->info);
        edge_ptr = vert_ptr->first_edge;
        while(edge_ptr != NULL) {
            printf("%d ", edge_ptr->dest_vert->info);
            edge_ptr = edge_ptr->next_edge;
        }
        printf("\n");
        vert_ptr = vert_ptr->next_vert;
    }
}

int main() {
    int o;
    while(1) {
        printf("Enter 1 to add a new vertex\nEnter 2 to add an edge\nEnter 3 to delete an edge\nEnter 4 to delete a vertex\nEnter 5 to Display\nEnter 0 to Exit\n");
        scanf("%d", &o);
        switch (o) {
            case 1: add_vert(); break;
            case 2: add_edge(); break;
            case 3: del_edge(); break;
            case 4: del_vert(); break;
            case 5: display(); break;
            case 0: exit(0); break;
            default: printf("Invalid value\n"); break;
        }
    }
    return 0;
}
