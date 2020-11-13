#pragma once
#include <Windows.h>

#define C_WHITE 0x0F
#define C_AQUA 0X0B
#define C_YELLOW 0x0E
#define C_RED 0x0C

class cColor
{
public:
	cColor();
	~cColor();
	void setColor(WORD w);
};
