#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct tas {
  int debut;
  int fin;
  int taille;
  int *cartes;
} tas;


int conversionCartes(char[]); // renvoie la carte sous la forme d'un entier

void manche(tas *pJ1, tas *pJ2);

void bataille(tas *j1, tas *j2);

void tailleTab(tas *pJ);


int main()
{
  int n=0; // nombre de cartes du joueur 1
  scanf("%d", &n);
  tas j1 = {0, n, n, (int*) malloc(n*sizeof(int))};
  for (int i = n-1; i >= 0; i--) {
    char cartesJ1[4]; // les n cartes du joueur 1
    scanf("%s", cartesJ1);
    j1.cartes[i] = conversionCartes(cartesJ1);
    // printf("Carte J1 : %d\n", j1.cartes[i]);
  }

  int m=0; // nombre de cartes du joueur 2
  scanf("%d", &m);
  tas j2 = {0, m, m, (int*) malloc(n*sizeof(int))};
  for (int i = m-1; i >= 0; i--) {
    char cartesJ2[4]; // les m cartes du joueur 1
    scanf("%s", cartesJ2);
    j2.cartes[i] = conversionCartes(cartesJ2);
    // printf("Carte J2 : %d\n", j2.cartes[i]);
  }

  int nbManches = 0;
  tas *pJ1 = &j1;
  tas *pJ2 = &j2;

  while ((j1.fin != j1.debut) || (j2.fin != j2.debut))
  {
    manche(pJ1, pJ2);
    nbManches ++;
  }

  if ((j1.debut == j1.fin) && (j2.debut != j2.fin))
  {
    printf("2 %d\n", nbManches);
  }
  else if ((j2.debut == j2.fin) && (j1.debut != j1.fin))
  {
    printf("1 %d\n", nbManches);
  }
  else
  {
    printf("PAT %d\n", nbManches);
  }
  return 0;
}


int conversionCartes(char carte[])
{
  int valeur = -1;
  switch (carte[0]) {
    case '2':
    valeur = 2;
    break;
    case '3':
    valeur = 3;
    break;
    case '4':
    valeur = 4;
    break;
    case '5':
    valeur = 5;
    break;
    case '6':
    valeur = 6;
    break;
    case '7':
    valeur = 7;
    break;
    case '8':
    valeur = 8;
    break;
    case '9':
    valeur = 9;
    break;
    case '1':
    valeur = 10;
    break;
    case 'J':
    valeur = 11;
    break;
    case 'Q':
    valeur = 12;
    break;
    case 'K':
    valeur = 13;
    break;
    case 'A':
    valeur = 14;
    break;
  }
  return valeur;
}

void manche (tas *j1, tas *j2)
{
  if (j1->cartes[j1->debut] > j2->cartes[j2->debut]) // J1 gagne la manche
  {
    // Les cartes du dessus vont en dessous de la pioche de J1 (d'abord J1 puis J2)
    j1->fin += 2;
    j1->debut ++;
    j2->debut ++;
    tailleTab(j1);
    tailleTab(j2);
    j1->cartes[j1->fin -2] = j1->cartes[j1->debut-1];
    j1->cartes[j1->fin -1] = j2->cartes[j2->debut-1];
  }
  else if (j2->cartes[j2->debut] > j1->cartes[j1->debut])
  {
    j2->fin += 2;
    j1->debut ++;
    j2->debut ++;
    tailleTab(j1);
    tailleTab(j2);
    j2->cartes[j2->fin -2] = j1->cartes[j1->debut-1];
    j2->cartes[j2->fin -1] = j2->cartes[j2->debut-1];
  }
  else if (j1->cartes[j1->debut] == j2->cartes[j2->debut])
  {
    bataille();
  }
}

void tailleTab(tas *j)
{
  if (j->fin >= j->taille-1 || j->debut >= j->taille-1)
  {
    int *tab = (int*) malloc(2*j->taille*sizeof(int));
    j->taille = 2*j->taille;
    int i;
    for (i=0; i<j->taille/2; i++)
    {
      tab[i] = j->cartes[i];
    }
    free (j->cartes);
    j->cartes = tab;
  }
}

void bataille(tas *j1, tas *j2)
{
  //
}
