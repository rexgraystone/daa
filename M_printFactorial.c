/*
    M. Write a program to find the factorial of a number using recursion.
*/

#include <stdio.h>
#include <time.h>

// Time complexity of Factorial Algorithm: O(n)

/**
 * @brief to find the factorial of a number
 * 
 * @param n number
 * @return int factorial of n
 */
unsigned int printFactorial(int n) { 
    if(n == 1) { // base case
        return 1;
    }
    return n * printFactorial(n - 1);
}

int main() {
    int n, startTime, endTime, totalTime; 
    printf("Enter a number: "); 
    scanf("%d", &n); 
    startTime = clock(); 
    printf("\nThe factorial of %d is %d.", n, printFactorial(n));  
    endTime = clock(); 
    totalTime = endTime - startTime; 
    printf("\nStart Time = %d ms \nEnd Time = %d ms \nTotal Time = %d ms\n", startTime, endTime, totalTime); 
}