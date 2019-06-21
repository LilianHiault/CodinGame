#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void deplacement(char ** diagramme, int H, int L)
// Associe les caractères du haut et du bas du diagramme en parcourant les lignes et colonnes
{
  int k=0;
  int i,j;
  for (k=0; k<L; k+=3)
  {
    // Une itération pour chaque caractère 'k' en haut du diagramme
    i=1; // 'i' est l'ordonnée du curseur qui va parcourir le diagramme (ligne) : initialisé à la première ligne
    j=k; // 'j' est son abscisse (colonne) : initialisé à la même colonne que le caractère
    for(i=1; i<H; i++)
    {
      // Pour chaque ligne on vérifie si il ne faut pas changer de colonne
      if ((j>1) && (diagramme[i][j-1] == '-'))
      // Si le caractère à gauche est une ligne alors il faut se déplacer sur colonne de gauche : on se décale de 3 caractères
      {
        j-=3;
      }
      else if ((j<L-1) && (diagramme[i][j+1] == '-'))
      // Idem à droite
      {
        j+=3;
      }
      // Si il n'y a pas de ligne horizontale, 'j' reste sur la colonne actuelle
    }
    printf("%c%c\n", diagramme[0][k], diagramme[H-1][j]);
    // Pour chaque caractère du haut on l'affiche associé au caractère du bas de
  }
}


int main()
{
  int L = 0; // Largeur du diagramme
  int H = 0; // Hauteur du diagramme
  scanf("%d%d", &L, &H);
  fgetc(stdin); // Permet de recevoir les données demandées
  char ** diagramme = (char **) malloc(L*sizeof(char*)); // Tableau à 1 dimension de type char** dont chaque case contient une chaîne de caractère : char*
  int i;
  for(i=0; i<H; i++)
  {
    diagramme[i]=(char *) malloc(L*sizeof(char)); //Pour chaque case de 'diagramme' on crée un tableau de caractères dans lequel on stocke chaque ligne entrée.
    fgets(diagramme[i], 1025, stdin);
  }
  deplacement(diagramme, H, L); // Suivre les lignes jusqu'à atteindre et afficher les associations de caractères
  free(diagramme); // Libère la mémoire utilisée par le diagramme
  return 0;
}
