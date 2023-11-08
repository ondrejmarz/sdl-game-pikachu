//
//  i_command.h
//  sdl-game-pikachu
//
//  Created by Ondřej März on 08.11.2023.
//

#ifndef i_command_h
#define i_command_h

class game_model;

class i_command {
    
public:
    
    i_command( game_model * model ): model(model) { }
    
    virtual void execute() const = 0;
    
protected:
    
    game_model * model;
};


#endif /* i_command_h */
