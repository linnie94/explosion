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
#include "Util.h"

int main()
{
    Sdl sdl(1024, 600);

    std::deque<Sprite> sprites;
    
    SDL_Surface* surface = Util::load("art/Explosion_Sprites.bmp", 0, 0, 0);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(sdl.renderer, surface);
    
    while(true)
    {
        std::cout << sprites.size() << std::endl;

        Input input;
        if(input.done())
            break;

        // Left click.
        if(input.button == 1)
            sprites.push_front(Sprite(input.x, input.y));
        
        // Right click.
        int x = std::rand() % sdl.xres;
        int y = std::rand() % sdl.yres;
        if(input.button == 4)
            sprites.push_front(Sprite(x, y));

        Sops :: draw(sprites, sdl, surface, texture);
        
        Sops :: update_timeouts(sprites);
        
        Sops :: remove_timeouts(sprites);
    }
}
