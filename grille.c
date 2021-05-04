#include "grille.h"

void initgrille(Grille *g){
   int i,j;
    for (i = 0; i < 6; i++)
      {
         for (j = 0; j < 7; j++)
         {
            g->grille[i][j] = ' ';
         }
      }

      for (j = 0; j < 7; j++)
      {
         g->remplissage[j] = 0; /* on initialise remplissage � z�ro, car 0 est sa premiere valeur*/
      }

      g->grilleS=IMG_Load("grille.png");
      g->jetons[0]=IMG_Load("jeton1.png");
      g->jetons[1]=IMG_Load("jeton2.png");
}

int jouable(Grille *g , int x){
    

   if (x >= 0 && (x < 7) && g->remplissage[x] >= 0 && g->remplissage[x] < 6)
      return 1;
   else
      return 0;
}

int dansGrille(int x, int y)
{
   if ((x >= 0) && (x <= 5) && (y >= 0) && (y <= 6))
      return 1;
   else
      return 0;
}


int saisircoup(Grille *g)
{
   int z; // z colonne//

   do
   {

      printf("\t      rentrez une colonne entre <0-6>:\n\t essaies une autre si celle-ci est remplie!\n");
      scanf("%d", &z);
      if (jouable(g,z) == 1)
         return z;

   } while (jouable(g,z) != 1);
}

void afficherGrille(Grille *g)
{
   int i, j;
   printf("\t\t********MOUSSY && MICK********\n");
   printf("\t\t*********Puissance4*******\n\n\n\n");

   for (i = 0; i < 6; i++)
   {
      printf("\t\t\t");
      printf("+-+-+-+-+-+-+-+");

      printf("\n");
      printf("\t\t\t");
      for (j = 0; j < 7; j++)

         printf("|%c", g->grille[5 - i][j]);

      printf("|%d \n", i); // affiche les num�ros horizontalement
   }
   if (i == 6)
      printf("\t\t\t");
   printf("+-+-+-+-+-+-+-+");
   printf("\n");
   printf("\t\t\t");
   for (j = 0; j <= 6; j++)
   {
      printf(" %d", j); // affiche les num�ro verticalement
   }
   printf("\n\n\t\t");
}

int estRemplieOuNon(Grille *g)
{
   int x, comp = 0;
   for (x = 0; x <= 6; x++)
   {
      if (jouable(g,x))
      {
         comp = comp + 1;
      }
   }
   if (comp == 0) //nbre de colonne+1

      return 1;

   else
      return 0;
}

int adjacent(Grille *g,int c, int l, int dirV, int dirH)
{
   int n = 0;

   if (dirV == 0)
   {
      if (dirH == 1)
      {
         while ((g->grille[l][c]) == (g->grille[l][c + 1]) && (g->grille[l][c] != ' '))
         {
            n++;
            c++;
         }
      }
      else if (dirH == -1)
      {
         while ((g->grille[l][c]) == (g->grille[l][c - 1]) && (g->grille[l][c] != ' '))
         {
            n++;
            c--;
         }
      }
   }
   if (dirV == 1)
   {
      if (dirH == 0)
      {
         while ((g->grille[l][c]) == (g->grille[l + 1][c]) && (g->grille[l][c] != ' '))
         {
            n++;
            l++;
         }
      }
      else if (dirH == 1)
      {
         while ((g->grille[l][c]) == (g->grille[l + 1][c + 1]) && (g->grille[l][c] != ' '))
         {
            n++;
            c++;
            l++;
         }
      }
      else if (dirH == -1)
      {
         while ((g->grille[l][c]) == (g->grille[l + 1][c - 1]) && (g->grille[l][c] != ' '))
         {
            n++;
            c--;
            l++;
         }
      }
   }
   if (dirV == -1)
   {
      if (dirH == 0)
      {
         while ((g->grille[l][c]) == (g->grille[l - 1][c]) && (g->grille[l][c] != ' '))
         {
            n++;
            l--;
         }
      }
      else if (dirH == -1)
      {
         while ((g->grille[l][c]) == (g->grille[l - 1][c - 1]) && (g->grille[l][c] != ' '))
         {
            n++;
            c--;
            l--;
         }
      }
      else if (dirH == 1)
      {
         while ((g->grille[l][c]) == (g->grille[l - 1][c + 1]) && (g->grille[l][c] != ' '))
         {
            n++;
            c++;
            l--;
         }
      }
   }
   return (n);
}

