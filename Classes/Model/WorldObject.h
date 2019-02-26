
#ifndef WorldObject_H_
#define WorldObject_H_
#include"cocos2d.h"
#include"Model/Point.h"
#include"Model/Texture.h"
#include"View/AbstractScene.h"
USING_NS_CC;
using namespace std;

class WorldObject
{
private:
	ETexture texName;
	int w;
	int h;
protected:
	PPoint * position;
	Sprite * sprite;
public:
	WorldObject();
	virtual ~WorldObject();
	WorldObject(PPoint * point, ETexture texname, int width, int height);
	int getWidth();
	int getHeight();
	void setWidth(int width);
	void setHeight(int height);
	PPoint* getPosition();
	void setPositionPoint(PPoint* point);
	Sprite* getTexture();
	ETexture getTextureName();
	int getSpriteX() { return sprite->getPositionX(); }
	int getSpriteY() { return sprite->getPositionY(); }
	void setBounds(int x, int y, int width, int height);
	void setTexture(ETexture texture);
	virtual void animate() {
		// do nothing
	}
	int inverse(int count);
};


#endif // WorldObject_H_
