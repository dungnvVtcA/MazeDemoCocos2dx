
#ifndef __SceneWin_H__
#define __SceneWin_H__
#include"AbstractScene.h"
#include"MainMenu.h"
USING_NS_CC;

class SceneWin : public AbstractScene
{
private:
	MenuController *menu;
	EventListenerTouchOneByOne * touch;
public:
	
	static SceneWin * create();
	virtual bool init();
	bool ontouchBegin(Touch *touch, Event *event);
	void setScene(int pos);
};

#endif // __ScenePlay_H__
