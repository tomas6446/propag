#include <stdio.h>

int minimum(int a, int b, int c) {
    if (a < b && a < c) {
        return a;
    } else if (b < a && b < c) {
        return b;
    } else if (c < a && c < b) {
        return c;
    }
}

int dbd(int a, int b, int c, int min) {
    for (int i = min; i > 1; i--) {
        if ((a % i == 0) && (b % i == 0) && (c % i) == 0) {
            return i;
        }
    }
}

int mbk(int a, int b, int c, int min) {
    for (int i = 2; i <= min; i++) {
        if ((a % i == 0) && (b % i == 0) && (c % i) == 0) {
            return i;
        }
    }
}

int main() {
    int a, b, c;
    printf("Iveskite 3 naturaliuosius skaicius: \n");
    scanf("%d%d%d", &a, &b, &c);
    int min = minimum(a, b, c);
    printf("DBD: %d\n", dbd(a, b, c, min));
    printf("MBK: %d", mbk(a, b, c, min));
    return 0;
}
