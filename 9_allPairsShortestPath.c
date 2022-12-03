/*
    9. Write graph program to calculate the all pairs shortest path of graph given graph using Floyd's algorithm.
*/

#include <stdio.h>
#include <time.h>

// Time complexity of Floyd's Algorithm: O(n^3)

/**
 * @brief to calculate the all pairs shortest path of graph given graph using Floyd's algorithm
 * 
 * @param graph[][] graph
 * @param n number of vertices
 */
void floyd(int graph[4][4], int n) {
	int i, j, k;
	for(k = 0; k < n; k++) {
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				if(graph[i][j] > (graph[i][k] + graph[k][j])) {
					graph[i][j] = (graph[i][k] + graph[k][j]);
				}
		    }
	    }
	}
	printf("The All Pairs Shortest Path for the given graph is :\n");
		for(i = 0; i < n; i++) {
	    	for(j = 0; j < n; j++) {
	    		printf("%d ", graph[i][j]);
			}
	    	printf("\n");
		}
}

int main() {
	int weightedGraph[4][4] = {
        {0, 3, 999, 4}, 
        {8, 0, 2, 999}, 
        {5, 999, 0, 1}, 
        {2, 999, 999, 0}
    }; 
	int n = 4;
    int startTime, endTime, totalTime;
    startTime = clock();
	floyd(weightedGraph, n);
    endTime = clock();
    totalTime = endTime - startTime;
    printf("\nStart Time = %d ms \nEnd Time = %d ms \nTotal Time = %d ms\n", startTime, endTime, totalTime); 
	return 0;
}