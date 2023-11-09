//
//  move_quick_attack.hpp
//  sdl-game-pikachu
//
//  Created by Ondřej März on 09.11.2023.
//

#ifndef move_quick_attack_hpp
#define move_quick_attack_hpp

#include "objects.h"

class move_quick_attack: public i_move {
    
public:
    
    move_quick_attack( game_model * model );
    
    void do_effect();
    void end_effect();
    
private:
    
    double speed_boost = 0.6;
};

#endif /* move_quick_attack_hpp */
