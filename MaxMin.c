#include <stdio.h>

#define MAX_SIZE 100  // Maximum array size

// Function to find Max and Min using Divide and Conquer
void MaxMin(int arr[], int i, int j, int *max, int *min) {
    int mid, max1, min1;

    // If there is only one element
    if (i == j) {
        *max = *min = arr[i];
        printf("Base Case: Single element [%d] -> Max: %d, Min: %d\n", arr[i], *max, *min);
        return;
    }

    // If there are two elements
    if (i == j - 1) {
        if (arr[i] < arr[j]) {
            *max = arr[j];
            *min = arr[i];
        } else {
            *max = arr[i];
            *min = arr[j];
        }
        printf("Base Case: Two elements [%d, %d] -> Max: %d, Min: %d\n", arr[i], arr[j], *max, *min);
        return;
    }

    // Divide the array into two halves
    mid = (i + j) / 2;
    printf("Dividing: [%d - %d] and [%d - %d]\n", i, mid, mid + 1, j);

    // Recursively find max and min in left half
    MaxMin(arr, i, mid, max, min);

    // Recursively find max and min in right half
    MaxMin(arr, mid + 1, j, &max1, &min1);

    // Combine results
    if (*max < max1) *max = max1;
    if (*min > min1) *min = min1;

    printf("Merging: [%d - %d] -> Max: %d, Min: %d\n", i, j, *max, *min);
}

int main() {
    int arr[MAX_SIZE], n, i, max, min;

    // Input: Size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Input: Array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call MaxMin function
    MaxMin(arr, 0, n - 1, &max, &min);

    // Output: Maximum and Minimum values
    printf("Final Result -> Max: %d, Min: %d\n", max, min);
    
    return 0;
}