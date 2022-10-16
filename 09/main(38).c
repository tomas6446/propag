#include <stdio.h>
#include <math.h>

typedef struct Point point;

struct Point
{
    double x, y;
};

void printfPoint(point p)
{
    printf("(%.1f, %.1f)\n", p.x, p.y);
}

point createPoint(double x, double y)
{
    point point;
    point.x = x;
    point.y = y;
    return point;
}

double getDistance(point p1, point p2)
{
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

int main()
{
    point p1, p2;
    p1.x = 2.0, p1.y = -3.0;
    p2.x = -4.0, p2.y = 5.0;

    printfPoint(p1);
    printfPoint(p2);
    printfPoint(createPoint(1, 2));

    printf("%f\n", getDistance(createPoint(1, 2), createPoint(3, 5)));

    return 0;
}
