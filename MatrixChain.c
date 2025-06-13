#include <stdio.h>
#include <limits.h>

#define MAX 20

int m[MAX][MAX];  // Minimum multiplication costs
int s[MAX][MAX];  // Split points for optimal parenthesization

// Function to print optimal parenthesization
void printOptimalParens(int i, int j) {
    if (i == j)
        printf("A%d", i);
    else {
        printf("(");
        printOptimalParens(i, s[i][j]);
        printOptimalParens(s[i][j] + 1, j);
        printf(")");
    }
}

void MatrixChainOrder(int p[], int n) {
    for (int i = 1; i < n; i++)
        m[i][i] = 0;  // Single matrix has zero cost

    for (int chainLen = 2; chainLen < n; chainLen++) {
        for (int i = 1; i <= n - chainLen; i++) {
            int j = i + chainLen - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}
int main() {
    int p[MAX];
    int n;

    printf("Enter number of matrices: ");
    scanf("%d", &n);  // Number of matrices A1 to An → total dimensions = n+1

    printf("Enter %d dimensions (p0 to p%d):\n", n, n);
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    MatrixChainOrder(p, n + 1);

    printf("\nMinimum number of multiplications: %d\n", m[1][n]);

    printf("Optimal Parenthesization: ");
    printOptimalParens(1, n);
    printf("\n");

    return 0;
}
