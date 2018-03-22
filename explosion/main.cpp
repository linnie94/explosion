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
        
        Sops :: draw(sprites, sdl);
        
        Sops :: remove_timeouts(sprites);
    }
}
