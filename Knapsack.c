#include <stdio.h>

#define MAX 100

int n;                    // Number of items
float w[MAX], p[MAX];     // Weights and profits
float x[MAX];             // Fractions of items taken
float ratio[MAX];         // Profit/weight ratio

// Swap function for sorting
void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

// Sort items by decreasing profit/weight ratio
void sortItems() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                swap(&ratio[j], &ratio[j + 1]);
                swap(&w[j], &w[j + 1]);
                swap(&p[j], &p[j + 1]);
            }
        }
    }
}

void knapsack(float W) {
    float totalProfit = 0.0;
    float remaining = W;

    for (int i = 0; i < n; i++)
        x[i] = 0.0; // Initially, take 0 fraction of each item

    for (int i = 0; i < n; i++) {
        if (w[i] > remaining)
            break;
        x[i] = 1.0;               // Take full item
        remaining -= w[i];
    }

    if (remaining > 0 && n > 0) {
        for (int i = 0; i < n; i++) {
            if (x[i] == 0.0) {
                x[i] = remaining / w[i];  // Take fraction of item
                break;
            }
        }
    }

    // Calculate total profit
    for (int i = 0; i < n; i++)
        totalProfit += p[i] * x[i];

    // Print solution
    printf("\nItem fractions taken (x[i]):\n");
    for (int i = 0; i < n; i++)
        printf("x[%d] = %.2f\n", i + 1, x[i]);

    printf("Total profit = %.2f\n", totalProfit);
}

int main() {
    float W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter capacity of knapsack: ");
    scanf("%f", &W);

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%f", &w[i]);

    printf("Enter profits of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%f", &p[i]);

    // Calculate profit/weight ratio
    for (int i = 0; i < n; i++)
        ratio[i] = p[i] / w[i];

    sortItems(); // Sort items by ratio

    knapsack(W);

    return 0;
}
