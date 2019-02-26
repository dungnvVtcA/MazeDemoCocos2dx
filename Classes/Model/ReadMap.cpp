#include"Model/ReadMap.h"
void ReadMap::getMap(vector<vector<int>> maze)
{
	for (int i = 0; i < maze.size(); i++)
	{
		for (int j = 0; j < maze[i].size(); j++)
		{
			if (maze[i][j] == 0)
			{
				vec.push_back(new TextureVec(new PPoint(i ,j), EWall, 8, 8));
			}
			if (maze[i][j] == 1)
			{
				vec.push_back(new TextureVec(new PPoint(i , j), EBackground, 8, 8));
				
			}
			if (maze[i][j] == 2)
			{
				vec.push_back(new TextureVec(new PPoint(i , j), EBackground, 8, 8));
				player.setPoint(i*4 +4, j*4 +4);
			}
			if (maze[i][j] == 3)
			{
				vec.push_back(new TextureVec(new PPoint(i, j), EBackground, 8, 8));
				destination.setPoint(i*4 +4, j*4 +4);

			}
			

		}
	}
}