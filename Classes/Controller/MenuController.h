
#ifndef __MenuController_H__
#define __MenuController_H__

#include "cocos2d.h"
#include"SimpleAudioEngine.h"

USING_NS_CC;
class MenuController
{
public :
	int selectMenuItem(int y, bool isTouch);
	
	int selectSceneWin(int pos);
	
};

#endif // __MenuController_H__
