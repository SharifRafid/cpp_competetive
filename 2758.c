#include <stdio.h>

int main()
{
    double a, b, c, d;
    scanf("%lf%lf", &a, &b);
    scanf("%lf%lf", &c, &d);
    printf("A = %0.6lf, B = %0.6lf", a, b);
    printf("C = %0.6lf, D = %0.6lf", c, d);
    printf("A = %0.1lf, B = %0.1lf", a, b);
    printf("C = %0.1lf, D = %0.1lf", c, d);
    printf("A = %0.2lf, B = %0.2lf", a, b);
    printf("C = %0.2lf, D = %0.2lf", c, d);
    printf("A = %0.3lf, B = %0.3lf", a, b);
    printf("C = %0.3lf, D = %0.3lf", c, d);

    printf("A = %0.3E, B = %0.3E", a, b);
    printf("C = %0.3E, D = %0.3E", c, d);

    printf("A = %d, B = %d", (int)a, (int)b);
    printf("C = %d, D = %d", (int)c, (int)d);
    return 0;
}
