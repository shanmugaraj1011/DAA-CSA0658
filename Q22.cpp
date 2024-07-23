#include <stdio.h>
#include <limits.h>

int optimalBST(int keys[], int freq[], int n) {
    int dp[n+1][n+1];
    
    for (int i = 1; i <= n; i++) {
        dp[i][i] = freq[i-1];
    }

    for (int length = 2; length <= n; length++) {
        for (int i = 1; i <= n - length + 1; i++) {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;

            int totalFreq = 0;
            for (int k = i; k <= j; k++) {
                totalFreq += freq[k-1];
            }

            for (int k = i; k <= j; k++) {
                int cost = totalFreq + (k > i ? dp[i][k-1] : 0) + (k < j ? dp[k+1][j] : 0);
                dp[i][j] = (cost < dp[i][j]) ? cost : dp[i][j];
            }
        }
    }

    return dp[1][n];
}

int main() {
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);

    int optimalCost = optimalBST(keys, freq, n);
    printf("Optimal Cost: %d\n", optimalCost);

    return 0;
}
