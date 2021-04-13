#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <math.h>
#include <SDL/SDL_image.h>


typedef struct 
{
	SDL_Surface * perso;//persoTab[2][3];
	SDL_Rect posperso;
	SDL_Rect posframe;	
int vh , vv,direction,frame;

	
	
	
}perso;

void init(perso* p);
void afficherPerso(perso *p,SDL_Surface* screen);
void deplacerPerso(perso *p);
void animerPerso(perso *p);
void saut(perso *p);

#endif // HEADER_H_INCLUDED
