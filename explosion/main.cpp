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

    // TODO:
    // We are going to load the sprite sheet here.
    // Another name for a sprite sheet is a surface.
    // Sprite sheets live in RAM once they are loaded.
    //
    // We only have one sprite sheet, so a deque is not necessary,
    // but it is good practise because in the future our game will use
    // many sprite sheets.
    //
    //      std::deque<SDL_Surface*> surfaces;
    //
    // Sprite sheets are useless in RAM. Transferring an image
    // from RAM to a rect area on the screen is very slow, so all the
    // sprite sheets must be converted and placed into graphics memory.
    // Graphics memory is very fast when it comes to moving images
    // to the screen.
    //
    // These things are called textures.
    //
    //      std::deque<SDL_Texture*> textures;
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
