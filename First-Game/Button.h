//
//  Button.h
//  GitTest
//
//  Created by Seth Johnson on 1/5/12.
//  Copyright (c) 2012 ESH Studio. All rights reserved.
//

#ifndef GitTest_Button_h
#define GitTest_Button_h
#include "Entity.h"

using std::string;

class Button : public Entity  {
    
public:
    Button() {
        clickable = true;
    }
    void draw(sf::RenderWindow &w);

    void setCenter(float x, float y) { center.x = x; center.y = y;}
    void setDimensions(float x, float y) { dimensions.x = x; dimensions.y = y;}
    void setText(string s) {text=s;}
    Entity* contains_point(sf::Vector2f point);

protected:
    string text;
    sf::Vector2f center;
    sf::Vector2f dimensions;
};


#endif
