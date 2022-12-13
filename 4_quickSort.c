/*
    4. Write a program to sort an array using quick sort algorithm.
*/

#include <stdio.h>
#include <time.h>

// Time complexity of Quick Sort Algorithm: O(n log n), O(n^2) for worst case

int n = 15; // number of elements in the array

/**
 * @brief to swap two elements in an array
 * 
 * @param x pointer array element
 * @param y pointer array element
 */
void swap(int *x, int *y) { 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
}

/**
 * @brief to partition the array
 * 
 * @param arr array
 * @param l left index
 * @param h right index
 * @return (int) index of the pivot element
 */
int partition(int arr[n], int l, int h) { 
    int pivot = arr[l]; 
    int i = l; 
    int j = h; 
    while (i < j) { 
        do { 
            i++; 
        } while (arr[i] <= pivot); 
        do { 
            j--; 
        } while (arr[j] > pivot); 
        if(i < j) { 
            swap(&arr[i], &arr[j]); 
        }
    }
    swap(&arr[l], &arr[j]); // swap the pivot with the element at j
    return j; // return the index of the pivot
}

/**
 * @brief to sort the array using quick sort algorithm
 * 
 * @param arr array
 * @param l left index
 * @param h right index
 */
void quickSort(int arr[n], int l, int h) { // l = low, h = high
    if(l < h) { // run the loop until the array has only one element
        int j = partition(arr, l, h); 
        quickSort(arr, l, j); // sort the left subarray
        quickSort(arr, (j + 1), h); // sort the right subarray
    }
}

/**
 * @brief to enter the elements of the array
 * 
 * @param arr array
 */
void enterArr(int arr[n]) { 
    printf("Enter the elements for an array of size %d - \n\n", n); 
    for(int i = 0; i < n; i++) { 
        printf("\tEnter the element at position %d: ", i); 
        scanf("%d", &arr[i]);
    }
}

/**
 * @brief to display the elements of the array
 * 
 * @param arr array
 */
void printArr(int arr[n]) { 
    for(int i = 0; i < n; i++) { 
        printf("\tElement at position %d of the sorted array is: %d\n", i, arr[i]); 
    }
}

int main() {
    int arr[n]; 
    int startTime, endTime, totalTime; 
    enterArr(arr); 
    startTime = clock();
    quickSort(arr, 0, (n - 1)); 
    endTime = clock(); 
    printf("\nThe array has been sorted.\n\n"); 
    printArr(arr); 
    totalTime = endTime - startTime; 
    printf("\nStart Time = %d\nEnd Time = %d\nTotal Time = %d ms\n", startTime, endTime, totalTime);
    return 0; 
}