int load_spritesBackground(BackgroundTexture *t[7], SDL_Renderer *renderer) {
    t[0]->texture = IMG_LoadTexture(renderer, "./Background/Blue.png");
    if (!t[0]) {
        printf("Unable to load image %s! SDL_image Error: %s\n", "Blue.png", IMG_GetError());
        return -1;
    } else {
        t[0]->rect = (SDL_Rect) {0, 0, 64, 64};
    }
    t[1]->texture = IMG_LoadTexture(renderer, "./Background/Brown.png");
    if (!t[1]) {
        printf("Unable to load image %s! SDL_image Error: %s\n", "Brown.png", IMG_GetError());
        return -1;
    } else {
        t[1]->rect = (SDL_Rect) {0, 0, 64, 64};
    }
    t[2]->texture = IMG_LoadTexture(renderer, "./Background/Gray.png");
    if (!t[2]) {
        printf("Unable to load image %s! SDL_image Error: %s\n", "Gray.png", IMG_GetError());
        return -1;
    } else {
        t[2]->rect = (SDL_Rect) {0, 0, 64, 64};
    }
    t[3]->texture = IMG_LoadTexture(renderer, "./Background/Green.png");
    if (!t[3]) {
        printf("Unable to load image %s! SDL_image Error: %s\n", "Green.png", IMG_GetError());
        return -1;
    } else {
        t[3]->rect = (SDL_Rect) {0, 0, 64, 64};
    }
    t[4]->texture = IMG_LoadTexture(renderer, "./Background/Pink.png");
    if (!t[4]) {
        printf("Unable to load image %s! SDL_image Error: %s\n", "Pink.png", IMG_GetError());
        return -1;
    } else {
        t[4]->rect = (SDL_Rect) {0, 0, 64, 64};
    }
    t[5]->texture = IMG_LoadTexture(renderer, "./Background/Purple.png");
    if (!t[5]) {
        printf("Unable to load image %s! SDL_image Error: %s\n", "Purple.png", IMG_GetError());
        return -1;
    } else {
        t[5]->rect = (SDL_Rect) {0, 0, 64, 64};
    }
    t[6]->texture = IMG_LoadTexture(renderer, "./Background/Yellow.png");
    if (!t[6]) {
        printf("Unable to load image %s! SDL_image Error: %s\n", "Yellow.png", IMG_GetError());
        return -1;
    } else {
        t[6]->rect = (SDL_Rect) {0, 0, 64, 64};
    }
    return 0;
}

void set_background(BackgroundTexture *t[7], SDL_Renderer *renderer, Background b[]) {
    int index = 0;
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 21; ++j) {
            t[b[index]]->rect = (SDL_Rect) {j * 64, i * 64, 64, 64};
            SDL_RenderCopy(renderer, t[b[index]]->texture, NULL, &t[b[index]]->rect);
            index ++;
        }
    }
}
