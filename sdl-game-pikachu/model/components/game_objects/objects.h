//
//  objects.h
//  sdl-game-pikachu
//
//  Created by Ondřej März on 05.11.2023.
//

#ifndef objects_h
#define objects_h

#include <vector>

#include "object.h"
#include "config.h"
#include "timer.h"

class attack: public object {
    
};


class character: public object {
    
public:
    character();
    
    bool want_move();
    void step();
    bool is_still();
    
    int  get_dir( void );
    int  get_facing( void );
    int  get_moves_number( void );
    
    void set_dir( int dir );
    
private:
    timer standing_still;
    
    std::vector< attack > attacks;
    
    int last_step;
    int direction;
};

class wall: public object {
    
};
#endif /* objects_h */