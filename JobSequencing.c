#include <stdio.h>
#include <stdlib.h>

// Structure to store job details
struct Job {
    int id;       // Job ID
    int deadline; // Deadline of job
    int profit;   // Profit of job
};

// Function to swap two jobs (for sorting)
void swap(struct Job *a, struct Job *b) {
    struct Job temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort jobs based on profit in descending order
void sortJobs(struct Job jobs[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (jobs[j].profit < jobs[j + 1].profit) {
                swap(&jobs[j], &jobs[j + 1]);
            }
        }
    }
}

// Function to find the maximum deadline
int findMaxDeadline(struct Job jobs[], int n) {
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }
    return maxDeadline;
}

// Function to perform Job Sequencing with Deadline
void jobSequencing(struct Job jobs[], int n) {
    // Step 1: Sort jobs in decreasing order of profit
    sortJobs(jobs, n);

    int maxDeadline = findMaxDeadline(jobs, n);
    
    int scheduledJobs[maxDeadline + 1]; // To store scheduled job IDs (0 means empty)
    for (int i = 0; i <= maxDeadline; i++) {
        scheduledJobs[i] = -1; // Initialize all slots as empty
    }

    int totalProfit = 0; // Variable to store maximum profit

    // Step 2: Schedule jobs one by one
    for (int i = 0; i < n; i++) {
        int jobID = jobs[i].id;
        int jobDeadline = jobs[i].deadline;
        int jobProfit = jobs[i].profit;

        // Find the latest available slot before the deadline
        for (int j = jobDeadline; j > 0; j--) {
            if (scheduledJobs[j] == -1) {
                scheduledJobs[j] = jobID;
                totalProfit += jobProfit;
                break;
            }
        }
    }

    // Step 3: Print the scheduled jobs and maximum profit
    printf("\nScheduled Jobs: ");
    for (int i = 1; i <= maxDeadline; i++) {
        if (scheduledJobs[i] != -1) {
            printf("Job%d ", scheduledJobs[i]);
        }
    }

    printf("\nMaximum Profit: %d\n", totalProfit);
}

// Main function
int main() {
    int n;

    // User input: Number of jobs
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    struct Job jobs[n];

    // Taking user input for jobs
    printf("Enter job details (ID, Deadline, Profit):\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d ID: ", i + 1);
        scanf("%d", &jobs[i].id);
        printf("Job %d Deadline: ", i + 1);
        scanf("%d", &jobs[i].deadline);
        printf("Job %d Profit: ", i + 1);
        scanf("%d", &jobs[i].profit);
    }

    // Perform job sequencing
    jobSequencing(jobs, n);

    return 0;
}