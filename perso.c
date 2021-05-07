#include "perso.h"

void initPerso(personne *p)
{
p->sprite=IMG_Load("astro.png");
p->pos.x=20;
p->pos.y=200;
p->frame.x=0;
p->frame.y=380;
p->frame.w=125;
p->frame.h=180;

p->vit=0;
//texte du vie 
TTF_Init();
p->police=TTF_OpenFont("Playball.ttf", 50);

SDL_Color couleurBlanche = {255,255,255};


//texte du score
p->s.pos.x=1500;
p->s.pos.y=10;

p->s.texte = TTF_RenderText_Blended(p->police, "Score : 0", couleurBlanche);

//image de vie
p->v.img=IMG_Load("f.png");

p->v.pos_img[1].x=10;
p->v.pos_img[1].y=10;

p->v.pos_img[2].x=70;
p->v.pos_img[2].y=10;

p->v.pos_img[3].x=130;
p->v.pos_img[3].y=10;

p->v.nb=3;
}

void AfficherPerso(personne *p, SDL_Surface * screen)
{
int i;
SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));


for(i=1;i<=3;i++)
{
SDL_BlitSurface(p->v.img, NULL, screen, &p->v.pos_img[i]);
}

SDL_BlitSurface(p->s.texte, NULL, screen, &p->s.pos);

SDL_BlitSurface(p->sprite,&p->frame,screen,&p->pos);

SDL_Flip(screen);

}
void deplacerPerso(personne *p,int dt,int Left)
{
p->vit+=0.05;
if(p->vit >0.5)              
p->vit=0.5;   
if(Left==0)
p->pos.x+=(int)((p->vit)*(dt));
else 
p->pos.x-=(int)((p->vit)*(dt));
}


void animerPerso(personne *p,int left)
{
if(left==1)
{
p->frame.y=190;
p->frame.x+=125;
if(p->frame.x==375)
p->frame.x=0;
SDL_Delay(80); 
}
else
{
p->frame.y=380;
p->frame.x+=125;
if(p->frame.x==375)
p->frame.x=0;
SDL_Delay(80); 
}

}
void saut(personne *p)
{
p->pos.y=115;

}


