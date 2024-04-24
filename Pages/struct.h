typedef struct Display{
    struct Game *game;
    struct Menu *menu;
    struct Pause *pause;
}Display;

typedef enum GameState{
    MENU,
    PLAY,
    PAUSE
}GameState;