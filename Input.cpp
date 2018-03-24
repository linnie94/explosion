//
//  Input.cpp
//  explosion
//
//  Created by Lynn Hyerin Sohn on 2018-03-22.
//  Copyright © 2018 Lynn Hyerin Sohn. All rights reserved.
//

#include "Input.h"

Input :: Input()
{
    SDL_PollEvent(&event);
    key = SDL_GetKeyboardState(NULL);
    button = SDL_GetMouseState(&x, &y);
}

bool Input :: done()
{
    return event.type == SDL_QUIT || key[SDL_SCANCODE_ESCAPE] || key[SDL_SCANCODE_END];
}
