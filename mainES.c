#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "atelier1.h"


int main()
{

SDL_Init(SDL_INIT_EVERYTHING);
SDL_Surface*screen ;

ennemie e;
perso p;

int continuer=1;
int collision =0;


while(continuer==1)
{
animationennemie (e,p,screen);

continuer=0;


}					
SDL_Quit();
return 0;
}
