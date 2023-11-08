//
//  impl_command.cpp
//  sdl-game-pikachu
//
//  Created by Ondřej März on 08.11.2023.
//

#include "impl_command.hpp"
#include "game_model.h"

// -4   -3   -2
//
// -1    0    1
//
//  2    3    4

void move_char_u_command::execute() const {
    model -> move_character(-3, STEP);
    model -> set_char_state(-3);
}

void move_char_d_command::execute() const {
    model -> move_character(3, STEP);
    model -> set_char_state(3);
}

void move_char_l_command::execute() const {
    model -> move_character(-1, STEP);
    model -> set_char_state(-1);
}

void move_char_r_command::execute() const {
    model -> move_character(1, STEP);
    model -> set_char_state(1);
}

void move_char_ul_command::execute() const {
    model -> move_character(-3, DIAGONAL_STEP);
    model -> move_character(-1, DIAGONAL_STEP);
    model -> set_char_state(-4);
}

void move_char_ur_command::execute() const {
    model -> move_character(-3, DIAGONAL_STEP);
    model -> move_character( 1, DIAGONAL_STEP);
    model -> set_char_state(-2);
}

void move_char_dl_command::execute() const {
    model -> move_character( 3, DIAGONAL_STEP);
    model -> move_character(-1, DIAGONAL_STEP);
    model -> set_char_state( 2);
}

void move_char_dr_command::execute() const {
    model -> move_character( 3, DIAGONAL_STEP);
    model -> move_character( 1, DIAGONAL_STEP);
    model -> set_char_state( 4);
}
