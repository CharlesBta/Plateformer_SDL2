#include "game.h"

void event(SDL_Event e, Player *p, int GL, GameState *gameState){
    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
        *gameState = PAUSE;
    } else{
        handleInput(e, p, GL);
    }
}

void update(SDL_Renderer *renderer, Player *p, Platform platforms[], int nbPlatforms, BackgroundTexture *backgroundTexture[], Background background[], int *GROUND_LEVEL, Cherries *cherries, WRT_Font fontWhite, WRT_Font fontBlack){
    // Render background
    set_background(backgroundTexture, renderer, background);

    // Render platforms
    setPlatforms(renderer, platforms, nbPlatforms);

    // Update player position
    *GROUND_LEVEL = updateGroundLevel(*p, *GROUND_LEVEL, platforms, nbPlatforms);
    updatePlayer(p, *GROUND_LEVEL);

    // Update cherry animation
    for (Cherries *c = cherries; c != NULL; c = c->next) {
        updateCherryAnimation(renderer, &c->cherry);
        checkCherryCollision(p, &c->cherry);
    }

    // Update player animation
    updatePlayerAnimation(renderer, p);

    // Update count cherry
    updateCountCherry(renderer, fontWhite, p);

    WRT_DrawText(renderer, fontWhite, "(Escape) to pause", WINDOW_WIDTH - 190, 10, 10);
}