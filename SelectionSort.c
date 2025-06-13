#include <stdio.h>

// Function to print the array at each step
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    int i, j, minIdx, temp;
    
    printf("\nSorting steps:\n");
    for (i = 0; i < n - 1; i++) {
        minIdx = i; // Assume the first element of unsorted part as minimum
        
        // Find the minimum element in the unsorted part
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        if (minIdx != i) {
            temp = arr[minIdx];
            arr[minIdx] = arr[i];
            arr[i] = temp;
        }

        // Print the array after each pass
        printf("Step %d: ", i + 1);
        printArray(arr, n);
    }
}

int main() {
    int n;

    // Taking user input for array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Taking user input for array elements
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Display original array
    printf("\nOriginal Array: ");
    printArray(arr, n);

    // Perform selection sort and show steps
    selectionSort(arr, n);

    // Display sorted array
    printf("\nSorted Array: ");
    printArray(arr, n);

    return 0;
}