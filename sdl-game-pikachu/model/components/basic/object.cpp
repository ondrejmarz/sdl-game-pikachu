//
//  object.cpp
//  sdl-game-pikachu
//
//  Created by Ondřej März on 05.11.2023.
//

#include <iostream>

#include "object.h"

object::object( void ) { }
object::object( const position & pos): pos(pos) { }
object::object( const position & pos, const area & are): pos(pos), are(are) { }

const position & object::get_position( void ) const { return pos; }
const area     & object::get_area    ( void ) const { return are; }

double object::get_other_x( void ) const { return pos.get_x() + are.get_w(); }
double object::get_other_y( void ) const { return pos.get_y() + are.get_h(); }

void object::set_position( const position & pos ) {
    
    this->pos = pos;
}

void object::set_area( const area & are ) {
    
    this->are = are;
}

bool object::intersects( const object & other ) const {
    
    position lt_1 = get_position();
    position rd_1 = position( get_other_x(), get_other_y() );
    position lt_2 = other.get_position();
    position rd_2 = position( other.get_other_x(), other.get_other_y() );
    
    // If one rectangle is on left side of other
    if (lt_1.get_x() > rd_2.get_x() || lt_2.get_x() > rd_1.get_x())
        return false;
     
    // If one rectangle is above other
    if (lt_1.get_y() > rd_2.get_y() || lt_2.get_y() > rd_1.get_y())
        return false;
    
    return true;
}
