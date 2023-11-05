//
//  impl_controller.cpp
//  sdl-game-pikachu
//
//  Created by Ondřej März on 05.11.2023.
//

#include "impl_controller.hpp"
#include "game_model.h"

void impl_controller::handle_input( void ) {
    
    //  0    1    2
    //
    //  3    4    5      (-4)
    //
    //  6    7    8
    
    int direction = 0;
    
    for (auto &e: key_state ) {
        
            switch (e) {
                    
                case SDLK_UP:
                    direction -= 3;
                    break;
                    
                case SDLK_DOWN:
                    direction += 3;
                    break;

                case SDLK_LEFT:
                    direction -= 1;
                    break;

                case SDLK_RIGHT:
                    direction += 1;
                    break;
                    
                case SDLK_1:
                    //model -> char_attack( 0 );
                    break;
                    
                case SDLK_2:
                    //model -> char_attack( 1 );
                    break;

                default:
                    break;
    
        }
    }
    
    model -> move_character(direction);
}

void impl_controller::key_pressed(SDL_Keysym key) {
    
    key_state.insert(key.sym);
}

void impl_controller::key_released(SDL_Keysym key) {
    
    key_state.erase(key.sym);
}
