#include "win.h"

char str[100] = "";
void updateWin(SDL_Renderer *renderer, BackgroundTexture *backgroundTexture[], Background background[], WRT_Font font, Player* player){
    set_background(backgroundTexture, renderer, background);
    WRT_DrawText(renderer, font, "You win !", 100, 100, 40);
    WRT_DrawText(renderer, font, "Restart game to play again", 100, 200, 40);
    sprintf(str, "Score: %d", player->score);
    WRT_DrawText(renderer, font, str, 100, 300, 40);
}