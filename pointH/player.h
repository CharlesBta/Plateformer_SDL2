typedef struct Sprite{
    SDL_Texture *texture;
    SDL_Rect srcRect;
    int Pos[12][2];
    int nbPos;
}Sprite;

typedef enum Direction{
    RIGHT,
    LEFT
} Direction;

typedef enum SpriteState{
    STATIC_RIGHT,
    STATIC_LEFT,
    RUN_RIGHT,
    RUN_LEFT,
    JUMP_RIGHT,
    JUMP_LEFT,
    FALL_RIGHT,
    FALL_LEFT
} SpriteState;

typedef struct Player {
    int speed;
    int jumpSpeed;
    int velocity[2]; // x and y velocity
    bool alive;
    bool moving;
    Direction direction;
    bool running;
    bool jumping;
    bool falling;
    SpriteState spriteIndex;
    SDL_Rect dstRect;
    Sprite *sprites[8]; // 0 static right sprite, 1 static left sprite, 2 run right sprite, 3 run left sprite, 4 jump right sprite, 5 jump left sprite, 6 fall right sprite, 7 fall left sprite
} Player;

void handleInput(SDL_Event event, Player *p, int GL){
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_q:
            case SDLK_LEFT:
                p->velocity[0] = -p->speed;
                p->moving = true;
                p->running = true;
                p->direction = LEFT;
                break;
            case SDLK_d:
            case SDLK_RIGHT:
                p->velocity[0] = p->speed;
                p->moving = true;
                p->running = true;
                p->direction = RIGHT;
                break;
            case SDLK_SPACE:
            case SDLK_z:
            case SDLK_UP:
                if (!p->jumping && !p->falling) {
                    p->velocity[1] = -p->jumpSpeed;
                    p->jumping = true;
                }
                break;
            case SDLK_s:
            case SDLK_DOWN:
                if (!p->jumping && !p->falling) {
                    if (GL < WINDOW_HEIGHT - p->dstRect.h) {
                        p->dstRect.y += 1;
                        p->falling = true;
                    }
                }
                break;
        }
    } else if (event.type == SDL_KEYUP) {
        switch (event.key.keysym.sym) {
            case SDLK_q:
            case SDLK_d:
            case SDLK_LEFT:
            case SDLK_RIGHT:
                p->velocity[0] = 0;
                p->moving = false;
                p->running = false;
                break;
        }
    }
}
void updatePlayer(Player *p, int GROUND_LEVEL){
    int nextX = p->dstRect.x + p->velocity[0];
    int nextY = p->dstRect.y + p->velocity[1];

    int nextXWidth = nextX + p->dstRect.w;
    int nextYHeight = nextY + p->dstRect.h;

    if (nextX < 0 || nextXWidth > WINDOW_WIDTH) {
        p->velocity[0] = 0;
    }

    p->dstRect.x += p->velocity[0];
    p->dstRect.y += p->velocity[1];

    p->velocity[1] += GRAVITY;
    if (p->dstRect.y >= GROUND_LEVEL) {
        p->dstRect.y = GROUND_LEVEL;
        p->velocity[1] = 0;
        p->jumping = false;
        p->falling = false;
    }

    if (p->velocity[1] > 0) {
        p->falling = true;
        p->jumping = false;
    }

    if (p->direction == RIGHT)
        if (p->jumping)
            p->spriteIndex = JUMP_RIGHT;
        else if (p->falling)
            p->spriteIndex = FALL_RIGHT;
        else if (p->running)
            p->spriteIndex = RUN_RIGHT;
        else
            p->spriteIndex = STATIC_RIGHT;

    else if (p->direction == LEFT)
        if (p->jumping)
            p->spriteIndex = JUMP_LEFT;
        else if (p->falling)
            p->spriteIndex = FALL_LEFT;
        else if (p->running)
            p->spriteIndex = RUN_LEFT;
        else
            p->spriteIndex = STATIC_LEFT;
    else
        p->spriteIndex = STATIC_RIGHT;
}
int spriteIndex = 0;
SpriteState stripteIndexTmp = STATIC_RIGHT;
void updatePlayerAnimation(SDL_Renderer *renderer, Player *p){
    if (stripteIndexTmp != p->spriteIndex) {
        spriteIndex = 0;
        stripteIndexTmp = p->spriteIndex;
    }

    p->sprites[p->spriteIndex]->srcRect.x = p->sprites[p->spriteIndex]->Pos[(int) spriteIndex / 4][0];
    p->sprites[p->spriteIndex]->srcRect.y = p->sprites[p->spriteIndex]->Pos[(int) spriteIndex / 4][1];

    if (spriteIndex == p->sprites[p->spriteIndex]->nbPos * 4 - 1) {
        spriteIndex = 0;
    } else {
        spriteIndex++;
    }

    SDL_RenderCopy(renderer, p->sprites[p->spriteIndex]->texture, &p->sprites[p->spriteIndex]->srcRect, &p->dstRect);
}
