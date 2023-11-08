//
//  impl_2D_field_map.hpp
//  sdl-game-pikachu
//
//  Created by Ondřej März on 07.11.2023.
//

#ifndef impl_2D_field_map_hpp
#define impl_2D_field_map_hpp

#include "i_map.h"

class impl_2D_field: public i_map {
    
public:
    impl_2D_field();
    ~impl_2D_field();
    
    bool load( void );
    bool can_walk_here( int x, int y ) const;
    
protected:
    
    char ** map;
};

#endif /* impl_2D_field_map_hpp */
