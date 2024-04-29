typedef struct Menu{
    void (*event)(SDL_Event e, GameState *gameState, SDL_Point mouse, Button *button);
    void (*update)(SDL_Renderer *renderer, Button *button, SDL_Point *mouse, BackgroundTexture *backgroundTexture[], Background background[]);
}Menu;

void eventMenu(SDL_Event e, GameState *gameState, SDL_Point mouse, Button *button);
void updateMenu(SDL_Renderer *renderer, Button *button, SDL_Point *mouse, BackgroundTexture *backgroundTexture[], Background background[]);