
#ifndef __ABSTRACTSCENE_H__
#define __ABSTRACTSCENE_H__

#include"cocos2d.h"
using namespace cocos2d;
USING_NS_CC;
class AbstractScene : public Layer
{
protected:
	Scene *scene;
public:
	Scene *getScene() const;

    
    
};

#endif // __ABSTRACTSCENE_H__
