//
//  Background.h
//  GitTest
//
//  Created by Seth Johnson on 1/6/12.
//  Copyright (c) 2012 ESH Studio. All rights reserved.
//

#ifndef GitTest_Background_h
#define GitTest_Background_h

#include "Entity.h"

class Background : public Entity {
public:
    void draw(sf::RenderWindow &w);
    void setColor(sf::Color c) {color = c;}
    Entity* contains_point(sf::Vector2f point){return this;}

protected:
    sf::Color color;
    sf::Image img;
    sf::Sprite sprite;
    
};


#endif
