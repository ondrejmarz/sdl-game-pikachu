//
//  character.cpp
//  sdl-game-pikachu
//
//  Created by Ondřej März on 05.11.2023.
//

#include <iostream>

#include "objects.h"
#include "move_quick_attack.hpp"
#include "move_discharge.hpp"

character::character( game_model * model ): object( position(100, 100), area(26, 28) ), speed(1) {
    
    moves.emplace_back( new move_quick_attack( model ) );
    moves.emplace_back( new move_discharge( model ));
}

bool character::want_move() { return direction != 0; }
bool character::is_still() const { return standing_still.elapsed(5); }
bool character::is_attacking() const { return !charging_attack.elapsed(); }
bool character::is_move_on_cd( int num ) const { return moves.at(num) -> is_on_cd(); }

void character::start_charging( double sec ) {
    
    charging_attack.set(sec);
    charging_attack.reset();
}

void character::use_move( int move_num ) {
    
    if (!is_move_on_cd(move_num)) {
        std::cout << "Not on cooldown." << std::endl;
        moves.at(move_num) -> start();
    }
}

void character::do_moves( void ) {
    
    for (auto const &m: moves) {
        
        if ( m -> is_activated() &&  m -> is_expired()) m -> end_effect();
        if (!m -> is_activated() && !m -> is_expired()) m -> do_effect();
    }
}


void character::set_dir( int dir ) { direction = dir; }
void character::add_speed( double add ) { speed += add; }

double character::get_speed( void ) const { return speed; }
int  character::get_dir( void ) const { return direction; }
int  character::get_facing( void ) { return direction + 4; }
int  character::get_moves_number( void ) { return 2; }

// -4   -3   -2
//
// -1    0    1
//
//  2    3    4

void character::step( int dir, double distance ) {

    last_step = dir;
    
    switch (dir+4) {
        
        case 1:
            pos.add_y(-distance * speed);
            break;
            
        case 3:
            pos.add_x(-distance * speed);
            break;
            
        case 5:
            pos.add_x( distance * speed);
            break;
            
        case 7:
            pos.add_y( distance * speed);
            break;
            
        default:
            break;
            
    }
    
    standing_still.reset();
}

void character::back( double distance ) {
    
    switch (last_step+4) {
        
        case 1:
            pos.add_y( distance * speed);
            break;
            
        case 3:
            pos.add_x( distance * speed);
            break;
            
        case 5:
            pos.add_x(-distance * speed);
            break;
            
        case 7:
            pos.add_y(-distance * speed);
            break;
            
        default:
            break;
            
    }
}
