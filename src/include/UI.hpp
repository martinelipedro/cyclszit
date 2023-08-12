#ifndef _UI_HPP
#define _UI_HPP

#define TEXT_FONT_PATH "src/assets/font.ttf"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <functional>

class UIText
{
private:
    SDL_Surface* text_surface;
public:
    TTF_Font* text_font;
    UIText();
    void set_text(const char* text);
    void draw(SDL_Surface* window_surface, int x, int y);
};

static UIText* TextManager = new UIText();

class UIFrame
{
public:
    virtual void draw(SDL_Surface* window_surface) = 0;
};

class UIFStatusBar : public UIFrame
{
private:
    int x, y;
    int w, h;
    SDL_Color bg, fg;
    float percent;
public:
    UIFStatusBar(int x, int y, int w, int h, SDL_Color bg, SDL_Color fg);
    void set_percent(float percent);
    void draw(SDL_Surface* window_surface) override;
};

class UIFInventory : public UIFrame
{
private:
    int x, y;   
    int w, h;
    SDL_Surface* text_surface;
    UIText* text_buffer;
public:
    bool is_visible;
    UIFInventory(int x, int y, int w, int h);

    void draw_background_border(SDL_Surface* window_surface);
    void draw_background_frame(SDL_Surface* window_surface);
    void draw(SDL_Surface* window_surface) override;
};

class UIManager
{
private:
public:
    std::vector<UIFrame*> ui_frames;
    UIManager() = default;
    void add_frame(UIFrame* frame);

    void draw(SDL_Surface* surface);
};

#endif