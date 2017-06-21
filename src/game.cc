#include "game.h"

#include <SDL/SDL.h>

namespace{
const int kScreenWidth = 640;
const int kScreenHeight = 480;
const int kBitsPerPixel = 32;
const int kFps = 60;
const float kTime = 1000/kFps;
}/*google style constnats with k for constant followed by camel case */
Game:: Game(){
   SDL_Init(SDL_INIT_EVERYTHING);
   SDL_ShowCursor(SDL_DISABLE):
   screen_ = SDL_SetVideoMode(
                 kScreenWidth/*width*/, 
                 kScreenHeight/*height*/, 
                 kBitsPerPixel/*bits per pixle*/, 
                 SDL_FULLSCREEN /*flags*/);
   eventLoop();
}

Game:: ~Game(){
   SDL_FreeSurface(screen_);
   SDL_QUIT();
}

void Game::eventLoop(){
   SDL_Event event;

   bool running = true;
   while (running){
      while(SDL_PollEvent(&event)) {
         switch (event.type) {
            case SDL_KEYDOWN:
               if(event.key.keysym.sym == SDLK_ESCAPE){
                  running = false;
               }
               break;
            default:
               break;
         }
      }
   //    update() .  Move the player. Move projectiles. Check collisions
      update();
      draw();
      // this loop lasts 1/60th of a second
      //                1000/60ths ms
      const int elapsed_time_ms = SDL_GetTicks() - start_time_ms;
      if(elapsed_time < kTime){
         SDL_Delay(kTime - elapsed_time_ms /*ms*/);
      }
   
    }
   // while(running) ~ 60 Hz
   //    Handle input. Handle timer callbacks.
   // 
   //    draw().   draw everything
}

void Game::update(){


}

void Game::draw(){

}
