typedef struct Display{
    struct Game *game;
    struct Menu *menu;
    struct Pause *pause;
    struct Win *win;
}Display;

typedef enum GameState{
    MENU,
    PLAY,
    PAUSE,
    WIN
}GameState;