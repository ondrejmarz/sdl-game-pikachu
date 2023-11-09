//
//  impl_2D_field_map.cpp
//  sdl-game-pikachu
//
//  Created by Ondřej März on 07.11.2023.
//

#include <string>
#include <fstream>
#include <iostream>

#include "impl_2D_field_map.hpp"

impl_2D_field::impl_2D_field( void ) { }

impl_2D_field::~impl_2D_field( void ) {
    
    for (int i = 0; i < rows; i++) {
        delete[] map[i];
    }
    delete[] map;
}

bool impl_2D_field::load( void ) {
    
    std::string file_name = "/Users/ondrejmars/Desktop/pro_grams/game/assets/2D_field_map.txt";
    std::ifstream file_stream(file_name);
    
    if (!file_stream.is_open()) {
        
        std::cerr << "Map could not be loaded from file " << file_name << "." << std::endl;
        return false;
    }

    file_stream >> rows >> cols;
    
    map = new char * [rows];
    
    for (int i = 0; i < rows; i++) {
        map[i] = new char[cols];
    }
    
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            
            file_stream >> map[r][c];
        }
    }
    
    file_stream.close();

    return true;
}

bool impl_2D_field::can_walk_here( double x, double y ) const {
    //std::cout << "at: [" << y*rows << "," << x*cols << "]=" << map[(int)(y * (rows))][(int)(x * (cols))] << std::endl;
    return map[(int)(y * (rows))][(int)(x * (cols))] == 'O';
}

