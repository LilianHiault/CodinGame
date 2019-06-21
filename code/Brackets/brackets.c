#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main()
{
    char expression[2049];
    scanf("%s", expression);
    int parenthese = 0;
    int crochet = 0;
    int accolade = 0;
    char caractere = expression[0];
    int compt = 0;
    int bienParenthesee = 1;
    //printf("Parenthèses | Crochets | Accolades\n")
    while (bienParenthesee && caractere != '\0')
    {
      caractere = expression[compt];
      // Si c'est un parenthèse alors incrémenter parenthese
      if (caractere == '(')
      {
        parenthese ++;
      }
      else if (caractere == ')')
      {
        parenthese --;
      }
      // Si c'est un crochet alors incrémenter crochet
      else if (caractere == '[')
      {
        crochet ++;
      }
      else if (caractere == ']')
      {
        crochet --;
      }
      // Si c'est une accolade alors incrémenter accolade
      else if (caractere == '{')
      {
        accolade ++;
      }
      else if (caractere == '}')
      {
        accolade --;
      }
      // Si un des ces caractères est en négatif alors il est fermé avant
      // d'être ouvert donc l'expression est mal parenthèsée.
      //printf("%d | %d | %d\n", parenthese, crochet, accolade);
      if ((parenthese < 0) || (crochet < 0) || (accolade < 0))
      {
        bienParenthesee = 0;
      }
      compt ++;
    }
    if (bienParenthesee && (parenthese == 0) && (crochet == 0) && (accolade == 0))
    {
      printf("true\n");
    }
    else
    {
      printf("false\n");
    }
    return 0;
}
