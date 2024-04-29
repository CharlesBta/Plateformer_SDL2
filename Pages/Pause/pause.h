typedef struct Pause{
    void (*event)(SDL_Event e, GameState *gameState, SDL_Point mouse, Button *button);
    void (*update)(SDL_Renderer *renderer, Player *p, Player *displayPlayer, Button *button, SDL_Point *mouse, BackgroundTexture *backgroundTexture[], Background background[], WRT_Font fontWhite, WRT_Font fontBlack);
}Pause;

void eventPause(SDL_Event e, GameState *gameState, SDL_Point mouse, Button *button);
void updatePause(SDL_Renderer *renderer, Player *p, Player *displayPlayer, Button *button, SDL_Point *mouse, BackgroundTexture *backgroundTexture[], Background background[], WRT_Font fontWhite, WRT_Font fontBlack);