#include <stdio.h>

int main()
{
    int sD, sH, sM, sS;
    int eD, eH, eM, eS;
    scanf("Dia %d", &sD);
    scanf("%d : %d : %d", &sH, &sM, &sS);
    scanf("Dia %d", &eD);
    scanf("%d : %d : %d", &eH, &eM, &eS);

    long sTotal = (sD * 24 * 3600) + (sH * 3600) + (sM * 60) + sS;
    long eTotal = (eD * 24 * 3600) + (eH * 3600) + (eM * 60) + eS;

    long diff = eTotal - sTotal;

    printf("%d dia(s)\n", diff / (24 * 3600));

    printf("%d hora(s)\n", (diff % (24 * 3600)) / 3600);

    printf("%d minuto(s)\n", ((diff % (24 * 3600)) % 3600) / 60);

    printf("%d segundo(s)\n", (((diff % (24 * 3600)) % 3600) % 60));

    return 0;
}
