typedef struct Cherry{
    SDL_Texture *texture;
    SDL_Rect dstRect;
    SDL_Rect srcRect;
    SDL_Rect hitbox;
    int Pos[17][2];
    int nbPos;
    bool colected;
}Cherry;

typedef struct Cherries {
    Cherry cherry;
    struct Cherries *next;
}Cherries;

Cherry generateCherry(SDL_Texture *texture, int x, int y);
void addCherry(Cherries **c, Cherry cherry){
    Cherries *newCherry = malloc(sizeof(Cherries));
    newCherry->cherry = cherry;
    newCherry->next = *c;
    *c = newCherry;
}
void updateCherryAnimation(SDL_Renderer *renderer, Cherry *c);
void checkCherryCollision(Player *p, Cherry *c);