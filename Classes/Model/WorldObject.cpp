#include"Model/WorldObject.h"
#include"View/ScenePlay.h"
using namespace std;
static char textures[ETexLast][60] =
{
	"hidel.png",// bachgroud =0
	"wall.png",// wall
	"player.png",//player
	"dich.png",//destination
	"wall.png",//key
	
};
WorldObject::WorldObject(PPoint *point, ETexture tex, int w, int h)
{
	this->w = w;
	this->h = h;
	position = new PPoint(point->getX(), point->getY(), w, h);
	this->texName = tex;
	this->sprite = Sprite::create(textures[tex]);
	this->sprite->setPosition(point->getX() * 4 + 4, point->getY() * 4 + 4);
}
WorldObject::~WorldObject()
{
	delete position;
}
int WorldObject::getWidth()
{
	return this->w;
}
int WorldObject::getHeight()
{
	return this->h;
}
void WorldObject::setWidth(int w)
{
	this->w = w;
}
void WorldObject::setHeight(int h)
{
	this->h = h;
}
PPoint * WorldObject::getPosition()
{
	return position;
}
Sprite * WorldObject::getTexture()
{
	return this->sprite;
}
ETexture WorldObject::getTextureName()
{
	return texName;
}void WorldObject::setTexture(ETexture tex)
{
	this->texName = tex;
	auto *t = Director::getInstance()->getTextureCache()->addImage(textures[tex]);
	this->sprite->setTexture(t);
}
void WorldObject::setPositionPoint(PPoint * point)
{
	position = new PPoint(point->getX(), point->getY(), w, h);
}
