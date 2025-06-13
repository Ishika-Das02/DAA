#include <stdio.h>

// Structure to store item details
struct Item {
    int weight;
    int value;
    double ratio; // value/weight ratio
};

// Function to swap two items
void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort items based on value-to-weight ratio (Descending Order)
void sortItems(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                swap(&items[j], &items[j + 1]);
            }
        }
    }
}

// Function to solve the Fractional Knapsack problem
double fractionalKnapsack(int W, struct Item items[], int n) {
    // Step 1: Sort items by value-to-weight ratio
    sortItems(items, n);

    double totalValue = 0.0; // Total maximum value
    int remainingCapacity = W; // Remaining capacity of knapsack

    printf("\nStep-by-step selection:\n");

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remainingCapacity) {
            // Step 2a: Take the whole item
            remainingCapacity -= items[i].weight;
            totalValue += items[i].value;
            printf("Taking full Item %d (Weight: %d, Value: %d)\n", i + 1, items[i].weight, items[i].value);
        } else {
            // Step 2b: Take a fraction of the item
            double fraction = (double)remainingCapacity / items[i].weight;
            totalValue += items[i].value * fraction;
            printf("Taking %.2f fraction of Item %d (Weight: %d, Value: %d)\n", fraction, i + 1, items[i].weight, items[i].value);
            break; // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int n, W;

    // User input: Number of items and Knapsack capacity
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    struct Item items[n];

    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &items[i].weight);
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &items[i].value);
        items[i].ratio = (double)items[i].value / items[i].weight; // Calculate value-to-weight ratio
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    // Solve the problem and print the result
    double maxValue = fractionalKnapsack(W, items, n);
    printf("\nMaximum value obtained: %.2f\n", maxValue);

    return 0;
}