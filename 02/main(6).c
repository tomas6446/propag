#include <stdio.h>
#include <stdlib.h>

int maximum(int x, int y) {
    return (x > y) ? x : y;
}

int minimum(int x, int y) {
    return (x < y) ? x : y;
}

int main() {
    int x, y, z;
    printf("X = ");
    scanf("%d", &x);

    printf("Y = ");
    scanf("%d", &y);

    printf("Z = ");
    scanf("%d", &z);

    int max = maximum(maximum(x, y), maximum(maximum(x, y), z)); // max3 = maximum(max1, max2)
    int min = minimum(minimum(x, y), minimum(minimum(x, y), z)); // min3 = minimum(min1, min2)
    printf("Max = %d\nMin = %d\n", min, max);

    return 0;
}
