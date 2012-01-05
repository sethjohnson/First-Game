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
#include <string>

using std::string;

class Game 
{
public:
    Game();
    int game_loop();
    
private: // Methods
    void init_video();
    void init_game();
    void update_game();
    void render_game();
    void handle_input();
    void handle_events();
    long getTickCount();

private: // Variables
    sf::Window App;
    bool fullscreen;

    sf::Vector2i screen_size;
private: // Constants
    const int TICKS_PER_SECOND;
    const int SKIP_TICKS;
    const int MAX_FRAMESKIP;
    const int FRAME_LIMIT;
    const string title;
    
};


#endif
