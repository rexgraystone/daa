/*
    3. Write a program to sort an array using merge sort algorithm.
*/

#include <stdio.h>
#include <time.h>

// Time complexity of Merge Sort Algorithm: O(n log n)

int n = 10; 

/**
 * @brief to merge two subarrays of arr[]
 * 
 * @param arr array
 * @param l left index
 * @param m middle index
 * @param r right index
 */
void simpleMerge(int arr[], int l, int mid, int h) { 
    int i, j, k, c[n]; 
    i = l; 
    j = mid + 1; 
    k = l; 
    while((i <= mid) && (j <= h)) { 
        if(arr[i] < arr[j]) { // copy the smaller element (at index i++) to c[]
            c[k++] = arr[i++]; 
        } else { // copy the smaller element (at index j++) to c[]
            c[k++] = arr[j++]; 
        }
    }
    while(i <= mid) { // copy the remaining elements from index i++ to c 
        c[k++] = arr[i++]; 
    }
    while(j <= h) { // copy the remaining elements from index j++ to c
        c[k++] = arr[j++]; 
    }
    for(i = l; i <= (k - 1); i++) { // copy the elements from c[] to arr[]
        arr[i] = c[i]; 
    }
}

/**
 * @brief to sort the array using merge sort algorithm
 * 
 * @param arr array
 * @param l left index
 * @param h right index
 */
void mergeSort(int arr[], int l, int h) { 
    int mid; 
    if(l < h) { 
        mid = (l + h)/2; 
        mergeSort(arr, l, mid); 
        mergeSort(arr, (mid + 1), h); 
        simpleMerge(arr, l, mid, h); 
    }
}

/**
 * @brief to print the array
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
 * @brief to print the array
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
    mergeSort(arr, 0, (n - 1));
    endTime = clock();
    printf("\nThe array has been sorted.\n\n");
    printArr(arr);
    totalTime = endTime - startTime;
    printf("\nStart Time = %d ms \nEnd Time = %d ms \nTotal Time = %d ms\n", startTime, endTime, totalTime); 
    return 0;
}