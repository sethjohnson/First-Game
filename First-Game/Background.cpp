//
//  Background.cpp
//  GitTest
//
//  Created by Seth Johnson on 1/6/12.
//  Copyright (c) 2012 ESH Studio. All rights reserved.
//

#include <iostream>
#include "Background.h"

void Background::draw(sf::RenderWindow &w)
{
    w.Draw(sf::Shape::Rectangle(0,0,w.GetWidth(), w.GetHeight(), color));
}

Entity* Background::contains_point(sf::Vector2f point)
{
    //A background should be the buck-stopper; 
    //therefore, it will always return true (itself)
    return this;
}