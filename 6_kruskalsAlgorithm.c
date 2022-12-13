/*
    6. Write a C program to implement Kruskal's algorithm for finding the minimum spanning tree of a given weighted graph.
*/

#include <stdio.h>
#include <time.h>

// Time complexity of Kruskal's Algorithm: O(n^2)

#define infinity 999

typedef struct graph {
    int v1;
    int v2;
    int cost;
}gr;

gr g[20];

int nodes, edges;

int find(int, int []);
void unionFunc(int, int, int[]);
int minimum(int);
void spanningTree();

int main() {
    int k, startTime, endTime, totalTime;
    printf("\n\tGRAPH CREATION\n");
    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    for(k = 0; k < edges; k++) {
        printf("Enter the vertices 'v1' and 'v2' that connect edge '%d': ", k + 1);
        scanf("%d %d", &g[k].v1, &g[k].v2);
        printf("Enter the cost for the edge '%d' that connects the vertices '%d' and '%d': ", k + 1, g[k].v1, g[k].v2);
        scanf("%d", &g[k].cost);
    }
    startTime = clock();
    spanningTree();
    endTime = clock();
    totalTime = endTime - startTime;
    printf("\nStart Time = %d\nEnd Time = %d\nTotal Time = %d ms\n", startTime, endTime, totalTime);
    return 0;
}

/**
 * @brief to find the minimum spanning tree
 * 
 * @param v2 the first vertex
 * @param parent[] the array of parent vertices
 * @return (int) the parent vertex
 */
int find(int v2, int parent[]) {
    while(parent[v2] != v2) {
        v2 = parent[v2];
    }
    return v2;
}
/**
 * @brief to perform the union operation
 * 
 * @param i 
 * @param j 
 * @param parent 
 */
void unionFunc(int i, int j, int parent[10]) {
    if(i < j) {
        parent[j] = i;
    } else {
        parent[i] = j;
    }
}

/**
 * @brief to find the minimum cost edge
 * 
 * @param n the number of edges
 * @return (int) the minimum cost edge
 */
int minimum(int n) {
    int i, small, pos;
    small = infinity;
    pos = -1;
    for(i = 0; i < n; i++) {
        if(g[i].cost < small) {
            small = g[i].cost;
            pos = i;
        }
    }
    return pos;
}

/**
 * @brief to find the spanning tree
 * 
 */
void spanningTree() {
    int count = 0, k = 0, v1, v2, i, j, tree[10][10], pos, parent[10];
    int sum = 0;
    for(i = 0; i < nodes; i++)
        parent[i] = i;
    while(count != nodes - 1) {
        pos = minimum(edges);
        if(pos == -1) {
            break;
        }
        v1 = g[pos].v1;
        v2 = g[pos].v2;
        i = find(v1, parent);
        j = find(v2, parent);
        if(i != j) {
            tree[k][0] = v1;
            tree[k][1] = v2;
            k++;
            count++;
            sum += g[pos].cost;
            unionFunc(i, j, parent);
        }
        g[pos].cost = infinity;
    }
    if(count == nodes - 1) {
        printf("\n\tSPANNING TREE IS:\n");
        printf("\n");
        for(i = 0; i < nodes - 1; i++) {
            printf("\n\t%d", tree[i][0]);
            printf("-");
            printf("%d\n", tree[i][1]);
        }
        printf("\nThe cost of the spanning tree is: %d", sum);
    } else {
        printf("No spanning tree:");
    }
}


