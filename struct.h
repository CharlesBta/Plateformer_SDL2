typedef struct Sprite{
    SDL_Texture *texture;
    SDL_Rect srcRect;
    int Pos[12][2];
    int nbPos;
}Sprite;

typedef enum TypePlatform{
    NORMAL,
    BREAKABLE,
    SPIKE
}TypePlatform;

typedef struct Platform{
    TypePlatform type;
    SDL_Texture *texture;
    int x, y;
    SDL_Rect rect;
}Platform;

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