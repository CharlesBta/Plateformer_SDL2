#define MAX_TOKENS 252
#define BUFFER_SIZE 1024

Background stringToBackground(const char* str);
Background* backgroundLoader(char path[]);
Platform* platformLoader(SDL_Texture *texture, char path[]);
Cherries* cherryLoader(SDL_Texture *texture, char path[]);
int countPlatforms(Platform *platforms);
int countCherries(Cherries *cherries);
StartPosition startPositionLoader(char path[]);
int count_directories(const char *path);
