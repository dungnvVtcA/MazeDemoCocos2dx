#include "ScenePlay.h"
#include "SimpleAudioEngine.h"
#include"Model/mazeGeneration.h"
#include"Model/ReadMap.h"
#include"MainMenu.h"
#include"SeneWin.h"
USING_NS_CC;

ScenePlay  * ScenePlay::create()
{
	ScenePlay * scene = new ScenePlay();
	if (scene && scene->init())
	{
		return(ScenePlay*)scene->autorelease();
	}
	CC_SAFE_DELETE(scene);
	return scene;
}



bool ScenePlay::init()
{
   
    if ( !Layer::init() )
    {
        return false;
    }
	this->sound = sound;
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	maze = new MazeGenerator();
	k = maze->getMaze(20);// max 68
	readmap = new ReadMap();
	readmap->getMap(k);

	for (auto sprite : readmap->getVecMaze())
	{
		this->addChild(sprite->getTexture(), 0);
	}
	
	player= Sprite::create("player.png");
	player->setPosition(Vec2(readmap->player));
	this->addChild(player);

	destination = Sprite::create("dich.png");
	destination->setPosition(Vec2(readmap->destination));
	this->addChild(destination);

	
	
	/*world_->setTexture(EBackground);
	world_->getTexture()->getPosition();*/
	
	

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(ScenePlay::ontouchBegin, this);
	listener->onTouchMoved = CC_CALLBACK_2(ScenePlay::ontouchMove, this);
	listener->onTouchEnded = CC_CALLBACK_2(ScenePlay::ontouchEnd, this);
	//listener->onTouchCancelled = CC_CALLBACK_2(ScenePlay::ontouchCall, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	keyboard = EventListenerKeyboard::create();
	keyboard->onKeyPressed = CC_CALLBACK_2(ScenePlay::onkeyPressed, this);
	//keyboard->onKeyReleased = CC_CALLBACK_2(ScenePlay::onkeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboard, this);
	this->schedule(schedule_selector(ScenePlay::UpdatePlayer));
	scene = Scene::create();
	scene->addChild(this);
	return true;
	
	
}


void ScenePlay::onkeyPressed(EventKeyboard::KeyCode keycode, Event *event)
{
	if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 && keycode == EventKeyboard::KeyCode::KEY_A)
	{
		Status = 0;
		this->isGo = true;
	}
	if(CC_TARGET_PLATFORM ==CC_PLATFORM_WIN32 && keycode == EventKeyboard::KeyCode::KEY_W)
	{
		Status = 1;
		this->isGo = true;
	}
	if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 && keycode == EventKeyboard::KeyCode::KEY_D)
	{
		Status = 2;
		this->isGo = true;
	}
	if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 && keycode == EventKeyboard::KeyCode::KEY_S)
	{
		this->isGo = true;
		Status = 3;
	}
}

bool ScenePlay::ontouchBegin(Touch *touch, Event *event)
{
	this->setTouch(touch->getLocation().x, touch->getLocation().y);
	isTouchDown = true;
	return true;
}



void ScenePlay::ontouchMove(Touch *touch, Event *event)
{
	if (touchX > touch->getLocation().x && abs(touch->getLocation().x - touchX) > 20 && abs(touch->getLocation().y - touchY) < 60)
	{
		Status = 0;
	}
	if (touchX < touch->getLocation().x && abs(touch->getLocation().x - touchX) > 20 && abs(touch->getLocation().y - touchY) < 60)
	{
		Status = 1;
	}
	if (touchY > touch->getLocation().y && abs(touch->getLocation().y - touchY) > 20 && abs(touch->getLocation().x - touchX) < 60)
	{
		Status = 1;
	}
	if (touchY < touch->getLocation().y && abs(touch->getLocation().y- touchY) > 20 && abs(touch->getLocation().x - touchX) < 60)
	{
		Status = 1;
	}
}

