#include"Controller/MenuController.h"


int MenuController::selectMenuItem(int y, bool isTouch)
{
	int item = 0;
	if (y > 180 && y < 250)
	{
		item = 1;
	}
	if (y > 120 && y < 180)
	{
		item = 2;
	}
	if (!isTouch)
	{
		return item;
	}
	else
	{
		return 0;
	}
}
int MenuController::selectSceneWin(int pos)
{
	if (pos > 180 && pos < 220)
	{
		return 1;
	}
	if (pos < 170 && pos > 130)
	{
		return 2;
	}
}