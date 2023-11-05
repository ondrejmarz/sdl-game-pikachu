//
//  i_view.h
//  sdl-game-pikachu
//
//  Created by Ondřej März on 05.11.2023.
//

#ifndef i_view_h
#define i_view_h

class i_view {
    
public:
    i_view(): update_cnt(0) { }
    
    virtual bool init() = 0;
    virtual void update() = 0;
    
protected:
    
    int update_cnt;
};


#endif /* i_view_h */
