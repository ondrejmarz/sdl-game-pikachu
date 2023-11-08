//
//  game_model.h
//  sdl-game-pikachu
//
//  Created by Ondřej März on 05.11.2023.
//

#ifndef game_model_h
#define game_model_h

#include "objects.h"
#include "i_map.h"
#include "i_command.h"

#include <queue>
#include <vector>

class game_model {
    
public:
    
                        game_model          ( void );
    
    /**
     * Method to add command for executions
     *
     * \param command to be executed
     *
     * \since This function is available since 1.0
     *
     * \sa exe\_commands()
     *
     */
    void                add_command         ( i_command * command);
    void                exe_commands        ( void );
    
    void                update              ( void );
    
    /**
     * Character oriented methods
     */
    void    char_stop               ( void );
    int     char_pos_x              ( void );
    int     char_pos_y              ( void );
    int     char_moves_size         ( void );
    int     get_char_state          ( void );
    void    set_char_state          (int dir);
    //int     char_move_in_use        ( void );
    bool    char_standing_still     ( void );
    bool    is_char_attacking       ( void );
    //void    char_attack             (int num);
    
    bool    is_outside_screen       ( const position & pos ) const;
    bool    allowed_on_map          ( const position & pos ) const;
    void    move_character          ( int direction, double distance);
    
    void    move_expiration         ( void );
    void    moves_hit_angry         ( void );
    void    delete_dead             ( void );
    
    const std::vector < character > & get_enemies ( void );
    
private:
    
    std::queue  < i_command * > commands = {};
    
    std::vector < character > enemies;
    std::vector < attack > attacks;
    
    i_map * map;
    character pika;
};

#endif /* game_model_h */
