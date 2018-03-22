//
//  Sops.cpp
//  explosion
//
//  Created by Lynn Hyerin Sohn on 2018-03-22.
//  Copyright © 2018 Lynn Hyerin Sohn. All rights reserved.
//

#include "Sops.h"

void Sops :: draw(const std::deque<Sprite>& sprites, Sdl& sdl)
{
    SDL_SetRenderDrawColor(sdl.renderer, 0, 0, 0, 0);
    SDL_RenderClear(sdl.renderer);
    
    for(const auto& s : sprites)
    {
        if(s.time < 180)
        {
            SDL_SetRenderDrawColor(sdl.renderer, s.time , 0, 255, 0);
            SDL_RenderDrawRect(sdl.renderer, &s.rect);
        }
    }
    SDL_RenderPresent(sdl.renderer);
    SDL_Delay(10);
}

void Sops :: update_timeouts(std::deque<Sprite>& sprites)
{
    for(auto& s : sprites)
    {
        if(s.time < 180)
            s.time++;
    }
}

void Sops :: remove_timeouts(std::deque<Sprite>& sprites)
{
    if(sprites.size() > 0)
    {
        if(sprites[0].time >= 180)
        {
            sprites.pop_front();
        }
    }
}
