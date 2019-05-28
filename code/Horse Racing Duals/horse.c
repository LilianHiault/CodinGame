#include <stdlib.h>
#include <stdio.h>
#include <string.h>

 
 int compare(void const *a, void const *b)
 {
     int const *pa = a;
     int const *pb = b;
     return *pa-*pb;
}
 
int main()
{
    int n;
    int *tab = (int*) malloc(n*sizeof(int));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int Pi;
        scanf("%d", &Pi);
        tab[i] = Pi;
    }
    qsort(tab, n, sizeof(int ), compare);
    int j;
    int diff = tab[1] - tab[0];
    for (j=1; j<n; j++)
    {
        if ((tab[j] - tab[j-1]) <= diff)
        {
            diff = tab[j] - tab[j-1];
        }
    }
    printf("%d\n", diff);
    return 0;
}
