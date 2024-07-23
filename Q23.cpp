#include <stdio.h>
#include <stdlib.h>
int binomialCoefficient(int n, int k) {
    int i, j;
    int** C = (int**)malloc((n + 1) * sizeof(int*));
    for (i = 0; i <= n; i++) {
        C[i] = (int*)malloc((k + 1) * sizeof(int));
    }
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= (i < k ? i : k); j++) {
            if (j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
    }

    int result = C[n][k];
    for (i = 0; i <= n; i++) {
        free(C[i]);
    }
    free(C);

    return result;
}

int main() {
    int n, k;
    printf("Enter values for n and k: ");
    scanf("%d %d", &n, &k);

    printf("Binomial Coefficient C(%d, %d) = %d\n", n, k, binomialCoefficient(n, k));

    return 0;
}

