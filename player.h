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

void handleInput(SDL_Event event, Player *p, int GROUND_LEVEL);
void updatePlayer(Player *p, int GROUND_LEVEL);
void updatePlayerAnimation(SDL_Renderer *renderer, Player *p);
