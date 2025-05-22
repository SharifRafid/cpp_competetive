#include <stdio.h>
#include <string.h>

void solve(int t)
{
    char inp[100];
    scanf("%s", inp);
    int sz = strlen(inp);
    char new[sz];
    int cI = 0;
    printf("Case %d: ", t + 1);
    for (int i = sz; i > 0; i--, cI++)
    {
        new[cI] = inp[i - 1];
    }
    new[cI] = '\0';
    if (strcmp(inp, new) == 0)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
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