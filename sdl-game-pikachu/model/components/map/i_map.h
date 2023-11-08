//
//  i_map.h
//  sdl-game-pikachu
//
//  Created by Ondřej März on 07.11.2023.
//

#ifndef i_map_h
#define i_map_h

#include "position.h"

class i_map {
    
public:
    i_map(): rows(0), cols(0) { }
    
    virtual bool load() = 0;
    virtual bool can_walk_here( double x, double y ) const = 0;
    
protected:
    
    int rows;
    int cols;
};

#endif /* i_map_h */
