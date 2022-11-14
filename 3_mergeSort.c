/*
    3. Write a program to sort an array using merge sort algorithm.
*/

# include <stdio.h>
# include <time.h>

int n = 10; // number of elements in the array

void simpleMerge(int arr[], int l, int mid, int h) { // l = low, mid = middle, h = high
    int i, j, k, c[n]; // i = index for left subarray, j = index for right subarray, k = index for merged array, c = merged array
    i = l; // initialize i to low
    j = mid + 1; // initialize j to middle + 1
    k = l; // initialize k to low
    while((i <= mid) && (j <= h)) { // while both the subarrays are not empty
        if(arr[i] < arr[j]) { // if the left subarray element is smaller
            c[k++] = arr[i++]; // store the left subarray element in the merged array and increment both i and k
        } 
        else { // if the right subarray element is smaller
            c[k++] = arr[j++]; // store the right subarray element in the merged array and increment both j and k
        }
    }
    while(i <= mid) { // if the left subarray is not empty
        c[k++] = arr[i++]; // store the left subarray element in the merged array and increment i and k
    }
    while(j <= h) { // if the right subarray is not empty
        c[k++] = arr[j++]; // store the right subarray element in the merged array and increment j and k
    }
    for(i = l; i <= (k - 1); i++) { // for all the elements in the merged array
        arr[i] = c[i]; // store the merged array elements in the original array
    }
}

void mergeSort(int arr[], int l, int h) { // l = low, h = high
    int mid; // mid = middle
    if(l < h) { // run the loop until the array has only one element
        mid = (l + h)/2; // calculate the middle index
        mergeSort(arr, l, (mid - 1) ); // sort the left subarray
        mergeSort(arr, (mid + 1), h); // sort the right subarray
        simpleMerge(arr, l, mid, h); // merge the left and right subarrays
    }
}

void enterArr(int arr[n]) { // enter the elements of the array
    printf("Enter the elements for an array of size %d - \n\n", n); // input the elements of the array
    for(int i = 0; i < n; i++) { // for all the elements in the array
        printf("\tEnter the element at position %d: ", i); // input the element
        scanf("%d", &arr[i]); // store the element in the array
    }
}

void printArr(int arr[n]) { // print the elements of the array
    for(int i = 0; i < n; i++) { // for all the elements in the array
        printf("\tElement at position %d of the sorted array is: %d\n", i, arr[i]); // print the element
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
    printf("\nTotal time taken is %d ms.\n", totalTime);
    return 0;
}