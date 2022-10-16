#include <stdio.h>

int main() {
    int n, digit;
    printf("Iveskite n: ");
    scanf("%d", &n);
    int max = n, min = n, sum = 0, average;
    for (int i = 0; i < n; i++) {
        scanf("%d", &digit);
        sum += digit;
        if (max < digit) {
            max = digit;
        }
        if (min > digit) {
            min = digit;
        }
    }
    average = sum / n;
    printf("Suma: %d\n Average: %d\n Maximum: %d\n Minimum: %d\n", sum, average, max, min);
    return 0;
}
