#include "Global.h"
#include "cSetting.h"

cSetting::cSetting()
{
	this->block = 550;
	this->star = 300;
	this->speed = 80;
	this->sound = new cSound();
	this->sound->play();
}

cSetting::~cSetting()
{
	delete sound;
}

void cSetting::setStar(const int star)
{
	this->star = star;
}

int cSetting::getStar()
{
	return star;
}

void cSetting::setBlock(const int block)
{
	this->block = block;
}

int cSetting::getBlock()
{
	return block;
}

void cSetting::setSpeed(const int speed)
{
	this->speed = speed;
}

int cSetting::getSpeed()
{
	return speed;
}

void cSetting::show()
{
	setColor(C_WHITE);
	for (int i = 0; i < 9; i++)
	{
		printf("\n");
	}
	printf("\t\t\tMaximum Star\t>> %04d <<\n", star);
	printf("\t\t\tMaximum Wall\t   %04d   \n", block);
	printf("\t\t\tMaximum Speed\t   %04d   \n", speed);
	printf("\t\t\tMusic Status\t   %04s   \n", sound->getStatus());
	
	gotoxy({ 80, 4 });
	printf("%c", 201);
	for (int i = 0; i < 26; i++)
	{
		printf("%c", 205);
	}
	printf("%c", 187);
	gotoxy({ 80, 5 });
	printf("%c SUDUT and Precious Stars %c", 186, 186);
	gotoxy({ 80, 6 });
	printf("%c", 200);
	for (int i = 0; i < 26; i++)
	{
		printf("%c", 205);
	}
	printf("%c", 188);
	gotoxy({ 66, 8 });
	printf("Legend:");
	gotoxy({ 66, 10 });
	printf("> Press the up or down arrow key to move the cursor");
	gotoxy({ 66, 11 });
	printf("> Press the left or right arrow key to change the value");
	gotoxy({ 66, 12 });
	printf("> Press the ESC key to save the current setting");
	
	gotoxy({ 50, 9 });
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
		if (star > 100)
		{
			printf("%04d", --star);
		}
		break;
	case VK_RIGHT:
		if (star < 500)
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
		if (block > 400)
		{
			printf("%04d", --block);
		}
		break;
	case VK_RIGHT:
		if (block < 700)
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
