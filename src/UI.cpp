#include "include/UI.hpp"
#include "include/helpers.hpp"

UIFStatusBar::UIFStatusBar(int x, int y, int w, int h, SDL_Color bg, SDL_Color fg)
    : x(x), y(y), w(w), h(h), bg(bg), fg(fg), percent(1) {}

void UIFStatusBar::set_percent(float percent)
{
    this->percent = percent;
}

void UIFStatusBar::draw(SDL_Surface* window_surface)
{
    SDL_Rect* background_rect = new SDL_Rect {this->x, this->y, this->w, this->h};
    
    SDL_FillRect(window_surface, background_rect, color_from_rgb(this->bg.r, this->bg.g, this->bg.b, this->bg.a));
    SDL_Rect* border_rect = new SDL_Rect {this->x + 2, this->y+ 2, this->w - 4, this->h-4};
    SDL_FillRect(window_surface, border_rect, 0);
    SDL_Rect* inner_rect = new SDL_Rect {
        this->x + 3,
        static_cast<int>((this->y + (this->h - this->h * this->percent)) + 3),
        static_cast<int>(this->w - 6.f),
        static_cast<int>(this->h * this->percent- 6.f)};
    SDL_FillRect(window_surface, inner_rect, color_from_rgb(this->fg.r, this->fg.g, this->fg.b, this->fg.a));
}

void UIManager::add_frame(UIFrame* frame)
{
    this->ui_frames.push_back(frame);
}

void UIManager::draw(SDL_Surface* surface)
{
    for (auto& frame : this->ui_frames)
    {
        frame->draw(surface);
    }
}