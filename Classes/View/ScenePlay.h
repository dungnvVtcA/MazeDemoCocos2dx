
#ifndef __ScenePlay_H__
#define __ScenePlay_H__

#include "Model/ReadMap.h"
#include"Controller/SoundController.h"
#include"Model/WorldObject.h"
#include"AbstractScene.h"

USING_NS_CC;
enum Status { LEFT, RIGHT, UP, DOWN };
class ScenePlay : public AbstractScene
{
private:
	MazeGenerator * maze;
	SoundController * sound;
	EventListenerTouchOneByOne * touchListener;
	EventListenerKeyboard * keyboard;
	ReadMap * readmap;
	Layer *layer_;
	WorldObject * world_;
	int touchX;
	int touchY;

	std::vector<std::vector<int>> k;

public:
	bool ontouchBegin(Touch *touch, Event *event);
	void ontouchMove(Touch *touch, Event *event);
	void ontouchEnd(Touch *touch, Event *event);
	//void ontouchCall(Touch *touch, Event *event);

	void onkeyPressed(EventKeyboard::KeyCode keycode, Event *event);
	void onkeyReleased(EventKeyboard::KeyCode keycode, Event * event);

	bool isTouchKeyDown = true;
	bool isTouchDown;

	bool isGo;
	void UpdatePlayer(float dt);
	static ScenePlay * create();
	
	float initialTouchPos[2];
	float currentTouchPos[2];

	Size visible;
	virtual bool init();

	Sprite *player, *destination;
	int Status;
	void setTouch(int x, int y)
	{
		touchX = x;
		touchY = y;
	}
	
	ETexture getnumber(ETexture tex)
	{
		return tex;
	}

	
    
};

#endif // __ScenePlay_H__
