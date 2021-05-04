#include "grille.h"
int main()
{
   Grille g;
   int i, j, joueur = 0, colonne, ligne;
   int y = 0, compt1 = 0;
   int N = 50;
   char nom1[N], nom2[N], recom;
   SDL_Surface *screen;
   screen = SDL_SetVideoMode(700, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
   affichage(&g,screen);
   SDL_Flip(screen);
   printf("nom du premier joueur!!\n");
   scanf("%s", &nom1[N]);
   printf("nom du deuxiem jouer\n");
   scanf("%s", &nom2[N]);

   
   initgrille(&g);

   afficherGrille(&g);
   //affichage(&g,screen);
   
    //  initgrille(&g);
      do
      {
         //affichage(&g,screen);
         if (joueur % 2 == 0) // evident
         {
            printf("%s, posez votre pion\n", &nom1[N]); // on rentre son nom
            colonne = saisircoup(&g);
            ligne = g.remplissage[colonne]; //remplissage d�finit les lignes de la colonne
            g.grille[ligne][colonne] = 'O';
            g.remplissage[colonne] = g.remplissage[colonne] + 1;
            compt1++;
            system("cls");
            afficherGrille(&g);
            affichage(&g,screen);
            if (partieEstGagneeOuPas(&g,colonne, ligne) == 1) // si la partie est gagn�e
            {
               printf("%s gagne au %deme coup\n", &nom1[N], compt1 / 2 + 1);
            }
         }

         if (joueur % 2 != 0)
         {
            //printf("%s, posez votre pion\n", &nom2[N]);
            //colonne = saisircoup(&g);
            colonne = IA(&g);
            ligne = g.remplissage[colonne];
            g.grille[ligne][colonne] = 'X';
            g.remplissage[colonne] = g.remplissage[colonne] + 1;
            compt1++;
            system("cls"); // efface
            afficherGrille(&g);
            affichage(&g,screen);
            if (partieEstGagneeOuPas(&g ,colonne, ligne) == 1)
            {
               printf("%s gagne au %deme coup\n", &nom2[N], compt1 / 2);
            }
         }

         joueur = joueur + 1; //on incremente le joueur

      } while ((!estRemplieOuNon(&g) && !partieEstGagneeOuPas(&g,colonne, ligne))); // r�p�ter tant que c'est pas rempli

      // printf("le score de %s est %d\n",&nom1[N],score1);
      // printf("le score de %s est %d\n",&nom2[N],score2);

     
}
