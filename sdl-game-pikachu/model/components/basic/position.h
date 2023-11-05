//
//  position.h
//  sdl-game-pikachu
//
//  Created by Ondřej März on 05.11.2023.
//

#ifndef position_h
#define position_h

class position {
    
public:
                    position            ( void )                : x(0), y(0) { }
                    position            ( double x, double y )  : x(x), y(y) { }
    
    double          get_x               ( void ) const          { return x; }
    double          get_y               ( void ) const          { return y; }
    
    void            set_x               ( double x )            { this -> x = x; }
    void            set_y               ( double y )            { this -> y = y; }
    void            set_pos             ( position pos )        { set_x( pos.get_x() ); set_y( pos.get_y()); }
    
    void add_x ( double value ) {
        
        x += value;
    }
    
    void add_y ( double value ) {
        
        y += value;
    }
    
    void add ( position pos ) {
        
        set_x( get_x() + pos.get_x() );
        set_y( get_y() + pos.get_y() );
    }
    
private:
    double x;
    double y;
};

#endif /* position_h */
