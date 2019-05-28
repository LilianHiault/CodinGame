#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


typedef struct coordonnees
{
  int x;
  int y;
}coord;


float distance(coord ville1, coord ville2)
// Revoie la distance entre deux villes
{
  return sqrt(pow(ville2.x-ville1.x, 2) + pow(ville2.y-ville1.y, 2));
}


int plusProche(int villeDepart, coord villes[], int taille, int dejaVisite[])
// Renvoie l'indice de la ville la plus proche
{
  int indice;
  int i=0;
  int trouve = 0;
  float distanceEnCours = 0;
  // Trouve une ville non visitée et différente du point de départ
  //printf("Ville non visitée : \n");
  while(i<taille && trouve==0)
  {
    distanceEnCours = distance(villes[villeDepart], villes[i]);
    //printf("distanceEnCours : %f\n", distanceEnCours);
    if ((distanceEnCours!=0) && (dejaVisite[i] == 0))
    {
      indice = i;
      //printf("indice ville non visitée : %d\n", indice);
      trouve = 1;
    }
    else
      {
	i++;
      }
  }

  // Cherche la ville la plus proche
  float distancePlusProche = distance(villes[villeDepart], villes[indice]);
  //printf("distancePlusProche : %f\n", distancePlusProche);
  int j=0;
  for(j=i; j<taille; j++)
  {
    distanceEnCours = distance(villes[villeDepart], villes[j]);
    //printf("distanceEnCours : %f\n", distanceEnCours);
    if((distanceEnCours!=0) && (distanceEnCours < distancePlusProche) && (dejaVisite[j] == 0))
    {
      indice = j;
      distancePlusProche = distanceEnCours;
      //printf("distancePlusProche : %f\n", distancePlusProche);
    }
  }
  return indice;
}


int main()
{
    int N;
    scanf("%d", &N);
    // Tableau contenant les emplacements des villes
    coord * villes = (coord *) malloc(N*sizeof(coord));
    // Tableau de booléens pour savoir si on a déjà visité une ville (initialisé à faux)
    int * dejaVisite = (int *) malloc(N*sizeof(int));
    int k;
    for (k=0; k<N; k++)
    {
      dejaVisite[k] = 0;
    }
    // Stocke les emplacements des villes ans un tableau
    int i;
    for(i = 0; i < N; i++)
    {
        scanf("%d%d", &villes[i].x, &villes[i].y);
    }
    // Calcul de la distance totale
    float sommeDistance = 0;
    int villeEnCours = 0;
    int villeArrivee = 0;
    int j;
    for (j=0; j<N-1; j++)
    {
      villeArrivee = plusProche(villeEnCours, villes, N, dejaVisite);
      sommeDistance += distance(villes[villeEnCours], villes[villeArrivee]);
      //printf("Somme distance : %f\n",sommeDistance);
      dejaVisite[villeEnCours] = 1;
      villeEnCours = villeArrivee;
    }
    sommeDistance += distance(villes[villeEnCours], villes[0]);
    printf("%d\n", (int) round(sommeDistance));
    free(villes);
    free(dejaVisite);
    return 0;
}
