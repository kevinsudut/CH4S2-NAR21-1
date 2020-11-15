#pragma once
#include "cConsole.h"
#include "cPlay.h"
#include "cScene.h"
#include "cBuildMap.h"
#include "cSetting.h"

class cGame : public cConsole
{
private:
	cPlay* play;
	cScene* scene;
	cBuildMap* build;
	cSetting* setting;
public:
	cGame();
	~cGame();
	void initialize();
	void run();
};
