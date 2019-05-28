#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void deplacement(char ** diagramme, int H, int L)
{
    int k=0;
    int i,j;
    for (k=0; k<L; k+=3)
    {
        // Une itération pour chaque lettre
        i=1;
        j=k;
        for(i=1; i<H; i++)
        {
            if ((j>1) && (diagramme[i][j-1] == '-'))
            {
                j-=3;
            }
            else if ((j<L-1) && (diagramme[i][j+1] == '-'))
            {
                j+=3;
            }
          }
        printf("%c%c\n", diagramme[0][k], diagramme[H-1][j]);
      }
}



int main()
{
    int L = 0;
    int H = 0;
    //Entrée de la largeur et de la hauteur
    scanf("%d%d", &L, &H);
    fgetc(stdin);
    char ** diagramme = (char **) malloc(L*sizeof(char*));
    int i;
    for(i=0; i<H; i++)
    {
        diagramme[i]=(char *) malloc(L*sizeof(char));
        fgets(diagramme[i], 1025, stdin);
    }
    deplacement(diagramme, H, L);
    free(diagramme);
    return 0;
}
