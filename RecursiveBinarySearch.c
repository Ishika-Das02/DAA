#include <stdio.h>

// Function for recursive binary search
int recursive_binary_search(int A[], int key, int low, int high) {
    if (low > high)
        return -1; // Key not found
    
    int mid = (low + high) / 2;
    printf("Step: low = %d, high = %d, mid = %d, A[mid] = %d\n", low, high, mid, A[mid]);
    
    if (A[mid] == key)
        return mid; // Key found
    else if (key < A[mid])
        return recursive_binary_search(A, key, low, mid - 1); // Search left half
    else
        return recursive_binary_search(A, key, mid + 1, high); // Search right half
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
    
    // Perform recursive binary search
    result = recursive_binary_search(A, key, 0, n - 1);
    
    // Print result
    if (result != -1)
        printf("Key found at index %d\n", result);
    else
        printf("Key not found\n");
    
    return 0;
}