//
//  Sops.cpp
//  explosion
//
//  Created by Lynn Hyerin Sohn on 2018-03-22.
//  Copyright © 2018 Lynn Hyerin Sohn. All rights reserved.
//

#include "Sops.h"
#include "Util.h"

void Sops :: draw(const std::deque<Sprite>& sprites, Sdl& sdl , SDL_Surface* surface, SDL_Texture* texture)
{
    // Clear screen.
    SDL_SetRenderDrawColor(sdl.renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(sdl.renderer);

    int height = surface->h;

    // Transfer all sprites.
    for(const auto& s : sprites)
    {
        SDL_Rect frame = { (s.time / 5) * height, 0, height, height };
        SDL_RenderCopy(sdl.renderer, texture, &frame, &s.rect);
    }

    // Present sprites and wait some milliseconds.
    SDL_RenderPresent(sdl.renderer);
    SDL_Delay(10);
}

void Sops :: update_timeouts(std::deque<Sprite>& sprites)
{
    for(auto& s : sprites)
        s.time++;
}

void Sops :: remove_timeouts(std::deque<Sprite>& sprites)
{
    const int timeout = 60;
        while(sprites.size() > 0)
    {
        const int last = sprites.size() - 1;
        if(sprites[last].time < timeout)
            break;
        sprites.pop_back();
     }
    
    // This will remove all timeouted sprites in one frame update.
}
