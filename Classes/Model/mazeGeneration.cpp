#include"mazeGeneration.h"
#include <time.h>      
#define mp make_pair

using namespace std;

// Objects' def.
int MazeGenerator::mSize, MazeGenerator::longestPth;
std::vector<std::pair<int, int>> MazeGenerator::frontier, MazeGenerator::inCell;
std::vector<std::vector<int>> MazeGenerator::a;
std::vector<std::vector<bool>> MazeGenerator::vis;
std::vector<std::vector<int>> MazeGenerator::dist;
std::pair<int, int> MazeGenerator::startCoordinates, MazeGenerator::endCoordinates;
std::pair<float, float> MazeGenerator::tileSize;

const short dx[8] = { 2, 0, -2, 0, 1, 0, -1, 0 },
dy[8] = { 0, -2, 0, 2, 0, -1, 0, 1 };

vector<vector<int>> MazeGenerator::getMaze(int _s)
{
	if (!(_s % 2))
		_s++;
	if (_s < 5)
		_s = 5;
	mSize = _s;
	a.resize(mSize); vis.resize(mSize); dist.resize(mSize);
	for (int i = 0; i < mSize; i++)
	{
		a[i].resize(mSize);
		vis[i].resize(mSize);
		dist[i].resize(mSize);
	}

	srand(static_cast<unsigned int>(time(nullptr)));
	pair<int, int> start, end;

	do
	{
		clear(a); clear(vis);

		// init first cell
		int tempX = rand() % mSize, tempY = rand() % mSize;
		while (!(tempX % 2))
			tempX = rand() % mSize;
		while (!(tempY % 2))
			tempY = rand() % mSize;
		a[tempX][tempY] = 1;
		for (int i = 0; i < 4; i++)
		{
			if (inBound(tempX + dx[i], tempY + dy[i]) && !a[tempX + dx[i]][tempY + dy[i]])
			{
				frontier.push_back(mp(tempX + dx[i], tempY + dy[i]));
				inCell.push_back(mp(tempX, tempY));
			}
		}
		int r = rand() % frontier.size();
		prim(frontier[r].first, frontier[r].second, r);

		assignElements(start, end);


		clear(vis);

	} while (!dfs(start, end));

	return a;
}

bool MazeGenerator::inBound(int x, int y)
{
	return (x < mSize && y < mSize && x >= 0 && y >= 0);
}

void MazeGenerator::prim(int x, int y, int r)
{
	if (!frontier.size())
		return;

	a[x][y] = 1;

	for (int i = 0; i < 4; i++)
	{
		if (inBound(x + dx[i], y + dy[i]) && !a[x + dx[i]][y + dy[i]] && find(frontier.begin(), frontier.end(), mp(x + dx[i], y + dy[i])) == frontier.end())
		{
			frontier.push_back(mp(x + dx[i], y + dy[i]));
			inCell.push_back(mp(x, y));
		}
	}

	// New Element and Bridge
	int tempX = frontier[r].first, tempY = frontier[r].second, tempDx = inCell[r].first, tempDy = inCell[r].second;
	frontier.erase(frontier.begin() + r);
	inCell.erase(inCell.begin() + r);

	if (!(tempX - tempDx))  // Bridge
	{
		// Check if it's up or down
		if (tempDy > tempY)
			a[tempX][tempY + 1] = 1;
		else a[tempX][tempY - 1] = 1;
	}
	else if (!(tempY - tempDy))
	{
		// Check if it's left or right
		if (tempDx > tempX)
			a[tempX + 1][tempY] = 1;
		else a[tempX - 1][tempY] = 1;
	}
	if (!frontier.size())
		return;
	int m = rand() % frontier.size();
	prim(frontier[m].first, frontier[m].second, m);
}


