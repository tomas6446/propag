#include <stdio.h>

int fib(int a, int b, int c) {
    if (c == 0) {
        return a;
    }
    if (c == 1) {
        return b;
    }
    return fib(a, b, c - 1) + fib(a, b, c - 2);
}

int main() {
    int a, b, c;
    printf("Iveskite 3 neneigiamus sviekuosius skaicius: \n");
    scanf("%d%d%d", &a, &b, &c);
    printf("%d", fib(a, b, c));
    return 0;
}
