#include <stdio.h>

int main()
{
    char a,b,c;
    scanf("%c", &a);
    scanf("%c", &b);
    scanf("%c", &c);
    printf("A = %c, B = %c, C = %c", a, b, c);
    printf("\n");
    printf("A = %c, B = %c, C = %c", b,c, a);
    printf("\n");
    printf("A = %c, B = %c, C = %c", c,a, b);
    printf("\n");
    return 0;
}