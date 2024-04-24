typedef struct BackgroundTexture{
    SDL_Texture *texture;
    SDL_Rect rect;
}BackgroundTexture;

typedef enum Background{
    BLUE,
    BROWN,
    GRAY,
    GREEN,
    PINK,
    PURPLE,
    YELLOW
}Background;