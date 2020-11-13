#include "Global.h"
#include "cSetting.h"

cSetting::cSetting()
{
}

cSetting::cSetting(cSound* sound)
{
	this->block = 300;
	this->star = 250;
	this->speed = 80;
	this->sound = sound;
}

cSetting::~cSetting()
{
}

void cSetting::show()
{
	for (int i = 0; i < 9; i++)
	{
		printf("\n");
	}
	printf("\t\t\tMax Star\t>> %04d <<\n", star);
	printf("\t\t\tMax Block\t   %04d   \n", block);
	printf("\t\t\tMax Speed\t   %04d   \n", speed);
	printf("\t\t\tMusic Status\t   %04s   \n", sound->getStatus());
}

void cSetting::run()
{
	system("cls");
	show();
	COORD left = { 40, 9 };
	COORD right = { 48, 9 };
	while (true)
	{
		if (kbhit())
		{
			int key = getch();
			if (key == 27)
			{
				return;
			}
			if (validArrow())
			{
				getch();
				gotoxy(left);
				printf("  ");
				gotoxy(right);
				printf("  ");
				move(left, right);
				gotoxy(left);
				printf(">>");
				gotoxy(right);
				printf("<<");
			}
		}
	}
}

void cSetting::move(COORD &left, COORD &right)
{
	if (GetAsyncKeyState(VK_UP))
	{
		if (left.Y - 1 < 9)
		{
			left.Y = right.Y = 12;
			return;
		}
		left.Y--;
		right.Y--;
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		if (left.Y + 1 > 12)
		{
			left.Y = right.Y = 9;
			return;
		}
		left.Y++;
		right.Y++;
	}
	else if (GetAsyncKeyState(VK_LEFT))
	{
		COORD c = { 43, left.Y };
		gotoxy(c);
		switch (left.Y)
		{
		case 9:
			starSetting(VK_LEFT);
			break;
		case 10:
			blockSetting(VK_LEFT);
			break;
		case 11:
			speedSetting(VK_LEFT);
			break;
		case 12:
			soundSetting(VK_LEFT);
			break;
		}
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		COORD c = { 43, left.Y };
		gotoxy(c);
		switch (left.Y)
		{
		case 9:
			starSetting(VK_RIGHT);
			break;
		case 10:
			blockSetting(VK_RIGHT);
			break;
		case 11:
			speedSetting(VK_RIGHT);
			break;
		case 12:
			soundSetting(VK_RIGHT);
			break;
		}
	}
}

void cSetting::starSetting(int key)
{
	switch (key)
	{
	case VK_LEFT:
		if (star > 50)
		{
			printf("%04d", --star);
		}
		break;
	case VK_RIGHT:
		if (star < 400)
		{
			printf("%04d", ++star);
		}
		break;
	}
}

void cSetting::blockSetting(int key)
{
	switch (key)
	{
	case VK_LEFT:
		if (block > 100)
		{
			printf("%04d", --block);
		}
		break;
	case VK_RIGHT:
		if (block < 500)
		{
			printf("%04d", ++block);
		}
		break;
	}
}

void cSetting::speedSetting(int key)
{
	switch (key)
	{
	case VK_LEFT:
		if (speed > 50)
		{
			printf("%04d", --speed);
		}
		break;
	case VK_RIGHT:
		if (speed < 100)
		{
			printf("%04d", ++speed);
		}
		break;
	}
}

void cSetting::soundSetting(int key)
{
	if (sound->getIsPlay())
	{
		sound->stop();
	}
	else
	{
		sound->play();
	}
	printf("%04s", sound->getStatus());
}
