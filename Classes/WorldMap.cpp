//
//  WorldMap.cpp
//  Oliver
//
//  Created by Anthony Gabriele on 2/20/17.
//
//

#include "WorldMap.h"
#include "ui/CocosGUI.h"
#include "NativeInterface.h"

USING_NS_CC;

Scene* WorldMap::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = WorldMap::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}


bool WorldMap::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    NativeInterface* ni = new NativeInterface();
    std::string nativeReturn = ni->nativeCallback();
     
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto actualSize = Size(visibleSize.height, visibleSize.width);
    auto actualCenter = Vec2(actualSize.width/2 - 10, 0);
    
    auto backgroundLayer = LayerColor::create(Color4B(100, 150, 200, 255));
    backgroundLayer->setAnchorPoint(Vec2(0.5, 0.5));
    backgroundLayer->setPosition(actualCenter);
    backgroundLayer->setContentSize(actualSize);
    this->addChild(backgroundLayer);
    
    auto backgroundSize = backgroundLayer->getContentSize();
    auto backgroundCenter = Vec2(backgroundSize.width / 2, backgroundSize.height / 2);
    /*auto label = Label::createWithSystemFont("0",
                                             "Helvetica",
                                             24,
                                             Size(32, 32),
                                             TextHAlignment::LEFT,
                                             TextVAlignment::TOP);
    label->setPosition(backgroundCenter);
    backgroundLayer->addChild(label);*/
    
    auto map = Sprite::create("res/worldMap/map.jpg");
    auto mapRatio = backgroundSize.width/map->getContentSize().width;
    map->setScale(mapRatio);
    map->setPosition(backgroundCenter);
    backgroundLayer->addChild(map);
    
    return true;
}
