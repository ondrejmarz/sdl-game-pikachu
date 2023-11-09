//
//  move_discharge.hpp
//  sdl-game-pikachu
//
//  Created by Ondřej März on 09.11.2023.
//

#ifndef move_discharge_hpp
#define move_discharge_hpp

#include "objects.h"

class move_discharge: public i_move {
    
public:
    
    move_discharge( game_model * model );
    
    void do_effect();
    void end_effect();
    
private:
    
    double power = 1;
};


#endif /* move_discharge_hpp */
