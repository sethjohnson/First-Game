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
    w.Draw(sf::Shape::Rectangle(center.x-dimensions.x/2, center.y-dimensions.y/2, center.x+dimensions.x/2, center.y+dimensions.y/2, sf::Color::Black));
    
    sf::String string;
    string.SetText(text);
    string.SetSize(dimensions.y*0.75);
    string.SetCenter(string.GetRect().GetWidth()/2, string.GetRect().GetHeight()/2);
    string.SetPosition(center.x, center.y-string.GetSize()/10);
    w.Draw(string);
    
}

Entity* Button::contains_point(sf::Vector2f point)
{
    if ((point.x>center.x-dimensions.x/2) && (point.x < center.x+dimensions.x/2)
        &&
        point.y>center.y-dimensions.y/2 && point.y < center.y+dimensions.y/2) {
        return this;
    }
    else
        return NULL;
}