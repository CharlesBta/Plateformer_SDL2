void setPlatforms(SDL_Renderer *renderer, Platform platforms[], int nbPlatforms) {
    for (int i = 0; i < nbPlatforms; i++) {
        SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0xFF, 0xFF);
        SDL_RenderFillRect(renderer, &platforms[i].rect);
    }
}

int updateGroundLevel(Player player, int GROUND_LEVEL, Platform platforms[], int nbPlatforms) {
    int X = player.dstRect.x;
    int Y = player.dstRect.y;
    int XW = X + player.dstRect.w;
    int YH = Y + player.dstRect.h;

    GROUND_LEVEL = WINDOW_HEIGHT - player.dstRect.h;
    for (int i = 0; i < nbPlatforms; ++i) {
        int platX = platforms[i].rect.x;
        int platY = platforms[i].rect.y;
        int platXW = platX + platforms[i].rect.w;

        int overPlatIndex = -1;

        for (int j = 0; j < nbPlatforms; ++j){
            if (platY > platforms[j].rect.y && X < platXW && XW > platX){
                overPlatIndex = j;
                break;
            }
        }

        if (overPlatIndex != -1){
            if (X < platforms[i].rect.x + platforms[i].rect.w && XW > platforms[i].rect.x &&
                YH <= platforms[i].rect.y + 1 && YH >= platforms[overPlatIndex].rect.y + 2){
                GROUND_LEVEL = platforms[i].rect.y - player.dstRect.h + 1;
            }
        } else {
            if (X < platforms[i].rect.x + platforms[i].rect.w && XW > platforms[i].rect.x &&
                YH <= platforms[i].rect.y + 1){
                GROUND_LEVEL = platforms[i].rect.y - player.dstRect.h + 1;
            }
        }
    }
    return GROUND_LEVEL;
}