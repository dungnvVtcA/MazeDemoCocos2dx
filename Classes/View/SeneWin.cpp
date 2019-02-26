#include "SeneWin.h"

#include"ScenePlay.h"
USING_NS_CC;

SceneWin * SceneWin::create()
{
	SceneWin * scene = new SceneWin();
	if (scene && scene->init())
	{
		return(SceneWin*)scene->autorelease();
	}
	CC_SAFE_DELETE(scene);
	return scene;
}



bool SceneWin::init()
{
   
    if ( !Layer::init() )
    {
        return false;
    }
	auto visi = Director::getInstance()->getVisibleSize();

	auto label = Label::createWithTTF("You Winner", "fonts/Marker Felt.ttf", visi.width / 8);
	label->setPosition(Vec2(visi.width/2 , visi.height * 0.7));
	label->setColor(Color3B::YELLOW);
	this->addChild(label);

	auto labelBack = Label::createWithTTF("Back Menu", "fonts/Marker Felt.ttf", visi.width / 20);
	labelBack->setPosition(visi / 2);
	labelBack->setColor(Color3B::WHITE);
	this->addChild(labelBack);

	auto labelReplay = Label::createWithTTF("Replay", "fonts/Marker Felt.ttf", visi.width / 20);
	labelReplay->setPosition(Vec2(visi.width / 2 , visi.height /2 - visi.width* 0.2));
	labelReplay->setColor(Color3B::WHITE);
	this->addChild(labelReplay);

	touch = EventListenerTouchOneByOne::create();
	touch->onTouchBegan = CC_CALLBACK_2(SceneWin::ontouchBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touch, this);
	

	scene = Scene::create();
	scene->addChild(this);
	return true;
	
	
}


bool SceneWin::ontouchBegin(Touch *touch, Event * event)
{
	setScene(menu->selectSceneWin(touch->getLocation().y));
	return true;
}
void SceneWin::setScene(int pos)
{
	switch (pos)
	{
	case 1 :
		getEventDispatcher()->removeEventListener(touch);
		Director::getInstance()->replaceScene(MainMenu::createScene()->getScene());
		break;
	case 2 :
		getEventDispatcher()->removeEventListener(touch);
		Director::getInstance()->replaceScene(ScenePlay::create()->getScene());
		break;
	}
}