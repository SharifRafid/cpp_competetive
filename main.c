#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int m;
    while (1)
    {
        char inp[50];
        if (fgets(inp, sizeof(inp), stdin) == NULL)
        {
            break;
        }
        if (strcmp(inp, "\n") == 0)
        {
            break;
        }
        if (sscanf(inp, "%d", &m) != 1)
        {
            break;
        }
        int pr = 1;
        for (int i = 2; i < m; i++)
        {
            if (m % i == 0)
            {
                pr = 0;
                break;
            }
        }
        if (pr == 0 || m < 2)
        {
            printf("Nada\n");
        }
        else
        {
            int isSpr = 1;
            for (int i = 0; inp[i] != '\n' || inp[i] != '\0'; i++)
            {
                if (isdigit(inp[i]))
                {
                    if (inp[i] == '2' || inp[i] == '3' || inp[i] == '5' || inp[i] == '7')
                    {
                    }
                    else
                    {
                        isSpr == 0;
                        break;
                    }
                }
            }
            if (isSpr == 1)
            {
                printf("Super\n");
            }
            else
            {
                printf("Primo\n");
            }
        }
    }
    return 0;
}
