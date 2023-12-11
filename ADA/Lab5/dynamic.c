#include <stdio.h>
#include <math.h>

int main() {
    int n, w;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("\nEnter the knapsack capacity: ");
    scanf("%d", &w);

    int val[n], wt[n];
    for (int i = 0; i < n; i++) {
        printf("\nEnter the weight for the %d element: ", i + 1);
        scanf("%d", &wt[i]);
        printf("Enter the value for the %d element: ", i + 1);
        scanf("%d", &val[i]);
    }

    printf("Entered values are:\n");
    for (int i = 0; i < n; i++) {
        printf("\nFor the %d element\nWeight - %d\nValue - %d\n", i + 1, wt[i], val[i]);
    }

    int b[n + 1][w + 1];
    for (int x = 0; x <= n; x++) {
        b[x][0] = b[0][x] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (wt[i - 1] <= j) {
                if (val[i - 1] + b[i - 1][j - wt[i - 1]] > b[i - 1][j] && j - wt[i - 1] >= 0) {
                    b[i][j] = val[i - 1] + b[i - 1][j - wt[i - 1]];
                } else {
                    b[i][j] = b[i - 1][j];
                }
            } else {
                b[i][j] = b[i - 1][j];
            }

            printf("\n\n");
            for (int z = 0; z <= n; z++) {
                for (int y = 0; y <= w; y++) {
                    printf("%d ", b[z][y]);
                }
                printf("\n");
            }
            printf("\n\n");
        }
    }

    printf("Max profit earned: %d\n", b[n][w]);
    return 0;
}
