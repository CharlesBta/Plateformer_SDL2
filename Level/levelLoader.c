#include "levelLoader.h"

Background stringToBackground(const char *str) {
    if (strcmp(str, "BLUE") == 0) return BLUE;
    else if (strcmp(str, "BROWN") == 0) return BROWN;
    else if (strcmp(str, "GRAY") == 0) return GRAY;
    else if (strcmp(str, "GREEN") == 0) return GREEN;
    else if (strcmp(str, "PINK") == 0) return PINK;
    else if (strcmp(str, "PURPLE") == 0) return PURPLE;
    else if (strcmp(str, "YELLOW") == 0) return YELLOW;
    return -1;
}

Background *backgroundLoader(char path[]) {
    Background *backgrounds = (Background *) malloc(MAX_TOKENS * sizeof(Background));
    char buffer[BUFFER_SIZE];
    FILE *fp = fopen(path, "r");
    if (!fp) {
        perror("Failed to open file");
        return false;
    }

    int count = 0;

    while (fgets(buffer, BUFFER_SIZE, fp) && count < MAX_TOKENS) {
        char *token = strtok(buffer, ",\n");
        while (token != NULL && count < MAX_TOKENS) {
            Background color = stringToBackground(token);
            if (color == -1) {
                fprintf(stderr, "Invalid color: %s\n", token);
                return false;
            }
            backgrounds[count++] = color;
            token = strtok(NULL, ",\n");
        }
    }

    fclose(fp);
    return backgrounds;
}

Platform *platformLoader(SDL_Texture *texture, char path[]) {
    Platform *platforms = (Platform *) malloc(MAX_TOKENS * sizeof(Platform));
    char buffer[BUFFER_SIZE];
    FILE *fp = fopen(path, "r");
    if (!fp) {
        perror("Failed to open file");
        return false;
    }

    int count = 0;
    int index = 0;
    int x = 0;
    int y = 0;

    while (fgets(buffer, BUFFER_SIZE, fp) && count < MAX_TOKENS) {
        char *token = strtok(buffer, ",\n");
        while (token != NULL && count < MAX_TOKENS) {
            if (count % 2 == 0) {
                x = atoi(token);
            } else {
                y = atoi(token);
                platforms[index] = (Platform) {.texture = texture, .x = x, .y = y};
                index++;
            }
            count++;
            token = strtok(NULL, ",\n");
        }
    }
    loadPlatforms(platforms, index);
    fclose(fp);
    return platforms;
}

Cherries *cherryLoader(SDL_Texture *texture, char path[]) {
    Cherries *head = NULL;
    char buffer[BUFFER_SIZE];
    FILE *fp = fopen(path, "r");
    if (!fp) {
        perror("Failed to open file");
        return false;
    }

    while (fgets(buffer, BUFFER_SIZE, fp)) {
        char *token = strtok(buffer, ",\n");
        int x = atoi(token);
        token = strtok(NULL, ",\n");
        int y = atoi(token);
        addCherry(&head, generateCherry(texture, x, y));
    }

    fclose(fp);
    return head;
}

//int countPlatforms(Platform *platforms) {
//    int count = 0;
//    while (platforms[count].texture != NULL) {
//        count++;
//    }
//    return count;
//}

int countPlatforms(const char *filePath) {
    FILE *file = fopen(filePath, "r"); // Ouvre le fichier en mode lecture
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return -1; // Retourne -1 en cas d'erreur lors de l'ouverture du fichier
    }

    int lines = 0; // Initialisation du compteur de lignes
    int ch; // Variable pour stocker chaque caractère lu

    // Boucle de lecture du fichier
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            lines++; // Incrémente le compteur de lignes à chaque nouvelle ligne
        }
    }

    fclose(file); // Ferme le fichier
    return lines + 1; // Retourne le nombre de lignes
}

int countCherries(Cherries *cherries) {
    int count = 0;
    while (cherries != NULL) {
        count++;
        cherries = cherries->next;
    }
    return count;
}

StartPosition startPositionLoader(char path[]) {
    StartPosition startPosition = (StartPosition) {0, 0};
    char buffer[BUFFER_SIZE];
    FILE *fp = fopen(path, "r");
    if (!fp) {
        perror("Failed to open file");
        return startPosition;
    }

    fgets(buffer, BUFFER_SIZE, fp);
    char *token = strtok(buffer, ",\n");
    startPosition.x = atoi(token);
    token = strtok(NULL, ",\n");
    startPosition.y = atoi(token);

    fclose(fp);
    return startPosition;
}

int count_directories(const char *path) {
    int folderCount = 0;
    struct dirent *entry;

    DIR *dir = opendir(path);

    if (dir == NULL) {
        perror("Failed to open directory");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                folderCount++;
            }
        }
    }

    closedir(dir);
    return folderCount;
}