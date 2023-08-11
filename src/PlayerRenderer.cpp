#include "include/PlayerRenderer.hpp"
#include "include/helpers.hpp"

void PlayerRenderer::draw(SDL_Surface* surface, int x, int y)
{
    SDL_Rect* rect = get_sprite_absolute_position(x, y);
    rect->x += 50;
    rect->y -= 30;
    rect->w = 30;
    rect->h = 70;

    SDL_FillRect(surface, rect, 0);

}