#pragma once
#include "cSound.h"

class cSetting
{
private:
	cSound* sound;
	int block;
	int speed;
	int star;
public:
	void gotoxy(COORD c)
	{ 
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	}
	bool validArrow()
	{
		return (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_DOWN));
	}

	cSetting();
	cSetting(cSound* sound);
	~cSetting();
	void show();
	void run();
	void move(COORD& left, COORD& right);
	void starSetting(int key);
	void blockSetting(int key);
	void speedSetting(int key);
	void soundSetting(int key);
};
