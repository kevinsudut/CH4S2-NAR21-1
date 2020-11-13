#include "cColor.h"

cColor::cColor()
{
}

cColor::~cColor()
{
}

void cColor::setColor(WORD w)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), w);
}
