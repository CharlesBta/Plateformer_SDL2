#include "count_cherry.h"

char str[100];
void updateCountCherry(SDL_Renderer *renderer, WRT_Font font, Player *p){
    sprintf(str, "Cherry: %d", p->collectedCherry);
    WRT_DrawText(renderer, font, str, 10, 10, 24);
}