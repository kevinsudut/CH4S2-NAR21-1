#include "cBuildMap.h"

cBuildMap::cBuildMap()
{
}

cBuildMap::cBuildMap(cScene* scene, cSetting* setting)
{
	this->scene = scene;
	this->setting = setting;
	this->block = setting->getBlock();
}

cBuildMap::~cBuildMap()
{
}

void cBuildMap::initialize()
{
	system("cls");
	setColor(C_WHITE);
	for (int i = 0; i < Y_MAX; i++)
	{
		for (int j = 0; j < X_MAX; j++)
		{
			if (i == 0 || j == 0 || i == Y_MAX - 1 || j == X_MAX - 1)
			{
				temp[i][j] = cNode(WALL, true);
			}
			else
			{
				temp[i][j] = cNode(FLOOR, false);
			}
			switch (temp[i][j].getStatus())
			{
			case FLOOR:
				printf(" ");
				break;
			case WALL:
				setColor(C_GREEN);
				printf("%c", 178);
				break;
			}
		}
		printf("\n");
	}
	setColor(C_WHITE);
	showLegend();
	gotoxy({ 82, 14 });
	printf("Remaining available wall: ", block);
	showBlockStatus();
}

void cBuildMap::run()
{
	COORD c = { 1, 1 }, x = { 28, 24 };
	gotoxy(c);
	while (true)
	{
		if (kbhit())
		{
			int key = getch();
			if (key == 27)
			{
				if (save())
				{
					return;
				}
			}
			else if (key == 32)
			{
				fill(c);
			}
			else if (validArrow())
			{
				getch();
				moveCursor(c);
			}
			showBlockStatus();
			gotoxy(c);
		}
	}
}

void cBuildMap::showLegend()
{
	gotoxy({ 89, 4 });
	printf("%c", 201);
	for (int i = 0; i < 26; i++)
	{
		printf("%c", 205);
	}
	printf("%c", 187);
	gotoxy({ 89, 5 });
	printf("%c SUDUT and Precious Stars %c", 186, 186);
	gotoxy({ 89, 6 });
	printf("%c", 200);
	for (int i = 0; i < 26; i++)
	{
		printf("%c", 205);
	}
	printf("%c", 188);
	gotoxy({ 81, 8 });
	printf("Legend:");
	gotoxy({ 81, 10 });
	printf("> Press the arrow key to move the cursor");
	gotoxy({ 81, 11 });
	printf("> Press the space key to add or remove a wall");
	gotoxy({ 81, 12 });
	printf("> Press the ESC key to save the current map");
}

void cBuildMap::showBlockStatus()
{
	for (short i = 108; i < 112; i++)
	{
		gotoxy({ i, 14 });
		printf(" ");
	}
	gotoxy({ 108, 14 });
	printf("%d", block);
}

void cBuildMap::floodFill(int x, int y)
{
	if (temp[y][x].getStatus() != WALL)
	{
		if (x > 0 && y > 0 && x < X_MAX && y < Y_MAX && !temp[y][x].getIsVisit())
		{
			temp[y][x].setIsVisit(true);
			floodFill(x - 1, y);
			floodFill(x, y - 1);
			floodFill(x + 1, y);
			floodFill(x, y + 1);
		}
	}
}

bool cBuildMap::validate()
{
	COORD c;
	do {
		c.X = random(X_MAX - 2, 1);
		c.Y = random(Y_MAX - 2, 1);
	} while (temp[c.Y][c.X].getStatus() == WALL);
	
	floodFill(c.X, c.Y);

	bool success = true;
	for (int i = 0; i < Y_MAX; i++)
	{
		for (int j = 0; j < X_MAX; j++)
		{
			if (!temp[i][j].getIsVisit())
			{
				success = false;
			}
			if (temp[i][j].getStatus() != WALL)
			{
				temp[i][j].setIsVisit(false);
			}
		}
	}

	return success;
}

bool cBuildMap::save()
{
	if (validate())
	{
		scene->set(temp);
		gotoxy({ 90, 16 });
		setColor(C_WHITE);
		printf("Successfully save the map!");
		getchar();
		return true;
	}

	gotoxy({ 86, 16 });
	setColor(C_RED);
	printf("The map cannot contain a dead zone!");
	setColor(C_WHITE);
	Sleep(1000);
	for (short i = 85; i < 125; i++)
	{
		gotoxy({ i, 16 });
		printf(" ");
	}
	return false;
}

void cBuildMap::fill(COORD c)
{
	switch (temp[c.Y][c.X].getStatus())
	{
	case WALL:
		printf(" ");
		temp[c.Y][c.X].setStatus(FLOOR);
		temp[c.Y][c.X].setIsVisit(false);
		block++;
		break;
	case FLOOR:
		if (block > 0)
		{
			setColor(C_GREEN);
			printf("%c", 178);
			setColor(C_WHITE);
			temp[c.Y][c.X].setStatus(WALL);
			temp[c.Y][c.X].setIsVisit(true);
			block--;
		}
		else
		{
			gotoxy({ 86, 16 });
			setColor(C_RED);
			printf("Already maximum block added!");
			Sleep(1000);
			setColor(C_WHITE);
			for (short i = 86; i < 115; i++)
			{
				gotoxy({ i, 16 });
				printf(" ");
			}
		}
		break;
	}
	showBlockStatus();
}

void cBuildMap::moveCursor(COORD& c)
{
	if (GetAsyncKeyState(VK_UP))
	{
		if (c.Y > 1)
		{
			c.Y--;
		}
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		if (c.Y < Y_MAX - 2)
		{
			c.Y++;
		}
	}
	else if (GetAsyncKeyState(VK_LEFT))
	{
		if (c.X > 1)
		{
			c.X--;
		}
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		if (c.X < X_MAX - 2)
		{
			c.X++;
		}
	}
}
