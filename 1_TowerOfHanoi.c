/*
    1. Write a program to solve Tower of Hanoi problem.
*/

#include <stdio.h>
#include <time.h>

int count = 0;

void TOH(int n, char beg, char mid, char end)
{
    if(n == 1)
    {
        printf("%d. ", ++count);
        printf("Moving disk 1 from tower %c to tower %c.\n", beg, end);
        return;
    }
    TOH(n - 1, beg, end, mid);
    printf("%d. ", ++count);
    printf("Moving disk %d from tower %c to tower %c.\n", n, beg, end);
    TOH(n - 1, mid, beg, end);
}

int main()
{
    int n, st, et, tt;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    st = clock();
    TOH(n, 'A', 'C', 'B');
    et = clock();
    tt = et - st;
    printf("Total time taken is %d ms.\n", tt);
    return 0;
}