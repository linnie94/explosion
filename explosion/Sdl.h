//
//  Sdl.h
//  explosion
//
//  Created by Lynn Hyerin Sohn on 2018-03-22.
//  Copyright © 2018 Lynn Hyerin Sohn. All rights reserved.
//

#pragma once

#include <SDL2/SDL.h>

class Sdl
{
public:
    SDL_Window* window;
    SDL_Renderer* renderer;
    int xres = 800;
    int yres = 400;
    
    Sdl();
};
