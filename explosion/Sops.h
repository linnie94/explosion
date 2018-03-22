//
//  Sops.h
//  rect
//
//  Created by Lynn Hyerin Sohn on 2018-03-20.
//  Copyright © 2018 Lynn Hyerin Sohn. All rights reserved.
//

#pragma once

#include <deque>
#include "Sprite.h"

namespace Sops
{
    void draw(const std::deque<Sprite>& sprites, Sdl& sdl);

    void update_timeouts(std::deque<Sprite>& sprites);
   
    void remove_timeouts(std::deque<Sprite>& sprites);
}
