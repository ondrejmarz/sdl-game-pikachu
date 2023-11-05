//
//  area.h
//  sdl-game-pikachu
//
//  Created by Ondřej März on 05.11.2023.
//

#ifndef area_h
#define area_h

class area {
    
public:
                    area                ( void )                : width(0), height(0) { }
                    area                ( int w, int h )        : width(w), height(h) { }
    
    int             get_w               ( void ) const          { return width;  }
    int             get_h               ( void ) const          { return height; }
    
    void            set_w               ( int w )               { width     = w; }
    void            set_h               ( int h )               { height    = h; }
    
private:
    
    int width;
    int height;
};

#endif /* area_h */
