//
//  move_quick_attack.cpp
//  sdl-game-pikachu
//
//  Created by Ondřej März on 09.11.2023.
//

#include "move_quick_attack.hpp"
#include "game_model.h"

move_quick_attack::move_quick_attack( game_model * model ): i_move(model, 5, 10) { }

void move_quick_attack::do_effect() {
    
    model -> add_char_speed_modifier(speed_boost);
    activated = true;
}

void move_quick_attack::end_effect() {
    
    model -> add_char_speed_modifier(-speed_boost);
    activated = false;
}
