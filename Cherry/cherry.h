typedef struct Cherry{
    SDL_Texture *texture;
    SDL_Rect dstRect;
    SDL_Rect srcRect;
    int Pos[17][2];
    int nbPos;
    bool colected;
}Cherry;

void updateCherryAnimation(SDL_Renderer *renderer, Cherry *c);