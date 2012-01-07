////
//  Interface.cpp
//  GitTest
//
//  Created by Seth Johnson on 1/5/12.
//  Copyright (c) 2012 ESH Studio. All rights reserved.
//

#include "Interface.h"

void Interface::draw(sf::RenderWindow &w)
{
    for (vector<Entity*>::iterator it = entities.begin(); it!=entities.end(); ++it) {
        (*it)->draw(w);
    }
   
}

Entity* Interface::object_with_point(sf::Vector2f point)
{
    Entity* result = NULL;
    
    std::cout << "Size: " << entities.size() << " ; Empty: " << entities.empty() << std::endl;
    
    for(std::vector<Entity*>::reverse_iterator it = entities.rbegin(); 
        it != entities.rend()&& !(result = ((*it)->contains_point(point))); 
    ++it);
    
   
    return result;
    
}