//
//  impl_SDL_view.hpp
//  sdl-game-pikachu
//
//  Created by Ondřej März on 05.11.2023.
//

#ifndef impl_SDL_view_hpp
#define impl_SDL_view_hpp

#include "i_view.h"

#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <stdio.h>

class game_model;

class imp_view_SDL: public i_view {
    
public:
    imp_view_SDL( game_model * model );
    ~imp_view_SDL();
    
    bool init() override;
    void update() override;
    
    void draw_bckg();
    void draw_ui();
    void draw_char();
    
    void draw_char_move (int move_id);
    void draw_char_run();
    
private:
    
    SDL_Texture * load_texture( std::string path );
    
    game_model * model;
    
    
    SDL_Rect char_text_states[ 30 ];
    SDL_Rect move_texture_animation[6];
    
    SDL_Window      * window;
    
    SDL_Renderer * renderer;

    SDL_Texture * bckg_texture;
    SDL_Texture * char_texture;
    SDL_Texture * move_texture;
    
    // UI
    SDL_Texture *                   frame_texture;
    SDL_Texture *                   ends_frame_texture;
    std::vector<SDL_Texture *>      moves_texture;
};

#endif /* impl_SDL_view_hpp */
