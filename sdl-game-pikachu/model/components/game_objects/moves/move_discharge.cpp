//
//  move_discharge.cpp
//  sdl-game-pikachu
//
//  Created by Ondřej März on 09.11.2023.
//

#include "move_discharge.hpp"
#include "game_model.h"

move_discharge::move_discharge( game_model * model ): i_move(model, 1, 1) { }

void move_discharge::do_effect() {
    
    model -> char_charge(2);
    
    // for all enemies deal damage
}

void move_discharge::end_effect() {
    
}
