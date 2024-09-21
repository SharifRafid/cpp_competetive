#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int m;
    char *buffer = NULL;
    size_t buffSize = 0;
    while (1)
    {
        if (getline(&buffer, &buffSize, stdin) == -1)
        {
            break;
        }
        if (strcmp(buffer, "\n") == 0)
        {
            break;
        }
        if (sscanf(buffer, "%d", &m) != 1)
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
            for (int i = 0; buffer[i] != '\0'; i++)
            {
                if (isdigit(buffer[i]))
                {
                    if (buffer[i] == '2' || buffer[i] == '3' || buffer[i] == '5' || buffer[i] == '7')
                    {
                    }
                    else
                    {
                        isSpr = 0;
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
