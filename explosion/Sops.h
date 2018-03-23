//
//  Sops.hpp
//  explosion
//
//  Created by Lynn Hyerin Sohn on 2018-03-22.
//  Copyright © 2018 Lynn Hyerin Sohn. All rights reserved.
//

#pragma once

#include <deque>
#include "Sprite.h"

namespace Sops
{
    void draw(const std::deque<Sprite>& sprites, Sdl& sdl , SDL_Surface* surface, SDL_Texture* texture);
    
    void update_timeouts(std::deque<Sprite>& sprites);
    
    void remove_timeouts(std::deque<Sprite>& sprites);
}
