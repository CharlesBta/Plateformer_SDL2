#include "WRT.h"

WRT_Font WRT_LoadFont(SDL_Texture *texture) {
    WRT_Font font;
    font.texture = texture;
    char tabSymbols[46] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,:?!()+- ";
    int y = 0;
    int x = 0;
    int i = 0;
    while(1){
        if (x == 80 && y == 40) break;
        font.symbols[i].c = tabSymbols[i];
        if (i == 26)
        {
            x = 0;
            y += 10;
        } else if (x == 80) {
            x = 0;
            y += 10;
        }
        font.symbols[i].zone = (SDL_Rect) {x, y, 8, 10};
        x += 8;
        i++;
    }
    return font;
}

void WRT_DrawText(SDL_Renderer *renderer, WRT_Font font, char *text, int x, int y, int size) {
    if (text == NULL) return;
    text = WRT_toUpper(text);
//    printf("%s\n", text);
    for (int i = 0; text[i] != '\0'; i++) {
        for (int j = 0; j < 46; ++j) {
            if (text[i] == font.symbols[j].c) {
                SDL_Rect src = font.symbols[j].zone;
                SDL_Rect dest = (SDL_Rect) {x + i * size, y, size, size};
                SDL_RenderCopy(renderer, font.texture, &src, &dest);
            }
        }
    }
}
