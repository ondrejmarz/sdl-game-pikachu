//
//  character.cpp
//  sdl-game-pikachu
//
//  Created by Ondřej März on 05.11.2023.
//

#include "objects.h"

character::character(): object( position(100, 100), area(26, 28) ) { }

bool character::want_move() { return direction != 0; }
bool character::is_still() { return standing_still.elapsed(5); }

int  character::get_dir( void ) const { return direction; }
int  character::get_facing( void ) { return last_step + 4; }
int  character::get_moves_number( void ) { return (int)attacks.size(); }

void character::set_dir( int dir ) { direction = dir; }

void character::step( void ) {

    if (direction == 0) return;
    
    last_step = direction;
    
    switch (direction+4) {
        case 0:
            pos.add_x(-DIAGONAL_STEP);
            pos.add_y(-DIAGONAL_STEP);
            break;
            
        case 1:
            pos.add_y(-STEP);
            break;
            
        case 2:
            pos.add_x(DIAGONAL_STEP);
            pos.add_y(-DIAGONAL_STEP);
            break;
            
        case 3:
            pos.add_x(-STEP);
            break;
            
        case 5:
            pos.add_x(STEP);
            break;
            
        case 6:
            pos.add_x(-DIAGONAL_STEP);
            pos.add_y(DIAGONAL_STEP);
            break;
            
        case 7:
            pos.add_y(STEP);
            break;
            
        case 8:
            pos.add_x(DIAGONAL_STEP);
            pos.add_y(DIAGONAL_STEP);
            break;
            
        default:
            break;
            
    }
    
    standing_still.reset();
}

void character::back( void ) {
    
    switch (last_step+4) {
        case 0:
            pos.add_x(DIAGONAL_STEP);
            pos.add_y(DIAGONAL_STEP);
            break;
            
        case 1:
            pos.add_y(STEP);
            break;
            
        case 2:
            pos.add_x(-DIAGONAL_STEP);
            pos.add_y(DIAGONAL_STEP);
            break;
            
        case 3:
            pos.add_x(STEP);
            break;
            
        case 5:
            pos.add_x(-STEP);
            break;
            
        case 6:
            pos.add_x(DIAGONAL_STEP);
            pos.add_y(-DIAGONAL_STEP);
            break;
            
        case 7:
            pos.add_y(-STEP);
            break;
            
        case 8:
            pos.add_x(-DIAGONAL_STEP);
            pos.add_y(-DIAGONAL_STEP);
            break;
            
        default:
            break;
            
    }
    
    standing_still.reset();
}
