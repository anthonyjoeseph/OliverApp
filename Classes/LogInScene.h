//
//  LogInScene.h
//  Oliver
//
//  Created by Anthony Gabriele on 2/20/17.
//
//

#ifndef LogInScene_h
#define LogInScene_h

#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;


class LogInScene : public cocos2d::Layer, public cocos2d::ui::EditBoxDelegate
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    ~LogInScene();
    
    void editBoxEditingDidBegin(ui::EditBox *editBox);
    void editBoxEditingDidEnd(ui::EditBox *editBox);
    void editBoxTextChanged(ui::EditBox *editBox, const std::string &text);
    void editBoxReturn(ui::EditBox *editBox);
    
    CREATE_FUNC(LogInScene);
    
private:
    LayerColor *backgroundLayer;
    Sprite *logInTitle;
    ui::Button *button;
    ui::Button *logInButton;
    
    ui::EditBox *logInBox;
    Sprite *watermark;
    bool hasWatermark;
    
    void buttonPressed(Ref* pSender, cocos2d::ui::Widget::TouchEventType type);
    
};

#endif /* LogInScene_h */
