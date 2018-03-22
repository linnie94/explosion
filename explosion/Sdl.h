//
//  Sdl.h
//  rect
//
//  Created by Lynn Hyerin Sohn on 2018-03-20.
//  Copyright © 2018 Lynn Hyerin Sohn. All rights reserved.
//

#pragma once

#include <SDL2/SDL.h>

class Sdl
{
public:
    SDL_Window* window;
    SDL_Renderer* renderer;
    
    Sdl(int xres, int yres);
};
