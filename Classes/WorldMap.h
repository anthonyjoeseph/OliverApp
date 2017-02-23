//
//  WorldMap.hpp
//  Oliver
//
//  Created by Anthony Gabriele on 2/20/17.
//
//

#ifndef WorldMap_h
#define WorldMap_h

#include "cocos2d.h"

class WorldMap : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(WorldMap);
};

#endif /* WorldMap_h */
