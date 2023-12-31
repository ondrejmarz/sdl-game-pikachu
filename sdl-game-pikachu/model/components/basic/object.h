//
//  object.h
//  sdl-game-pikachu
//
//  Created by Ondřej März on 05.11.2023.
//

#ifndef object_h
#define object_h

#include "position.h"
#include "area.h"

class object {
    
public:
    object();
    object(const position &);
    object(const position &, const area &);
    
    const position & get_position( void ) const;
    const area     & get_area    ( void ) const;
    
    double get_other_x( void ) const;
    double get_other_y( void ) const;
    
    void set_position   ( const position & );
    void set_area       ( const area & );
    
    bool intersects( const object & other ) const;
    //virtual void accept( visitor * ) const = 0;
    
protected:
    position pos;
    area     are;
};

#endif /* object_h */
