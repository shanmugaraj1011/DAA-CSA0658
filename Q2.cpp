#include <stdio.h>

int isArmstrong(int num) {
    int originalNum = num;
    int sum = 0;
    int numDigits = 0;

    while (num != 0) {
        numDigits++;
        num /= 10;
    }

    num = originalNum;

    while (num != 0) {
        int digit = num % 10;
        sum += digit * digit * digit;
        num /= 10;
    }

    return sum == originalNum;
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isArmstrong(num)) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }

    return 0;
}
