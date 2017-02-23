//
//  LogInScene.cpp
//  Oliver
//
//  Created by Anthony Gabriele on 2/20/17.
//
//#include "AppDelegate.h"
#include "ui/CocosGUI.h"

#include "WorldMap.h"

#include "LogInScene.h"
#include <stdio.h>
using namespace std;

USING_NS_CC;


Scene* LogInScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = LogInScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool LogInScene::init()
{
    //  you can create scene with following comment code instead of using csb file.
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto center = Vec2(visibleSize.width/2, visibleSize.height/2);
    
    backgroundLayer = LayerColor::create(Color4B(252, 195, 90, 255));
    backgroundLayer->setPosition(origin);
    backgroundLayer->setContentSize(visibleSize);
    this->addChild(backgroundLayer);
    
    logInTitle = Sprite::create("res/LogInTitle.jpg");
    logInTitle->setPosition(Vec2(center.x, center.y + 50));
    auto ratio = visibleSize.width / logInTitle->getContentSize().width;
    logInTitle->setScale(ratio);
    backgroundLayer->addChild(logInTitle, 0);
    
    button = ui::Button::create("res/LogInButton.png", "res/LogInButton.png");
    button->setTouchEnabled(true);
    button->setScale(0.35);
    button->setPosition(Vec2(center.x, center.y - 110));
    button->addTouchEventListener(CC_CALLBACK_2(LogInScene::buttonPressed, this));
    backgroundLayer->addChild(button);
    
    logInButton = ui::Button::create("res/LogInButton.png", "res/LogInButton.png");
    logInButton->setTouchEnabled(true);
    logInButton->setScale(0.35);
    logInButton->setPosition(Vec2(center.x, center.y - 85));
    logInButton->addTouchEventListener(CC_CALLBACK_2(LogInScene::buttonPressed, this));
    backgroundLayer->addChild(logInButton);
    
    return true;
}

void LogInScene::buttonPressed(Ref* pSender, ui::Widget::TouchEventType type){
    if (type == ui::Widget::TouchEventType::ENDED)
    {
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        auto center = Vec2(visibleSize.width/2, visibleSize.height/2);
        
        logInTitle->setPosition(Vec2(center.x, center.y + 70));
        button->removeFromParent();
        logInButton->removeFromParent();
        
        auto editBoxSize = Size(100, 20);
        
        logInBox = ui::EditBox::create(editBoxSize, ui::Scale9Sprite::create("res/editBoxBkgdScale9.png"));
        logInBox->setPosition(center);
        logInBox->setFontName("Paint Boy");
        logInBox->setFontSize(12);
        logInBox->setFontColor(Color3B::WHITE);
        logInBox->setMaxLength(8);
        logInBox->setReturnType(ui::EditBox::KeyboardReturnType::DEFAULT);
        logInBox->setInputMode(ui::EditBox::InputMode::SINGLE_LINE);
        logInBox->setContentSize(Size(150, 20));
        logInBox->setDelegate(this);
        
        watermark = Sprite::create("res/emailWatermark.png");
        watermark->setAnchorPoint(Vec2(0,0.5));
        watermark->setPosition(Vec2(10,10));
        watermark->setScale(0.3);
        watermark->retain();
        logInBox->addChild(watermark);
        hasWatermark = true;
        backgroundLayer->addChild(logInBox);
        
        auto newSceneButton = ui::Button::create("res/LogInButton.png", "res/LogInButton.png");
        newSceneButton->setTouchEnabled(true);
        newSceneButton->setScale(0.35);
        newSceneButton->setPosition(Vec2(center.x, center.y - 110));
        newSceneButton->addTouchEventListener( [](Ref* pSender, ui::Widget::TouchEventType type){
            if (type == ui::Widget::TouchEventType::ENDED){
                auto newScene = WorldMap::createScene();
                Director::getInstance()->replaceScene(newScene);
            }
        });
        backgroundLayer->addChild(newSceneButton);
    }
}

void LogInScene::editBoxEditingDidBegin(ui::EditBox *editBox){
    if(hasWatermark){
        watermark->removeFromParent();
        hasWatermark = false;
    }
}
void LogInScene::editBoxEditingDidEnd(ui::EditBox *editBox){
    if(strcmp(logInBox->getText(), "") == 0 || logInBox->getText() == NULL){
        logInBox->addChild(watermark);
        hasWatermark = true;
    }
}
void LogInScene::editBoxTextChanged(ui::EditBox *editBox, const std::string &text){}
void LogInScene::editBoxReturn(ui::EditBox *editBox){}

LogInScene::~LogInScene(){
    watermark->release();
    watermark = NULL;
}
