#include "MainMenu.h"
#include "SimpleAudioEngine.h"
#include"ScenePlay.h"
USING_NS_CC;

MainMenu* MainMenu::createScene()
{
	MainMenu * scene = new MainMenu();
	if (scene && scene->init())
	{
		return (MainMenu *)scene->autorelease();
	}
	CC_SAFE_DELETE(scene);
	return scene;
}
bool MainMenu::init()
{

    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	auto label = Label::createWithTTF("Maze_Dung", "fonts/Marker Felt.ttf", 50);
	label->setColor(Color3B::WHITE);
	label->setPosition(Vec2( origin.x + visibleSize.width / 2,origin.y +  visibleSize.height / 2 + label->getContentSize().height *2));
	this->addChild(label, 1);

	auto buttonplay_ = Label::createWithTTF("Play", "fonts/Marker Felt.ttf", 35);
	buttonplay_->setColor(Color3B::WHITE);
	buttonplay_->setPosition(Vec2(visibleSize.width/2, 220));

	auto buttonExit_ = Label::createWithTTF("Exit", "fonts/Marker Felt.ttf", 35);
	buttonExit_->setColor(Color3B::RED);
	buttonExit_->setPosition(Vec2(visibleSize.width/2, 150));
	this->addChild(buttonplay_, 1);
	this->addChild(buttonExit_, 1);


	/*auto sprite_icon = Sprite::create("icon_games.png");
	sprite_icon->setPosition(Vec2(200, 200));
	this->addChild(sprite_icon);*/
	this->touchlistener_ = EventListenerTouchOneByOne::create();
	touchlistener_->onTouchBegan = CC_CALLBACK_2(MainMenu::onTouchBegan, this);
	touchlistener_->onTouchMoved = CC_CALLBACK_2(MainMenu::onTouchMove, this);
	touchlistener_->onTouchEnded = CC_CALLBACK_2(MainMenu::onTouchEnded, this);
	getEventDispatcher()->addEventListenerWithFixedPriority(touchlistener_, 100);

	keyboard = EventListenerKeyboard::create();
	keyboard->onKeyReleased = CC_CALLBACK_2(MainMenu::onKeyBoard, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboard, this);
	

	scene = Scene::create();
	scene->addChild(this);

	
	
    return true;
}

bool MainMenu::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
	setMenu(menucontroller->selectMenuItem(touch->getLocation().y, true));
	return true;
}
void MainMenu::onTouchMove(cocos2d::Touch *touch, cocos2d::Event * event)
{
	setMenu(menucontroller->selectMenuItem(touch->getLocation().y, true));
}
void MainMenu::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event * event)
{
	setMenu(menucontroller->selectMenuItem(touch->getLocation().y, false));
}

void MainMenu::onKeyBoard(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event *event)
{
	if ( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 && key == EventKeyboard::KeyCode::KEY_ESCAPE)
	{
		Director::getInstance()->end();
	}
}
void MainMenu::setMenu(int item)
{
	switch (item)
	{
	case 1 :
		getEventDispatcher()->removeEventListener(touchlistener_);
		Director::getInstance()->pushScene(ScenePlay::create()->getScene());
		break;
	case 2:
		Director::getInstance()->end();
		break;
	default:
		break;
	}
}