#include <stdio.h>

// Function for iterative binary search
int iterative_binary_search(int A[], int key, int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;
        printf("Step: low = %d, high = %d, mid = %d, A[mid] = %d\n", low, high, mid, A[mid]);
        
        if (A[mid] == key)
            return mid; // Key found
        else if (key < A[mid])
            high = mid - 1; // Search left half
        else
            low = mid + 1; // Search right half
    }
    return -1; // Key not found
}

int main() {
    int n, key, result;
    
    // Taking array size as input
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int A[n];
    // Taking sorted array elements as input
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    
    // Taking key to search
    printf("Enter the key to search: ");
    scanf("%d", &key);
    
    // Perform binary search
    result = iterative_binary_search(A, key, 0, n - 1);
    
    // Print result
    if (result != -1)
        printf("Key found at index %d\n", result);
    else
        printf("Key not found\n");
    
    return 0;
}