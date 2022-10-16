#include <stdio.h>
#include <math.h>

int main() {
    char type_name[4][10] = {"char", "short", "int/long", "long long"};
    for (int i = 1, data = 0; i <= 8; i, data++) {
        unsigned long long p = pow(2, i * 8);

        unsigned long long unsigned_a = 0;
        unsigned long long unsigned_b = p;

        long long signed_a = p / 2;
        long long signed_b = p / 2 - 1;

        for (int j = 0; j < 10; j++) {
            printf("%c", type_name[data][j]);
        }
        printf("%5d %s %5", i * 8, "bit ", "");
        if (data == 3) {
            signed_a *= 2;
            signed_b *= 2;
        }
        printf("%s %llu %llu %s %lld %lld %s", "unsigned [", unsigned_a, unsigned_b, "], unsigned [", -signed_a, signed_b, "] \n");
        i *= 2;
    }
    return 0;
}
