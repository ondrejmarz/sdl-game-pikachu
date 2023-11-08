//
//  impl_command.hpp
//  sdl-game-pikachu
//
//  Created by Ondřej März on 08.11.2023.
//

#ifndef impl_command_hpp
#define impl_command_hpp

#include "i_command.h"

class move_char_u_command: public i_command {
    
public:
    move_char_u_command(game_model * model): i_command(model) { }
    
    void execute() const override;
};

class move_char_d_command: public i_command {
    
public:
    move_char_d_command(game_model * model): i_command(model) { }
    
    void execute() const override;
};

class move_char_r_command: public i_command {
    
public:
    move_char_r_command(game_model * model): i_command(model) { }
    
    void execute() const override;
};

class move_char_l_command: public i_command {
    
public:
    move_char_l_command(game_model * model): i_command(model) { }
    
    void execute() const override;
};

class move_char_ur_command: public i_command {
    
public:
    move_char_ur_command(game_model * model): i_command(model) { }
    
    void execute() const override;
};

class move_char_ul_command: public i_command {
    
public:
    move_char_ul_command(game_model * model): i_command(model) { }
    
    void execute() const override;
};

class move_char_dr_command: public i_command {
    
public:
    move_char_dr_command(game_model * model): i_command(model) { }
    
    void execute() const override;
};

class move_char_dl_command: public i_command {
    
public:
    move_char_dl_command(game_model * model): i_command(model) { }
    
    void execute() const override;
};

#endif /* impl_command_hpp */
