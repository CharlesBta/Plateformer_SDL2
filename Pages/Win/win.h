typedef struct Win{
    void (*update)(SDL_Renderer *renderer, BackgroundTexture *backgroundTexture[], Background background[], WRT_Font font, Player* player);
}Win;

void updateWin(SDL_Renderer *renderer, BackgroundTexture *backgroundTexture[], Background background[], WRT_Font font, Player* player);