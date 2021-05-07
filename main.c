#include "perso.h"

int main(void) {

SDL_Init(SDL_INIT_VIDEO);
SDL_Surface * screen = NULL;
  if (SDL_Init(SDL_INIT_VIDEO) != 0) 
  {
    printf("ERROR: Unable to initialize SDL");
    return 1;
  }
  screen = SDL_SetVideoMode(1800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption("lost in space ", NULL);


Uint32 dt,t_prev;
int continuer=1;


SDL_Event event;
personne p;
int left,posinit,up;

initPerso(&p);
AfficherPerso(&p,screen);

SDL_EnableKeyRepeat(10,10);

while(continuer)
{
t_prev=SDL_GetTicks();
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
                
                  left=0;
                  animerPerso(&p,left);
                  deplacerPerso(&p,dt,left);
                  AfficherPerso(&p,screen);
                                   
                  break;  
                    
                  case SDLK_LEFT:
                  left=1;                 
                  animerPerso(&p,left);
                  deplacerPerso(&p,dt,left);
                  AfficherPerso(&p,screen);
                  break;
                  case SDLK_UP:                 
                  saut(&p);
                  deplacerPerso(&p,dt,left);
                  AfficherPerso(&p,screen); 
                  break; 
            case SDL_QUIT:
            continuer=0;
            break;
           
          } 
          break;
         case SDL_KEYUP:
                   
            switch(event.key.keysym.sym)
            {
                case SDLK_UP:
                p.pos.y=200;
                AfficherPerso(&p,screen); 
               break;
               }
               break;
                
         
}
dt=SDL_GetTicks()-t_prev;
}
SDL_FreeSurface(p.sprite);
SDL_Quit();
 return 0;

}


