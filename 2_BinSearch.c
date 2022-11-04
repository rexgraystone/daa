/*
    2. Write a program to search for a key element in an array using binary search algorithm.
*/

#include <stdio.h> 
#include <time.h> 

int binarySearch(int arr[], int l, int h, int n) { // l = low, h = high, n = number to be searched
    if (h >= l) { // base case
        int m = l + (h - l)/2; // calculate the middle index
        if (arr[m] == n) { // if the middle element is the number to be searched
            return m; // return the middle index
        }
        if (arr[m] > n) { // if the middle element is greater than the number to be searched
            return binarySearch(arr, l, m-1, n); // search in the left subarray
        }    
        return binarySearch(arr, m+1, h, n); // search in the right subarray
    }
    return -1; // if the number is not found
}

int main(void) { 
    int arr[] = {1, 4, 7, 9, 16, 56, 70}; // array to be searched
    int l = 0; // low index
    int h = 7; // high index
    int n, st, et, tt; // n = number to be searched, st = start time, et = end time, tt = total time
    printf("Enter a number: \n"); // input the number to be searched
    scanf("%d", &n); // store the number to be searched in n
    st = clock(); // start time
    int i = binarySearch(arr, l, h-1, n); // call the function
    et = clock(); // end time
    tt = et - st; // total time
    if(i == -1 ) { // if the number is not found
        printf("Element %d not found in the array.\n", n); // print the number is not found
    }
    else { // if the number is found
        printf("Element %d found at index: %d.\n", n, i); // print the number is found
    }
    printf("Total time taken is %d ms.\n", tt); // print the total time
    return 0;
}