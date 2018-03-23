//
//  Util.cpp
//  explosion
//
//  Created by Lynn Hyerin Sohn on 2018-03-23.
//  Copyright © 2018 Lynn Hyerin Sohn. All rights reserved.
//

#include "Util.h"

// R,G,B specifies color key. The color key will not be shown when the image is transferred to the screen.
SDL_Surface* Util::load(const char* path, uint32_t r, uint32_t g, uint32_t b)
{
    // Loads surface from bmp image.
    SDL_Surface* bmp = SDL_LoadBMP(path);
    // Removes alpha channel from surface so a color key can be applied to surface.
    SDL_PixelFormat* allocation = SDL_AllocFormat(SDL_PIXELFORMAT_RGB888);
    SDL_Surface* converted = SDL_ConvertSurface(bmp, allocation, 0);
    // Frees old surface.
    //SDL_FreeFormat(allocation);
    //SDL_FreeSurface(bmp);
    // Applies color key to new surface.
    SDL_SetColorKey(converted, SDL_TRUE, SDL_MapRGB(converted->format, r, g, b));
    // Returns new surface.
    return converted;
}
