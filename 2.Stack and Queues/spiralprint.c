#include <stdio.h>

// Function to print matrix in spiral order
void spiralPrint(int m, int n, int matrix[][10]) {
    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        // Print top row
        for (int i = left; i <= right; ++i) {
            printf("%d ", matrix[top][i]);
        }
        top++;

        // Print right column
        for (int i = top; i <= bottom; ++i) {
            printf("%d ", matrix[i][right]);
        }
        right--;

        // Print bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }

        // Print left column
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }
}

int main() {
    int m, n, matrix[10][10];

    printf("Enter the number of rows and columns for the matrix: ");
    scanf("%d %d", &m, &n);

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &matrix[i][j]);

    printf("\nSpiral Order Matrix:\n");
    spiralPrint(m, n, matrix);

    return 0;
}




