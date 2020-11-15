#pragma once
#include "cConsole.h"
#include "cSound.h"

class cSetting : public cConsole
{
private:
	cSound* sound;
	int star;
	int block;
	int speed;
public:
	cSetting();
	cSetting(cSound* sound);
	~cSetting();
	void setStar(const int star);
	int getStar();
	void setBlock(const int block);
	int getBlock();
	void setSpeed(const int speed);
	int getSpeed();
	void show();
	void run();
	void move(COORD& left, COORD& right);
	void starSetting(int key);
	void blockSetting(int key);
	void speedSetting(int key);
	void soundSetting(int key);
};
