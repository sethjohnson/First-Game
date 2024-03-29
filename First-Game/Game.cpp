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
    init_game();
}


void Game::init_video()
{
    App.SetFramerateLimit(FRAME_LIMIT);
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
    
    fps_string.SetColor(sf::Color(255, 255, 255));
    fps_string.SetPosition(5, 5);
    fps_string.SetSize(20.f);


    Interface* i = new Interface;
    interfaces.clear();
    interfaces.push_back(i);
    Button* b = new Button;
    b->setCenter(400, 300-20);
    b->setDimensions(400, 50);
    b->setText("Return to Game");
    
    Background* bg = new Background;
    bg->setColor(sf::Color(126,126,126,126));
    
    
    interfaces[0]->entities.push_back(bg);
    interfaces[0]->entities.push_back(b);

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
            handle_input();
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

   
    std::ostringstream oss;
    oss << "fps: " << 1./App.GetFrameTime();
    oss << "\n";
    oss << App.GetWidth() << " x " << App.GetHeight();
    fps_string.SetText(oss.str());
    
    App.SetView(View);
    
    App.Clear();
    App.Draw(background_sprite);
    
    App.SetView(App.GetDefaultView());
    App.Draw(fps_string);

    for (vector<Interface*>::iterator it = interfaces.begin(); it!=interfaces.end(); ++it) {
        (*it)->draw(App);            
    }

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
                View.SetHalfSize(Event.Size.Width/2, Event.Size.Height/2); //Resize the display view
                App.GetDefaultView().SetFromRect(sf::Rect<float>(0, 0, Event.Size.Width, Event.Size.Height)); // Resize the actual window view (Used for HUD for now)
                break;  

            case sf::Event::KeyPressed:
                if (Event.Key.Code == sf::Key::F)
                {
                    if (fullscreen) 
                    {
                        App.Create(sf::VideoMode(screen_size.x, screen_size.y),title);
                        
                        
                        View.SetHalfSize(App.GetWidth()/2, App.GetHeight()/2);
                        View.SetCenter(center);
                        
                        fullscreen = false;
                    }
                    else
                    {
                        App.Create(sf::VideoMode::GetMode(0), title, sf::Style::Fullscreen);
                        View.SetCenter(center);
                        View.SetHalfSize(App.GetWidth()/2, App.GetHeight()/2);
                        fullscreen = true;
                        
                    }
                    
                }
				else if(Event.Key.Code == sf::Key::Escape)
				{
					App.Close();
				}
            default:
                break;
        }
    }

}


void Game::handle_input()
{
    const sf::Input& Input = App.GetInput();
    if (Input.IsMouseButtonDown(sf::Mouse::Left) ) {
        // Get mouse position
        sf::Vector2f MousePos = App.ConvertCoords(Input.GetMouseX(), Input.GetMouseY(),&App.GetDefaultView());
        if (App.GetInput().IsMouseButtonDown(sf::Mouse::Left)) 
        {
            Entity* clicked = NULL;
            for (vector<Interface*>::iterator it = interfaces.begin(); it!=interfaces.end(); ++it) {
                clicked = (*it)->object_with_point(MousePos);            
            }
            std::cout << MousePos.x << ", " << MousePos.y << ": " << clicked  << "\n";
            
        }
        
        cursor_pos.x = MousePos.x;
        cursor_pos.y = MousePos.y;
    }
        

    
    

}
