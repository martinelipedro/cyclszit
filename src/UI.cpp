#include "include/UI.hpp"
#include "include/helpers.hpp"

#define INVENTORY_BACKGROUND_BORDER_OFFSET 0.05
#define INVENTORY_ITEM_TEXT_OFFSET_X 20

UIText::UIText()
{
    TTF_Init();
    this->text_font = TTF_OpenFont(TEXT_FONT_PATH, 20);
}

void UIText::set_text(const char* text)
{
    this->text_surface = TTF_RenderText_Solid(text_font, text, {0, 0, 0, 255});
}

void UIText::draw(SDL_Surface* window_surface, int x, int y)
{
    SDL_Rect* draw_rect = new SDL_Rect{x, y, 0, 0};
    SDL_BlitSurface(this->text_surface, NULL, window_surface, draw_rect);
}

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

UIFInventory::UIFInventory(int x, int y, int w, int h) : x(x), y(y), w(w), h(h), text_buffer(new UIText), is_visible(true) {}


void UIFInventory::draw_background_border(SDL_Surface* window_surface)
{
    SDL_Rect* background_frame_rect = new SDL_Rect{this->x, this->y, this->w, this->h};
    SDL_FillRect(window_surface, background_frame_rect, 0);
}

void UIFInventory::draw_background_frame(SDL_Surface* window_surface)
{
    SDL_Rect* background_frame_rect = new SDL_Rect{
        this->x + (int)(this->x * INVENTORY_BACKGROUND_BORDER_OFFSET),
        this->y + (int)(this->y * INVENTORY_BACKGROUND_BORDER_OFFSET),
        this->w - (int)(this->x * INVENTORY_BACKGROUND_BORDER_OFFSET * 2),
        this->h - (int)(this->y * INVENTORY_BACKGROUND_BORDER_OFFSET * 2)
    };
    SDL_FillRect(window_surface, background_frame_rect, color_from_rgb(144, 144, 144, 255));
}


void UIFInventory::draw(SDL_Surface* window_surface)
{
    if (!is_visible)
        return;

    this->draw_background_border(window_surface);
    this->draw_background_frame(window_surface);
    text_buffer->set_text("Wood: 5");
    text_buffer->draw(window_surface, this->x + INVENTORY_ITEM_TEXT_OFFSET_X, this->y + INVENTORY_ITEM_TEXT_OFFSET_X);
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