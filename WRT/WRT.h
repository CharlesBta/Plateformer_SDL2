#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct symbol{
    char c;
    SDL_Rect zone;
} symbol;

typedef struct WRT_Font{
    symbol symbols[46];
    SDL_Texture *texture;
} WRT_Font;

WRT_Font WRT_LoadFont(SDL_Texture *texture);
void WRT_DrawText(SDL_Renderer *renderer, WRT_Font font, char *text, int x, int y, int size);
char* WRT_toUpper(const char* input) {
    // Allocate memory for the output string (+1 for the null terminator)
    char* output = malloc(strlen(input) + 1);
    if (!output) {
        // Handle memory allocation error
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }

    // Convert to uppercase
    for (size_t i = 0; input[i] != '\0'; i++) {
        if (isalpha((unsigned char)input[i])) {
            output[i] = toupper((unsigned char)input[i]);
        } else {
            output[i] = input[i];
        }
    }

    // Null-terminate the output string
    output[strlen(input)] = '\0';

    return output;
}