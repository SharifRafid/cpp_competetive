#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    double d = (b * b) - (4 * a * c);
    if (d < 0 || a == 0)
    {
        printf("Impossivel calcular\n");
    }
    else
    {
        double e = -b + sqrt(d);
        double f = -b - sqrt(d);
        printf("R1 = %0.5lf\n", e / 2 * a);
        printf("R2 = %0.5lf\n", f / 2 * a);
    }
    return 0;
}
