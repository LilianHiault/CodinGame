#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct zoneDeRecherche
{
  int gauche;
  int droite;
  int haut;
  int bas;
} zone;

typedef struct position
{
  int x;
  int y;
} position;


void initZoneRecherche(zone * pSecteurRech, position batman, int nvGauche, int nvDroite, int nvHaut, int nvBas)
// Initialise la zone de recherche des bombes
{
  pSecteurRech->gauche = nvGauche;
  pSecteurRech->droite = nvDroite;
  pSecteurRech->haut = nvHaut;
  pSecteurRech->bas = nvBas;
}


void changerZoneRecherche(zone * pSecteurRech, char * bombeDir, position batman)
// Change la zone de recherche des bombes par rapport à leur direction
{
  if(strcmp(bombeDir, "U") == 0) {
    initZoneRecherche(pSecteurRech, batman, batman.x, batman.x, pSecteurRech->haut, batman.y-1);
  }
  else if (strcmp(bombeDir, "UR") == 0) {
    initZoneRecherche(pSecteurRech, batman, batman.x+1, pSecteurRech->droite, pSecteurRech->haut, batman.y-1);
  }
  else if (strcmp(bombeDir, "R") == 0) {
    initZoneRecherche(pSecteurRech, batman, batman.x+1, pSecteurRech->droite, batman.y, batman.y);
  }
  else if (strcmp(bombeDir, "DR") == 0) {
    initZoneRecherche(pSecteurRech, batman, batman.x+1, pSecteurRech->droite, batman.y+1, pSecteurRech->bas);
  }
  else if (strcmp(bombeDir, "D") == 0) {
    initZoneRecherche(pSecteurRech, batman, batman.x, batman.x, batman.y+1, pSecteurRech->bas);
  }
  else if (strcmp(bombeDir, "DL") == 0) {
    initZoneRecherche(pSecteurRech, batman, pSecteurRech->gauche, batman.x-1, pSecteurRech->bas, batman.y+1);
  }
  else if (strcmp(bombeDir, "L") == 0) {
    initZoneRecherche(pSecteurRech, batman, pSecteurRech->gauche, batman.x-1, batman.y, batman.y);
  }
  else if (strcmp(bombeDir, "UL") == 0) {
    initZoneRecherche(pSecteurRech, batman, pSecteurRech->gauche, batman.x-1, pSecteurRech->haut, batman.y-1);
  }
}


void deplaceBatman(zone secteurRech, position *pBatman)
// Deplace Batman au centre de la zone de recherche
{
  pBatman->x = (secteurRech.gauche + secteurRech.droite)/2;
  pBatman->y = (secteurRech.haut + secteurRech.bas)/2;
}


int main()
{
    // Entrées
    int largeur; // largeur du bâtiment.
    int hauteur; // hauteur du bâtiment.
    scanf("%d%d", &largeur, &hauteur);
    int nbTours; // nombre maximum de tours.
    scanf("%d", &nbTours);
    position batman; // Initialiser la position de Batman.
    position *pBatman = &batman;
    scanf("%d%d", &batman.x, &batman.y);
    // Initialiser la zone de recherche
    zone secteurRech = {0, largeur-1, 0, hauteur-1};
    zone *pSecteurRech = &secteurRech;

    while (1) {
        char bombeDir[4]; // direction des bombes selon la position de Batman (U, UR, R, DR, D, DL, L ou UL)
        scanf("%s", bombeDir);
        changerZoneRecherche(pSecteurRech, bombeDir, batman);
        deplaceBatman(secteurRech, pBatman);
        printf("%d %d\n", batman.x, batman.y); // coordonées de la fenêtre vers laquelle Batman va sauter.
    }
    return 0;
}
