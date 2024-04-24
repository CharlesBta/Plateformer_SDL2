#include "include.h"

int main() {
#pragma region SDL2_Setup
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("SDL_image could not initialize! IMG_Error: %s\n", IMG_GetError());
        SDL_Quit();
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow(WINDOW_TITLE,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          WINDOW_WIDTH, WINDOW_HEIGHT,
                                          SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        IMG_Quit();
        SDL_Quit();
        return -1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return -1;
    }

    SDL_Texture *IdleRight = IMG_LoadTexture(renderer, "./Sprites/IdleRight.png");
    if (!IdleRight) {
        printf("Unable to load image %s! SDL_image Error: %s\n", "IdleRight.png", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return -1;
    }

    SDL_Texture *IdleLeft = IMG_LoadTexture(renderer, "./Sprites/IdleLeft.png");
    if (!IdleLeft) {
        printf("Unable to load image %s! SDL_image Error: %s\n", "IdleLeft.png", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return -1;
    }

    SDL_Texture *RunRight = IMG_LoadTexture(renderer, "./Sprites/RunRight.png");
    if (!RunRight) {
        printf("Unable to load image %s! SDL_image Error: %s\n", "RunRight.png", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return -1;
    }

    SDL_Texture *RunLeft = IMG_LoadTexture(renderer, "./Sprites/RunLeft.png");
    if (!RunLeft) {
        printf("Unable to load image %s! SDL_image Error: %s\n", "RunLeft.png", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return -1;
    }

    SDL_Texture *JumpRight = IMG_LoadTexture(renderer, "./Sprites/JumpRight.png");
    if (!JumpRight) {
        printf("Unable to load image %s! SDL_image Error: %s\n", "JumpRight.png", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return -1;
    }

    SDL_Texture *JumpLeft = IMG_LoadTexture(renderer, "./Sprites/JumpLeft.png");
    if (!JumpLeft) {
        printf("Unable to load image %s! SDL_image Error: %s\n", "JumpLeft.png", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return -1;
    }

    SDL_Texture *FallRight = IMG_LoadTexture(renderer, "./Sprites/FallRight.png");
    if (!FallRight) {
        printf("Unable to load image %s! SDL_image Error: %s\n", "FallRight.png", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return -1;
    }

    SDL_Texture *FallLeft = IMG_LoadTexture(renderer, "./Sprites/FallLeft.png");
    if (!FallLeft) {
        printf("Unable to load image %s! SDL_image Error: %s\n", "FallLeft.png", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return -1;
    }

    SDL_Texture *texturePlatform = IMG_LoadTexture(renderer, "./Platform/Image/Platform.png");
    if (!texturePlatform) {
        printf("Unable to load image %s! SDL_image Error: %s\n", "Platform.png", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return -1;
    }
#pragma endregion
#pragma region Sprites_Setup
    Sprite staticRightSprite = {
            .texture = IdleRight,
            .srcRect = {4, 7, 23, 28},
            .Pos = {
                    {5,   6},
                    {37,  6},
                    {69,  6},
                    {101, 6},
                    {133, 6},
                    {165, 6},
                    {197, 6},
                    {229, 6},
                    {261, 6},
                    {293, 6},
                    {325, 6}
            },
            .nbPos = 11
    };

    Sprite staticLeftSprite = {
            .texture = IdleLeft,
            .srcRect = {4, 7, 23, 28},
            .Pos = {
                    {5,   6},
                    {37,  6},
                    {69,  6},
                    {101, 6},
                    {133, 6},
                    {165, 6},
                    {197, 6},
                    {229, 6},
                    {261, 6},
                    {293, 6},
                    {325, 6}
            },
            .nbPos = 11
    };

    Sprite runRightSprite = {
            .texture = RunRight,
            .srcRect = {4, 7, 23, 28},
            .Pos = {
                    {5,   4},
                    {37,  4},
                    {69,  4},
                    {101, 4},
                    {133, 4},
                    {165, 4},
                    {197, 4},
                    {229, 4},
                    {261, 4},
                    {293, 4},
                    {325, 4},
                    {357, 4}
            },
            .nbPos = 12
    };

    Sprite runLeftSprite = {
            .texture = RunLeft,
            .srcRect = {4, 7, 23, 28},
            .Pos = {
                    {4,   4},
                    {36,  4},
                    {68,  4},
                    {100, 4},
                    {132, 4},
                    {164, 4},
                    {196, 4},
                    {228, 4},
                    {260, 4},
                    {292, 4},
                    {324, 4},
                    {356, 4}
            },
            .nbPos = 12
    };

    Sprite jumpRightSprite = {
            .texture = JumpRight,
            .srcRect = {4, 7, 23, 28},
            .Pos = {{4, 4}},
            .nbPos = 1
    };

    Sprite jumpLeftSprite = {
            .texture = JumpLeft,
            .srcRect = {4, 7, 23, 28},
            .Pos = {{4, 4}},
            .nbPos = 1
    };

    Sprite fallRightSprite = {
            .texture = FallRight,
            .srcRect = {4, 7, 23, 28},
            .Pos = {{4, 4}},
            .nbPos = 1
    };

    Sprite fallLeftSprite = {
            .texture = FallLeft,
            .srcRect = {4, 7, 23, 28},
            .Pos = {{4, 4}},
            .nbPos = 1
    };
#pragma endregion
#pragma region Font_Setup
    SDL_Texture *picFontBlack = IMG_LoadTexture(renderer, "./Font/Text(Black).png");
    if (!picFontBlack) {
        printf("Unable to load image %s! SDL_image Error: %s\n", "Text(Black).png", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return -1;
    }

    SDL_Texture *picFontWhite = IMG_LoadTexture(renderer, "./Font/Text(White).png");
    if (!picFontWhite) {
        printf("Unable to load image %s! SDL_image Error: %s\n", "Text(White).png", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return -1;
    }

    WRT_Font fontBlack = WRT_LoadFont(picFontBlack);
    WRT_Font fontWhite = WRT_LoadFont(picFontWhite);
#pragma endregion
#pragma region Background_Setup
    BackgroundTexture *backgroundTexture[7] = {malloc(sizeof(BackgroundTexture)), malloc(sizeof(BackgroundTexture)),
                                               malloc(sizeof(BackgroundTexture)), malloc(sizeof(BackgroundTexture)),
                                               malloc(sizeof(BackgroundTexture)), malloc(sizeof(BackgroundTexture)),
                                               malloc(sizeof(BackgroundTexture))};
    if (load_spritesBackground(backgroundTexture, renderer) == -1) {
        printf("Unable to load image %s! SDL_image Error: %s\n", "Background", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return -1;
    }

    Background background[252] = {BLUE};
#pragma endregion
#pragma region Platforms_Setup
    Platform platforms[] = {
            (Platform) {.texture = texturePlatform, .x = 200, .y = WINDOW_HEIGHT - 130},
            (Platform) {.texture = texturePlatform, .x = 400, .y = WINDOW_HEIGHT - 230},
            (Platform) {.texture = texturePlatform, .x = 600, .y = WINDOW_HEIGHT - 130},
            (Platform) {.texture = texturePlatform, .x = 600, .y = WINDOW_HEIGHT - 330},
            (Platform) {.texture = texturePlatform, .x = 150, .y = WINDOW_HEIGHT - 330},
            (Platform) {.texture = texturePlatform, .x = 600, .y = WINDOW_HEIGHT - 430},
            (Platform) {.texture = texturePlatform, .x = 900, .y = WINDOW_HEIGHT - 530},
    };
    int nbPlatforms = sizeof(platforms) / sizeof(platforms[0]);
    loadPlatforms(renderer, platforms, nbPlatforms);
#pragma endregion
#pragma region Cherry_Setup
    SDL_Texture *textureCherry = IMG_LoadTexture(renderer, "./Cherry/Image/Cherries.png");
    if (!textureCherry) {
        printf("Unable to load image %s! SDL_image Error: %s\n", "Cherries.png", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return -1;
    }

    Cherries *cherries = NULL;
    addCherry(&cherries, generateCherry(textureCherry, 600, 200));
    addCherry(&cherries, generateCherry(textureCherry, 800, 200));
#pragma endregion

    Player player = {
            .speed = 5,
            .jumpSpeed = 22,
            .velocity = {0, 0},
            .alive = true,
            .moving = false,
            .direction = RIGHT,
            .running = false,
            .jumping = false,
            .falling = false,
            .colectedCherry = 0,
            .spriteIndex = STATIC_RIGHT,
            .dstRect = {0, 0, (int)132, (int)132},
            .sprites = {
                    &staticRightSprite,
                    &staticLeftSprite,
                    &runRightSprite,
                    &runLeftSprite,
                    &jumpRightSprite,
                    &jumpLeftSprite,
                    &fallRightSprite,
                    &fallLeftSprite}
    };

    int GROUND_LEVEL = WINDOW_HEIGHT - player.dstRect.h;

    bool running = true;
    SDL_Event e;
    while (running) {
        // Handle events on queue
        while (SDL_PollEvent(&e)) {
            // User requests quit
            if (e.type == SDL_QUIT) {
                running = false;
            } else{
                handleInput(e, &player, GROUND_LEVEL);
            }
        }
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        // Render background
        set_background(backgroundTexture, renderer, background);

        // Render platforms
        setPlatforms(renderer, platforms, sizeof(platforms)/ sizeof(platforms[0]));

        // Update player position
        GROUND_LEVEL = updateGroundLevel(player, GROUND_LEVEL, platforms, (sizeof(platforms)/ sizeof(platforms[0])));
        updatePlayer(&player, GROUND_LEVEL);

        // Update cherry animation
        for (Cherries *c = cherries; c != NULL; c = c->next){
            updateCherryAnimation(renderer, &c->cherry);
        }

        // Check cherry collision
        for (Cherries *c = cherries; c != NULL; c = c->next){
            checkCherryCollision(&player, &c->cherry);
        }

        // Update player animation
        updatePlayerAnimation(renderer, &player);

//        WRT_DrawText(renderer, fontWhite, "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,:?!()+- A^A*A", 10, 100, 20);
//        WRT_DrawText(renderer, fontBlack, "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,:?!()+- AAA", 10, 120, 20);

        // Update count cherry
        updateCountCherry(renderer, fontWhite, &player);

        SDL_RenderPresent(renderer);
        SDL_Delay(1000 / FPS);
    }

    // Free resources and close SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}

