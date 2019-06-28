#include <stdlib.h>
#include <stdio.h>
#include <string.h>


long long incrementerRiviere(long long  r)
// Calcule la nouvelle valeur de la rivière après une itération
{
  long long riviere = r; // On sauvegarde la valeur actuelle de la rivière
  long long somme = 0; // Initialisation de la somme à 0
  while(riviere != 0) // Tant que la valeur de la rivière n'est pas nulle ...
  {
    somme += riviere%10; // ... On ajoute le chiffre des unités actuel de la rivière
    riviere /= 10; // Puis on divise la rivière par 10 pour décaler le chiffre de dizaines au chiffre des unités
  }
  return r+somme; // On ajoute le chiffre obtenu à la somme
  // A la fin de l'éxecution on aura donc fait la somme des différents chiffres qui composent le nombre
}


int main()
{
  // On initialise les deux rivières
  long long r1;
  scanf("%lld", &r1);
  long long r2;
  scanf("%lld", &r2);
  // Tant que leurs valeurs ne sont pas égales, la plus petite des 2 va prendre la nouvelle valeur c'est à dire avec une itération de plus
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
  printf("%lld", r1); // On affiche la valeur à laquelle r1 et r2 sont égaux, on peut donc afficher l'un ou l'autre
  return 0;
}
