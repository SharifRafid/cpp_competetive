#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buffer = NULL;
    size_t buffSize = 0;

    getline(&buffer, &buffSize, stdin);
    int x;
    sscanf(buffer, "%d", &x);
    int c = 0, r = 0, s = 0;
    for (int i = 0; i < x; i++)
    {
        int d;
        getline(&buffer, &buffSize, stdin);
        char chr;
        sscanf(buffer, "%d %c", &d, &chr);
        if (chr == 'C')
        {
            c += d;
        }
        else if (chr == 'R')
        {
            r += d;
        }
        else if (chr == 'S')
        {
            s += d;
        }
    }
    printf("Total: %d cobaias\n", c + r + s);
    printf("Total de coelhos: %d\n", c);
    printf("Total de ratos: %d\n", r);
    printf("Total de sapos: %d\n", s);
    printf("Percentual de coelhos: %0.2lf %%\n", ((double)c / (double)(c + r + s)) * 100);
    printf("Percentual de ratos: %0.2lf %%\n", ((double)r / (double)(c + r + s)) * 100);
    printf("Percentual de sapos: %0.2lf %%\n", ((double)s / (double)(c + r + s)) * 100);

    return 0;
}
