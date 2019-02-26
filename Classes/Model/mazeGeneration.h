
#ifndef MazeGenerator_H_
#define MazeGenerator_H_

#include <iostream>
#include <vector>
#include <queue>


class MazeGenerator
{
	static int mSize, longestPth;
	static std::vector<std::pair<int, int>> frontier, inCell;
	static std::pair<int, int> startCoordinates, endCoordinates;
	static std::pair<float, float> tileSize;

	static std::vector<std::vector<int>> a;
	static std::vector<std::vector<bool>> vis;
	static std::vector<std::vector<int>> dist;

	static void clear(std::vector<std::vector<bool>> &x);
	static void clear(std::vector<std::vector<int>> &x);
	static void prim(int x, int y, int r);
	static bool inBound(int x, int y);
	static void longestPath();
	static void calculateDistance(int y, int x);
	static void assignElements(std::pair<int, int> &s, std::pair<int, int> &e);
	static bool dfs(std::pair<int, int> s, std::pair<int, int> e);
public:
	static std::vector<std::vector<int>> getMaze(int size);
	static int getDistance() { return longestPth; }
	static std::pair<int, int> getStartCoordinates() { return startCoordinates; }
	static std::pair<int, int> getEndCoordinates() { return endCoordinates; }
	static std::pair<float, float> getTileSize() { return tileSize; }
	static std::vector<std::vector<int>> getMazeArray() { return a; }
	static std::vector<std::vector<int>> getDistArray() { return dist; }
	static std::vector<std::pair<int, int>> getPathCoordinates();
	static void printMaze(std::vector<std::vector<int>> a);
};

#endif /* MazeGenerator_H */