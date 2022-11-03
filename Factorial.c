#include<stdio.h>
#include<time.h>

unsigned int factorial(int n)
{
    if(n == 1)
    {
        return 1;
    }
    return n * factorial(n-1);
}

int main()
{
    int n = 5, st, et, tt;
    st = clock();
    printf("\nThe factorial of %d is %d.", n, factorial(n)); 
    et = clock();
    tt = et - st;
    printf("\nThe total time taken to calculate the factorial of %d is %d ms.\n", n, tt);
}