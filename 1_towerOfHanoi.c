/*
    1. Write a program to solve the Tower of Hanoi problem.
*/

#include <stdio.h>
#include <time.h> 

int count = 0;

// Time complexity of Tower of Hanoi problem: O(2^n)

/**
 * @brief to simulate the Tower of Hanoi problem
 * @param n number of disks
 * @param beg beginning rod
 * @param mid middle rod
 * @param end ending rod
 */
void towerOfHanoi(int n, char beg, char mid, char end) { // beg = beginning, mid = middle, end = end
    if(n == 1) { // base case
        printf("%d. ", ++count); 
        printf("Moving disk 1 from tower %c to tower %c.\n", beg, end); 
        return;
    }
    towerOfHanoi(n - 1, beg, end, mid); 
    printf("%d. ", ++count); 
    printf("Moving disk %d from tower %c to tower %c.\n", n, beg, end); 
    towerOfHanoi(n - 1, mid, beg, end); 
}

int main() {
    int n, startTime, endTime, totalTime; 
    printf("Enter the number of disks: ");
    scanf("%d", &n); 
    startTime = clock(); 
    towerOfHanoi(n, 'A', 'C', 'B'); 
    endTime = clock(); 
    totalTime = endTime - startTime; 
    printf("\nStart Time = %d\nEnd Time = %d\nTotal Time = %d ms\n", startTime, endTime, totalTime);
    return 0;
}