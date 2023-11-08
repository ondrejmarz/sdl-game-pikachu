//
//  impl_controller.cpp
//  sdl-game-pikachu
//
//  Created by Ondřej März on 05.11.2023.
//

#include "impl_controller.hpp"
#include "game_model.h"
#include "impl_command.hpp"

void impl_controller::key_pressed(SDL_Keysym key) {
    
    key_state.insert(key.sym);
}

void impl_controller::key_released(SDL_Keysym key) {
    
    key_state.erase(key.sym);
}

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
                    model -> char_attack( 0 );
                    break;
                    
                case SDLK_2:
                    model -> char_attack( 1 );
                    break;

                default:
                    break;
    
        }
    }
    
    if (direction == 0) return;
    
    switch (direction+4) {
        
        case 0:
            model->add_command( new move_char_ul_command(model) );
            break;
            
        case 1:
            model->add_command( new move_char_u_command(model) );
            break;
            
        case 2:
            model->add_command( new move_char_ur_command(model) );
            break;
            
        case 3:
            model->add_command( new move_char_l_command(model) );
            break;
            
        case 5:
            model->add_command( new move_char_r_command(model) );
            break;
            
        case 6:
            model->add_command( new move_char_dl_command(model) );
            break;
            
        case 7:
            model->add_command( new move_char_d_command(model) );
            break;
            
        case 8:
            model->add_command( new move_char_dr_command(model) );
            break;
            
        default:
            break;
            
    }
}
