//
//  Util.h
//  explosion
//
//  Created by Lynn Hyerin Sohn on 2018-03-23.
//  Copyright © 2018 Lynn Hyerin Sohn. All rights reserved.
//
#pragma once

#include <SDL2/SDL.h>

namespace Util
{
    void check(void* p);
    SDL_Surface* load(const char* path, uint32_t r, uint32_t g, uint32_t b);
};
