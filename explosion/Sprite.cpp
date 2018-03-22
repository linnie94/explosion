//
//  Sprite.cpp
//  explosion
//
//  Created by Lynn Hyerin Sohn on 2018-03-22.
//  Copyright © 2018 Lynn Hyerin Sohn. All rights reserved.
//

#include "Sprite.h"

Sprite :: Sprite(int x, int y)
{
    rect.x = x;
    rect.y = y;
    rect.h = 10;
    rect.w = 10;
    time = 0;
}

void Sprite :: speak() const
{
    std::cout << rect.x << "," << rect.y << "," << time <<std::endl;
}
