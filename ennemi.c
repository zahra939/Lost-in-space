/**
* @file ennemi.c
*/
#include "ennemi.h"
/**
* @brief To initialize the ennemi e .
* @param e the ennemi
* @param url the url of the image
* @return Nothing
*/



void initEnnemi(ennemi *e)
{
e->sprite1=IMG_Load("2.png");
e->sprite2=IMG_Load("3.png");
e->pos.x=500;
e->pos.y=300;
e->frame.x=0;
e->frame.y=0;
e->frame.w=185;
e->frame.h=222;
e->dir=1;
}
/**
* @brief To show the ennemi e .

* @param s the ennemi
* @return Nothing
*/

void AfficherEnnemi(ennemi e, SDL_Surface * screen)
{
SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
if(e.dir==1)
{SDL_BlitSurface(e.sprite1,&e.frame,screen,&e.pos);
SDL_Flip(screen);}
else 
{SDL_BlitSurface(e.sprite2,&e.frame,screen,&e.pos);
SDL_Flip(screen);}
}
/**
* @brief show the ennemi
* @param screen the screen
* @param e the ennemi
* @return Nothing
*/




void deplacerEnnemi(ennemi *e,SDL_Rect pos)
{


   if (e->pos.x <= 100)  { e->dir =2 ; }
   if (e->pos.x > 400)  { e->dir =1 ; }

   if (e->dir==2) {e->pos.x=e->pos.x + 5 ;  }
   if (e->dir==1) {e->pos.x=e->pos.x - 5 ; }


}
/**
* @brief To move the ennemi.
* @param e the ennemi
* @return Nothing
*/

void animerEnnemi(ennemi *e)
{
e->frame.x+=185;
if(e->frame.x==555)
e->frame.x=185;
SDL_Delay(80); 
}
/**
* @brief To annimate the ennemi.
* @param e the ennemi
* @return Nothing
*/

int collisionBB(SDL_Rect pos,ennemi e)
{
 if( (pos.x+pos.w < e.pos.x) || (pos.x>pos.x+e.frame.w) ||
(pos.y+pos.h < e.pos.y) || (pos.y> pos.y + e.frame.h))
return 0; 
return 1 ;
}
/**
* @brief To detect collision.
* @param e the ennemi
* @return value 1 or 0
*/





