#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, num_count = 0;
    scanf("%d", &n);
    int n_copy = n;
    while (n_copy > 0) {
        num_count++;
        n_copy /= 10;
    }
    for (int i = num_count; i > 0; i--) {
        for (int j = i - 1; j > 0; j--) {
            int pow1 = pow(10, i - 1);
            int pow2 = pow(10, j - 1);

            int first = n / pow1 % 10;
            int second = n / pow2 % 10;
            (first > second) ? n = n - (first - second) * pow1 + (first - second) * pow2 : 0;
        }
    }
    printf("%d\n", n);
    return 0;
}
