//
//  i_move.cpp
//  sdl-game-pikachu
//
//  Created by Ondřej März on 05.11.2023.
//

#include "objects.h"

i_move::i_move( game_model * model ): model(model), expire(0), cooldown(0), activated(false) { }

i_move::i_move( game_model * model, double expire_sec, double cooldown_sec ): model(model), expire(expire_sec), cooldown(cooldown_sec), activated(false) { }

void i_move::start( void ) {
    expire.reset();
    cooldown.reset();
}

bool i_move::is_on_cd( void ) const {
    
    return !cooldown.elapsed();
}

bool i_move::is_expired( void ) const {
    
    return expire.elapsed();
}

bool i_move::is_activated( void ) const { return activated; }
