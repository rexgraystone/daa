/*
    8. Write a C program to implement Longest Common Subsequence of two given strings using Dynamic Programming.
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
 
// Time complexity of Longest Common Subsequence: O(m*n)

#define MAX 100

int i, j, m, n, c[MAX][MAX];
char x[MAX], y[MAX], b[MAX][MAX];

/**
 * @brief to print the Longest Common Subsequence
 * 
 * @param i index of x
 * @param j index of y
 */ 
void printSequence(int i, int j) {
    if(i == 0 || j == 0) {
        return;
    }
    if(b[i][j] == 'c') {
        printSequence(i - 1, j - 1);
        printf("%c", x[i - 1]);
    } else if(b[i][j] == 'u') {
        printSequence(i - 1, j);
    } else {
        printSequence(i, j - 1);
    }
}

/**
 * @brief to find the Longest Common Subsequence
 * 
 * @param x string
 * @param y string
 */ 
void longestCommonSubsequence() {
    m = strlen(x);
    n = strlen(y);
    for(i = 0; i <= m; i++) {
        c[i][0] = 0;
    }
    for(i = 0; i <= n; i++) {
        c[0][i] = 0;   
    }
    //c, u and l denotes cross, upward and downward directions respectively
    for(i = 1; i <= m; i++) {
        for(j = 1; j <= n; j++) {
            if(x[i - 1] == y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'c';
            } else if(c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'u';
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'l';
            }
        }
    }
}
 
int main() {
    int startTime, endTime, totalTime;
    printf("Enter the 1st sequence: ");
    scanf("%s", x);
    printf("Enter the 2nd sequence: ");
    scanf("%s", y);
    printf("\nThe Longest Common Subsequence is ");
    startTime = clock();
    longestCommonSubsequence();
    printSequence(m, n);
    endTime = clock();
    totalTime = endTime - startTime;
    printf("\nStart Time = %d ms \nEnd Time = %d ms \nTotal Time = %d ms\n", startTime, endTime, totalTime);
    return 0;
}