#include <stdio.h>

#define CAPACITY 10

int main()
{
    // a) apibrėžia masyvą, galinti sutalpinti 10 elementų, tame pačiame sakinyje inicializuodama juos nulinėmis reikšmėmis

    int array[CAPACITY] = {0};

    // b) atspausdina visą masyvą į ekraną

    for (int i = 0; i < CAPACITY; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    // c) pačiam pirmam, ketvirtam ir dešimtam masyvo elementams priskiria reikšmes atitinkamai 1, 2 ir 3

    array[0] = 1; // pirmas elementas
    array[3] = 2; // ketvirtas el
    array[9] = 3; // desimtas el

    // d) ištrina iš masyvo trečią elementą

    for (int i = 2; i < CAPACITY; i++)
    {
        array[i] = array[i + 1];
    }

    // e) įterpia į masyvą naują elementą su reikšme 4

    for (int i = CAPACITY; i >= 6; i--)
    {
        array[i] = array[i - 1];
    }
    array[6] = 4;

    // f) atspausdina visą masyvą į ekraną

    for (int i = 0; i < CAPACITY; i++)
    {
        printf("%d ", array[i]);
    }

    // g) elementui su indeksu x nustato naują reikšmę, lygią y

    int x, y;
    printf("\nIveskite du skaicius(x ir y) (nauja reiksme y, su indeksu x): ");
    scanf("%d %d", &x, &y);
    array[x] = y;

    // h) ištrina iš masyvo elementą su indeksu x

    printf("\nIveskite viena skaiciu (x) (istrina elementa x): ");
    scanf("%d", &x);
    for (int i = x; i < CAPACITY; i++)
    {
        array[i] = array[i + 1];
    }

    // j)  įterpia naują elementą su reikšme y, su indeksu x

    printf("\nIveskite skaicius (x ir y) (iterpia elementa su reiksme y): ");
    scanf("%d %d", &x, &y);
    for (int i = CAPACITY; i >= x; i--)
    {
        array[i] = array[i - 1];
    }
    array[x] = y;

    // j) atspausdina visą masyvą į ekraną

    for (int i = 0; i < CAPACITY; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
