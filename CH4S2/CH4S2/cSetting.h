#pragma once
#include "cConsole.h"
#include "cSound.h"

class cSetting : public cConsole
{
private:
	cSound* sound;
	int block;
	int speed;
	int star;
public:
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
