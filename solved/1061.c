#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sD, sH, sM, sS;
    int eD, eH, eM, eS;

    char *buffer = NULL;
    size_t buffSize = 0;

    getline(&buffer, &buffSize, stdin);
    sscanf(buffer, "Dia %d", &sD);
    getline(&buffer, &buffSize, stdin);
    sscanf(buffer, "%d : %d : %d", &sH, &sM, &sS);
    getline(&buffer, &buffSize, stdin);
    sscanf(buffer, "Dia %d", &eD);
    getline(&buffer, &buffSize, stdin);
    sscanf(buffer, "%d : %d : %d", &eH, &eM, &eS);

    long sTotal = (sD * 24 * 3600) + (sH * 3600) + (sM * 60) + sS;
    long eTotal = (eD * 24 * 3600) + (eH * 3600) + (eM * 60) + eS;

    long diff = eTotal - sTotal;

    printf("%ld dia(s)\n", diff / (24 * 3600));

    printf("%ld hora(s)\n", (diff % (24 * 3600)) / 3600);

    printf("%ld minuto(s)\n", ((diff % (24 * 3600)) % 3600) / 60);

    printf("%ld segundo(s)\n", (((diff % (24 * 3600)) % 3600) % 60));

    return 0;
}
