#include <stdio.h>
#include <limits.h>

#define MAX_N 20

int n; 
int dist[MAX_N][MAX_N]; 
int dp[MAX_N][1 << MAX_N]; 
int tsp(int pos, int mask) {
    if (mask == ((1 << n) - 1)) {
        return dist[pos][0];
    }

    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }

    int minCost = INT_MAX;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) { 
            int newCost = dist[pos][city] + tsp(city, mask | (1 << city));
            if (newCost < minCost) {
                minCost = newCost;
            }
        }
    }

    return dp[pos][mask] = minCost;
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i][j] = -1;
        }
    }

    int result = tsp(0, 1); 
    printf("The minimum cost of visiting all cities is: %d\n", result);

    return 0;
}

