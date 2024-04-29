#include "menu.h"

void eventMenu(SDL_Event e, GameState *gameState, SDL_Point mouse, Button *button) {
    if (e.type == SDL_MOUSEBUTTONDOWN) {
        if (isButtonClicked(button, mouse) == SDL_TRUE) {
            *gameState = PLAY;
            SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW));
        }
    }
}

void updateMenu(SDL_Renderer *renderer, Button *button, SDL_Point *mouse, BackgroundTexture *backgroundTexture[], Background background[]) {
    set_background(backgroundTexture, renderer, background);
    updateButton(renderer, button, *mouse);
}