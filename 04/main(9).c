#include <stdio.h>

int main() {
    int a, b, c;
    printf("Iveskite 3 sveikuosius skaicius: \n");
    scanf("%d%d%d", &a, &b, &c);
    for (int i = a + 1; i <= b; i++) {
        if (i % c == 1) {
            printf("%d\n", i);
        }
    }
    return 0;
}
