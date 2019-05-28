#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long long incrementerRiviere(long long  r)
{
    long long riviere = r;
    long long somme = 0;
    while(riviere != 0)
    {
        somme += riviere%10;
        riviere /= 10;
    }
    return r+somme;
}

int main()
{
    long long r1;
    scanf("%lld", &r1);
    long long r2;
    scanf("%lld", &r2);
    while (r1 != r2)
    {
        while (r1 < r2)
        {
            r1 = incrementerRiviere(r1);
        }
        while (r1 > r2)
        {
            r2 = incrementerRiviere(r2);
        }
    }
    printf("%lld", r1);
    return 0;
}
