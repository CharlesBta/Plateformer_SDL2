#include "pause.h"

void eventPause(SDL_Event e, GameState *gameState, SDL_Point mouse, Button *button) {
    if (e.type == SDL_MOUSEBUTTONDOWN) {
        if (isButtonClicked(button, mouse) == SDL_TRUE) {
            *gameState = PLAY;
            SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW));
        }
    } else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
        *gameState = PLAY;
        SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW));
    }
}

char cherry[100];
char score[100];
void updatePause(SDL_Renderer *renderer, Player *p, Player *displayPlayer, Button *button, SDL_Point *mouse, BackgroundTexture *backgroundTexture[], Background background[], WRT_Font fontWhite, WRT_Font fontBlack){
    set_background(backgroundTexture, renderer, background);
    updatePlayerAnimation(renderer, displayPlayer);
    updateButton(renderer, button, *mouse);
    sprintf(cherry, "Cherry: %d", p->collectedCherry);
    snprintf(score, 100, "Score: %d", p->score);
    WRT_DrawText(renderer, fontWhite, cherry, 280, WINDOW_HEIGHT/2 + 130, 24);
    WRT_DrawText(renderer, fontWhite, score, 280, WINDOW_HEIGHT/2 + 160, 24);
    WRT_DrawText(renderer, fontWhite, "(Escape) to resume", WINDOW_WIDTH - 190, 10, 10);
    WRT_DrawText(renderer, fontBlack, "PAUSE", WINDOW_WIDTH/2 - 3*30, 50, 30);
}