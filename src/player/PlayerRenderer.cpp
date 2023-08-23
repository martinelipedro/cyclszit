#include "../include/player/PlayerRenderer.hpp"
#include "../include/helpers.hpp"

void PlayerRenderer::draw(SDL_Surface* surface, int x, int y)
{
    SDL_Point* position = get_absolute_position(x, y);
    SDL_Rect* draw_rect = new SDL_Rect{position->x, position->y, 0, 0};
    draw_rect->x += 50;
    draw_rect->y -= 30;
    draw_rect->w = 30;
    draw_rect->h = 70;

    SDL_FillRect(surface, draw_rect, 0);
    delete position;
    delete draw_rect;
}