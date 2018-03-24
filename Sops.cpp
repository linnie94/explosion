//
//  Sops.cpp
//  explosion
//
//  Created by Lynn Hyerin Sohn on 2018-03-22.
//  Copyright © 2018 Lynn Hyerin Sohn. All rights reserved.
//

#include "Sops.h"
#include "Util.h"

void Sops :: draw(const std::deque<Sprite>& sprites, Sdl& sdl, SDL_Surface* surface, SDL_Texture* texture)
{
    // Clear screen.
    SDL_SetRenderDrawColor(sdl.renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(sdl.renderer);

    int height = surface->h;

    // Transfer all sprites.
    for(const auto& s : sprites)
    {
        SDL_Rect frame = { (s.time / s.stretch) * height, 0, height, height };
        SDL_RenderCopy(sdl.renderer, texture, &frame, &s.rect);
    }

    // Present sprites and wait some milliseconds.
    SDL_RenderPresent(sdl.renderer);
}

void Sops :: update_timeouts(std::deque<Sprite>& sprites)
{
    for(auto& s : sprites)
        s.time++;
}

void Sops :: remove_timeouts(std::deque<Sprite>& sprites)
{
    if(sprites.size() > 0)
    {
        const int last = sprites.size() - 1;
        Sprite& back = sprites[last];
        if(back.time >= back.frames * back.stretch)
            sprites.pop_back();
    }
}
