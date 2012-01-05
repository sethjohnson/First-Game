//
//  Game.cpp
//  First-Game
//
//  Created by Seth Johnson on 1/4/12.
//  Copyright (c) 2012 ESH Studio. All rights reserved.
//

#include "Game.h"


Game::Game()  : title("Untitled"),
                FRAME_LIMIT(120),
                TICKS_PER_SECOND(25),
                SKIP_TICKS(1000/TICKS_PER_SECOND),
                MAX_FRAMESKIP(5),
                fullscreen(false)
{
    screen_size.x = 800;
    screen_size.y = 600;
    
    init_video();
}


void Game::init_video()
{
    if (fullscreen) 
    {
        App.Create(sf::VideoMode::GetMode(0), title, sf::Style::Fullscreen);
    }
    else
    {
        App.Create(sf::VideoMode(screen_size.x, screen_size.y),title);
    }
}

// game_loop()
// This should be a function called once in main, and should 
// be in operation for the entire course of the game.

int Game::game_loop()
{
    
    long next_game_tick = getTickCount();
    int loops;
    
    while (App.IsOpened()) 
    {
        loops = 0;
        while (getTickCount() > next_game_tick && loops < MAX_FRAMESKIP)
        {
            handle_events();
            
            update_game();
            next_game_tick += SKIP_TICKS;
            loops++;
        }
        
        render_game();
    }
    return 0;
}


// getTickCount()
// 

long Game::getTickCount()
{
    static sf::Clock clock;
    return clock.GetElapsedTime()*1000;
}

// update_game()

void Game::update_game()
{
    
}

void Game::render_game()
{
    
}

void Game::handle_events()
{
    
}