#include "cPlay.h"

cPlay::cPlay()
{
}

cPlay::cPlay(cScene* scene, cSetting* setting)
{
	this->scene = scene;
	this->setting = setting;
	this->head = this->tail = this->bHead = NULL;
}

cPlay::~cPlay()
{
}

void cPlay::initialize()
{
	system("cls");
	setColor(C_WHITE);
	for (int i = 0; i < Y_MAX; i++)
	{
		for (int j = 0; j < X_MAX; j++)
		{
			map[i][j] = scene->getNode(j, i);
		}
	}
	show();
}

void cPlay::show()
{
	generate();
	for (int i = 0; i < Y_MAX; i++)
	{
		for (int j = 0; j < X_MAX; j++)
		{
			setColor(C_WHITE);
			switch (map[i][j].getStatus())
			{
			case FLOOR:
				printf(" ");
				break;
			case WALL:
				setColor(C_GREEN);
				printf("%c", 178);
				break;
			case STAR:
				setColor(C_YELLOW);
				printf("*");
				break;
			case PLAYER:
				setColor(C_AQUA);
				printf("%c", 2);
				break;
			}
		}
		printf("\n");
	}
}

void cPlay::generate()
{
	star = random(setting->getStar(), 80);
	for (int i = 0; i < star; i++)
	{
		COORD c;
		do {
			c.X = random(X_MAX - 2, 1);
			c.Y = random(Y_MAX - 2, 1);
		} while (map[c.Y][c.X].getStatus() != FLOOR);
		map[c.Y][c.X].setStatus(STAR);
	}

	do {
		player.X = random(X_MAX - 2, 1);
		player.Y = random(Y_MAX - 2, 1);
	} while (map[player.Y][player.X].getStatus() != FLOOR);
	map[player.Y][player.X].setStatus(PLAYER);
	map[player.Y][player.X].setIsVisit(true);
}

void cPlay::run()
{
	int count = 0;
	setColor(C_WHITE);
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

	gotoxy({ 93, 8 });
	printf("Total of Star Caught");
	while (star > 0)
	{
		setColor(C_WHITE);
		gotoxy({ 101, 10 });
		printf("%03d", count);
		catchStar();
		count++;
		star--;
	}

	setColor(C_WHITE);
	gotoxy({ 101, 10 });
	printf("%03d", count);	
	gotoxy({ 88, 12 });
	printf("Finished catching all the stars");
	getchar();
}

void cPlay::catchStar()
{
	pushTrack(player, NULL);
	Track* curr = head;
	while (curr)
	{
		if (openPath(curr))
		{
			break;
		}
		curr = curr->next;
	}
	for (int i = 0; i < Y_MAX; i++)
	{
		for (int j = 0; j < X_MAX; j++)
		{
			if (map[i][j].getStatus() == OPEN_PATH || map[i][j].getStatus() == PATH)
			{
				map[i][j].setStatus(FLOOR);
				map[i][j].setIsVisit(false);
			}
		}
	}
	popTrack();
	popBackTrack();
}

bool cPlay::openPath(Track* curr)
{
	int rand = random(0, 1);
	short dx[4] = { 1, -1, 0, 0 };
	short dy[4] = { 0, 0, -1, 1 };
	
	if (rand == 1)
	{
		dx[0] = dx[1] = 0;
		dx[2] = 1;
		dx[3] = -1;
		dy[0] = -1;
		dy[1] = 1;
		dy[2] = dy[3] = 0;
	}
	
	for (int i = 0; i < 4; i++)
	{
		COORD c = curr->c;
		c.X += dx[i];
		c.Y += dy[i];	
		if (c.X > 0 && c.X < X_MAX - 1 && c.Y > 0 && c.Y < Y_MAX - 1)
		{
			if (!map[c.Y][c.X].getIsVisit())
			{
				map[c.Y][c.X].setIsVisit(true);
				if (map[c.Y][c.X].getStatus() != STAR)
				{
					map[c.Y][c.X].setStatus(OPEN_PATH);
					pushTrack(c, curr);
				}
				
				if (map[c.Y][c.X].getStatus() == STAR)
				{
					setColor(C_RED);
					gotoxy(c);
					printf("*");
					while (curr)
					{
						map[curr->c.Y][curr->c.X].setStatus(PATH);
						pushBackTrack(curr->c);
						curr = curr->parent;
					}
					Track* back = bHead;
					while (back)
					{
						Sleep(setting->getSpeed());
						setColor(C_AQUA);
						gotoxy(back->c);
						printf(" ");
						if (back->next)
						{
							gotoxy(back->next->c);
							printf("%c", 2);
						}
						back = back->next;
					}
					map[c.Y][c.X].setStatus(PLAYER);
					gotoxy(c);
					printf("%c", 2);
					map[c.Y][c.X].setStatus(PLAYER);
					map[c.Y][c.X].setIsVisit(true);
					player = c;
					return true;
				}
			}
		}
	}
	return false;
}
