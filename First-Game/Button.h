//
//  Button.h
//  GitTest
//
//  Created by Seth Johnson on 1/5/12.
//  Copyright (c) 2012 ESH Studio. All rights reserved.
//

#ifndef GitTest_Button_h
#define GitTest_Button_h
#include "Rectangle.h"

using std::string;

class Button : public Rectangle  {
    
public:
    Button() {
        clickable = true;
    }
    void draw(sf::RenderWindow &w);

    void setText(string s) {text=s;}
    
    void setClickedMethod(void (*c)(Entity*)) {clicked = c;}
    
protected:
    string text;
    void (*clicked)(Entity*);
};


#endif
