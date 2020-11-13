#pragma once
#include "cColor.h"
#include "cSetting.h"
#include "cSound.h"
#include "cScene.h"

class cGame
{
private:
	cColor* color;
	cSetting* setting;
	cSound* sound;
	cScene* scene;
public:
	void clear_screen()
	{
		system("cls");
		for (int _ = 0; _ < 25; _++)
		{
			printf("\n");
		}
	}

	cGame();
	~cGame();
	void initialize();
	void run();
};
