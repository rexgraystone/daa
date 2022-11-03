/*
    3. Write a program to sort an array using merge sort.
*/

#include <stdio.h>
#include <time.h>

int n = 10;

void simpleMerge(int arr[], int l, int mid, int h)
{
    int i, j, k, c[n];
    i = l;
    j = mid+1;
    k = l;
    while((i<=mid)&&(j<=h))
    {
        if(arr[i]<arr[j])
        {
            c[k++] = arr[i++];
        }
        else
        {
            c[k++] = arr[j++];
        }
    }
    while(i<=mid)
    {
        c[k++] = arr[i++];
    }
    while(j<=h)
    {
        c[k++] = arr[j++];
    }
    for(i = l; i<=k-1; i++)
    {
        arr[i] = c[i];
    }
}

void mergeSort(int arr[], int l, int h)
{
    int mid;
    if(l<h)
    {
        mid = (l+h)/2;
        mergeSort(arr, l, mid-1);
        mergeSort(arr, mid+1, h);
        simpleMerge(arr, l, mid, h);
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
    mergeSort(arr, 0, n-1);
    et = clock();
    printf("\nThe array has been sorted.\n\n");
    printArr(arr);
    tt = et - st;
    printf("Total time taken is %d ms.\n", tt);
    return 0;
}