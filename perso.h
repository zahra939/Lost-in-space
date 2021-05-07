#ifndef PERSO_H_
#define PERSO_H_

#include <stdlib.h>
#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
typedef struct{
    SDL_Surface * img;   
    SDL_Rect pos_img[3];     
    int nb;
}vie;
typedef struct
{
 SDL_Surface *texte;
 SDL_Rect pos;
 }score;
typedef struct {
    TTF_Font *police;
    SDL_Surface *sprite;
    vie v;
    score s;
    SDL_Rect pos,frame;
    double vit;
}personne;

void initPerso(personne *p);
void AfficherPerso(personne *p, SDL_Surface * screen);
void deplacerPerso(personne *p,int dt,int left);
void animerPerso(personne *p,int left);
void saut(personne *p);

#endif
