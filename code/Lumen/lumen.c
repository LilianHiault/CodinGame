#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void initialiseLigne(char ligne[], int numLigne, int** piece, int taille, int intensite)
// Pour un ligne donnée, initialiseLigne positionne les bougies dans le tableau de la pièce
{
  int i;
  for(i=0; i<taille*2-1; i+=2) // On avance de 2 en 2 pour ne pas prendre en compte les espaces entre les caractères
  {
    if(ligne[i] == 'C')
    {
      piece[numLigne][i/2] = intensite; // Si le caractère est un 'C' alors c'est une bougie et on lui donne valeur la valeur de l'intensité de la lumière
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
  // Si il y a au moins une lumière voisine à la case ciblée alors la somme sera > 0
  return somme;
}


void eclairer(int intensite, int** piece, int taille)
//On éclaire la case si on trouve une lumière parmi ses voisons puis on recommence avec une luminosité plus faible
{
  int i,j;
  while(intensite > 1)
  {
    for(i=0; i<taille; i++)
    {
      for(j=0; j<taille; j++)
      {
        if((piece[i][j] == 0) && (luminosite(intensite, piece, taille, i, j) != 0))
        // Si on se trouve sur une case sombre et qu'il y a une case illuminée parmi les cases voisines ...
        {
          piece[i][j] = intensite-1;
          // ... alors la case actuelle prendra la valeur de la luminosité -1
        }
      }
    }
    intensite --;
    // On recommence mais avec une valeur de la lumière plus faible
  }
}


int ombre(int** piece, int taille)
// On cherche le nombre de zones d'ombre dans la pièce
{
  int somme = 0; // Nombre total de zones d'ombre
  int i,j;
  for(i=0; i<taille; i++)
  {
    for(j=0; j<taille; j++)
    {
      // Pour chaque case de la pièce ...
      if(piece[i][j] == 0) // ... si la valeur de la luminosité est nulle (=ombre) ...
      {
        somme ++; // ... alors on rajoutte une zome d'ombre
      }
    }
  }
  return somme;
}


int main()
{
  int taille; // Taille de la pièce dans laquelle on se trouve
  scanf("%d", &taille);
  int intensite; // Intensité de la lumière : nombres de cases éclairées autour de la bougie (à chaque case la lumière décroit)
  scanf("%d", &intensite); fgetc(stdin);
  int* piece[taille]; // Création d'un tableau en deux dimension qui représentera la pièce vue du dessus
  int i;
  for(i=0; i<taille; i++)
  {
    piece[i] = (int *) malloc(taille*sizeof(int));
    // A chaque case du tableau on associe un tableau
  }
  // Dans chaque case du tableau 2D on donne la valeur de la luminosité à cet endroit
  int j;
  for(i=0; i<taille; i++)
  {
    for(j=0; j<taille; j++)
    {
      piece[i][j] = 0; // On initialise la luminosité de chaque case de la pièce à 0 (sombre)
    }
  }
  for (i = 0; i < taille; i++)
  {
    char ligne[501]; // Chaîne de caractère qui correspond à l'entrée de l'utilisateur pour chaque ligne
    fgets(ligne, 501, stdin);
    initialiseLigne(ligne, i, piece, taille, intensite); // On positionne les bougies dans la pièce
  }
  eclairer(intensite, piece, taille); // On dispose la lumière autour des bougies
  int nbOmbre = ombre(piece, taille); // On compte les zones d'ombres
  printf("%d\n", nbOmbre);
  return 0;
}
