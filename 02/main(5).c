#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	double x, y, z;
	printf("X = ");
	scanf("%lf", &x);

	printf("Y = ");
	scanf("%lf", &y);

	printf("Z = ");
	scanf("%lf", &z);
	//a
	printf("%f\n", x + 4*y + pow(z, 3));
	//b
	printf("%lf", (x + sqrt(y)) * (pow(z, 4) - fabs(z) + 46.3));
    return 0;
}
