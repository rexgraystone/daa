/*
    2. Write a program to search for a key element in an array using binary search algorithm.
*/

#include <stdio.h> 
#include <time.h> 

// Time complexity of Binary Search Algorithm: O(log n)

/**
 * @brief to search for a key element in an array using binary search algorithm
 * @param arr array
 * @param n size of array
 * @param key key element to be searched
 * @return int index of key element if found, else -1
 */
int binarySearch(int arr[], int l, int h, int n) { // l = low, h = high, n = number to be searched
    if (h >= l) { // base case
        int m = l + (h - l)/2; // calculate the middle index
        if (arr[m] == n) { 
            return m; 
        }
        if (arr[m] > n) { 
            return binarySearch(arr, l, m - 1, n); 
        }    
        return binarySearch(arr, m + 1, h, n); 
    }
    return -1; 
}

int main(void) { 
    int arr[] = {1, 4, 7, 9, 16, 56, 70}; 
    int l = 0; 
    int h = 7; 
    int n, startTime, endTime, totalTime; 
    printf("Enter a number: \n"); 
    scanf("%d", &n); 
    startTime = clock(); 
    int i = binarySearch(arr, l, h - 1, n); 
    endTime = clock(); 
    totalTime = endTime - startTime; 
    if(i == -1 ) { 
        printf("Element %d not found in the array.\n", n); 
    } else { 
        printf("Element %d found at index: %d.\n", n, i); 
    }
    printf("\nStart Time = %d\nEnd Time = %d\nTotal Time = %d ms\n", startTime, endTime, totalTime);
    return 0;
}