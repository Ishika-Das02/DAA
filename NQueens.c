#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int x[MAX]; // x[k] stores the column number of the queen in row k
int board[MAX][MAX];

// Display current board state (for intermediate steps)
void printBoard(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i] == j)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
    printf("\n");
}

// Check if queen can be placed at row k and column i
int Place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return 0; // conflict
    }
    return 1;
}

// Recursive function to solve N-Queens
void NQueens(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (Place(k, i)) {
            x[k] = i;
            printBoard(k); // Show intermediate board

            if (k == n) {
                // Found one solution - print array
                printf("Solution: ");
                for (int j = 1; j <= n; j++) {
                    printf("%d ", x[j]);
                }
                printf("\n\n");
            } else {
                NQueens(k + 1, n);
            }

            // Backtrack step (optional to clear)
            x[k] = 0;
        }
    }
}

int main() {
    int n;

    printf("Enter number of queens (n): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Enter a value between 1 and %d.\n", MAX);
        return 1;
    }

    printf("\nIntermediate steps and solutions:\n\n");
    NQueens(1, n);

    return 0;
}




// #include <stdio.h>
// #include <stdlib.h>

// #define MAX 20

// int x[MAX]; // x[k] = column position of queen in row k

// // Check if placing a queen at (k, i) is valid
// int Place(int k, int i) {
//     for (int j = 1; j < k; j++) {
//         if (x[j] == i || abs(x[j] - i) == abs(j - k))
//             return 0; // Conflict: same column or diagonal
//     }
//     return 1; // Safe to place
// }

// // Backtracking function to solve N-Queens
// void NQueens(int k, int n) {
//     for (int i = 1; i <= n; i++) {
//         if (Place(k, i)) {
//             x[k] = i;
//             if (k == n) {
//                 // All queens placed: print the solution
//                 for (int j = 1; j <= n; j++)
//                     printf("%d ", x[j]);
//                 printf("\n");
//             } else {
//                 NQueens(k + 1, n);
//             }
//         }
//     }
// }

// int main() {
//     int n;
//     printf("Enter number of queens (n): ");
//     scanf("%d", &n);

//     if (n < 1 || n > MAX) {
//         printf("Please enter a valid value (1-%d).\n", MAX);
//         return 1;
//     }

//     printf("Solutions:\n");
//     NQueens(1, n);

//     return 0;
// }
