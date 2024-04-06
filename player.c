typedef struct Player {
    int speed;
    int jumpSpeed;
    int velocity[2]; // x and y velocity
    bool alive;
    bool moving;
    bool running;
    bool jumping;
    bool falling;
    SDL_Rect *rect;
} Player;


void handleInput(SDL_Event event, Player *player) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_LEFT:
                player->velocity[0] = -player->speed;
                player->moving = true;
                break;
            case SDLK_RIGHT:
                player->velocity[0] = player->speed;
                player->moving = true;
                break;
            case SDLK_UP:
                if (!player->jumping && !player->falling) {
                    player->velocity[1] = -player->jumpSpeed;
                    player->jumping = true;
                }
                break;
        }
    } else if (event.type == SDL_KEYUP) {
        switch (event.key.keysym.sym) {
            case SDLK_LEFT:
            case SDLK_RIGHT:
                player->velocity[0] = 0;
                player->moving = false;
                break;
        }
    }
}

void updatePlayer(Player *player, int GROUND_LEVEL) {
    player->rect->x += player->velocity[0];
    player->rect->y += player->velocity[1];

    player->velocity[1] += GRAVITY;
    if (player->rect->y >= GROUND_LEVEL) {
        player->rect->y = GROUND_LEVEL;
        player->velocity[1] = 0;
        player->jumping = false;
        player->falling = false;
    }

    // If player is in the air and not moving upwards anymore, they are falling
    if (player->velocity[1] > 0) {
        player->falling = true;
    }
}

void updatePlayerAnimation() {
    // Implement player animation here
}