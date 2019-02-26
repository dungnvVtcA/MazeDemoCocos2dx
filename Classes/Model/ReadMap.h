
#ifndef __ReadMap_H__
#define __ReadMap_H__
#include<vector>
#include"Model/mazeGeneration.h"
#include"Model/TextureVec2.h"
using namespace std;
class ReadMap
{
	TexVec2 vec; 
public:
	ReadMap() {};
	~ReadMap() {};
	TexVec2  getVecMaze() 
	{
		return  vec;
	}
	void getMap(std::vector<std::vector<int>> a);
	Vec2 player;
	Vec2 destination;
};

#endif // __HELLOWORLD_SCENE_H__
