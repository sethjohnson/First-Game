//
//  Game.h
//  First-Game
//
//  Created by Seth Johnson on 1/4/12.
//  Copyright (c) 2012 ESH Studio. All rights reserved.
//

#ifndef First_Game_Game_h
#define First_Game_Game_h

#include <SFML/Graphics.hpp>

class Game 
{
public:
    Game();
    int game_loop();
    
private: // Methods
    void update_game();
    void render_game();
    void handle_input();
    void handle_events();
    
private: // Varaibles
    sf::Window App;
private: // Constants
    const int TICKS_PER_SECOND;
    const int SKIP_TICKS;
    const int MAX_FRAMESKIP;

    long  getTickCount();

    
};


#endif
