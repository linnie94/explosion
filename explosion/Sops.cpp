//
//  Sops.cpp
//  explosion
//
//  Created by Lynn Hyerin Sohn on 2018-03-22.
//  Copyright © 2018 Lynn Hyerin Sohn. All rights reserved.
//

#include "Sops.h"
#include "Util.h"

void Sops :: draw(const std::deque<Sprite>& sprites, Sdl& sdl , SDL_Surface* surface, SDL_Texture* texture)
{
    // Clear screen.
    SDL_SetRenderDrawColor(sdl.renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(sdl.renderer);

    // TODO:
    // Have a look at the Explosion_Sprite.bmp in the art folder.
    // See how each sprite frame is square. You can find the dimensions of the square
    // by getting the height of hte entire image.
    //
    // From the surface you passed in:
    //
    int height = surface->h.
    //
    // Select the first frame of the surface sprite for the texture by building a rect:
    //
    //     SDL_Rect frame = { 0 * height, 0, height, height };
    //
    // To select the second frame, do:
    //
    //     SDL_Rect frame = { 1 * height, 0, height, height };
    //
    // To select the third frame, do:
    //
    //     SDL_Rect frame = { 2 * height, 0, height, height };
    //

    // Transfer all sprites.
    for(const auto& s : sprites)
    {
        // There are 12 frames in the sprite sheet. Our sprite timer expires at 60 seconds.
        //
        //     Thus, 60 / 5 == 12, and therefor, the above nicely becomes:
        //
        SDL_Rect frame = { (s.time / 5) * height, 0, height, height };
        //
        // You can then use SDL_RenderCopy() to transfer the frame rect above containing one frame of sprite data
        // to the sprites rect location on the window from the deque.
        //
        // That is, instead of just plainly coloring rects and transferring them:
        //
        //SDL_SetRenderDrawColor(sdl.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        //SDL_RenderDrawRect(sdl.renderer, &s.rect);

        // Do this instead:
        //
<<<<<<< HEAD
        SDL_RenderCopy(sdl.renderer, texture, &frame, sprite.rect);
=======
        // SDL_RenderCopy(sdl.renderer, texture, &frame, &s.rect);
>>>>>>> 3ab45952ce16093d582aa73bd41804484b759dd3
        //
        //This will transfer the sprite frame from the texture to the renderer at the sprite rect location.
    }

    // Present sprites and wait some milliseconds.
    SDL_RenderPresent(sdl.renderer);
    SDL_Delay(10);
}

void Sops :: update_timeouts(std::deque<Sprite>& sprites)
{
    for(auto& s : sprites)
        s.time++;
}

void Sops :: remove_timeouts(std::deque<Sprite>& sprites)
{
    const int timeout = 60;
    // TODO:
    // When you add many sprites at once to the screen in a single instance (like 100 at the same time)
    // you will notice that this only removes one per frame update.
    //
    // That is, if we add 100 sprites at the same time with random locations like we do with right click,
    // they will all timeout at the same time, but they will not be removed at the same time. One timeout will be removed per
    // frame update. If we do 100 frame updates per second (due to SDL_Delay(10)) it will take almost a second to get rid of them all.
    //
    // To remove them all at once, instead of doing this:
    //if(sprites.size() > 0)
    //{
    //    const int last = sprites.size() - 1;
    //    if(sprites[last].time >= 60)
    //        sprites.pop_back();
    //}

    // Do this:
    while(sprites.size() > 0)
    {
        const int last = sprites.size() -1;
        if(sprites[last].time < timeout)
            break;
        sprites.pop_back();
     }
    
    // This will remove all timeouted sprites in one frame update.
}
