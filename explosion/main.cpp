//
//  main.cpp
//  explosion
//
//  Created by Lynn Hyerin Sohn on 2018-03-21.
//  Copyright © 2018 Lynn Hyerin Sohn. All rights reserved.
//

#include "Sdl.h"
#include "Input.h"
#include "Sprite.h"
#include "Sops.h"

int main()
{
    Sdl sdl(800, 400);
    std::deque<Sprite> sprites;
    while(true)
    {
        std::cout << sprites.size() << std::endl;
        Input input;
        if(input.done())
            break;
        
        if(input.button == 1)
            sprites.push_front(Sprite(input.x, input.y));
        
        Sops :: update_timeouts(sprites);

        // TODO:
        //
        // Timeouts must be removed before the sprites are drawn.
        //
        // There are 18 frames for the explosion. We will draw:
        //
        //   Frame  0 when time is   0 -  10 (not including 10).
        //   Frame  1 when time is  10 -  20 (not including 20).
        //   ...
        //   Frame 17 when time is 170 - 180 (not including 180).
        //
        // So if update_timeouts() is 180 at the back of the deque it must be removed.
        //
        // Swap the order of draw() and remove_timeouts().
        
        Sops :: draw(sprites, sdl);
        
        Sops :: remove_timeouts(sprites);
    }
}
