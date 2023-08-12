#ifndef _UI_HPP
#define _UI_HPP

#include <SDL2/SDL.h>
#include <vector>
#include <functional>

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

class UIManager
{
private:
    std::vector<UIFrame*> ui_frames;
public:
    UIManager() = default;
    void add_frame(UIFrame* frame);

    void draw(SDL_Surface* surface);
};

#endif