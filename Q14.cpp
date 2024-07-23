#include <stdio.h>
#include <limits.h>

void findMinAndMax(int arr[], int size, int *min, int *max) {
    *min = INT_MAX;
    *max = INT_MIN;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the list: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min, max;
    findMinAndMax(arr, n, &min, &max);
    printf("The minimum value in the list is: %d\n", min);
    printf("The maximum value in the list is: %d\n", max);

    return 0;
}

