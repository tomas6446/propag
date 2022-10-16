#include <stdio.h>

int main() {
    int number = 1;
    int maximum_num = 0, maximum_counter = 0, counter = 0;
    while (number > 0) {
        scanf("%d", &number);
        int copy_number = number;
        while (copy_number > 0) {
            copy_number /= 10;
            counter++;
        }
        if (counter > maximum_counter) {
            maximum_counter = counter;
            maximum_num = number;
        }
        counter = 0;
    }
    printf("%d", maximum_num);
    return 0;
}
