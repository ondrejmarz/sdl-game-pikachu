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

class game_model;

class i_move: public object {
    
public:
    
    i_move( game_model * model );
    i_move( game_model * model, double expire_sec, double cooldown_sec );
    
    virtual void start( void );
    virtual void do_effect( void ) = 0;
    virtual void end_effect( void ) = 0;
    
    virtual bool is_on_cd( void ) const;
    virtual bool is_expired( void ) const;
    
    virtual bool is_activated( void ) const;
    
protected:
    
    game_model * model;
    
    bool deactivated;
    bool activated;
    
    timer expire;
    timer cooldown;
};


class character: public object {
    
public:
    character( game_model * model );
    
    bool want_move();
    void step( int dir, double distance );
    void back( double distance );
    bool is_still() const;
    bool is_attacking() const;
    bool is_move_on_cd( int num ) const;
    
    void use_move( int move_num );
    void do_moves( void );
    void start_charging( double sec);
    
    int  get_dir( void ) const;
    int  get_facing( void );
    int  get_moves_number( void );
    double get_speed( void ) const;
    std::vector< i_move * > & get_moves() const;
    
    void set_dir( int dir );
    void add_speed( double add );
    
private:
    double speed;
    
    timer standing_still;
    timer charging_attack;
    
    std::vector< i_move * > moves;
    
    int last_step;
    int direction;
};

#endif /* objects_h */
