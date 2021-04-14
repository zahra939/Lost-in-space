#ifndef ATELIER1_H_INCLUDED
#define ATELIER1_H_INCLUDED
#include <stdio.h>

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <stdlib.h>
#include <string.h>

typedef struct {

  SDL_Surface *sprite;

  SDL_Rect position;
} ennemie ;

typedef struct {
SDL_Surface * sprt ;
SDL_Rect pos ;
}
perso ;


ennemie initennemie();
perso initperso ();

int positionhay(ennemie *e, perso *p,int collision);
void animationennemie(ennemie e,perso p, SDL_Surface *screen);

#endif
