#pragma once
#include "Global.h"

#define C_WHITE 0x0F
#define C_AQUA 0X0B
#define C_GREEN 0X0A
#define C_PURPLE 0X0D
#define C_YELLOW 0x0E
#define C_RED 0x0C

class cConsole
{
protected:
	void clearScreen();
	void setColor(WORD w);
	void gotoxy(COORD c);
	bool validArrow();
	int random(int max, int min);
};
