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

impl_2D_field::impl_2D_field( void ) {
    
    rows = 50;
    cols = 50;
    
    map = new char * [rows];
    
    for (int i = 0; i < rows; i++) {
        map[i] = new char[cols];
    }
    
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            
            if (r == 0 || c == 0 || r == rows-3 || c == cols-3)
                map[r][c] = 'X';
            else
                map[r][c] = 'O';
        }
    }
}

impl_2D_field::~impl_2D_field( void ) {
    
    for (int i = 0; i < rows; i++) {
        delete[] map[i];
    }
    delete[] map;
}

bool impl_2D_field::load( void ) {
    
    std::string file_name = "./sdl-game-pikachu/model/map/2D_field_map.txt";
    std::ifstream file_stream(file_name);
    
    if (!file_stream.is_open()) {
        
        std::cerr << "Map could not be loaded from file " << file_name << "." << std::endl;
        return false;
    }

    file_stream >> rows >> cols;
    
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            
            file_stream >> map[r][c];
        }
    }
    
    file_stream.close();

    return true;
}

bool impl_2D_field::can_walk_here(const position & pos) {
    
    return map[(int)(pos.get_x() * (cols-1))][(int)(pos.get_y() * (rows-1))] == 'O'; 
}

