
#ifndef __PPoint_H__
#define __PPoint_H__
class PPoint
{
private :
	int x; 
	int y;
public:
	PPoint(int x, int y);
	PPoint(int x, int y, int width, int height);
	int getX();
	int getY();
	PPoint * multiPly(int size);
};

#endif // __PPoint_H__
