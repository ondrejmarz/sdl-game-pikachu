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
    void step( int dir, double distance );
    void back( double distance );
    bool is_still() const;
    bool is_attacking() const;
    
    int  get_dir( void ) const;
    int  get_facing( void );
    int  get_moves_number( void );
    
    void do_attack( int attack );
    void set_dir( int dir );
    
private:
    timer standing_still;
    timer charging_attack;
    
    //std::vector< attack > attacks;
    
    int last_step;
    int direction;
};

#endif /* objects_h */
