#include "cConsole.h"

void cConsole::clearScreen()
{
	system("cls");
	for (int _ = 0; _ < 25; _++)
	{
		printf("\n");
	}
}

void cConsole::setColor(WORD w)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), w);
}

void cConsole::gotoxy(COORD c)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

bool cConsole::validArrow()
{
	return (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_DOWN));
}
