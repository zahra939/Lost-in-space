#ifndef ENNEMI_H_
#define ENNEMII_H_


#include <stdlib.h>
#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"



/**
* @struct Ennemi
* @brief struct for ennemi
*/

typedef struct {
   
    SDL_Surface *sprite1,*sprite2;/*!< Surface. */
    
    SDL_Rect pos,frame;/*!< Rectangle*/
    int dir;
    
}ennemi;

void initEnnemi(ennemi *e);

void AfficherEnnemi(ennemi e, SDL_Surface * screen);

void deplacerEnnemi(ennemi *e,SDL_Rect pos);

void animerEnnemi(ennemi *e);

int collisionBB(SDL_Rect pos,ennemi e);


#endif
