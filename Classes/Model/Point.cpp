#include"Model/Point.h"
PPoint::PPoint(int x, int y)
{
	this->x = x;
	this->y = y;
}
PPoint::PPoint(int x, int y, int w, int h)
{
	this->x = x * w;
	this->y = y * h;

}
int PPoint::getX()
{
	return x;
}
int PPoint::getY()
{
	return y;
}
PPoint * PPoint::multiPly(int size)
{
	return new PPoint(x, y, size, size);
}