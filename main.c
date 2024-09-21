#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buffer = NULL;
    size_t buffSize = 0;

    while (1)
    {
        getline(&buffer, &buffSize, stdin);

        int n;
        sscanf(buffer, "%d", &n);

        // if (x == 0)
        // {
        //     break;
        // }

        for (int i = 0; i < n; i++)
        {
            int x;
            getline(&buffer, &buffSize, stdin);
            sscanf(buffer, "%d", &x);
            if (x % 2 == 0)
            {
                printf("0\n");
            }else{
                printf("1\n");
            }
        }

        break;
    }

    return 0;
}
