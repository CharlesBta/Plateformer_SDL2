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
    SDL_Rect rect;
}Platform;

