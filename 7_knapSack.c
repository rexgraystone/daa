/*
    7. Write a C program to implement 0/1 Knapsack problem using Dynamic Programming.
*/

#include <stdio.h>
#include <time.h>
 
// Time complexity of 0/1 Knapsack problem: O(n^2)

/**
 * @brief a utility function that returns the maximum of two integers
 * 
 * @param a first integer
 * @param b second integer
 * @return int 
 */
int max(int a, int b)  { 
    return (a > b) ? a : b; 
}

/**
 * @brief to solve the 0/1 Knapsack problem using Dynamic Programming
 * 
 * @param W capacity of the knapsack
 * @param wt array of weights
 * @param val array of values
 * @param n number of items
 * @return (int) the maximum value that can be put in a knapsack of capacity W 
 */
int knapSack(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0) { // Base Case
        return 0;
    }
    if (wt[n - 1] > W) {
        return knapSack(W, wt, val, n - 1);
    } else {
        return max(
                    val[n - 1]+ knapSack(W - wt[n - 1], wt, val, n - 1),
                    knapSack(W, wt, val, n - 1));
    }
}
 
int main() {
    int val[] = {60, 100, 40, 50, 70, 30, 40, 20, 10, 15};
    int wt[] = {5, 10, 10, 15, 15, 15, 20, 20, 25};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    int startTime, endTime, totalTime;
    startTime = clock();
    printf("%d", knapSack(W, wt, val, n));
    endTime = clock();
    totalTime = endTime - startTime;
    printf("\nStart Time = %d ms \nEnd Time = %d ms \nTotal Time = %d ms\n", startTime, endTime, totalTime);
    return 0;
}