/*
    4. Write a program to sort an array using quick sort algorithm.
*/

#include <stdio.h>
#include <time.h>

int n = 15; // number of elements in the array

void swap(int *x, int *y) { // swap the values of x and y
    int temp = *x; // store the value of x in temp
    *x = *y; // store the value of y in x
    *y = temp; // store the value of temp in y
}

int partition(int arr[n], int l, int h) { // l = low, h = high
    int pivot = arr[l]; // initialize pivot to the first element
    int i = l; // initialize i to low
    int j = h; // initialize j to high
    while (i < j) { // run the loop until i and j cross each other
        do { // run the loop until the element at i is greater than the pivot
            i++; // increment i
        } while (arr[i] <= pivot); // run the loop until the element at i is greater than the pivot
        do { // run the loop until the element at j is smaller than the pivot
            j--; // decrement j
        } while (arr[j] > pivot); // run the loop until the element at j is smaller than the pivot
        if(i < j) { // if i and j have not crossed each other
            swap(&arr[i], &arr[j]); // swap the elements at i and j
        }
    }
    swap(&arr[l], &arr[j]); // swap the pivot with the element at j
    return j; // return the index of the pivot
}

void quickSort(int arr[n], int l, int h) { // l = low, h = high
    if(l < h) { // run the loop until the array has only one element
        int j = partition(arr, l, h); // partition the array
        quickSort(arr, l, j); // sort the left subarray
        quickSort(arr, (j + 1), h); // sort the right subarray
    }
}

void enterArr(int arr[n]) { // enter the elements of the array
    printf("Enter the elements for an array of size %d - \n\n", n); // input the elements of the array
    for(int i = 0; i<n; i++) { // for all the elements in the array
        printf("\tEnter the element at position %d: ", i); // input the element
        scanf("%d", &arr[i]);
    }
}

void printArr(int arr[n]) { // print the elements of the array
    for(int i = 0; i<n; i++) { // for all the elements in the array
        printf("\tElement at position %d of the sorted array is: %d\n", i, arr[i]); // print the element
    }
}

int main() {
    int arr[n]; // array to be sorted
    int st, endTime, totalTime; 
    enterArr(arr); // call the function to enter the elements of the array
    st = clock(); // start time
    quickSort(arr, 0, (n - 1)); // call the function to sort the array
    endTime = clock(); // end time
    printf("\nThe array has been sorted.\n\n"); // print the array has been sorted
    printArr(arr); // call the function to print the elements of the array
    totalTime = endTime - st; // total time
    printf("Total time taken is %d ms.\n", totalTime); // print the total time
    return 0; 
}