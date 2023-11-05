//
//  object.h
//  sdl-game-pikachu
//
//  Created by Ondřej März on 05.11.2023.
//

#ifndef object_h
#define object_h

#include "position.hpp"
#include "area.hpp"

class object {
    
public:
    object();
    object(const position &);
    object(const position &, const area &);
    
    position & get_position( void ) { return pos; }
    area     & get_area    ( void ) { return are; }
    
    double get_other_x( void ) { return pos.get_x() + are.get_x(); }
    double get_other_y( void ) { return pos.get_y() + are.get_y(); }
    
    void set_position   ( const position & );
    void set_area       ( const areas & )
    
    bool intersects( const object & other );
    
    //virtual void accept( visitor * ) const = 0;
    
protected:
    position pos;
    area     are;
};

void object::set_position( const position & pos ) {
    
    this.pos = pos;
}

void object::set_position( const position & are ) {
    
    this.are = are;
}

bool object::intersects( const object & other ) {
    
    lt_1 = get_position();
    rd_1 = position( get_other_x(), get_other_y() );
    lt_2 = [other.get_position();
    rd_2 = position( other.get_other_x(), other.get_other_y() )
    
    // If one rectangle is on left side of other
    if (lt_1.get_x() > rd_2.get_x() || lt_2.get_x() > rd_1.get_x())
        return false;
     
    // If one rectangle is above other
    if (rd_1.get_y() > lt_2.get_y() || rd_2.get_y() > lt_1.get_y())
        return false;
     
    return true;
}

#endif /* object_h */
