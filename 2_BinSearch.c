/*
    2. Write a program to search for a key element in an array using binary search algorithm.
*/

#include <stdio.h>
#include <time.h>

int BinSearch(int arr[], int l, int h, int n) {
    if (h >= l) {
        int m = l + (h - l)/2;
        if (arr[m] == n) {
            return m;
        }
        if (arr[m] > n) {
            return BinSearch(arr, l, m-1, n);
        }    
        return BinSearch(arr, m+1, h, n);
    }
    return -1;
}

int main(void) {
    int arr[] = {1, 4, 7, 9, 16, 56, 70};
    int l = 0;
    int h = 7;
    int n, st, et, tt;
    printf("Enter a number: \n");
    scanf("%d", &n);
    st = clock();
    int i = BinSearch(arr, l, h-1, n);
    et = clock();
    tt = et - st;
    if(i == -1 ) {
        printf("Element %d not found in the array.\n", n);
    }
    else {
        printf("Element %d found at index: %d.\n", n, i);
    }
    printf("Total time taken is %d ms.\n", tt);
    return 0;
}