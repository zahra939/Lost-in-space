

#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "atelier1.h"


ennemie initennemie (){
printf("ici init \n");
ennemie e;
e.position.x=0;
e.position.y=480;

  e.sprite = IMG_Load("Alien1.png");
  return e;
}

perso initperso ()
{ 

perso p ;
p.pos.x=480;
p.pos.y=480;
p.pos.w=30;
p.pos.h=40;  
  return p ;
}



 int positionhay(ennemie *e, perso *p, int collision )
{

e->position.x++;
 if( (p->pos.x+p->pos.w < e->position.x) || (p->pos.x>e->position.x+e->position.w) ||
(p->pos.y+p->pos.h < e->position.y) || (p->pos.y> e->position.y + e->position.h))
{
collision = 0; 
}
else 
 { collision = 1;
printf ("collision detecte");
e->position.x--;

return collision ;
}
 

}
void animationennemie(ennemie e,perso p, SDL_Surface *screen)
{
 int continuer=1;
int collision ;	
 

 e=initennemie ();
p=initperso () ;

 screen=SDL_SetVideoMode(960,600,32,SDL_SWSURFACE);


 //SDL_SetColorKey(e.sprite, SDL_SRCCOLORKEY, SDL_MapRGB(e.sprite->format, 0x00, 0xff, 0xff));
 //SDL_SetColorKey(o.obst, SDL_SRCCOLORKEY, SDL_MapRGB(o.obst->format, 0x00, 0xff, 0xff));
while(continuer==1)
{

                SDL_Event event;
                while(SDL_PollEvent(&event)) {
                        switch(event.type) {
                                case SDL_QUIT:
					
                                        continuer = 0;
                                        break;
						}
					}

SDL_FillRect(screen,&e.position,0x00);

positionhay(&e,&p,collision);
printf("ici position %d \n",e.position.x);

SDL_BlitSurface(e.sprite,NULL,screen,&e.position);

SDL_Flip(screen);


}
SDL_FreeSurface(e.sprite);

SDL_Quit();
}