int partieEstGagneeOuPas(Grille *g,int c, int l){
    

   if ((adjacent(g,c, l, 0, 1) + adjacent(g,c, l, 0, -1)) >= 3 ||
       (adjacent(g,c, l, 1, 0) + adjacent(g,c, l, -1, 0)) >= 3 ||
       (adjacent(g,c, l, 1, 1) + adjacent(g,c, l, -1, -1)) >= 3 ||
       (adjacent(g,c, l, 1, -1) + adjacent(g,c, l, -1, 1) >= 3))
      return 1;
   else
      return 0;
}


void affichage(Grille *g,SDL_Surface *screen){
    int i,j;
    SDL_Rect pos;
    SDL_BlitSurface(g->grilleS,NULL,screen,NULL);

    for ( i = 0; i < 6; i++)
    {
        for ( j = 0; j < 7; j++)
        {
            pos.x=j*100;
            pos.y=(5-i)*100;
            if (g->grille[i][j]=='X') SDL_BlitSurface(g->jetons[1],NULL,screen,&pos);
            else if (g->grille[i][j]=='O') SDL_BlitSurface(g->jetons[0],NULL,screen,&pos);
        }
        
    }
    SDL_Flip(screen);
    
}


int IA(Grille *g){
   int meilleur_col[7]={0,0,0,0,0,0,0};
   int i,var,imax=0,score_max=0;
   for ( i = 0; i < 7; i++)
   {
   if (g->remplissage[i]!=6){    
    
      var = g->remplissage[i];
   if (i<4)   {
      if ((g->grille[i+1][var]==g->grille[i+2][var]) && (g->grille[i+3][var]==g->grille[i+2][var])) meilleur_col[i]+=10;
   }
   if (i>=3)   {
      if ((g->grille[i-1][var]==g->grille[i-2][var]) && (g->grille[i-3][var]==g->grille[i-2][var])) meilleur_col[i]+=10;
   }

   if (var>=3)   {
      if ((g->grille[i][var-1]==g->grille[i][var-2]) && (g->grille[i][var-3]==g->grille[i][var-2])) meilleur_col[i]+=10;
   }


   if ((var>=3)&&(i>=3))   {
      if ((g->grille[i-1][var-1]==g->grille[i-2][var-2]) && (g->grille[i-3][var-3]==g->grille[i-2][var-2])) meilleur_col[i]+=10;
   }

   if ((var>=3)&&(i<4))   {
      if ((g->grille[i+1][var-1]==g->grille[i+2][var-2]) && (g->grille[i+3][var-3]==g->grille[i+2][var-2])) meilleur_col[i]+=10;
   }



   if (i<5)   {
      if (g->grille[i+1][var]==g->grille[i+2][var])  meilleur_col[i]+=5;
   }

   if (i>=2)   {
      if (  g->grille[i-1][var]==g->grille[i-2][var])  meilleur_col[i]+=5;
   }

   if (var>=2)   {
      if (g->grille[i][var-1]==g->grille[i][var-2]) meilleur_col[i]+=5;
   }

    if ((var>=2)&&(i>=2))   {
      if (g->grille[i-1][var-1]==g->grille[i-2][var-2])  meilleur_col[i]+=5;
   }

   if ((var>=2)&&(i<5))   {
      if (g->grille[i+1][var-1]==g->grille[i+2][var-2] ) meilleur_col[i]+=5;
   }
   /////////
      if (i<6)   {
      if (g->grille[i+1][var]=='X')  meilleur_col[i]+=2;
   }

   if (i>=1)   {
      if (  g->grille[i-1][var]=='X')  meilleur_col[i]+=2;
   }

   if (var>=1)   {
      if (g->grille[i][var-1]=='X') meilleur_col[i]+=2;
   }

    if ((var>=1)&&(i>=1))   {
      if (g->grille[i-1][var-1]=='X')  meilleur_col[i]+=2;
   }

   if ((var>=1)&&(i<6))   {
      if (g->grille[i+1][var-1]=='X' ) meilleur_col[i]+=2;
   }


   }}

//-----recherche de max -------//


score_max =meilleur_col[0];
for ( i = 0; i < 7; i++)
{
   if (meilleur_col[i]>score_max)
   {
      score_max=meilleur_col[i];
      imax=i;
   }
   
}

return imax;
}


