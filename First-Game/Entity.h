//
//  Entity.h
//  GitTest
//
//  Created by Seth Johnson on 1/5/12.
//  Copyright (c) 2012 ESH Studio. All rights reserved.
//

#ifndef GitTest_Entity_h
#define GitTest_Entity_h
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

class Entity  {
protected:
    bool clickable;
public:
    virtual void draw(sf::RenderWindow &w) = 0;
    virtual Entity* contains_point(sf::Vector2f point) =0;
};


#endif
