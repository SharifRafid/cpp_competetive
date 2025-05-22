#include <stdio.h>

void solve(int t)
{
    printf("Case %d: ", t + 1);
    int a, b;
    scanf("%d%d", &a, &b);
    if (a == b)
    {
        if (a == 0)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n", 11+(a*4)+8);
        }
    }
    else
    {
        printf("%d\n", (abs(a-b)*4)+11+(a*4)+8);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
        solve(i);
    return 0;
}