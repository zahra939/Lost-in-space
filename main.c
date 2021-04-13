#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "perso.h"
#include "temps.h"
#include "minimap.h"
#include "collision.h"
#include <SDL/SDL_ttf.h>


#define GRAVITY 10
int main()
{
    TTF_Init();
SDL_Color couleurnoire = {0, 0, 0};
TTF_Font *police;
SDL_Surface *image_temps;
police=TTF_OpenFont("avocado.ttf",22);
int time;
clock_t debut;
debut=clock();
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *screen , *mask/*, *mini*/;
screen=SDL_SetVideoMode (1300,700,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
//mini=IMG_Load("minimap.png");
SDL_WM_SetCaption("perso\t1",NULL);
SDL_Rect camera;
SDL_Event event;
perso p;
minimap m;
SDL_Surface *back;
back=IMG_Load("back.png");
mask=IMG_Load("mask.png");
int continuer=1;
int right=0,left=0,up=0;
init(&p);
init_map(&m);
camera.x=0;
camera.y=0;
camera.w=1300;
camera.h=700;

while(continuer)
{char chaine_temps[10];
    
    time=affichetemps (screen ,0,debut);
    printf ("%d \n",time);
    sprintf(chaine_temps,"%02d",time);
    image_temps=TTF_RenderText_Blended(police,chaine_temps,couleurnoire);
    
    time=affichetemps (screen ,0,debut);
    printf ("%d \n",time);
    SDL_BlitSurface(back,NULL,screen,NULL);
while(SDL_PollEvent(&event))
	{

		switch(event.type)
		{
		case SDL_QUIT:

			continuer=0;
		break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
                case SDLK_LEFT:
                    left=1;
                break;
                case SDLK_RIGHT:
                   
                       right=1;
                   
                   
                    
                break;
                case SDLK_UP:
                    up=1;
                break;    

            }
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.sym)
			{
                case SDLK_LEFT:
                    left=0;
                break;
                case SDLK_RIGHT:
                    right=0;
                break;
                case SDLK_UP:
                    up=0;
                break;
            }
        break;    
        }
    }        

if (left==1) {
    
    p.direction=1;
    deplacerPerso(&p);

    }
if (right==1)
{//if (collision_parfaite_right(mask , p.posperso )==0)
           //        {
    p.direction=0;
    deplacerPerso(&p);

               //    }
} 
if (up==1) saut(&p);




//deplacerPerso(&p);
/*if (p.direction==0) p.posperso.x--;
if (p.direction==1) p.posperso.x++;*/

if (p.direction==0) {
    if (collision_parfaite_right(mask , p.posperso )==0)
                  {
    p.posperso.x+= p.vh;
                  }
}

if (p.direction==1) {
    if (collision_parfaite_left(mask , p.posperso )==0)
                  {
    p.posperso.x-= p.vh;
                  }
}




if (left==0 && right==0)
{
    p.vh=0;
}
afficherPerso(&p,screen);
animerPerso(&p);

MAJMinimap(p.posperso ,  &m, camera, 20);
afficherminimap(m,screen);
SDL_BlitSurface(image_temps,NULL,screen,NULL);


if ((collision_parfaite_down(mask , p.posperso )==0)) p.posperso.y += p.vv;
p.vv += GRAVITY ;
if (p.posperso.y>520)
{
    p.posperso.y=520;
    p.vv=0;
}


SDL_Flip(screen);
//SDL_Delay();

}

    return 0;
}





