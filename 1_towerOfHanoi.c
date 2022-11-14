/*
    1. Write a program to solve the Tower of Hanoi problem.
*/

# include <stdio.h>
# include <time.h> 

int count = 0;

void towerOfHanoi(int n, char beg, char mid, char end) { // beg = beginning, mid = middle, end = end
    if(n == 1) { // base case
        printf("%d. ", ++count); // print the count
        printf("Moving disk 1 from tower %c to tower %c.\n", beg, end); // move disk 1 from beg to end
        return;
    }
    towerOfHanoi(n - 1, beg, end, mid); // move n - 1 disks from beg to mid using end
    printf("%d. ", ++count); // print the count
    printf("Moving disk %d from tower %c to tower %c.\n", n, beg, end); // move nth disk from beg to end
    towerOfHanoi(n - 1, mid, beg, end); // move n - 1 disks from mid to end using beg
}

int main() {
    int n, startTime, endTime, totalTime; // n = number of disks
    printf("Enter the number of disks: "); // input the number of disks
    scanf("%d", &n); // store the number of disks in n
    startTime = clock(); // start time
    towerOfHanoi(n, 'A', 'C', 'B'); // call the function
    endTime = clock(); // end time
    totalTime = endTime - startTime; // total time
    printf("Total time taken is %d ms.\n", totalTime); // print the total time
    return 0;
}