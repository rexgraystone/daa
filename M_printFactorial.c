/*
    M. Write a program to find the factorial of a number using recursion.
*/

#include <stdio.h>
#include <time.h>

unsigned int printFactorial(int n) { // n = number
    if(n == 1) { // base case
        return 1;
    }
    return n * printFactorial(n - 1); // recursive call
}

int main() {
    int n, st, et, tt; // n = number, st = start time, et = end time, tt = total time
    printf("Enter a number: "); // input the number
    scanf("%d", &n); // store the number in n
    st = clock(); // start time
    printf("\nThe factorial of %d is %d.", n, printFactorial(n));  // call the function
    et = clock(); // end time
    tt = et - st; // total time
    printf("\nThe total time taken to calculate the factorial of %d is %d ms.\n", n, tt); // print the total time
}