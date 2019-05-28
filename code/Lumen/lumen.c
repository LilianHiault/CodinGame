#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void initialiseLigne(char ligne[], int numLigne, int** piece, int taille, int intensite)
//On rempli le tableau d'entier avec les bougies
{
  int i;
  for(i=0; i<taille*2-1; i+=2)
    {
      if(ligne[i] == 'C')
	{
	  piece[numLigne][i/2] = intensite;
	}
    }
}


int luminosite(int lumiere, int** piece, int taille, int i, int j)
// On regarde s'il y a une source de lumière sur les cases voisines
{
  int somme=0;
  if((i>=1) && (piece[i-1][j] == lumiere)){
    somme ++;
  }
  if(i+1<taille && piece[i+1][j] == lumiere){
    somme ++ ;
  }
  if(j-1>=0 &&  piece[i][j-1] == lumiere){
    somme ++;
  }
  if(j+1<taille && piece[i][j+1] == lumiere){
    somme ++;
  }
  if((i-1>=0) && (j+1<taille) && piece[i-1][j+1] == lumiere){
    somme ++;
  }
  if((i-1>=0) && (j-1>=0) && piece[i-1][j-1] == lumiere){
    somme ++;
  }
  if((i+1<taille) && (j+1<taille) && piece[i+1][j+1] == lumiere){
    somme ++;
  }
  if((i+1<taille) && (j-1>=0) &&  piece[i+1][j-1] == lumiere){
    somme ++;
  }
  return somme;
}


void eclairer(int intensite, int** piece, int taille)
//On éclaire la case si on trouve une lumière parmi ses voisons puis on recommence avec une luminosité plus faible
{
  int lumiere = intensite;
  int i,j;
  while(lumiere > 1)
    {
      for(i=0; i<taille; i++)
	     {
	        for(j=0; j<taille; j++)
	         {
	            if((piece[i][j] == 0) && (luminosite(lumiere, piece, taille, i, j) != 0))
		            {
		                piece[i][j] = lumiere-1;
                  }
	               }
               }
               lumiere --;
             }
           }


/*void afficheTab2D(int** tab, int taille)
{
  printf("Tableau : \n");
  int i,j;
  for(i=0; i<taille; i++)
    {
      for(j=0; j<taille; j++)
	{
	  printf("%d ", tab[i][j]);
	}
      printf("\n");
    }
  printf("\n");
}*/


int ombre(int** piece, int taille)
{
  int somme = 0;
  int i,j;
  for(i=0; i<taille; i++)
    {
      for(j=0; j<taille; j++)
	{
	  if(piece[i][j] == 0)
	  {
	    somme ++;
	  }
	}
    }
  return somme;
}


int main()
{
    int taille;
    scanf("%d", &taille);
    int intensite;
    scanf("%d", &intensite); fgetc(stdin);
    int* piece[taille];
    int i;
    for(i=0; i<taille; i++)
    {
	     piece[i] = (int *) malloc(taille*sizeof(int));
    }
    int j;
    // Tableau d'entier représentant la salle dont chaque case désigne la luminosité
    for(i=0; i<taille; i++)
      {
	       for(j=0; j<taille; j++)
	        {
	           piece[i][j] = 0;
	          }
          }
    for (i = 0; i < taille; i++) {
        char ligne[501];
        fgets(ligne, 501, stdin);
	       // On positionne les bougies dans la pièce
	        initialiseLigne(ligne, i, piece, taille, intensite);
        }
    //afficheTab2D(piece, taille);
    // On dispose la lumière autour des bougies
    eclairer(intensite, piece, taille);
    //afficheTab2D(piece, taille);
    // On compte les zones d'ombres
    int nbOmbre = ombre(piece, taille);
    printf("%d\n", nbOmbre);
    return 0;
}
