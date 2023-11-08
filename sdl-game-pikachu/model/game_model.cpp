//
//  game_model.cpp
//  sdl-game-pikachu
//
//  Created by Ondřej März on 05.11.2023.
//

#include "impl_2D_field_map.hpp"
#include "game_model.h"
#include "config.h"

//static const pikachu p(electric, 100, 120, 100, position(640, 60), area(26, 28));

game_model::game_model() {
    
    map = new impl_2D_field();
    map -> load();
    //float RESIZE_X = (float)SCREEN_WIDTH / (float)BCKG_WIDTH;
    //float RESIZE_Y = (float)SCREEN_HEIGHT / (float)BCKG_HEIGHT;
}

int game_model::char_pos_x() { return (int) pika.get_position().get_x(); }
int game_model::char_pos_y() { return (int) pika.get_position().get_y(); }

int game_model::char_moves_size() { return pika.get_moves_number(); }

int     game_model::get_char_state      ( void )        { if (char_standing_still()) return 4; return pika.get_facing(); }
void    game_model::set_char_state      ( int dir)      { pika.set_dir(dir); }

//int game_model::char_move_in_use() { return pika.get_move_in_use(); }


void game_model::add_command( i_command * command ) {
    
    commands.push( command );
}

void game_model::exe_commands( void ) {
    
    while (!commands.empty()) {
     
        commands.front() -> execute();
        commands.pop();
    }
}

void game_model::update( void ) {
    
    exe_commands();
    
    //if (pika.can_move() && pika.want_move()) {
    
    //}
    
    //move_expiration();
    //moves_hit_angry();
    //delete_dead();
}

bool common_intersects( object & obj1, object & obj2 ) {
    
    if ( obj1.get_other_y() < obj2.get_position().get_y() || obj2.get_other_y() < obj1.get_position().get_y() ) return false;
    if ( obj1.get_other_x() < obj2.get_position().get_x() || obj2.get_other_x() < obj1.get_position().get_x() ) return false;
    
    return true;
}

/*

void game_model::moves_hit_angry( void ) {
    
    for (auto &e: enemies) {
        for (auto const &a: attacks) {
            
            if (common_intersects(e, a))
                e.recive_damage( pika.get_atck(), pika.has_atck_stab(a), a );
        }
    }
}

void game_model::delete_dead( void ) {
    
    std::erase_if( enemies, [](const character &e) { return e.is_dead();    } );
}

void game_model::move_expiration( void ) {
    
    std::erase_if( attacks, [](const attack  &m) { return m.did_expire(); } );
} */

bool game_model::char_standing_still( void ) const {
    
    return pika.is_still();
}

bool game_model::char_attacking( void ) const {
    
    return pika.is_attacking();
}

void game_model::char_attack(int num) {
    
    pika.do_attack(num);
}

// -4   -3   -2
//
// -1    0    1
//
//  2    3    4

bool game_model::is_outside_screen( const position & pos ) const {
    
    return (pos.get_x() <= 0 || pos.get_y() <= 0 || pos.get_x() >= SCREEN_WIDTH || pos.get_y() >= SCREEN_HEIGHT);
}

bool game_model::allowed_on_map( const position & pos ) const {
    
    return map -> can_walk_here( pos.get_x()/SCREEN_WIDTH, pos.get_y()/SCREEN_HEIGHT);
}

void game_model::move_character(int direction, double distance) {
    
    if (pika.is_attacking()) return;
    
    pika.step(direction, distance);
    
    if (is_outside_screen(    pika.get_position() )) pika.back(distance);
    else if (!allowed_on_map( pika.get_position() )) pika.back(distance);
}

const std::vector < character > & game_model::get_enemies( void ) {
    return enemies;
}
