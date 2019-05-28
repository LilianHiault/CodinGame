#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int incrementerRiviere(int r)
{
    int riviere = r;
    int somme = 0;
    while(riviere != 0)
    {
        somme += riviere%10;
        riviere /= 10;
    }
    return r+somme;
}


int main()
{
    int r1;
    scanf("%d", &r1);
    int i = r1-1;
    int trouve = 0;
    while ((trouve==0) && (i>0))
    {
      int r2 = i;
      //printf("r2(i) = %d\n", r2);
      //while(r2<r1)
      //{
      r2 = incrementerRiviere(r2);
        //printf("Incrémentation r2 : %d\n", r2);
      //}
      if (r1==r2)
      {
        trouve = 1;
      }
      i--;
    }
    if (trouve==1)
    {
      printf("YES\n");
    }
    else
    {
      printf("NO\n");
    }
    return 0;
}
