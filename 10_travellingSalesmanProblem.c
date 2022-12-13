/*
    10. Write a program to implement Travelling Salesman Problem using dynamic programming.
*/

#include <stdio.h>
#include <time.h>

// Time complexity of Travelling Salesman Problem: O(n^2 * 2^n)

#define MAX 15
int arr[MAX][MAX], completed[MAX], n, cost = 0;
 
void takeInput() {
    int i, j;
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    printf("\nEnter the Cost Matrix\n");
    for(i = 0; i < n; i++) {
        printf("\nEnter Elements of Row %d: ", i + 1);
            for(j = 0; j < n; j++)
                scanf("%d", &arr[i][j]);
        completed[i] = 0;
    } 
    printf("\n\nThe cost list is: ");
    for(i = 0; i < n; i++) {
        printf("\n"); 
        for(j = 0; j < n; j++)
            printf("\t%d", arr[i][j]);
    }
}

int least(int city) {
    int i, nCity = 999;
    int min = 999, kmin; 
    for(i = 0; i < n; i++) {
        if((arr[city][i] != 0) && (completed[i] == 0))
            if(arr[city][i] + arr[i][city] < min) {
                min = arr[i][0] + arr[city][i];
                kmin = arr[city][i];
                nCity = i;
            }
    } 
    if(min != 999)
        cost += kmin;
    return nCity;
}

void minCost(int city) {
    int i, nCity;
    completed[city] = 1;
    printf("%d--->", city + 1);
    nCity = least(city);
    if(nCity == 999) {
        nCity = 0;
        printf("%d", nCity + 1);
        cost += arr[city][nCity];
        return;
    }
    minCost(nCity);
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