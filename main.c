#include "include.h"

int main(int argc, char *argv[]) {
#pragma region SDL2_Setup
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    if (TTF_Init() == -1) {
        printf("SDL_ttf could not initialize! TTF_Error: %s\n", TTF_GetError());
        SDL_Quit();
        return -1;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("SDL_image could not initialize! IMG_Error: %s\n", IMG_GetError());
        TTF_Quit();
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
        TTF_Quit();
        SDL_Quit();
        return -1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        IMG_Quit();
        TTF_Quit();
        SDL_Quit();
        return -1;
    }
#pragma endregion

    SDL_Texture *image = IMG_LoadTexture(renderer, "Idle.png");
    if (!image) {
        printf("Unable to load image %s! SDL_image Error: %s\n", "HIM.png", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return -1;
    }

    SDL_Rect srcRect;
    srcRect.x = 4;  // X position of the top-left corner of the rectangle in the image
    srcRect.y = 7;  // Y position of the top-left corner of the rectangle in the image
    srcRect.w = 23; // Width of the rectangle
    srcRect.h = 28; // Height of the rectangle

    int table[11][2] = {
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
    };

    // Define the destination rectangle on the rendering target (screen)
    SDL_Rect dstRect;
    dstRect.x = 0; // X position of the top-left corner where you want to render the image on the screen
    dstRect.y = 0; // Y position
    dstRect.w = srcRect.w + 100; // You can scale here if you want
    dstRect.h = srcRect.h + 100;

    Player player = {
            .speed = 5,
            .jumpSpeed = 25,
            .velocity = {0, 0},
            .alive = true,
            .moving = false,
            .running = false,
            .jumping = false,
            .falling = false,
            .rect = &dstRect
    };

    int GROUND_LEVEL = WINDOW_HEIGHT - dstRect.h;

    bool running = true;
    SDL_Event e;
    int index = 0;
    while (running) {
        // Handle events on queue
        while (SDL_PollEvent(&e)) {
            // User requests quit
            if (e.type == SDL_QUIT) {
                running = false;
            } else {
                handleInput(e, &player);
            }
        }
        printf("x: %d, y: %d\n", player.rect->x, player.rect->y);
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);
        // Update player position
        updatePlayer(&player, GROUND_LEVEL);

        // Update player animation
        updatePlayerAnimation();

        // Render image
        srcRect.x = table[(int) index / 4][0];
        srcRect.y = table[(int) index / 4][1];
        SDL_RenderCopy(renderer, image, &srcRect, &dstRect);
        if (index == 40) {
            index = 0;
        } else {
            index++;
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(1000 / FPS);
    }

    // Free resources and close SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();

    return 0;
}

