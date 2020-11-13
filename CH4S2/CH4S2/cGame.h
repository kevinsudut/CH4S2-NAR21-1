#pragma once
#include "cConsole.h"
#include "cSetting.h"
#include "cSound.h"
#include "cScene.h"

class cGame : public cConsole
{
private:
	cSetting* setting;
	cSound* sound;
	cScene* scene;
public:
	cGame();
	~cGame();
	void initialize();
	void run();
};
