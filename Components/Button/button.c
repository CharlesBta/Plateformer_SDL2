#include "button.h"

Color creatColor(int r, int g, int b){
    Color *color = malloc(sizeof(Color));
    color->r = r;
    color->g = g;
    color->b = b;
    color->a = 255;
    return *color;
}

Button createButton(WRT_Font font, char text[], int fontSize, int x, int y, Color color, int padding){
    Button *button = malloc(sizeof(Button));
    button->color = color;
    button->font = font;
    button->fontSize = fontSize;
    strcpy(button->text, text);
    if (padding < 0) padding = 0;
    button->padding = padding;
    button->zone = (SDL_Rect) {x, y, strlen(button->text) * fontSize + button->padding, fontSize + button->padding};
    return *button;
}

SDL_bool isButtonClicked(Button *button, SDL_Point mouse){
    return SDL_PointInRect(&mouse, &button->zone);
}

void updateButton(SDL_Renderer *renderer, Button *button, SDL_Point mouse){
    if (SDL_PointInRect(&mouse, &button->zone) == SDL_TRUE) {
        SDL_SetRenderDrawColor(renderer, 128, 128, 128, button->color.a);
        SDL_RenderFillRect(renderer, &button->zone);
        WRT_DrawText(renderer, button->font, button->text, button->zone.x + (button->padding / 2), button->zone.y + (button->padding / 2), button->fontSize);
        SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
    } else {
        SDL_SetRenderDrawColor(renderer, button->color.r, button->color.g, button->color.b, button->color.a);
        SDL_RenderFillRect(renderer, &button->zone);
        WRT_DrawText(renderer, button->font, button->text, button->zone.x + (button->padding / 2), button->zone.y + (button->padding / 2), button->fontSize);
        SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW));
    }
}

