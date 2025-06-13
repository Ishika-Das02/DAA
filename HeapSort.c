#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the max-heap property
void maxHeapify(int arr[], int n, int i) {
    int largest = i;  // Initialize the largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        printf("Swapping %d and %d\n", arr[i], arr[largest]);
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected sub-tree
        maxHeapify(arr, n, largest);
    }
}

// Function to build a max heap
void buildMaxHeap(int arr[], int n) {
    printf("Building max heap...\n");
    for (int i = n / 2 - 1; i >= 0; i--) {
        printf("Heapifying at index %d...\n", i);
        maxHeapify(arr, n, i);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    // Step 1: Build max heap
    buildMaxHeap(arr, n);

    // Step 2: Extract elements one by one
    printf("Performing heap sort...\n");
    for (int i = n - 1; i > 0; i--) {
        printf("Swapping root %d with %d\n", arr[0], arr[i]);
        swap(&arr[0], &arr[i]);

        // Reduce heap size and heapify the root
        printf("Heapifying root after swap...\n");
        maxHeapify(arr, i, 0);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int arr[100], n;

    // Input: Size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input: Array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print initial array
    printf("Initial array: ");
    printArray(arr, n);

    // Perform heap sort
    heapSort(arr, n);

    // Print sorted array
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}