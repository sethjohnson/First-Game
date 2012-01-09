//
//  Rectangle.cpp
//  GitTest
//
//  Created by Seth Johnson on 1/8/12.
//  Copyright (c) 2012 ESH Studio. All rights reserved.
//

#include <iostream>
#include "Rectangle.h"

void Rectangle::draw(sf::RenderWindow &w)
{
    w.Draw(sf::Shape::Rectangle(center.x-dimensions.x/2, center.y-dimensions.y/2, center.x+dimensions.x/2, center.y+dimensions.y/2, sf::Color::Black));
    
}

Entity* Rectangle::contains_point(sf::Vector2f point)
{
    if (clickable)
        if ((point.x>center.x-dimensions.x/2) && (point.x < center.x+dimensions.x/2)
            &&
            point.y>center.y-dimensions.y/2 && point.y < center.y+dimensions.y/2) {
            return this;
        }
    return NULL;
}