void ScenePlay::ontouchEnd(Touch *touch, Event * event)
{
	if (touchX > touch->getLocation().x && abs(touch->getLocation().y - touchY) < 60)
	{
		Status = 0;
	}
	if (touchX < touch->getLocation().x && abs(touch->getLocation().y - touchY) < 60)
	{
		Status = 1;
	}
	if (touchY > touch->getLocation().y && abs(touch->getLocation().x - touchX) < 60)
	{
		Status = 2;
	}
	if (touchY < touch->getLocation().y && abs(touch->getLocation().x - touchX) < 60)
	{
		Status = 3;
	}
	isTouchDown = true;
}



void ScenePlay::UpdatePlayer(float dt)
{
	
	if (isTouchDown)
	{
		if (Status == 0)
		{
			player->setPositionX(player->getPositionX() - 4);
		}
		if (Status == 1)
		{
			player->setPositionX(player->getPositionX() + 4);
		}
		if (Status == 2)
		{
			player->setPositionY(player->getPositionY() + 4);
		}
		if (Status == 3)
		{
			player->setPositionY(player->getPositionY() - 4);
		}
	}
	if (isTouchKeyDown)
	{
		if (Status == 0 && k[player->getPositionX() / 4 - 2][player->getPositionY() / 4 -1] == 1 || k[player->getPositionX() / 4 - 2][player->getPositionY() / 4 - 1] == 3)
		{
			
			if (isGo == true || k[player->getPositionX() / 4 - 1][player->getPositionY() / 4] != 1 && k[player->getPositionX() / 4 - 1][player->getPositionY() / 4 - 2] != 1)
			{
				player->setPositionX(player->getPositionX() - 4);
			}
			if (k[player->getPositionX() / 4 - 1][player->getPositionY() / 4] != 1 || k[player->getPositionX() / 4 - 1][player->getPositionY() / 4 - 2] != 1)
			{
				isGo = false;
			}
		}
		if (Status == 1 && k[player->getPositionX() / 4- 1][player->getPositionY() / 4 ] == 1 || k[player->getPositionX() / 4 - 1][player->getPositionY() / 4] == 3)
		{
			if (isGo || k[player->getPositionX() / 4 - 2][player->getPositionY() / 4 - 1] != 1 && k[player->getPositionX() / 4][player->getPositionY() / 4 - 1] != 1)
			{
				player->setPositionY(player->getPositionY() + 4);
			
			}
			if (k[player->getPositionX() / 4 - 2][player->getPositionY() / 4 - 1] != 1 || k[player->getPositionX() / 4][player->getPositionY() / 4 - 1] != 1)
			{
				isGo = false;
			}
		}
		if (Status == 2 && k[player->getPositionX() / 4  ][player->getPositionY() / 4 -1 ] == 1 || k[player->getPositionX() / 4 ][player->getPositionY() / 4 - 1] == 3)
		{
			if (isGo || k[player->getPositionX() / 4 - 1][player->getPositionY()/ 4 ] != 1 && k[player->getPositionX() / 4 - 1][player->getPositionY() / 4 - 2] != 1)
			{
				player->setPositionX(player->getPositionX() + 4);
			}
			if (k[player->getPositionX() / 4 - 1][player->getPositionY() / 4] != 1 || k[player->getPositionX() / 4 - 1][player->getPositionY() / 4 - 2] != 1)
			{
				isGo = false;
			}
		}
		if (Status == 3&& k[player->getPositionX() / 4 - 1][player->getPositionY() / 4 - 2] == 1 || k[player->getPositionX() / 4 - 1][player->getPositionY() / 4 - 2] == 3)
		{
			if (isGo || k[player->getPositionX() / 4 - 2][player->getPositionY() / 4 - 1] != 1 && k[player->getPositionX() / 4][player->getPositionY() / 4 - 1] != 1)
			{
				player->setPositionY(player->getPositionY() - 4);
			}
			if (k[player->getPositionX() / 4 - 2][player->getPositionY() / 4 - 1] != 1 || k[player->getPositionX() / 4][player->getPositionY() / 4 - 1] != 1)
			{
				isGo = false;
			}
		}
	}
	if (player->getPosition() == destination->getPosition())
	{
		Director::getInstance()->replaceScene(SceneWin::create()->getScene());
	}

}