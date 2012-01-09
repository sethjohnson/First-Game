//
//  Rectangle.h
//  GitTest
//
//  Created by Seth Johnson on 1/8/12.
//  Copyright (c) 2012 ESH Studio. All rights reserved.
//

#ifndef GitTest_Rectangle_h
#define GitTest_Rectangle_h

#include "Entity.h"

class Rectangle : public Entity {
public:
    void draw(sf::RenderWindow &w);
    
    void setCenter(float x, float y) { center.x = x; center.y = y;}
    void setDimensions(float x, float y) { dimensions.x = x; dimensions.y = y;}
    
    Entity* contains_point(sf::Vector2f point);
    
protected:
    sf::Vector2f center;
    sf::Vector2f dimensions;

};

#endif
