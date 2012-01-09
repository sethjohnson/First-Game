//
//  Button.cpp
//  GitTest
//
//  Created by Seth Johnson on 1/5/12.
//  Copyright (c) 2012 ESH Studio. All rights reserved.
//

#include "Button.h"


void Button::draw(sf::RenderWindow &w)
{
    Rectangle::draw(w);
    
    sf::String string;
    string.SetColor(sf::Color::White);
    string.SetText(text);
    string.SetSize(dimensions.y*0.75);
    string.SetCenter(string.GetRect().GetWidth()/2, string.GetRect().GetHeight()/2);
    string.SetPosition(Rectangle::center.x, Rectangle::center.y-string.GetSize()/10);
    w.Draw(string);
    
}

