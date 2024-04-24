typedef struct Game{
    void (*event)(SDL_Event e, Player *p, int GL, GameState *gameState);
    void (*update)(SDL_Renderer *renderer, Player *p, Platform platforms[], int nbPlatform, BackgroundTexture *backgroundTexture[], Background background[], int *GROUND_LEVEL, Cherries *cherries, WRT_Font fontWhite, WRT_Font fontBlack);
}Game;

void event(SDL_Event e, Player *p, int GL, GameState *gameState);
void update(SDL_Renderer *renderer, Player *p, Platform platforms[], int nbPlatform, BackgroundTexture *backgroundTexture[], Background background[], int *GROUND_LEVEL, Cherries *cherries, WRT_Font fontWhite, WRT_Font fontBlack);