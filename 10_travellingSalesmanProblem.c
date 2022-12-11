/*
    10. Write a program to implement Travelling Salesman Problem using dynamic programming.
*/

#include <stdio.h>
#include <time.h>

// Time complexity of Travelling Salesman Problem: O(n^2 * 2^n)
#define MAX 15
int ary[MAX][MAX], completed[MAX], n, cost = 0;
 
void takeInput() {
    int i, j;
    printf("Enter the number of villages: ");
    scanf("%d", &n);
    printf("\nEnter the Cost Matrix\n");
    for(i = 0; i < n; i++) {
        printf("\nEnter Elements of Row %d: ", i + 1);
            for(j = 0; j < n; j++)
                scanf("%d", &ary[i][j]);
        completed[i] = 0;
    } 
    printf("\n\nThe cost list is: ");
    for(i = 0; i < n; i++) {
        printf("\n"); 
        for(j = 0; j < n; j++)
            printf("\t%d", ary[i][j]);
    }
}

int least(int c) {
    int i, nc = 999;
    int min = 999, kmin; 
    for(i = 0; i < n; i++) {
        if((ary[c][i] != 0) && (completed[i] == 0))
            if(ary[c][i] + ary[i][c] < min) {
                min = ary[i][0] + ary[c][i];
                kmin = ary[c][i];
                nc = i;
            }
    } 
    if(min != 999)
        cost += kmin;
    return nc;
}

void minCost(int city) {
    int i, ncity;
    completed[city] = 1;
    printf("%d--->", city + 1);
    ncity = least(city);
    if(ncity == 999) {
        ncity = 0;
        printf("%d", ncity + 1);
        cost += ary[city][ncity];
        return;
    }
    minCost(ncity);
}
 
int main() {
    takeInput();    
    printf("\n\nThe Path is:\n");
    int startTime, endTime, totalTime;
    startTime = clock();
    minCost(0); //passing 0 because starting vertex
    endTime = clock();
    totalTime = endTime - startTime;
    printf("\n\nMinimum cost is %d\n ", cost);
    printf("\nStart Time = %d ms \nEnd Time = %d ms \nTotal Time = %d ms\n", startTime, endTime, totalTime); 
    return 0;
}