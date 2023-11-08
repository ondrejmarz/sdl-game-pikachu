//
//  character.cpp
//  sdl-game-pikachu
//
//  Created by Ondřej März on 05.11.2023.
//

#include "objects.h"

character::character(): object( position(100, 100), area(26, 28) ) { }

bool character::want_move() { return direction != 0; }
bool character::is_still() const { return standing_still.elapsed(5); }
bool character::is_attacking() const { return !charging_attack.elapsed(2); }

void character::do_attack( int attack ) { charging_attack.reset(); }
void character::set_dir( int dir ) { direction = dir; }

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
            pos.add_y(-distance);
            break;
            
        case 3:
            pos.add_x(-distance);
            break;
            
        case 5:
            pos.add_x( distance);
            break;
            
        case 7:
            pos.add_y( distance);
            break;
            
        default:
            break;
            
    }
    
    standing_still.reset();
}

void character::back( double distance ) {
    
    switch (last_step+4) {
        
        case 1:
            pos.add_y( distance);
            break;
            
        case 3:
            pos.add_x( distance);
            break;
            
        case 5:
            pos.add_x(-distance);
            break;
            
        case 7:
            pos.add_y(-distance);
            break;
            
        default:
            break;
            
    }
}
