#include "cherry.h"

Cherry generateCherry(SDL_Texture *texture, int x, int y){
    Cherry* c = malloc(sizeof(Cherry));
    c->texture = texture;
    c->dstRect = (SDL_Rect) {x, y, 64, 64};
    c->srcRect = (SDL_Rect) {0, 0, 32, 32};
    c->hitbox = (SDL_Rect) {x + 10, y + 10, 44, 44};
    for (int i = 0; i < 17; i++) {
        c->Pos[i][0] = i * 32;
        c->Pos[i][1] = 0;
    }
    c->nbPos = 17;
    c->collected = false;
    return *c;
}

int Index = 0;
void updateCherryAnimation(SDL_Renderer *renderer, Cherry *c){
    if (c->collected) {
        return;
    }
    if (Index >= c->nbPos *10 -1) {
        Index = 0;
    } else {
        Index++;
    }
    c->srcRect.x = c->Pos[(int) Index / 10][0];
    c->srcRect.y = c->Pos[(int) Index / 10][1];
    SDL_RenderCopy(renderer, c->texture, &c->srcRect, &c->dstRect);
    Index++;
}

void checkCherryCollision(Player *p, Cherry *c){
    if (SDL_HasIntersection(&p->dstRect, &c->hitbox) == SDL_TRUE && !c->collected){
        c->collected = true;
        p->collectedCherry++;
        p->score += 100;
    }
}