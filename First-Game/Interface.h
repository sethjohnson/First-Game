//
//  Interface.h
//  GitTest
//
//  Created by Seth Johnson on 1/5/12.
//  Copyright (c) 2012 ESH Studio. All rights reserved.
//

#ifndef GitTest_Interface_h
#define GitTest_Interface_h

#include "Entity.h"
#include <vector>
#include <SFML/Graphics.hpp>
using std::vector;

class Interface {
    
public:
    vector<Entity*> entities;
    sf::View view;
};


#endif
