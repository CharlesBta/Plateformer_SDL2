typedef struct Color{
    int r, g, b, a;
}Color;

typedef struct Button{
    Color color;
    WRT_Font font;
    int fontSize;
    char text[100];
    SDL_Rect zone;
    int padding;
}Button;

Color creatColor(int r, int g, int b);
Button createButton(WRT_Font font, char text[], int fontSize, int x, int y, Color color, int padding);
void updateButton(SDL_Renderer *renderer, Button *button, SDL_Point mouse);