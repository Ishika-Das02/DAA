#include <stdio.h>

// Function to solve Tower of Hanoi
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;
    
    // Taking user input for number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Calling the Tower of Hanoi function
    printf("\nSteps to solve Tower of Hanoi for %d disks:\n", n);
    towerOfHanoi(n, 'A', 'B', 'C');  // A = Source, B = Auxiliary, C = Destination

    return 0;
}
