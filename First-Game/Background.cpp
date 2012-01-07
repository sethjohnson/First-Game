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