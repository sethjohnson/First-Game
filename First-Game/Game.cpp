//
//  Game.cpp
//  First-Game
//
//  Created by Seth Johnson on 1/4/12.
//  Copyright (c) 2012 ESH Studio. All rights reserved.
//

#include "Game.h"
#include <iostream>

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
    init_game();
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

void Game::init_game()
{
    background_image.LoadFromFile("background.JPG");
    background_sprite.SetImage(background_image);
    View.SetCenter(center);
    View.SetHalfSize(screen_size.x/2, screen_size.y/2);
    background_sprite.SetPosition(center.x-background_sprite.GetSize().x/2, center.y-background_sprite.GetSize().y/2);

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
        
        handle_events();
        
        while (getTickCount() > next_game_tick && loops < MAX_FRAMESKIP)
        {
            //handle_input();
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
    App.SetView(View);
    
    App.Clear();
    App.Draw(background_sprite);
    App.Display();
}

void Game::handle_events()
{
    sf::Event Event;
    while (App.GetEvent(Event)) 
    {
        switch (Event.Type) 
        {
            case sf::Event::Closed:
                App.Close();
                break;
            case sf::Event::Resized: 
                View.SetHalfSize(Event.Size.Width/2, Event.Size.Height/2);
                
                break;  

            case sf::Event::KeyPressed:
                if (Event.Key.Code == sf::Key::F) {
                    if (fullscreen) 
                    {
                        App.Create(sf::VideoMode(screen_size.x, screen_size.y),title);
                        
                        
                        View.SetHalfSize(App.GetWidth()/2, App.GetHeight()/2);
                        View.SetCenter(center);
                        
                        fullscreen = false;
                    }
                    else
                    {
                        View.SetCenter(center);
                        View.SetHalfSize(1024, 576);
                        App.Create(sf::VideoMode::GetMode(0), title, sf::Style::Fullscreen);
                        fullscreen = true;
                        
                    }
                    
                }
            default:
                break;
        }
    }

}