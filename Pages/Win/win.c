#include "win.h"

void updateWin(SDL_Renderer *renderer, BackgroundTexture *backgroundTexture[], Background background[], WRT_Font font){
    set_background(backgroundTexture, renderer, background);
    WRT_DrawText(renderer, font, "You win !", 100, 100, 40);
    WRT_DrawText(renderer, font, "Restart game to play again", 100, 200, 40);
}