#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// Structure qui contient le nom et l'extension d'un type MIME.
typedef struct{
  char nom[51];
  char extension[11];
}mime;


int main()
{
    int nbAssoc; // Nombre d'éléments qui composent la table d'association.
    scanf("%d", &nbAssoc);
    int nbFichiers; // Nombre de fichiers à être analysé.
    scanf("%d", &nbFichiers);
    mime * tableMime = (mime *) malloc(nbAssoc*sizeof(mime)); // Tableau qui
    // correspond à la table d'association de types MIME.
    int i;
    for (i = 0; i < nbAssoc; i++) // On récupère les associations extension/types
    {
        char extension[11]; // Extension de fichier.
        char typeMime[51]; // Type MIME.
        scanf("%s%s", extension, typeMime); fgetc(stdin);
        strcpy(tableMime[i].nom, typeMime);
        strcpy(tableMime[i].extension, extension);
    }
    for (i = 0; i < nbFichiers; i++)
    {
        char nomFichier[258]; // On y stocke le nom complet des fichiers entrés.
        fgets(nomFichier, 258, stdin); // One file name per line.
        strtok(nomFichier, "\n"); // On retire le retour à la ligne.
        // On  extrait l'extension.
        const char * extFichier = strrchr(nomFichier, '.'); // Extension du
        // fichier avec le point.
        int trouve = 0; // Booléen pour arrêter la recherche dans le tableau.
        // On vérifie qu'il existe une extension après le dernier point.
        if (extFichier != NULL)
        {
            if (extFichier + 1 != NULL)
                {
                    const char * extensionFichier = extFichier + 1; //Extension
                    // sans le point.
                    int j = 0;
                    // On recherche l'extension dans la table d'association
                    // tableMime.
                    while((trouve == 0) || (j<nbAssoc))
                    {
                      if (strcasecmp(extensionFichier, tableMime[j].extension) == 0)
                      // On cherche un correspondance des extensions.
                      {
                        trouve = 1;
                        printf("%s\n", tableMime[j].nom);
                        // On renvoie le nom qui correspond à l'extension.
                      }
                      j++;
                    }
                  }
                }
              if (trouve == 0)
              {
                printf("UNKNOWN\n");
                // Si rien a été trouve on affiche "UNKNOWN".
              }
    }
    return 0;
}
