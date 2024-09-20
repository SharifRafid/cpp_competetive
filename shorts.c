#include <stdio.h>

int main()
{
    char a,b,c;
    scanf("%c", &a);
    printf("\n");
    long long a, b;
    scanf("%lld%lld",&a, &b);
    long count = b-a+1;
    printf("%lld\n", (count*(a+b))/2);
    return 0;
}