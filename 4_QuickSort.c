/*
    4. Write a program to sort an array using quick sort.
*/

#include <stdio.h>
#include <time.h>

int n = 15;

void swap(int *x, int *y) 
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int arr[n], int l, int h)
{
    int pivot = arr[l];
    int i = l;
    int j = h;
    while (i<j)
    {
        do
        {
            i++;
        } while (arr[i]<=pivot);
        do
        {
            j--;
        } while (arr[j]>pivot);
        if(i<j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[l], &arr[j]);
    return j;
}

void quickSort(int arr[n], int l, int h)
{
    if(l<h)
    {
        int j = partition(arr, l, h);
        quickSort(arr, l, j);
        quickSort(arr, j+1, h);
    }
}

void enterArr(int arr[n])
{
    printf("Enter the elements for an array of size %d - \n\n", n);
    for(int i = 0; i<n; i++)
    {
        printf("\tEnter the element at position %d: ", i);
        scanf("%d", &arr[i]);
    }
}

void printArr(int arr[n])
{
    for(int i = 0; i<n; i++)
    {
        printf("\tElement at position %d of the sorted array is: %d\n", i, arr[i]);
    }
}

int main()
{
    int arr[n];
    int st, et, tt;
    enterArr(arr);
    st = clock();
    quickSort(arr, 0, n-1);
    et = clock();
    printf("\nThe array has been sorted.\n\n");
    printArr(arr);
    tt = et - st;
    printf("Total time taken is %d ms.\n", tt);
    return 0;
}