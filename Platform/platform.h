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