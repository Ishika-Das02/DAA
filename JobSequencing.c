#include <stdio.h>

#define MAX 100

int n;               // Number of jobs
int d[MAX];          // Deadlines
int p[MAX];          // Profits
int J[MAX];          // Sequence of selected jobs

// Function to input and sort jobs by decreasing profit
void inputAndSort() {
    printf("Enter number of jobs: ");
    scanf("%d", &n);

    printf("Enter profits of jobs:\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);

    printf("Enter deadlines of jobs:\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &d[i]);

    // Sort jobs in decreasing order of profit
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (p[i] < p[j]) {
                int temp = p[i]; p[i] = p[j]; p[j] = temp;
                temp = d[i]; d[i] = d[j]; d[j] = temp;
            }
        }
    }
}

// Function implementing the Job Sequencing algorithm
int jobSequencing() {
    d[0] = 0; // Dummy initialization
    J[0] = 0;

    J[1] = 1; // Always include the first job
    int k = 1;

    for (int i = 2; i <= n; i++) {
        int r = k;

        // Find position r where job i can be inserted
        while ((d[J[r]] > d[i]) && (d[J[r]] != r))
            r--;

        if ((d[J[r]] <= d[i]) && (d[i] > r)) {
            // Shift jobs to make space
            for (int q = k; q > r; q--)
                J[q + 1] = J[q];

            J[r + 1] = i;
            k++;
        }
    }

    return k; // Return number of jobs selected
}

int main() {
    inputAndSort();

    int k = jobSequencing();

    printf("\nSelected jobs (index in sorted order):\n");
    int totalProfit = 0;
    for (int i = 1; i <= k; i++) {
        printf("Job %d (Profit: %d, Deadline: %d)\n", J[i], p[J[i]], d[J[i]]);
        totalProfit += p[J[i]];
    }

    printf("Total profit = %d\n", totalProfit);

    return 0;
}
