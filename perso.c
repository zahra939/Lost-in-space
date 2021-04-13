#include "perso.h"

void init(perso* p)
{ 
	p->perso=IMG_Load("hero_spr.png");
	p->posframe.x=0;
	p->posframe.y=0;
	p->posframe.h=100;
	p->posframe.w=100;
	p->posperso.x=50;
	p->posperso.y=520;
	p->posperso.h=100;
	p->posperso.w=100;
	p->direction=0;
	p->frame=0;
	p->vh=0;
	p->vv=0;
	

}



void afficherPerso(perso *p,SDL_Surface* screen)
{
	SDL_BlitSurface(p->perso,&p->posframe,screen,&p->posperso);
}

void deplacerPerso(perso *p)
{
	p->vh++;
	/*if (p->direction==0)
	{
		p->posperso.x += p->vh;// cad :    p->posperso.x = p->posperso.x + p-> vh 
	}
	else if (p->direction==1)
	{
		p->posperso.x -= p->vh;
	}*/
	if (p->vh > 50)
	{
		p->vh = 50;
	}
	
}

void animerPerso(perso *p)
{
	 p -> posframe.y = p -> direction * p -> posframe.h;
  if (p -> posframe.x == 400 - p -> posframe.w) {
    p -> posframe.x = 0;
  } else {
    p -> posframe.x += p -> posframe.w;
  }
  if (p->vh==0)
	{
		p->posframe.x=0;
	}
	
	/*p->frame++;
	if (p->frame > 2)
	{
		p->frame=0;
	}
	if (p->vh==0)
	{
		p->frame=0;
	}*/
	
	
}


void saut(perso *p)
{
	if (p->posperso.y==520)// achanger
	{
		p->vv=-60;
	}
	
	
}


	




