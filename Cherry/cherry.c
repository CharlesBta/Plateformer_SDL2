#include "cherry.h"

int Index = 0;
void updateCherryAnimation(SDL_Renderer *renderer, Cherry *c){
    if (Index == c->nbPos *10 -1) {
        Index = 0;
    } else {
        Index++;
    }
    // TODO modif ca pour eviter de recrer une texture a chaque fois
    c->srcRect = (SDL_Rect){c->Pos[(int)Index/10][0] / 4, c->Pos[(int)Index/10][1], 32, 32};
    SDL_RenderCopy(renderer, c->texture, &c->srcRect, &c->dstRect);
    Index++;
}