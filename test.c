#include <stdlib.h>
#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"


int main(void) {

SDL_Init(SDL_INIT_VIDEO);
SDL_Surface * screen = NULL;
  if (SDL_Init(SDL_INIT_VIDEO) != 0) 
  {
    printf("ERROR: Unable to initialize SDL");
    return 1;
  }
  screen = SDL_SetVideoMode(1800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption("Cat ", NULL);


Uint32 dt,t_prev;
int continuer=1;
SDL_Surface* astro;
SDL_Rect pos,frame;
int state=0,k=0;
SDL_Event event;


astro=IMG_Load("astro.png");
pos.x=20;
pos.y=100;
frame.x=0;
frame.y=380;
frame.w=125;
frame.h=180;
SDL_BlitSurface(astro,&frame,screen,&pos);
SDL_Flip(screen);
SDL_EnableKeyRepeat(10,10);

while(continuer)
{

SDL_PollEvent(&event);

switch(event.type)
{
            case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
                 case SDLK_ESCAPE:
                 continuer = 0;
                 break;  
                  case SDLK_RIGHT:
                  frame.y=380;
                  frame.x+=125;
                  if(frame.x==375)
                  frame.x=0;
                  pos.x+=10;
                  SDL_BlitSurface(astro,&frame,screen,&pos);
                  SDL_Flip(screen);
                  SDL_Delay(80);                  
                  break;  
                    
                  case SDLK_LEFT:
                  frame.y=190;
                  frame.x+=125;
                  if(frame.x==375)
                  frame.x=0;
                  pos.x-=10;
                  SDL_BlitSurface(astro,&frame,screen,&pos);
                  SDL_Flip(screen);
                  SDL_Delay(80); 
                  if(state==1)
                  {pos.y=40;                                  
                  pos.x+=20;
                  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
                  SDL_BlitSurface(astro,&frame,screen,&pos);
                  SDL_Flip(screen);}
                  break;
                  
                  case SDLK_UP:
                  state=1;
     
                  if(state==1)  
                  {
                  pos.y=40;                  
                  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
                  SDL_BlitSurface(astro,&frame,screen,&pos);
                  SDL_Flip(screen);
                  SDL_Delay(100);
                  }                 
                  pos.y=100;
                  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
                  SDL_BlitSurface(astro,&frame,screen,&pos);
                  SDL_Flip(screen);
                  state=0;
                   break;         
                      
            case SDL_QUIT:
            continuer=0;
            break;
           
}  
         
}

}
SDL_FreeSurface(astro);
SDL_Quit();
 return 0;

}












                 
