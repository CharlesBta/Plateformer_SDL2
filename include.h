#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <pthread.h>
#include <stdbool.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/stat.h>

#include "WRT/WRT.c"

#include "define.h"

#include "Player/player.c"
#include "Platform/platform.c"
#include "Background/background.c"
#include "Cherry/cherry.c"
#include "Components/Button/button.c"
#include "Components/CountCherry/count_cherry.c"
#include "Pages/struct.h"
#include "Pages/Game/game.c"
#include "Pages/Menu/menu.c"
#include "Pages/Pause/pause.c"
#include "Pages/Win/win.c"

#include "Level//struct.h"
#include "Level/levelLoader.c"