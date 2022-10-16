#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    printf("3 sveikus skaicius (a, b, c):\n");
    scanf("%d%d%d", &a, &b, &c);
    int D = (b * b) - 4 * a * c;
    int x1 = (-b + sqrt(D)) / 2 * a, x2 = (-b - sqrt(D)) / 2 * a;
    if (D == 0) {
        printf( "Vienas sprendimas:\nx = %d\n", x1);
    } else if (D > 0) {
        printf("%s%d%s%d\n","Du sprendimai:\nx1 = ", x1, ", x2 = ", x2);
    } else if (D < 0) {
        printf("Sprendimu nera");
    }


    return 0;
}