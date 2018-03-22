//
//  Sdl.cpp
//  explosion
//
//  Created by Lynn Hyerin Sohn on 2018-03-22.
//  Copyright © 2018 Lynn Hyerin Sohn. All rights reserved.
//

#include "Sdl.h"

#include <iostream>

Sdl :: Sdl(int xres, int yres)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(xres, yres, 0, &window, &renderer);
    if(window == NULL || renderer == NULL)
        std::cout << SDL_GetError() << std::endl;
}

