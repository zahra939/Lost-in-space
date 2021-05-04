#ifndef grille_H_INCLUDED
#define grille_H_INCLUDED

#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>


typedef struct
{
    SDL_Surface* grilleS;
    SDL_Surface *jetons[2];
    int grille[6][7];
    int remplissage[7];
   // int tour;
  //  int winner;

}Grille;

void initgrille(Grille *g);
int jouable(Grille *g , int x);
int dansGrille(int x, int y);
int saisircoup(Grille *g);
void afficherGrille(Grille *g);

void affichage(Grille *g,SDL_Surface *screen);

int IA(Grille *g);

int estRemplieOuNon(Grille *g);
int adjacent(Grille *g,int c, int l, int dirV, int dirH);
int partieEstGagneeOuPas(Grille *g,int c, int l);








#endif // grille_H_INCLUDED