void MazeGenerator::calculateDistance(int y, int x)
{
	queue<pair<pair<int, int>, int>> q;
	q.push(mp(mp(y, x), 0));
	int i, j, d;
	std::vector<std::vector<int>> tempDist(dist.size());
	for (int i = 0; i < dist.size(); i++)
		tempDist[i].resize(dist[i].size());

	clear(tempDist);

	while (!q.empty())
	{
		i = q.front().first.first; j = q.front().first.second;
		d = q.front().second;
		q.pop();

		if (d > tempDist[i][j])
			tempDist[i][j] = d;
		vis[i][j] = 1;

		for (int r = 4; r < 8; r++)
		{
			int n = i + dy[r], m = j + dx[r];
			if (inBound(n, m) && a[n][m] && d + 1 > tempDist[n][m] && !vis[n][m])
				q.push(mp(mp(n, m), d + 1));
		}
	}

	int tempMax = 0, max = 0;
	for (int i = 0; i < dist.size(); i++)
	{
		for (int j = 0; j < dist[i].size(); j++)
		{
			if (max < dist[i][j])
				max = dist[i][j];
			if (tempMax < tempDist[i][j])
				tempMax = tempDist[i][j];
		}
	}

	if (max < tempMax)
	{
		dist = tempDist;
		longestPth = tempMax;
	}
}

void MazeGenerator::longestPath()
{
	clear(dist);
	for (int i = 0; i < mSize; i++)
	{
		for (int j = 0; j < mSize; j++)
		{
			clear(vis);
			calculateDistance(i, j);
		}
	}
}

void MazeGenerator::clear(std::vector<std::vector<bool>> &x)
{
	for (int i = 0; i < x.size(); i++)
		for (int j = 0; j < x[i].size(); j++)
			x[i][j] = 0;

}

void MazeGenerator::clear(std::vector<std::vector<int>> &x)
{
	for (int i = 0; i < x.size(); i++)
		for (int j = 0; j < x[i].size(); j++)
			x[i][j] = 0;
}


void MazeGenerator::assignElements(pair<int, int> &s, pair<int, int> &e)
{
	s = mp(-1, -1); e = mp(-1, -1);

	longestPath();

	int max = 0, min = mSize * mSize;
	for (int i = 0; i < mSize; i++)
		for (int j = 0; j < mSize; j++)
		{
			if (dist[i][j] >= max)
			{
				max = dist[i][j];
				e = mp(i, j);
				endCoordinates = e;
			}
			if (dist[i][j] < min && a[i][j])
			{
				min = dist[i][j];
				s = mp(i, j);
				startCoordinates = s;
			}
		}



	if (s != mp(-1, -1) && e != mp(-1, -1))
	{
		a[s.first][s.second] = 2;
		a[e.first][e.second] = 3;
		return;
	}
	// Start
	for (int i = 0; i < mSize; i++)
	{
		for (int j = 0; j < mSize / 3; j++)
		{
			if (a[i][j])
			{
				s = mp(i, j);
				startCoordinates = s;
				a[i][j] = 2;
				goto out;
			}
		}
	}
out:
	for (int i = mSize - 1; i >= 0; i--)
	{
		for (int j = mSize - 1; j >= 0; j--)
		{
			if (a[i][j])
			{
				e = mp(i, j);
				endCoordinates = e;
				a[i][j] = 3;
				return;
			}
		}
	}

}

bool MazeGenerator::dfs(pair<int, int> s, pair<int, int> e)
{
	if (s == e)
		return true;
	bool x = false;
	vis[s.first][s.second] = 1;
	for (int i = 4; i < 8; i++)
	{
		if (inBound(s.first + dy[i], s.second + dx[i]) && !vis[s.first + dy[i]][s.second + dx[i]] && a[s.first + dy[i]][s.second + dx[i]] && !x)
			x = dfs(mp(s.first + dy[i], s.second + dx[i]), e);
	}

	return x;
}

void MazeGenerator::printMaze(std::vector<std::vector<int>> a)
{
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[i].size(); j++)
			cout << a[i][j];
		cout << '\n';
	}
}

std::vector<std::pair<int, int>> MazeGenerator::getPathCoordinates()
{
	std::vector<std::pair<int, int>> res;
	std::pair<int, int> curr;
	int currDist;
	res.push_back(endCoordinates);
	while (res[res.size() - 1] != startCoordinates)
	{
		curr = res[res.size() - 1];
		currDist = dist[curr.first][curr.second];
		for (int i = 4; i < 8; i++)
		{
			if (dist[curr.first + dy[i]][curr.second + dx[i]] == currDist - 1)
			{
				res.push_back(mp(curr.first + dy[i], curr.second + dx[i]));
				break;
			}
		}
	}
	std::reverse(res.begin(), res.end());

	//    cout << "\n\n";
	//    for (int i = 0; i < res.size(); i++)
	//        cout << res[i].first << ' ' << res[i].second << '\n';
	//    cout << '\n';
	return res;
}