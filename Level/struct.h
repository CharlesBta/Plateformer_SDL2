typedef struct StartPosition{
    int x, y;
}StartPosition;

typedef struct Level{
    int ID;
    Background *background[252];
    Platform *platforms[20];
    int nbPlatform;
    Cherries *cherries;
    int nbCherries;
    StartPosition startPosition;
    struct Level *next;
}Level;
