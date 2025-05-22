#include <stdio.h>

void solve(int t)
{
    // printf("Case %d: ", t + 1);
    int b, p, f;
    scanf("%d%d%d", &b, &p, &f);
    int h, c;
    scanf("%d%d", &h, &c);
    int hb = 0;
    int cb = 0;
    if (h > c)
    {
        if (b >= (p * 2))
        {
            hb = p;
            b -= (p * 2);
            if (b >= (f * 2))
            {
                cb = f;
                b -= (f * 2);
            }
            else
            {
                cb = b / 2;
                b = 0;
            }
        }
        else
        {
            b = 0;
            hb = b / 2;
        }
    }
    else
    {
        if (b >= (f * 2))
        {
            cb = f;
            b -= (f * 2);
            if (b >= (p * 2))
            {
                hb = p;
            }
            else
            {
                hb = b / 2;
            }
        }
        else
        {
            cb = b / 2;
            b = 0;
        }
    }
    // printf("%d\n", (hb * h));
    // printf("%d\n", (cb * c));
    printf("%d\n", (hb * h) + (cb * c));
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
        solve(i);
    return 0;
}