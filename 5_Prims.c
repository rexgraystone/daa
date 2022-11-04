/*  
    5. Write a program to find the Minimum Cost Spanning Tree of a given graph using Prim's algorithm.
*/

#include <stdio.h>
#include <stdbool.h>

# define INF 99999999 //infinity

int main() {
    int i, j, e; // i = index for rows, j = index for columns, e = number of edges
    int g[6][6], selected[6]; // g = graph, selected = selected vertices
    int n, x; // n = number of vertices, x = number of edges
    int y, min; // y = minimum cost
    printf("Enter the number of vertices less than 6: "); // input the number of vertices
    scanf("%d", &n); // input the number of vertices
    printf("Input the weighted graph in terms of matrix: \n"); // input the weighted graph in terms of matrix
    memset(selected, false, sizeof(selected));
    for(i = 0; i < n; i++) { // for all the vertices
        for(j = 0; j < n; j++) { 
            scanf("%d", &g[i][j]);
        }
    }
    memset(selected, false, sizeof(selected)); // set all the elements of selected to false
    int e = 0; // initialize e to 0
    selected[0] = true; // select the first vertex
    printf("Edge \tWeight\n"); // print the edges and their weights
    while(e < (n - 1)) { // run the loop until all the edges are selected
        int min = INF; // initialize min to infinity
        int x = 0; // initialize x to 0
        int y = 0; // initialize y to 0
        for(int i = 0; i < n; i++) { // for all the vertices
            if(selected[i]) { // if the vertex is selected
                for(int j = 0; j < n; j++) { // for all the vertices
                    if(!selected[j] && g[i][j]) { // if the vertex is not selected and the edge exists
                        if(min > g[i][j]) { // if the weight of the edge is less than min
                            min = g[i][j]; // update min
                            x = i; // update x
                            y = j; // update y
                        }
                    }
                }
            }
        }
    }
    printf("%d - %d \t%d", x, y, g[x][y]); // print the edge and its weight
    selected[y] = true; // select the vertex
    return 0; // return 0
}