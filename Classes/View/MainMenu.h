
#ifndef __MainMenu_SCENE_H__
#define __MainMenu_SCENE_H__
#include"View/AbstractScene.h"
#include "cocos2d.h"
#include"Controller/MenuController.h"


class MainMenu : public AbstractScene
{
private:
	
	EventListenerTouchOneByOne* touchlistener_;
	EventListenerKeyboard *keyboard;
	MenuController *menucontroller;

public:
    static MainMenu * createScene();

    virtual bool init();

	void setMenu(int item);
	bool onTouchBegan(cocos2d::Touch *, cocos2d::Event *);
	void onTouchMove(cocos2d::Touch *, cocos2d::Event *);
	void onTouchEnded(cocos2d::Touch *, cocos2d::Event *);

	void onKeyBoard(cocos2d::EventKeyboard::KeyCode, cocos2d::Event *);

    
};

#endif // __MainMenu_SCENE_H__
