#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "temps.h"
#include <time.h>

int affichetemps(SDL_Surface* screen,int t,clock_t debut)
{ SDL_Rect pos;
 clock_t fin;
long clk_tck = CLOCKS_PER_SEC;
int diff =0;
fin = clock();
diff = (int) (fin - debut)/(int) clk_tck;


return  t+diff;
}

